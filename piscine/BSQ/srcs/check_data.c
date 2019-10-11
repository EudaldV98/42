/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_data.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgarcia- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/23 11:46:52 by mgarcia-          #+#    #+#             */
/*   Updated: 2019/07/25 13:02:54 by mgarcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

int				set_map_info(char *str, t_map_info *code, unsigned int i)
{
	char	*nb;

	code->full = str[--i];
	code->obstacle = str[--i];
	code->empty = str[--i];
	nb = ft_strndup(str, i);
	return (ft_atoi(nb));
}

static int		check_string(char *str, t_map_info *code, unsigned int x)
{
	unsigned int	y;

	y = 0;
	code->col = 0;
	while (*str)
	{
		x = 0;
		while (*str == code->empty || *str == code->obstacle)
		{
			str++;
			x++;
		}
		if (*str != '\n')
			return (0);
		if (code->col == 0)
			code->col = x;
		else if (code->col != 0 && x != code->col)
			return (0);
		str++;
		y++;
	}
	if (y != code->lns)
		return (0);
	if (x == 0)
		return (0);
	return (1);
}

int				check_data(char *str, t_map_info *code)
{
	unsigned int	x;
	unsigned int	i;

	x = 0;
	i = 0;
	if (!str || !*str)
		return (0);
	if (*str < '0' || *str > '9')
		return (0);
	while (str[i] != '\n')
		i++;
	if (i < 4)
		return (0);
	code->lns = set_map_info(str, code, i);
	while (*str >= '0' && *str <= '9')
		str++;
	i = 0;
	while (*str++ != '\n')
		i++;
	if (i > 3)
		return (0);
	if (!(check_string(str, code, x)))
		return (0);
	return (1);
}
