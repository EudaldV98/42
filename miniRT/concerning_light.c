/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   concerning_light.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgarcia- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 13:06:14 by mgarcia-          #+#    #+#             */
/*   Updated: 2020/02/15 17:05:01 by mgarcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

double		compute_light(t_p3 p, t_p3 normal, t_scn data, t_lst *lst)
{
	double	light;
	t_p3	direction;

	light = 0;
	light += data.al;
	while (data.l)
	{
    	direction = vec_substract(data.l->o, p);
		if (is_lit(p, direction, data, lst) && dot(normal, direction) > 0)
			light += (data.l->br * dot(normal, direction)) / (mod(normal) * mod(direction));
		data.l = data.l->next;
	}
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

int		is_lit(t_p3 O, t_p3 d, t_scn data, t_lst *lst)
{
	double in;

	while (lst)
	{
		if (lst->flag & SP)
			in = sphere_intersection(O, d, lst);
		else if (lst->flag & PL)
			in = plane_intersection(O, d, lst);
		/*else if (lst->flag & SQ)
			in = sqare_intersection;*/
		

		if (in > 0.001 && in < 1)
			return (0);
		lst = lst->next;
	}
	return (1);
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

/*	r = pow(r, 1/2.2) * 10;
	g = pow(g, 1/2.2) * 10;
	b = pow(b, 1/2.2) * 10;
*/
	r = r > 255 ? 255 : r;
	g = g > 255 ? 255 : g;
	b = b > 255 ? 255 : b;

	return ((r << 16) | (g << 8) | b);
}
