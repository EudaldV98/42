/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_params.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgarcia- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/13 15:20:45 by mgarcia-          #+#    #+#             */
/*   Updated: 2019/07/17 11:37:54 by mgarcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "functions.h"

static void		get_rows(char **argv, t_pov *pov)
{
	int		i;
	int		j;

	i = 16;
	j = 0;
	while (i < 24)
	{
		pov->rowleft[j] = argv[1][i] - '0';
		j++;
		i += 2;
	}
	j = 0;
	while (i < 32)
	{
		pov->rowright[j] = argv[1][i] - '0';
		j++;
		i += 2;
	}
}

void			get_params(char **argv, t_pov *pov)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (i < 8)
	{
		pov->colup[j] = argv[1][i] - '0';
		j++;
		i += 2;
	}
	j = 0;
	while (i < 16)
	{
		pov->coldown[j] = argv[1][i] - '0';
		j++;
		i += 2;
	}
	get_rows(argv, pov);
}
