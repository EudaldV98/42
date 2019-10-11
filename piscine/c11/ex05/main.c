/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgarcia- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/22 16:01:02 by mgarcia-          #+#    #+#             */
/*   Updated: 2019/07/22 18:11:18 by mgarcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "functions.h"

static t_op_ptr		g_tab[] =
{
	{"+", &addition},
	{"-", &substraction},
	{"*", &multiplication},
	{"/", &division},
	{"%", &modulo},
	{0, 0}
};

void		do_op(char *sign, char *nb1, char *nb2)
{
	int		i;
	int		a;
	int		b;

	a = ft_atoi(nb1);
	b = ft_atoi(nb2);
	i = 0;
	while (g_tab[i].op != 0)
	{
		if (ft_strcmp(g_tab[i].op, sign) == 0)
		{
			(g_tab[i].ptr)(a, b);
			return ;
		}
		i++;
	}
	ft_putstr("0\n");
}

int			main(int ac, char **av)
{
	if (ac != 4)
		return (0);
	else
		do_op(av[2], av[1], av[3]);
	return (0);
}
