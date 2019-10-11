/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_solution.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgarcia- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/13 16:01:13 by mgarcia-          #+#    #+#             */
/*   Updated: 2019/07/14 22:42:27 by mgarcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "functions.h"

static int		check_col_up(t_pov *pov, int **tab)
{
	int i;
	int j;
	int visibility;
	int count;

	j = 0;
	while (j < 4)
	{
		i = 0;
		count = 0;
		visibility = 0;
		while (i < 4)
		{
			if (tab[i][j] > visibility)
			{
				visibility = visibility + (tab[i][j] - visibility);
				count += 1;
			}
			i++;
		}
		if (count != pov->colup[j])
			return (0);
		j++;
	}
	return (1);
}

static int		check_col_down(t_pov *pov, int **tab)
{
	int i;
	int j;
	int visibility;
	int count;

	j = 0;
	while (j < 4)
	{
		i = 3;
		count = 0;
		visibility = 0;
		while (i >= 0)
		{
			if (tab[i][j] > visibility)
			{
				visibility = visibility + (tab[i][j] - visibility);
				count += 1;
			}
			i--;
		}
		if (count != pov->coldown[j])
			return (0);
		j++;
	}
	return (1);
}

static int		check_row_left(t_pov *pov, int **tab)
{
	int i;
	int j;
	int visibility;
	int count;

	i = 0;
	while (i < 4)
	{
		j = 0;
		count = 0;
		visibility = 0;
		while (j < 4)
		{
			if (tab[i][j] > visibility)
			{
				visibility = visibility + (tab[i][j] - visibility);
				count += 1;
			}
			j++;
		}
		if (count != pov->rowleft[i])
			return (0);
		i++;
	}
	return (1);
}

static int		check_row_right(t_pov *pov, int **tab)
{
	int i;
	int j;
	int visibility;
	int count;

	i = 0;
	while (i < 4)
	{
		j = 3;
		count = 0;
		visibility = 0;
		while (j >= 0)
		{
			if (tab[i][j] > visibility)
			{
				visibility = visibility + (tab[i][j] - visibility);
				count += 1;
			}
			j--;
		}
		if (count != pov->rowright[i])
			return (0);
		i++;
	}
	return (1);
}

int				valid_solution(t_pov *pov, int **tab)
{
	if (!check_col_up(pov, tab))
		return (0);
	if (!check_col_down(pov, tab))
		return (0);
	if (!check_row_left(pov, tab))
		return (0);
	if (!check_row_right(pov, tab))
		return (0);
	return (1);
}
