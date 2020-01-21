/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniRT.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgarcia- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/20 08:39:55 by mgarcia-          #+#    #+#             */
/*   Updated: 2020/01/21 11:52:07 by mgarcia-         ###   ########.fr       */
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

void		define_line(int i, int j, double xratio, double yratio, t_scn *data)
{
	t_p3	p;

	p.z = data->fr.ulcorner.z;
	p.x = xratio * i + data->fr.ulcorner.x;
	p.y = yratio * j - data->fr.ulcorner.y;
	data->nv = normalize(p);
}

void		sphere_intersection(void *mlx_ptr, void *win_ptr, int i, int j, t_scn data)
{
	//return type int, 1 si corta loksea y 0 si no corta ni bakalaoo
	double	disc;

	disc = pow(scl_product(data.nv, vec_substract(data.O, data.sphere1.c)), 2) -
		(scl_product(vec_substract(data.O, data.sphere1.c), vec_substract(data.O, data.sphere1.c)) - pow(data.sphere1.r, 2));
	
	//aqui no se pinta eh, asi que a ver si vamos quitando ya las mierdas estas hombre
	
	if (disc < 0)
		mlx_pixel_put(mlx_ptr, win_ptr, i, j, 0xffffff);
	else if (disc == 0)
		mlx_pixel_put(mlx_ptr, win_ptr, i, j, 0xff0000);
	else
		mlx_pixel_put(mlx_ptr, win_ptr, i, j, 0xff0000);
}

void		render_scene(void *mlx_ptr, void *win_ptr, t_scn data)
{
	int 	i = 1;
	int 	j = 1;
	double	xratio;
	double	yratio;

	//parse_scene(&data);
	set_camera(&data);
	
	xratio = data.fr.x / data.xres;
	yratio = data.fr.y / data.yres;

	while (j < data.yres)
	{
		i = 0;
		while (i < data.xres)
		{
			define_line(i, j, xratio, yratio, &data);
			// Test intersection w/ all the elments of the scene
			//pick the closer and calculate the color
			sphere_intersection(mlx_ptr, win_ptr, i, j, data);
			//calculate_color
			//putpiksel klk loko
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
	t_lst	lst;

	parse_scene(&data, &lst, ac, av);
	//data.xres = 800;
	//data.yres = 800;
	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, data.xres, data.yres, "miniRT v1");

	render_scene(mlx_ptr, win_ptr, data);

	mlx_loop(mlx_ptr);

	return (0);
}
