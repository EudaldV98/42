/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_solution.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sverhaeg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/14 13:21:51 by sverhaeg          #+#    #+#             */
/*   Updated: 2019/07/14 22:24:59 by mgarcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "functions.h"

void	print_solution(int **tab)
{
	int i;
	int j;

	i = 0;
	j = 0;
	if (tab[0][0] == 0)
	{
		display_error();
		return ;
	}
	while (i < 4)
	{
		while (j < 4)
		{
			ft_putchar(tab[i][j] + '0');
			if (j < 3)
				ft_putchar(' ');
			j++;
		}
		j = 0;
		i++;
		ft_putchar('\n');
	}
}
