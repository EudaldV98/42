/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tab_allocate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgarcia- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/13 15:22:13 by mgarcia-          #+#    #+#             */
/*   Updated: 2019/07/16 20:56:24 by mgarcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "functions.h"

int		**tab_allocate(void)
{
	int **tab;
	int i;
	int j;

	i = 0;
	if ((tab = (int**)malloc(sizeof(int*) * 4)))
		return (NULL);
	while (i < 4)
	{
		if (!(tab[i] = (int*)malloc(sizeof(int) * 4)))
			return (NULL);
		j = 0;
		while (j < 4)
		{
			tab[i][j] = 0;
			j++;
		}
		i++;
	}
	return (tab);
}
