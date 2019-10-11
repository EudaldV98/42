/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgarcia- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/23 10:29:28 by mgarcia-          #+#    #+#             */
/*   Updated: 2019/07/24 22:57:28 by mgarcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

typedef struct			s_point
{
	unsigned int	x;
	unsigned int	y;
}						t_info;

typedef struct			s_map_info
{
	unsigned int	lns;
	unsigned int	col;
	char			empty;
	char			full;
	char			obstacle;
}						t_map_info;

typedef struct			s_square
{
	unsigned int		x;
	unsigned int		y;
	unsigned int		size;
}						t_square;

#endif
