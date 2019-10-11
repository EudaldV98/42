/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgarcia- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/20 22:23:46 by mgarcia-          #+#    #+#             */
/*   Updated: 2019/07/21 23:31:42 by mgarcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "functions.h"

int		main(int ac, char **av)
{
	char	*dict;
	char	*nbr;
	int		i;

	if (!(check_params(ac, av)))
	{
		display_error();
		return (0);
	}
	if (!(dict = read_dict(ac, av)))
	{
		display_dict_error();
		return (0);
	}
	if (!(check_dictionary(dict)))
	{
		display_dict_error();
		return (0);
	}
	dict = dict_cleaner(dict);
	i = ((ac == 2) ? 1 : 2);
	write_number(av[i], dict);
	free(dict);
	return (0);
}
