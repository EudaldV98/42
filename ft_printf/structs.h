/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgarcia- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/27 15:06:15 by mgarcia-          #+#    #+#             */
/*   Updated: 2019/11/27 16:28:23 by mgarcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

# define FLAG_ZEROPAD   (1U << 0U)
# define FLAG_LEFT      (1U << 1U)
# define FLAG_PLUS      (1U << 2U)
# define FLAG_SPACE     (1U << 3U)
# define FLAG_HASH      (1U << 4U)
# define FLAG_UPPERCASE (1U << 5U)
# define FLAG_CHAR      (1U << 6U)
# define FLAG_SHORT     (1U << 7U)
# define FLAG_LONG      (1U << 8U)
# define FLAG_LONG_LONG (1U << 9U)
# define FLAG_PRECISION (1U << 10U)
# define FLAG_ADAPT_EXP (1U << 11U)

typedef struct		s_flags
{
	unsigned int	i;
	size_t			idx;
	int				base;
	unsigned int	flags;
	int				width;
	int				precision;
}					t_flags;

#endif
