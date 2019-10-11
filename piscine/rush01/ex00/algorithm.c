/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgarcia- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/13 14:43:40 by mgarcia-          #+#    #+#             */
/*   Updated: 2019/07/17 11:38:10 by mgarcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "functions.h"

int				algorithm(t_pov *pov, int **tab)
{
	int i;
	int j;
	int value;
	int *ptr;
	int *ptr2;

	value = 1;
	ptr = &i;
	ptr2 = &j;
	if (!find_blanks(ptr, ptr2, tab))
	{
		if (valid_solution(pov, tab))
			return (1);
		else
			return (0);
	}
	while (value <= 4)
	{
		if (is_possible(value, i, j, tab))
		{
			tab[i][j] = value;
			//print_solution(tab);
			//ft_putchar('\n');
			if (algorithm(pov, tab))
				return (1);
			tab[i][j] = 0;
		}
		value++;
	}
	return (0);
}
