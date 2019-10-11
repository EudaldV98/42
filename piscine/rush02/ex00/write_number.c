/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_number.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgarcia- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/20 15:53:46 by mgarcia-          #+#    #+#             */
/*   Updated: 2019/07/21 23:30:06 by mgarcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "functions.h"

static int		last_word(char *str)
{
	str++;
	while (*str == '0')
		str++;
	if (!*str)
		return (1);
	return (0);
}

static int		dict_putstr(char *dict, char *digit, int bol)
{
	char		*word;

	if (!(word = ft_strstr(dict, digit)))
		return (0);
	while (*word && *(word - 1) != ':')
		word++;
	while (*word && *word == 32)
		word++;
	ft_putline(word);
	if (bol == 1)
		ft_putchar(32);
	else if (bol == 2)
		ft_putstr(", ");
	else if (bol == 3)
		ft_putstr(" and ");
	else if (bol == 4)
		ft_putstr("-");
	return (1);
}

static void		write_digit(char *str, char *dict, int len)
{
	char		digit[3];
	char		*word;

	if (len % 3 == 0 || len % 3 == 1)
	{
		digit[0] = *str;
		digit[1] = '\0';
		dict_putstr(dict, digit, len > 1 ? 1 : 0);
		if (len % 3 == 0)
			dict_putstr(dict, "100", len > 2 ? 1 : 0);
	}
	else if (len % 3 == 2)
	{
		digit[0] = *str;
		digit[1] = *(str + 1);
		digit[2] = '\0';
		if (ft_strstr(dict, digit))
			dict_putstr(dict, digit, len > 2 ? 1 : 0);
		else
		{
			digit[1] = '0';
			digit[2] = '\0';
			dict_putstr(dict, digit, len > 2 ? 1 : 0);
		}
	}
}

void			write_number(char *str, char *dict)
{
	char		b10[ft_strlen(str) + 1];
	char		digit[3];
	int			i;
	int			bol;
	int			len;

	if (*str == '+')
		str++;
	while (*str == '0')
		str++;
	len = ft_strlen(str);
	bol = 0;
	while (len > 0)
	{
		if (ft_strstr(dict, str) && *str != '0' && *str)
		{
			if (*str == '1' && len > 2)
				dict_putstr(dict, "1", 1);
			dict_putstr(dict, str, 0);
			break ;
		}
		else if (*str)
		{
			if (*str  != '0')
				write_digit(str, dict, len);
			digit[0] = *str;
			digit[1] = *(str + 1);
			digit[2] = '\0';
			if (len % 3 == 2 && ft_strstr(dict, digit))
				str++;
			if (len % 3 == 1 && len > 1)
			{
				b10[0] = '1';
				i = 1;
				while (i < len)
					b10[i++] = '0';
				b10[i] = '\0';
				if (*str != '0' || (*str == '0' && bol == 0))
				{
					dict_putstr(dict, b10, !last_word(str) ? 1 : 0);
					bol = 1;
				}
			}
		}
		str++;
		len--;
	}
	ft_putchar('\n');
}
