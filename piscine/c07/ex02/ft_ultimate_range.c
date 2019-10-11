/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgarcia- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/11 21:17:42 by mgarcia-          #+#    #+#             */
/*   Updated: 2019/07/15 22:52:19 by mgarcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_ultimate_range(int **range, int min, int max)
{
	int		i;
	int		*tab;

	if (min >= max)
	{
		*range = NULL;
		return (0);
	}
	if (!(tab = (int *)malloc(sizeof(int) * (max - min))))
		return (-1);
	i = 0;
	while (min < max)
		tab[i++] = min++;
	*range = tab;
	return (i);
}
