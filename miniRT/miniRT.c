/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniRT.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgarcia- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/20 08:39:55 by mgarcia-          #+#    #+#             */
/*   Updated: 2020/02/15 16:47:49 by mgarcia-         ###   ########.fr       */
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

void	render_scene(void *mlx_ptr, void *win_ptr, t_scn data, t_lst *lst,
			int *pixel_tab, int t /*void * t*/)
{
	int			n = data.yres / NUM_THREADS;

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

	j = n * t;
	while (/*j < data.yres */   j < (n * (t + 1)))
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

			/*if (is_lit(ip, vec_substract(data.l->o, ip), data, lst))
			{
				normal = calc_normal(ip, closest_figure);
				color = color_x_light(color, compute_light(ip, normal, data));
			}
			else
				color = color_x_light(color, data.al);
			*/
			normal = calc_normal(ip, closest_figure);
			color = color_x_light(color, compute_light(ip, normal, data, lst));
			
			//mlx_pixel_put(mlx_ptr, win_ptr, i, j, color);
			pixel_tab[i + (j * data.xres)] = color;
			i++;
		}
		j++;
	}
}


void		*do_the_thing(void *jeje)
{
	t_thngs		*cosas;

	cosas = (t_thngs*)jeje;
	render_scene(cosas->mlx_ptr, cosas->win_ptr, cosas->data, cosas->lst, cosas->pixel_tab, cosas->i);

}

int main(int ac, char **av)
{
	pthread_t	threads[NUM_THREADS];
	int			i;

	void		*mlx_ptr;
	void		*win_ptr;
	void		*img_ptr;
	
	int			bits_per_pixel;
	int			size_line;
	int			endian;
	int			*pixel_tab;

	t_scn		data;
	t_lst		*lst;
	t_lst		*begin;
	t_thngs		cosas[NUM_THREADS];

	
	parse_scene(&data, &lst, ac, av);
	
	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, data.xres, data.yres, "miniRT v1");
	
	img_ptr = mlx_new_image (mlx_ptr, data.xres, data.yres);
		
	pixel_tab = (int *)mlx_get_data_addr(img_ptr, &bits_per_pixel, &size_line, &endian);

	i = 0;
	while (i < NUM_THREADS)
	{	
		cosas[i].mlx_ptr = mlx_ptr;
		cosas[i].win_ptr = win_ptr;
		cosas[i].data = data;
		cosas[i].lst = lst;
		cosas[i].i = i;
		cosas[i].pixel_tab = pixel_tab;
		i++;
	}
	i = 0;
	while (i < NUM_THREADS)
	{
		pthread_create(&threads[i], NULL, do_the_thing, (&cosas[i]));
		i++;
	}
	i = 0;
	while (i < NUM_THREADS)
		pthread_join(threads[i++], NULL);

	mlx_put_image_to_window (mlx_ptr, win_ptr, img_ptr, 0, 0);
	
	mlx_hook(win_ptr, 17, 1L << 17, exit, &data);
	mlx_loop(mlx_ptr);
	
	pthread_exit(NULL);

	return (0);
}
