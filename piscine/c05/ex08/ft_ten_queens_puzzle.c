/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ten_queens_puzzle.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgarcia- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/09 01:19:17 by mgarcia-          #+#    #+#             */
/*   Updated: 2019/07/14 23:04:23 by mgarcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int		is_possible(int *tab, int i, int j)
{
	int idx;

	idx = 0;
	while (i > idx)
	{
		if (tab[idx] == j)
			return (0);
		else if (tab[idx] == j - (i - idx))
			return (0);
		else if (tab[idx] == j + (i - idx))
			return (0);
		idx++;
	}
	return (1);
}

int		find_comb(int *tab, int i)
{
	int count;
	int idx;
	int j;

	count = 0;
	if (i == 10)
	{
		idx = 0;
		while (idx < 10)
			ft_putchar(tab[idx++] + '0');
		ft_putchar('\n');
		return (1);
	}
	j = 0;
	while (j < 10)
	{
		if (is_possible(tab, i, j) == 1)
		{
			tab[i] = j;
			count += find_comb(tab, i + 1);
			tab[i] = -1;
		}
		j++;
	}
	return (count);
}

int		ft_ten_queens_puzzle(void)
{
	int	tab[10];
	int i;

	i = 0;
	while (i < 10)
		tab[i++] = -1;
	return (find_comb(tab, 0));
}
