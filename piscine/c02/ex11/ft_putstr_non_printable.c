/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgarcia- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/05 15:13:49 by mgarcia-          #+#    #+#             */
/*   Updated: 2019/07/07 12:49:51 by mgarcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

char	*ft_strcpy(char *dest, char *src)
{
	while (*src)
		*dest++ = *src++;
	*dest = '\0';
	return (dest);
}

void	hex(int nb, int bol)
{
	char str[17];

	ft_strcpy(str, "0123456789abcdef");
	if (nb < 16 && bol == 1)
		ft_putchar('0');
	if (nb > 15)
	{
		hex(nb / 16, 0);
		hex(nb % 16, 0);
	}
	else
		ft_putchar(str[nb]);
}

void	ft_putstr_non_printable(char *str)
{
	while (*str)
	{
		if (*(unsigned char *)str > 31 && (*(unsigned char *)str < 127))
			ft_putchar(*str++);
		else
		{
			ft_putchar('\\');
			hex(*(unsigned char *)str++, 1);
		}
	}
}
