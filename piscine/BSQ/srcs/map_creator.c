/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_creator.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgarcia- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/23 15:44:43 by mgarcia-          #+#    #+#             */
/*   Updated: 2019/07/24 16:27:17 by mgarcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

unsigned int		**map_creator(char *str, t_map_info *code, unsigned int *s)
{
	unsigned int	**tab;
	unsigned int	i;
	unsigned int	j;

	*s = 1;
	while (*str != '\n' && ++(*s))
		str++;
	str++;
	tab = (unsigned int**)malloc(sizeof(unsigned int*) * code->lns);
	i = 0;
	while (i < code->lns)
	{
		j = 0;
		tab[i] = (unsigned int*)malloc(sizeof(unsigned int) * code->col);
		while (j < code->col)
			tab[i][j++] = (*str++ == code->empty ? 1 : 0);
		str++;
		i++;
	}
	return (tab);
}
