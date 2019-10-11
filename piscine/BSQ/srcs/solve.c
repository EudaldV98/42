/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damouyal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/23 21:17:42 by damouyal          #+#    #+#             */
/*   Updated: 2019/07/24 19:52:44 by mgarcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

static void			ft_sq_setup(t_square *sq, unsigned int x, unsigned int y,
		unsigned int s)
{
	sq->x = x;
	sq->y = y;
	sq->size = s;
}

static void			update_tab(unsigned int **tab, unsigned int ncol,
		unsigned int nline)
{
	unsigned int min;

	if (!(ncol == 0 || nline == 0))
	{
		min = (tab[nline][ncol - 1] < tab[nline - 1][ncol] ?
				tab[nline][ncol - 1] : tab[nline - 1][ncol]);
		tab[nline][ncol] = (min < tab[nline - 1][ncol - 1] ? min :
				tab[nline - 1][ncol - 1]) + 1;
	}
}

void				solve(unsigned int **tab, t_map_info *mi, t_square *champ)
{
	unsigned int ncol;
	unsigned int nline;

	champ->size = 0;
	nline = 0;
	while (nline < mi->lns)
	{
		ncol = 0;
		while (ncol < mi->col)
		{
			if (tab[nline][ncol] > 0)
			{
				update_tab(tab, ncol, nline);
				if (tab[nline][ncol] > champ->size)
					ft_sq_setup(champ, ncol, nline, tab[nline][ncol]);
			}
			ncol++;
		}
		nline++;
	}
}
