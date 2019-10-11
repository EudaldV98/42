/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgarcia- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/03 18:45:15 by mgarcia-          #+#    #+#             */
/*   Updated: 2019/07/03 20:40:37 by mgarcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	print_ab(int a, int b)
{
	if (a <= 9)
	{
		ft_putchar('0');
		ft_putchar(a + '0');
	}
	else
	{
		ft_putchar(a / 10 + '0');
		ft_putchar(a % 10 + '0');
	}
	ft_putchar(32);
	if (b <= 9)
	{
		ft_putchar('0');
		ft_putchar(b + '0');
	}
	else
	{
		ft_putchar(b / 10 + '0');
		ft_putchar(b % 10 + '0');
	}
}

void	ft_print_comb2(void)
{
	int a;
	int b;

	a = 0;
	while (a <= 98)
	{
		b = a + 1;
		while (b < 100)
		{
			print_ab(a, b);
			if (a != 98)
			{
				ft_putchar(44);
				ft_putchar(32);
			}
			b++;
		}
		a++;
	}
}
