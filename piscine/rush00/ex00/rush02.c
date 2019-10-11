/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush02.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgarcia- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/06 14:10:38 by mgarcia-          #+#    #+#             */
/*   Updated: 2019/07/06 14:49:08 by mgarcia-         ###   ########.fr       */
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
			if ((i == 1 && j == 1) || (i == 1 && j == x))
				ft_putchar('A');
			else if (((i == 1 || i == y) && (j > 1 && j < x))
					|| ((i > 1 && i < y) && (j == 1 || j == x)))
				ft_putchar('B');
			else if ((i > 1 && i < y) && (j > 1 && j < x))
				ft_putchar(32);
			else if (i == y && (j == 1 || j == x))
				ft_putchar('C');
			j++;
		}
		if (y > 0 && x > 0)
			ft_putchar('\n');
		i++;
	}
}
