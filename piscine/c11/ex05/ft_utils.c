/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgarcia- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/22 16:18:00 by mgarcia-          #+#    #+#             */
/*   Updated: 2019/07/22 17:41:54 by mgarcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	while (*str)
		write(1, str++, 1);
}

void	ft_putnbr(int nb)
{
	if (nb > 9 || nb < -9)
		ft_putnbr(nb / 10);
	else if (nb < 0)
		ft_putchar('-');
	ft_putchar(nb > 0 ? nb % 10 + 48 : -(nb % 10) + 48);
}

int		ft_strcmp(char *s1, char *s2)
{
	int i;

	i = 0;
	while (s1[i] == s2[i] && s1[i] && s2[i])
		i++;
	return (s1[i] - s2[i]);
}

int		ft_atoi(char *str)
{
	int nb;
	int neg;

	nb = 0;
	neg = 0;
	while (*str == 32 || *str == '\t' || *str == '\n'
			|| *str == '\v' || *str == '\f' || *str == '\r')
		str++;
	while (*str == '+' || *str == '-')
	{
		if (*str == '-')
			neg++;
		str++;
	}
	while ((*str >= '0' && *str <= '9'))
		nb = (nb * 10) + *str++ - 48;
	if (neg % 2 != 0)
		nb = -nb;
	return (nb);
}
