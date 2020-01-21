/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgarcia- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 11:31:29 by mgarcia-          #+#    #+#             */
/*   Updated: 2020/01/21 11:54:01 by mgarcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"
#include <stdio.h>

void		parse_scene(t_scn *data, t_lst *lst, int ac, char **av)
{
	if (ac != 2)
	{
		printf("Error\n");
		exit(0);
	}

}

int main(int ac, char **av)
{
	t_scn	data;
	t_lst	lst;

	parse_scene(&data, &lst, ac, av);
	return (0);
}
