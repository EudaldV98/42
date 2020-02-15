/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniRT.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgarcia- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/20 08:39:55 by mgarcia-          #+#    #+#             */
/*   Updated: 2020/02/15 12:41:15 by mgarcia-         ###   ########.fr       */
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

int		**render_scene(void *mlx_ptr, void *win_ptr, t_scn data, t_lst *lst,
			int **img, int t /*void * t*/)
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

			if (is_lit(ip, vec_substract(data.l->o, ip), data, lst))
			{
				normal = calc_normal(ip, closest_figure);
				color = color_x_light(color, compute_light(ip, normal, data));
			}
			else
				color = color_x_light(color, data.al);
				
			
			//mlx_pixel_put(mlx_ptr, win_ptr, i, j, color);
			img[i][j % n] = color;
			i++;
		}
		j++;
	}
	return (img);
}


void		*do_the_thing(void *jeje)
{
	t_thngs		*cosas;
	int			n;
	int			i = 0;

	cosas = (t_thngs*)jeje;
	n = cosas->i;
	printf("entrando con thread id %d\n", cosas->i);
	cosas->img = malloc(sizeof(int*) * cosas->data.xres);
	while (i < cosas->data.xres)
		cosas->img[i++] = malloc(sizeof(int) * (cosas->data.yres / NUM_THREADS));
	cosas->img = render_scene(cosas->mlx_ptr, cosas->win_ptr, cosas->data, cosas->lst, cosas->img, cosas->i);
	printf("saliendoo con thread id %d\n", cosas->i);
}

int main(int ac, char **av)
{
	pthread_t	threads[NUM_THREADS];
	int			rc;
	int			i = 0;
	int			x;
	int			y;

	void		*mlx_ptr;
	void		*win_ptr;
	t_scn		data;
	t_lst		*lst;
	t_lst		*begin;
	t_thngs		cosas[NUM_THREADS];

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

	i = 0;
	while (i < NUM_THREADS)
	{	
		cosas[i].mlx_ptr = mlx_ptr;
		cosas[i].win_ptr = win_ptr;
		cosas[i].data = data;
		cosas[i].lst = lst;
		cosas[i].i = i;
		i++;
	}
	//cosas->i = i;
	//do_the_thing(cosas);
	//render_scene(mlx_ptr, win_ptr, data, lst);

	i = 0;
	while (i < NUM_THREADS)
	{
		//printf("i = %d and cosas->i =%d\n", i, cosas->i);
		rc = pthread_create(&threads[i], NULL, do_the_thing, (&cosas[i]));
		if (rc) {
			printf("Error:unable to create thread, %d\n", rc);
			exit(-1);
		}
		i++;
	}
	i = 0;
	while (i < NUM_THREADS)
	{
		pthread_join(threads[i], NULL);
		printf("thread %d ended\n", i);
		i++;
	}
	//sleep(10);
	//pthread_exit(NULL);
	i = 0;
	while (i < NUM_THREADS)
	{
		y = 0;
		while (y < data.yres / NUM_THREADS)
		{
			x = 0;
			while (x < data.xres)
			{
				//mlx_pixel_put(mlx_ptr, win_ptr, i, j, color);
				mlx_pixel_put(mlx_ptr, win_ptr, x, y + (i * (data.yres / NUM_THREADS)), cosas[i].img[x][y]);
				x++;
			}
			y++;
		}
		i++;
	}

	mlx_hook(win_ptr, 17, 1L << 17, exit, &data);

	mlx_loop(mlx_ptr);
	
	//pthread_join(threads[i - 1], NULL);
	pthread_exit(NULL);

	return (0);
}
