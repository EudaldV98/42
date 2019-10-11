/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_dictionary.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgarcia- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/21 21:57:57 by mgarcia-          #+#    #+#             */
/*   Updated: 2019/07/21 23:32:12 by mgarcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "functions.h"

char		*dict_cleaner1(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if ((str[i] == 32 && str[i + 1] == ':')
			|| (str[i] == 32 && str[i - 1] == ':'))
		{
			while (str[i])
			{
				str[i] = str[i + 1];
				i++;
			}
			i = -1;
		}
		i++;
	}
	return (str);
}

char		*dict_cleaner2(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] == 32 && str[i - 1] == 32)
		{
			while (str[i])
			{
				str[i] = str[i + 1];
				i++;
			}
			i = -1;
		}
		i++;
	}
	return (str);
}

char		*dict_cleaner(char *str)
{
	char	*dict;

	dict = dict_cleaner1(str);
	dict = dict_cleaner2(dict);
	return (dict);
}

int			check_dictionary(char *str)
{
	while (*str)
	{
		while (*str == '\n')
			str++;
		if (*str < '0' || *str > '9')
			return (0);
		while (*str >= '0' && *str <= '9')
			str++;
		while (*str == 32)
			str++;
		if (*str != ':')
			return (0);
		str++;
		while (*str == 32)
			str++;
		if (*str == '\n')
			return (0);
		while (*str > 31)
			str++;
		if (*str != '\n')
			return (0);
		str++;
	}
	return (1);
}
