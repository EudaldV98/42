/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgarcia- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/20 16:52:56 by mgarcia-          #+#    #+#             */
/*   Updated: 2019/11/21 20:46:44 by mgarcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
//# include "libft.h"

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

typedef struct	s_info
{
	size_t			idx;
	unsigned int	flags;
	int				width;
	int				precision;
}				t_info;

void			ft_putchar(char c);

int				is_digit(char c);

int				_atoi(const char **str);

int				ft_printf(const char *format, ...);

int				ft_vprintf(const char *format, va_list ap);

void			eval_flags(const char **format, t_info *data);

void			eval_width(const char **format, t_info *data, va_list ap);

void			eval_precision(const char **format, t_info *data, va_list ap);

void			eval_length(const char **format, t_info *data);

#endif
