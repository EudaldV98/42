/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_params.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-bars <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/20 14:09:36 by tle-bars          #+#    #+#             */
/*   Updated: 2019/07/21 23:38:56 by mgarcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "functions.h"

int		check_params1(int ac, char **av)
{
	int i;

	if (ac == 1 || ac > 3)
		return (0);
	else if (ac == 2)
	{
		i = 0;
		if (av[1][i] == '+')
			i++;
		while (av[1][i] == 48)
			i++;
		while (av[1][i] && (av[1][i] >= '0' && av[1][i] <= '9'))
			i++;
		if (av[1][i] != '\0')
			return (0);
	}
	return (1);
}

int		check_params2(int ac, char **av)
{
	int i;

	if (ac == 3)
	{
		i = 0;
		if (av[1][i] == '+')
			i++;
		while (av[1][i] == 48)
			i++;
		while (av[1][i] && (av[1][i] >= '0' && av[1][i] <= '9'))
			i++;
		if (av[1][i] != '\0')
			return (0);
	}
	return (1);
}

int		check_params(int ac, char **av)
{
	if (!(check_params1(ac, av)))
		return (0);
	if (!(check_params2(ac, av)))
		return (0);
	return (1);
}
