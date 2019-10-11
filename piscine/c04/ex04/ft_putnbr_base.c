/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgarcia- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/08 10:17:54 by mgarcia-          #+#    #+#             */
/*   Updated: 2019/07/12 16:50:09 by mgarcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int		check_base(char *base)
{
	int i;

	if (!*base++ || !*base)
		return (0);
	base--;
	while (*base)
	{
		if (!((*base > 47 && *base < 58)
					|| (*base > 64 && *base < 91)
					|| (*base > 96 && *base < 123)))
			return (0);
		i = 1;
		while (*(base + i))
		{
			if (*base == *(base + i))
				return (0);
			i++;
		}
		base++;
	}
	return (1);
}

void	ft_putnbr_base(int nbr, char *base)
{
	int i;

	i = 0;
	if (!check_base(base))
		return ;
	while (*(base + i))
		i++;
	if (nbr > (i - 1) || nbr < -(i - 1))
		ft_putnbr_base(nbr / i, base);
	else if (nbr < 0)
		ft_putchar('-');
	ft_putchar(nbr > 0 ? base[nbr % i] : base[-(nbr % i)]);
}
