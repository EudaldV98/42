/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniRT.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgarcia- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/20 08:39:55 by mgarcia-          #+#    #+#             */
/*   Updated: 2020/02/12 15:47:39 by mgarcia-         ###   ########.fr       */
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

void	try_all_intersections(t_p3 O, t_p3 d, double min, double max, t_lst *lst, t_lst *closest_figure, double *closest_intersection)
{
	double	in;

	while (lst)
	{
		if (lst->flag & SP)
			in = sphere_intersection(O, d, lst);
		else if (lst->flag & PL)
			in = plane_intersection(O, d, lst);
		/*else if (lst->flag & SQ)
			in = square_intersection;
		else if (lst->flag & CY)
			in = cylinder_intersection;
		else if (lst->flag & TR)
			in = triangle_intersection;
		*/
		if (in > min && in < *closest_intersection)
		{
			*closest_figure = *lst;
			*closest_intersection = in;
		}

		lst = lst->next;
	}
}

void		render_scene(void *mlx_ptr, void *win_ptr, t_scn data, t_lst *lst)
{
	int 		i;
	int 		j;
	int			color;

	t_lst		closest_figure;
	double		closest_intersection;
	
	t_p3		d;

	t_p3		ip;
	t_p3		normal;

	double xratio;
	double yratio;

	data.background = 0xffffff;

	color = 0x000000;
	set_camera(&data);

	xratio = data.fr.x / data.xres;
	yratio = data.fr.y / data.yres;

	j = 0;
	while (j < data.yres)
	{
		i = 0;
		while (i < data.xres)
		{
			d = trace_ray(i, j, &data, xratio, yratio);
				
			closest_intersection = INFINITY;
			closest_figure.flag = 0;
			try_all_intersections(data.O, d, 1, INFINITY, lst, &closest_figure, &closest_intersection);	
			color = closest_figure.flag != 0 ? closest_figure.color : data.background;
			ip = vec_add(data.O, scal_x_vec(closest_intersection, normalize(d)));

			if (is_lit(ip, vec_substract(data.l->o, ip), data, lst))
			{
				normal = calc_normal(ip, closest_figure);
				color = color_x_light(color, compute_light(ip, normal, data));
			}
			else
				color = color_x_light(color, data.al);

			
			mlx_pixel_put(mlx_ptr, win_ptr, i, j, color);
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

	mlx_hook(win_ptr, 17, 1L << 17, exit, &data);

	mlx_loop(mlx_ptr);

	return (0);
}
