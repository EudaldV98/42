/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgarcia- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/20 16:52:56 by mgarcia-          #+#    #+#             */
/*   Updated: 2019/11/24 19:05:38 by mgarcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H


# include <stdarg.h>
# include <unistd.h>
#include <stdlib.h>

#include <stdio.h>

# include "libft.h"

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

typedef struct	s_flags
{
	size_t			idx;
	unsigned int	flags;
	int				width;
	int				precision;
}				t_flags;

void			_putchar(char c, t_flags *f);

int				_atoi(const char **str);

int				ft_printf(const char *format, ...);

int				ft_vprintf(const char *format, va_list ap);

void			eval_flags(const char **format, t_flags *f);

void			eval_width(const char **format, t_flags *f, va_list ap);

void			eval_precision(const char **format, t_flags *f, va_list ap);

void			eval_length(const char **format, t_flags *f);

void			format_number(char *nb, int negative, char fmt, t_flags *f);

void			format_string(t_flags *f, va_list ap);

void			format_character(t_flags *f, va_list ap);

char			*itoa_base(size_t nbr, int neg, int base, t_flags *f);

void			format_integer(char fmt, t_flags *f, va_list ap);

#endif
