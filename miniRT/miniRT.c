/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniRT.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgarcia- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/20 08:39:55 by mgarcia-          #+#    #+#             */
/*   Updated: 2020/02/07 12:50:07 by mgarcia-         ###   ########.fr       */
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

double	sphere_intersection(t_p3 d, t_scn data, t_lst *lst)
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

double		try_all_intersections(t_scn data, t_lst *lst, t_p3 d, t_lst *closest_figure, double *closest_intersection, t_p3 *n)
{
	double	in;

	while (lst)
	{
		if (lst->flag & SP)
			in = sphere_intersection(d, data, lst);
		/*else if (lst->flag & PL)
			in = plane_intersection;
		else if (lst->flag & SQ)
			in = square_intersection;
		else if (lst->flag & CY)
			in = cylinder_intersection;
		else if (lst->flag & TR)
			in = triangle_intersection;
		*/
		if (/*in > 0 Origne de la cmaar &&*/ in < *closest_intersection)
		{
			*closest_figure = *lst;
			*closest_intersection = in;
			*n = lst->fig.sp.c;
		}

		lst = lst->next;
	}
	return (in);
}


double		compute_light(t_p3 p, t_p3 normal, t_scn data)
{
	double	light;
	t_p3	direction;
	
	light = 0;
	light += data.al;
    direction = vec_substract(data.l->o, p);
	if (dot(normal, direction) > 0)
		light += data.l->br * (dot(normal, direction) / (mod(normal) * mod(direction)));
	return (light);
}


void		render_scene(void *mlx_ptr, void *win_ptr, t_scn data, t_lst *lst)
{
	int 		i;
	int 		j;
	int			color;

	t_lst		closest_figure;
	double		closest_intersection;
	
	t_p3		d;
	double		in;

	t_p3		p;
	t_p3		n;


	double xratio;
	double yratio;

	//data.background = 0X202020;
	data.background = 0xffffff;


	color = 0x000000;
	set_camera(&data);

	xratio = data.fr.x / data.xres;
	yratio = data.fr.y / data.yres;

/*	closest_intersection.x = INFINITY;
	closest_intersection.y = INFINITY;
	closest_intersection.z = INFINITY;*/

	j = 0;
	while (j < data.yres)
	{
		i = 0;
		while (i < data.xres)
		{
			d = trace_ray(i, j, &data, xratio, yratio);
				
			closest_intersection = INFINITY;
			closest_figure.flag = 0;
			in = try_all_intersections(data, lst, d, &closest_figure, &closest_intersection, &n);
			color = closest_figure.flag != 0 ? closest_figure.color : data.background;
		

			p = vec_add(data.O, scal_x_vec(closest_intersection, normalize(d)));
			//P = O + closest_t*D  # Compute intersection
    	
			n = vec_substract(p, n); //p - closest sphere center
    		n = normalize(n);
    		
			color *= compute_light(p, n, data);
			
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

	//mlx_hook(win_ptr, 17, 1L << 17, exit, &data);

	mlx_loop(mlx_ptr);

	return (0);
}
