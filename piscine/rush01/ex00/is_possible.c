/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_possible.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgarcia- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/13 14:43:28 by mgarcia-          #+#    #+#             */
/*   Updated: 2019/07/13 20:41:33 by mgarcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "functions.h"

static int		ft_check_line(int value, int line, int **tab)
{
	int i;

	i = 0;
	while (i < 4)
	{
		if (tab[line][i] == value)
			return (0);
		i++;
	}
	return (1);
}

static int		ft_check_column(int value, int column, int **tab)
{
	int i;

	i = 0;
	while (i < 4)
	{
		if (tab[i][column] == value)
			return (0);
		i++;
	}
	return (1);
}

int				is_possible(int value, int i, int j, int **tab)
{
	if (!ft_check_line(value, i, tab))
		return (0);
	if (!ft_check_column(value, j, tab))
		return (0);
	return (1);
}
