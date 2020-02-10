/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   concerning_light.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgarcia- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 13:06:14 by mgarcia-          #+#    #+#             */
/*   Updated: 2020/02/10 13:20:17 by mgarcia-         ###   ########.fr       */
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
