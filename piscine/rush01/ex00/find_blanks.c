/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_blanks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgarcia- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/13 14:43:36 by mgarcia-          #+#    #+#             */
/*   Updated: 2019/07/13 15:18:12 by mgarcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "functions.h"

int		find_blanks(int *ptr, int *ptr2, int **tab)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (i < 4)
	{
		while (j < 4)
		{
			if (tab[i][j] == 0)
			{
				*ptr = i;
				*ptr2 = j;
				return (1);
			}
			j++;
		}
		j = 0;
		i++;
	}
	return (0);
}
