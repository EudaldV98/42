/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgarcia- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/13 14:43:46 by mgarcia-          #+#    #+#             */
/*   Updated: 2019/07/16 20:57:01 by mgarcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "functions.h"

static int		check_map(int argc, char **argv)
{
	int i;

	if (argc != 2)
		return (0);
	if (ft_strlen(argv[1]) != 31)
		return (0);
	i = 1;
	while (i < 31)
	{
		if (argv[1][i] != 32)
			return (0);
		i += 2;
	}
	i = 0;
	while (i < 31)
	{
		if (argv[1][i] < '0' || argv[1][i] > '4')
			return (0);
		i += 2;
	}
	return (1);
}

int				main(int argc, char **argv)
{
	t_pov	pov;
	int		**tab;

	if (!check_map(argc, argv))
	{
		display_error();
		return (0);
	}
	get_params(argv, &pov);
	if (!(tab = tab_allocate()))
	{
		display_error();
		return (0);
	}
	algorithm(&pov, tab);
	print_solution(tab);
	free(tab);
	return (0);
}
