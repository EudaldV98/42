/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersections.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgarcia- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 13:02:52 by mgarcia-          #+#    #+#             */
/*   Updated: 2020/02/12 11:31:28 by mgarcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

double		plane_intersection(t_p3 d, t_scn data, t_lst *lst)
{
	double	x;
	double	denom;

	denom  = dot(lst->fig.pl.nv, d/*menos origen*/);

	if (denom == 0)
		return (INFINITY);

	//x = (dot(lst->fig.pl.nv, lst->fig.pl.p) - dot(lst->fig.pl.nv, d)) / denom;
	x = (dot(lst->fig.pl.nv, vec_substract(lst->fig.pl.p, data.O))) / denom;

	return (x > 0 ? x : INFINITY);
}

double		sphere_intersection(t_p3 d, t_scn data, t_lst *lst)
{
	//return type int, 1 si corta loksea y 0 si no corta ni bakalaoo
	double	disc;
	double	k1;
	double 	k2;
	double	k3;
	double	x1;
	double	x2;
	t_p3	oc;

	oc = vec_substract(data.O, lst->fig.sp.c);

	k1 = dot(d, d);
	k2 = 2 * dot(d, oc);
	k3 = dot(oc, oc) - lst->fig.sp.r * lst->fig.sp.r;

	//disc =  dot(data.nv, oc) * dot(data.nv, oc) - (dot(oc, oc) - (lst->fig.sp.r * lst->fig.sp.r));
	disc = k2*k2 - (4*k1*k3);

	x1 = (-k2 + sqrt(disc)) / (2 * k1);
	x2 = (-k2 - sqrt(disc)) / (2 * k1);

	if (disc < 0)
		return (INFINITY);
	else if (disc == 0)
		return (x1);
	else
		return (x1 < x2 ? x1 : x2);
}
