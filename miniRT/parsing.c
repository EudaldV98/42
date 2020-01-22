/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgarcia- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 11:31:29 by mgarcia-          #+#    #+#             */
/*   Updated: 2020/01/22 14:26:13 by mgarcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include "libft.h"

#define BUFSIZE 32

static char		*readfile(char *str, int fd)
{
	char	buf[BUFSIZE + 1];
	char	*ptr;
	int		ret;
	int		bol;

	bol = 0;
	while ((ret = read(fd, buf, BUFSIZE)) > 0)
	{
		ptr = str;
		buf[ret] = '\0';
		if (!(str = ft_strjoin(str, buf)))
			return (NULL);
		free(ptr);
	}
	return (str);
}

int			stoi(char **str)
{
	int i;
	int	neg;

	i = 0;
	neg = 1;
	if (**str == '-' && *((*str)++))
		neg = -1;
	while (ft_isdigit(**str))
		i = i * 10 + (*((*str)++) - '0');
	return (i * neg);
}

double		stof(char **str)
{
	int		w;
	double	d;
	int		neg;

	w = 0;
	neg = 1;
	if (**str == '-' && *((*str)++))
		neg = -1;
	while (ft_isdigit(**str))
		w = w * 10 + (*((*str)++) - '0');
	if (**str == '.')
		(*str)++;
	d = 0.0;
	while(ft_isdigit(**str))
		d = d * 10 + (*((*str)++) - '0');
	while (d > 1)
		d /= 10;
	d += w;
	return (d * neg);
}

void		next(char **str)
{
	while (**str == 32 || **str == 9)
		(*str)++;
}

void		comma(char **str)
{
	if (**str != ',')
	{
		ft_putstr("Scene Error\n, aprende a hacer una escena en condiciones gilipollas\n");
		exit(0);
	}	
	(*str)++;
}

void		parse_res(t_scn *data, char **str)
{
	next(str);
	data->xres = stoi(str);
	next(str);
	data->yres = stoi(str);
}


void		parse_alight(t_scn *data, char **str)
{
	data->acl = 0;

	next(str);
	data->al = stof(str);
	next(str);
	data->acl |= stoi(str) << 16;
	comma(str);
	data->acl |= stoi(str) << 8;
	comma(str);
	data->acl |= stoi(str) << 0;
}

void		parse_camera(t_scn *data, char **str)
{
	next(str);
	data->O.x = stof(str);
	comma(str);
	data->O.y = stof(str);
	comma(str);
	data->O.z = stof(str);
	next(str);
	data->nv.x = stof(str);
	comma(str);
	data->nv.y = stof(str);
	comma(str);
	data->nv.z = stof(str);
	next(str);
	data->fov = stoi(str);
}

void		parse_cylinder(t_scn *data, t_lst *lst, char **str)
{
	lst->fig.cy.color = 0;

	next(str);
	lst->fig.cy.c.x = stof(str);
	comma(str);
	lst->fig.cy.c.y = stof(str);
	comma(str);
	lst->fig.cy.c.z = stof(str);
	next(str);
	lst->fig.cy.nv.x = stof(str);
	comma(str);
	lst->fig.cy.nv.y = stof(str);
	comma(str);
	lst->fig.cy.nv.z = stof(str);
	next(str);
	lst->fig.cy.r = stof(str) / 2;
	next(str);
	lst->fig.cy.h = stof(str);
	next(str);
	lst->fig.cy.color |= stoi(str) << 16;
	comma(str);
	lst->fig.cy.color |= stoi(str) << 8;
	comma(str);
	lst->fig.cy.color |= stoi(str) << 0;
	
}

void		parse_c(t_scn *data, t_lst *lst, char **str)
{
	if (**str == 32 || **str == 9)
		parse_camera(data, str);
	else if (**str == 'y' && *((*str)++))
		parse_cylinder(data, lst, str);
}
/*
void		parse_light(t_scn *data, char *str)
{
	a
}

void		parse_sphere()
{
	a
}

void		parse_square()
{
	a
}

void		parse_s(t_scn *data, t_lst *lst, char *str)
{
	a
}

void		parse_plane(t_scn *data, t_lst *lst, char *str)
{
	a
}

void		parse_triangle(t_scn *data, t_lst *lst, char *str)
{
	a
}
*/

void	parse_elems(t_scn *data, t_lst *lst, char *str)
{
	while (*str)
	{
		if (*str == 'R' && *(str++))
			parse_res(data, &str);
		else if (*str == 'A' && *(str++))
			parse_alight(data, &str);
		else if (*str == 'c' && *(str++))
			parse_c(data, lst, &str);
		/*else if (*str == 'l')
			parse_light(data, str);
		else if (*str == 's')
			parse_s(data, lst, str);
		else if (*str == 'p')
			parse_plane(data, lst, str);
		else if (*str == 't')
			parse_triangle(data, lst, str);*/
		str++;
	}
}

void	parse_scene(t_scn *data, t_lst *lst, int ac, char **av)
{
	char	*str;
	int		fd;

	if (ac != 2)
	{
		printf("Error\n");
		exit(0);
	}
	str = (char *)malloc(sizeof(char) * (BUFSIZE + 1));
	fd = open(av[1], 0);
	str = readfile(str, fd);
	//printf("%s\n", str);

	parse_elems(data, lst, str);

	printf("%d, %d\n", data->xres, data->yres);
	printf("ambient light is %.2f, and color is %d\n", data->al, data->acl);
	printf("coords of camera origin are %.1f, %.1f, %.1f. Normalized vector coords are %.1f, %.1f, %.1f. Fov is %d\n", data->O.x, data->O.y, data->O.z, data->nv.x, data->nv.y, data->nv.z, data->fov);
	printf("cylinder c crds are %.1f, %.1f, %.1f. nv crds are %.1f, %.1f, %.1f. Radius is %.1f. Height is %.1f. Color is %d", lst->fig.cy.c.x, lst->fig.cy.c.y, lst->fig.cy.c.z, lst->fig.cy.nv.x, lst->fig.cy.nv.y, lst->fig.cy.nv.z, lst->fig.cy.r, lst->fig.cy.h, lst->fig.cy.color);
}

int main(int ac, char **av)
{
	t_scn	data;
	t_lst	lst;

	lst.next = NULL;
	parse_scene(&data, &lst, ac, av);
	return (0);
}
