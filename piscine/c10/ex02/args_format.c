/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_format.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgarcia- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/23 18:41:35 by mgarcia-          #+#    #+#             */
/*   Updated: 2019/07/24 12:32:07 by mgarcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

void		ft_putstr(char *str)
{
	while (*str)
		write(1, str++, 1);
}

void		args_format(char *name, char *str, int valid, int bol)
{
	if (bol == 1)
		ft_putstr(str);
	else
	{
		if (valid > 1)
			ft_putstr("\n");
		ft_putstr("==> ");
		ft_putstr(name);
		ft_putstr(" <==\n");
		ft_putstr(str);
	}
}
