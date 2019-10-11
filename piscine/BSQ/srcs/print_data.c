/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_data.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damouyal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/23 22:36:43 by damouyal          #+#    #+#             */
/*   Updated: 2019/07/24 18:26:09 by mgarcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

void	print_bsq(char *str, t_map_info *mi, t_square *chp)
{
	unsigned int idx;
	unsigned int ldx;
	unsigned int cdx;

	if (chp->size > 0)
	{
		idx = (mi->col + 1) * (chp->y - chp->size + 1) + chp->x - chp->size + 1;
		ldx = 0;
		while (ldx++ < chp->size)
		{
			cdx = 0;
			while (cdx++ < chp->size)
				str[idx++] = mi->full;
			idx += mi->col + 1 - chp->size;
		}
	}
}
