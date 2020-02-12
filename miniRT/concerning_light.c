/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   concerning_light.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgarcia- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 13:06:14 by mgarcia-          #+#    #+#             */
/*   Updated: 2020/02/12 11:31:29 by mgarcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

double		compute_light(t_p3 p, t_p3 normal, t_scn data)
{
	double	light;
	t_p3	direction;

	light = 0;
	light += data.al;
    direction = vec_substract(data.l->o, p);
	if (dot(normal, direction) > 0)
		light += (data.l->br * dot(normal, direction)) / (mod(normal) * mod(direction));
	return (light);
}

t_p3		calc_normal(t_p3 p, t_lst lst)
{
	t_p3	normal;

	if (lst.flag & SP)
		normal = normalize(vec_substract(p, lst.fig.sp.c));
	else if (lst.flag & PL)
		normal = lst.fig.pl.nv;

	return (normal);
}

int		color_x_light(int color, double light)
{
	int mask = 255;
	int r;
	int	g;
	int	b;

	r = light * ((color & (mask << 16)) >> 16);
	g = light * ((color & (mask << 8)) >> 8);
	b = light * (color & mask);
	
	return ((r << 16) | (g << 8) | b);
}
