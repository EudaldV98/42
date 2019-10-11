/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgarcia- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/23 10:37:58 by mgarcia-          #+#    #+#             */
/*   Updated: 2019/07/24 23:19:12 by mgarcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

void	solve_map(char *av, int bol)
{
	unsigned int	**tab;
	char			*str;
	t_map_info		code;
	t_square		sol;
	unsigned int	to_skip;

	if (!(str = read_file(av, bol)))
	{
		write(2, "map error\n", 10);
		return ;
	}
	if (check_data(str, &code))
	{
		tab = map_creator(str, &code, &to_skip);
		solve(tab, &code, &sol);
		free_tab(tab, code.lns);
		print_bsq(str + to_skip, &code, &sol);
		write(1, (str + to_skip), ft_strlen(str + to_skip));
	}
	else
		write(2, "map error\n", 10);
	free(str);
}

int		main(int ac, char **av)
{
	int	i;

	i = 1;
	if (ac > 1)
	{
		while (i < ac)
		{
			solve_map(av[i++], 1);
			if (i < ac)
				ft_putchar('\n');
		}
	}
	else
		solve_map(av[0], 0);
	return (0);
}
