/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush00.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adlesieu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/06 10:43:32 by adlesieu          #+#    #+#             */
/*   Updated: 2019/07/06 14:49:42 by mgarcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	rush(int x, int y)
{
	int i;
	int j;

	i = 1;
	while (i <= y)
	{
		j = 1;
		while (j <= x)
		{
			if ((i == 1 && j == 1) || (i == 1 && j == x)
					|| (i == y && j == 1) || (i == y && j == x))
				ft_putchar('o');
			else if (i == 1 || i == y)
				ft_putchar('-');
			else if ((i > 1 && i < y) && (j == 1 || j == x))
				ft_putchar('|');
			else if ((i > 1 && i < y) && (j > 1 && j < x))
				ft_putchar(' ');
			j++;
		}
		if (y > 0 && x > 0)
			ft_putchar('\n');
		i++;
	}
}
