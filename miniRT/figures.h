/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   figures.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgarcia- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 10:48:18 by mgarcia-          #+#    #+#             */
/*   Updated: 2020/01/27 15:19:34 by mgarcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _FIGURES_H_
# define _FIGURES_H_

#include "miniRT.h"

typedef struct	s_p3
{
	double x;
	double y;
	double z;
}				t_p3;

typedef struct	s_sphere
{
	t_p3	c;
	double	r;
	int		color;
}				t_sphere;

typedef struct	s_plane
{
	t_p3	p;
	t_p3	nv;
	int		color;
}				t_plane;

typedef struct	s_square
{
	t_p3	c;
	t_p3	nv;
	double	size;
	int		color;

}				t_square;

typedef struct	s_cylinder
{
	t_p3	c;
	t_p3	nv;
	double	r;
	double	h;
	int		color;
}				t_cylinder;

typedef struct	s_triangle
{
	t_p3	p1;
	t_p3	p2;
	t_p3	p3;
	int		color;
}				t_triangle;

union figures
{
	t_sphere	sp;
	t_plane		pl;
	t_square	sq;
	t_cylinder	cy;
	t_triangle	tr;
};

#endif
