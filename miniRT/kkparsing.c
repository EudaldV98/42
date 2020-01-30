/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgarcia- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 11:31:29 by mgarcia-          #+#    #+#             */
/*   Updated: 2020/01/30 09:56:29 by mgarcia-         ###   ########.fr       */
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

void		ft_addnewlst_back(t_lst **alst, t_lst** begin)
{
	t_lst	*elem;
	t_lst	*list;

	list = *alst;
	if (!(elem = malloc(sizeof(t_lst))))
	{
		printf("goorbai\n");
		exit (1);
	}
	elem->next = NULL;
	if (list)
	{
		while (list->next)
			list = list->next;
		list->next = elem;
	}
	else
	{
		*alst = elem;
		*begin = elem;
	}
}

void		next(char **str)
{
	while (**str == 32 || (**str >= 9 && **str <= 13))
		(*str)++;
}

void		comma(char **str)
{
	if (**str != ',')
	{
		ft_putstr("Scene Error\naprende a hacer una escena en condiciones gilipollas\n");
		printf("\nCuando ha hecho pum *str era %s\n", *str);
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

void		parse_cylinder(t_scn *data, t_lst **elem, t_lst **begin, char **str)
{
	t_lst	*lst;
	
	ft_addnewlst_back(elem, begin);
	lst = *elem;
	while (lst->next)
		lst = lst->next;
	lst->flag = 0;
	lst->flag |= CY;
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

void		parse_light(t_scn **data, char **str)
{
	t_light	*elem;
	t_light	*list;
	t_light *begin;

	begin = (*data)->l;
	list = (*data)->l;
	if (!(elem = malloc(sizeof(t_light))))
	{
		printf("goorbai\n");
		exit (1);
	}
	elem->next = NULL;
	if (list)
	{
		while (list->next)
			list = list->next;
		list->next = elem;
	}
	else
	{
		list = elem;
		begin = elem;
	}
	
	list->color = 0;
	next(str);
	list->o.x = stof(str);
	comma(str);
	list->o.y = stof(str);
	comma(str);
	list->o.z = stof(str);
	next(str);
	list->br = stof(str);
	next(str);
	list->color |= stoi(str) << 16;
	comma(str);
	list->color |= stoi(str) << 8;
	comma(str);
	list->color |= stoi(str) << 0;

	(*data)->l = begin;
}

void		parse_sphere(t_scn *data, t_lst **elem, t_lst **begin, char **str)
{
	t_lst	*lst;
	
	ft_addnewlst_back(elem, begin);
	lst = *elem;
	while (lst->next)
		lst = lst->next;
	lst->flag = 0;
	lst->flag |= SP;
	lst->fig.sp.color = 0;
	next(str);
	lst->fig.sp.c.x = stof(str);
	comma(str);
	lst->fig.sp.c.y = stof(str);
	comma(str);
	lst->fig.sp.c.z = stof(str);
	next(str);
	lst->fig.sp.r = stof(str) / 2;
	next(str);
	lst->fig.sp.color |= stoi(str) << 16;
	comma(str);
	lst->fig.sp.color |= stoi(str) << 8;
	comma(str);
	lst->fig.sp.color |= stoi(str) << 0;

}

void		parse_square(t_scn *data, t_lst **elem, t_lst **begin, char **str)
{
	t_lst	*lst;
	
	ft_addnewlst_back(elem, begin);
	lst = *elem;
	while (lst->next)
		lst = lst->next;
	lst->fig.sq.color = 0;
	lst->flag = 0;
	lst->flag |= SQ;
	next(str);
	lst->fig.sq.c.x = stof(str);
	comma(str);
	lst->fig.sq.c.y = stof(str);
	comma(str);
	lst->fig.sq.c.z = stof(str);
	next(str);
	lst->fig.sq.nv.x = stof(str);
	comma(str);
	lst->fig.sq.nv.y = stof(str);
	comma(str);
	lst->fig.sq.nv.z = stof(str);
	next(str);
	lst->fig.sq.size = stof(str);
	next(str);
	lst->fig.sq.color |= stoi(str) << 16;
	comma(str);
	lst->fig.sq.color |= stoi(str) << 8;
	comma(str);
	lst->fig.sq.color |= stoi(str) << 0;
}

void		parse_plane(t_scn *data, t_lst **elem, t_lst **begin, char **str)
{
	t_lst	*lst;
	
	ft_addnewlst_back(elem, begin);
	lst = *elem;
	while (lst->next)
		lst = lst->next;
	lst->fig.pl.color = 0;
	lst->flag = 0;
	lst->flag |= PL;
	next(str);
	lst->fig.pl.p.x = stof(str);
	comma(str);
	lst->fig.pl.p.y = stof(str);
	comma(str);
	lst->fig.pl.p.z = stof(str);
	next(str);
	lst->fig.pl.nv.x = stof(str);
	comma(str);
	lst->fig.pl.nv.y = stof(str);
	comma(str);
	lst->fig.pl.nv.z = stof(str);
	next(str);
	lst->fig.pl.color |= stoi(str) << 16;
	comma(str);
	lst->fig.pl.color |= stoi(str) << 8;
	comma(str);
	lst->fig.pl.color |= stoi(str) << 0;
}
/*
void		parse_triangle(t_scn *data, t_lst *lst, char *str)
{
	a
}
*/

void	parse_elems(t_scn *data, t_lst **lst, t_lst **begin, char *str)
{
	while (*str)
	{
		if (*str == 'R' && *(str++))
			parse_res(data, &str);
		else if (*str == 'A' && *(str++))
			parse_alight(data, &str);
		else if (*str == 'c' && (*(str + 1) == 32 || *(str + 1) == 9) && *(str++))
			parse_camera(data, &str);
		else if (*str == 'c' && *(str + 1) == 'y' && *(str++) && *(str++))
			parse_cylinder(data, lst, begin, &str);
		else if (*str == 'l' && (*(str + 1) == 32 || *(str + 1) == 9) && *(str++))
			parse_light(&data, &str);
		else if (*str == 's' && *(str + 1) == 'p' && *(str++) && *(str++))
			parse_sphere(data, lst, begin, &str);
		else if (*str == 's' && *(str + 1) == 'q' && *(str++) && *(str++))
			parse_square(data, lst, begin, &str);
		else if (*str == 'p' && *(str + 1) == 'l' && *(str++) && *(str++))
		{
			printf("Holaktalsoy un plano jajajajaj\n");
			parse_plane(data, lst, begin, &str);
		}
		//else if (*str == 't')
		//	parse_triangle(data, lst, str);
		str++;
	}
}

void	parse_scene(t_scn *data, t_lst *lst, int ac, char **av)
{
	t_lst	*begin;
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

	parse_elems(data, &lst, &begin, str);

	printf("%d, %d\n", data->xres, data->yres);
	printf("ambient light is %.2f, and color is %d\n", data->al, data->acl);
	printf("coords of camera origin are %.1f, %.1f, %.1f. Normalized vector coords are %.1f, %.1f, %.1f. Fov is %d\n", data->O.x, data->O.y, data->O.z, data->nv.x, data->nv.y, data->nv.z, data->fov);
	
	// AQUI PETAAAA

	//data->l = data->begin;

	printf("light crds are %.1f, %.1f, %.1f, bright is %.1f, and color is %d\n", data->l->o.x, data->l->o.y, data->l->o.z, data->l->br, data->l->color);
	
	//					^
	//	SISI AHI MISMO ^|^
	//					|

	
	lst = begin;
	while (lst->next)
		if (lst->flag & PL)
			break;
		else
			lst = lst->next;
	
	printf("plane crds are %.1f, %.1f, %.1f, nv is %.1f, %.1f, %.1f, and color is %d\n",
			lst->fig.pl.p.x, lst->fig.pl.p.y, lst->fig.pl.p.z, lst->fig.pl.nv.x, lst->fig.pl.nv.y, lst->fig.pl.nv.z, lst->fig.pl.color);



	lst = begin;
	while (lst->next)
		if (lst->flag & SP)
			break;
		else
			lst = lst->next;

	printf("sphere crds are %.1f, %.1f, %.1f, radius is %.5f and color is %d\n", lst->fig.sp.c.x,
			lst->fig.sp.c.y, lst->fig.sp.c.z, lst->fig.sp.r, lst->fig.sp.color);

	lst = begin;
	while (lst->next)
		if (lst->flag & SQ)
			break;
		else
			lst = lst->next;

	printf("square crds are %.1f, %.1f, %.1f, nv is %.1f, %.1f, %.1f, size is %.2f and color is %d\n", lst->fig.sq.c.x, lst->fig.sq.c.y, lst->fig.sq.c.z, lst->fig.sq.nv.x, lst->fig.sq.nv.y, lst->fig.sq.nv.z, lst->fig.sq.size, lst->fig.sq.color);



	lst = begin;
	while (lst->next)
		if (lst->flag & CY)
			break;
		else
			lst = lst->next;

	printf("cylinder c crds are %.1f, %.1f, %.1f. nv crds are %.1f, %.1f, %.1f. Radius is %.1f. Height is %.1f. Color is %d", lst->fig.cy.c.x, lst->fig.cy.c.y, lst->fig.cy.c.z, lst->fig.cy.nv.x, lst->fig.cy.nv.y, lst->fig.cy.nv.z, lst->fig.cy.r, lst->fig.cy.h, lst->fig.cy.color);
	printf("");


}

int main(int ac, char **av)
{
	t_scn	data;
	t_lst	*lst;

	lst = NULL;
	data.l = NULL;
	parse_scene(&data, lst, ac, av);
	return (0);
}
