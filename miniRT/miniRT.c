/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniRT.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgarcia- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/20 08:39:55 by mgarcia-          #+#    #+#             */
/*   Updated: 2020/02/06 11:02:56 by mgarcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

void		set_camera(t_scn *data)
{
	data->O.x = 0;
	data->O.y = 0;
	data->O.z = 0;
	data->fr.x = 1;
	data->fr.y = 1;
	data->fr.ulcorner.x = -0.5;
	data->fr.ulcorner.y = 0.5;
	data->fr.ulcorner.z = 1;
}

t_p3		trace_ray(int i, int j, t_scn *data, double xratio, double yratio)
{
	t_p3	p;

	p.z = data->fr.ulcorner.z;
	p.x = xratio * i + data->fr.ulcorner.x;
	p.y = yratio * j - data->fr.ulcorner.y;
	data->nv = normalize(p);
	return (p);
}

double	sphere_intersection(void *mlx_ptr, void *win_ptr, int i, int j, t_p3 d, t_scn data, t_lst *lst)
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
	x2 = (-k2 + sqrt(disc)) / (2 * k1);
	
	if (disc < 0)
		return (1000000);
	else if (disc == 0)
		return (x1);
	else
		return (x1 < x2 ? x1 : x2);
}

void		render_scene(void *mlx_ptr, void *win_ptr, t_scn data, t_lst *lst)
{
	int 		i;
	int 		j;
	int			color;
	t_sphere	*closest;
	double		jeje = -1;
	double		cerkita =  -1;
	int			background;
	t_p3		d;

	t_lst		*alst = lst;

	double xratio;
	double yratio;

	background = 0X202020;

	color = 0x000000;
	set_camera(&data);

	xratio = data.fr.x / data.xres;
	yratio = data.fr.y / data.yres;


	j = 1;
	while (j < data.yres)
	{
		i = 0;
		while (i < data.xres)
		{
			d = trace_ray(i, j, &data, xratio, yratio);
			
			//Test intersection w/ all the elments of the scene
			//pick the closest and calculate the color
			lst = alst;	
			while (lst->next)
			{
				if (!(lst->flag & SP))
					lst = lst->next;
				jeje = sphere_intersection(mlx_ptr, win_ptr, i, j, d, data, lst);
				if (cerkita == -1)
				{
					closest = &lst->fig.sp;
					cerkita = jeje;
				}
				else if (jeje < cerkita)
				{
					closest = &lst->fig.sp;
					cerkita = jeje;
				}
				lst = lst->next;
			}
			//printf("cerkita es %f\n", cerkita);
			if (cerkita > 1)
				mlx_pixel_put(mlx_ptr, win_ptr, i, j, closest->color);
			else
				mlx_pixel_put(mlx_ptr, win_ptr, i, j, background);

			//calculate_color

			i++;
		}
		j++;
	}
}

int main(int ac, char **av)
{
	void	*mlx_ptr;
	void	*win_ptr;
	t_scn	data;
	t_lst	*lst;
	t_lst	*begin;

	lst = NULL;
	data.l = NULL;

	parse_scene(&data, &lst, ac, av);

	/*printf("%d, %d\n", data.xres, data.yres);
	printf("ambient light is %.2f, and color is %d\n", data.al, data.acl);
	
	printf("sphere crds are %.1f, %.1f, %.1f, radius is %.5f and color is %d\n", lst->fig.sp.c.x,
			lst->fig.sp.c.y, lst->fig.sp.c.z, lst->fig.sp.r, lst->fig.sp.color);
*/
	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, data.xres, data.yres, "miniRT v1");

	render_scene(mlx_ptr, win_ptr, data, lst);

	//mlx_hook(win_ptr, 17, 1L << 17, exit, &data);

	mlx_loop(mlx_ptr);

	return (0);
}
