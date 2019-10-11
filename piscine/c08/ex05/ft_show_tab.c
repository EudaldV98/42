/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_show_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgarcia- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/10 22:48:13 by mgarcia-          #+#    #+#             */
/*   Updated: 2019/07/12 13:32:06 by mgarcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stock_str.h"
#include <unistd.h>

void		ft_putchar(char c)
{
	write(1, &c, 1);
}

void		ft_putnbr(int nb)
{
	if (nb > 9 || nb < -9)
		ft_putnbr(nb / 10);
	else if (nb < 0)
		ft_putchar('-');
	ft_putchar(nb > 0 ? nb % 10 + 48 : -(nb % 10) + 48);
}

void		ft_show_tab(struct s_stock_str *par)
{
	int i;

	i = 0;
	while (par->str != 0)
	{
		i = 0;
		while (par->str[i])
			ft_putchar(par->str[i++]);
		ft_putchar('\n');
		ft_putnbr(par->size);
		ft_putchar('\n');
		i = 0;
		while (par->str[i])
			ft_putchar(par->copy[i++]);
		ft_putchar('\n');
		par++;
	}
}
