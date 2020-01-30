/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniRT.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgarcia- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/20 08:42:41 by mgarcia-          #+#    #+#             */
/*   Updated: 2020/01/30 12:58:07 by mgarcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _MINIRT_H_
# define _MINIRT_H_

#include <OpenGL/gl3.h>
#include "mlx.h"
#include "figures.h"
#include <stdlib.h>
#include <math.h>

#define SP (1 << 1)
#define PL (1 << 2)
#define SQ (1 << 3)
#define CY (1 << 4)
#define TR (1 << 5)


/*
typedef struct	s_p3
{
	double	x;
	double	y;
	double	z;
}				t_p3;
*/
typedef struct	s_frame
{
	double	x;
	double	y;
	t_p3	ulcorner;
}				t_frame;

typedef struct	s_light
{
	t_p3	o;
	double	br;
	int		color;
	struct	s_light	*next;
}				t_light;

typedef struct	s_scene
{
	int			xres;
	int			yres;
	t_p3		O;
	t_p3		nv;
	char		fov;
	t_frame		fr;
	double		al;
	int			acl;
	t_light		*l;
}				t_scn;

t_p3			normalize(t_p3 p);

typedef struct	s_lst
{
	int				flag;
	union			figures	fig;
	struct s_lst	*next;
}				t_lst;

double 			scl_product(t_p3 a, t_p3 b);

t_p3			vec_add(t_p3 a, t_p3 b);

t_p3			vec_substract(t_p3 a, t_p3 b);

void			parse_scene(t_scn *data, t_lst **lst, int ac, char **av);

#endif
