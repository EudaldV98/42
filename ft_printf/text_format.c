/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   text_format.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgarcia- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/22 11:51:44 by mgarcia-          #+#    #+#             */
/*   Updated: 2019/11/28 15:40:59 by mgarcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int				check_null(char *s, char *buf, t_flags *f)
{
	if (!s)
	{
		putstr_buff("(null)", buf, f);
		return (1);
	}
	return (0);
}

void			format_string(t_flags *f, char *buf, va_list ap)
{
	char	*str;
	int		len;
	int		i;

	str = va_arg(ap, char *);
	if (check_null(str, buf, f))
		return ;
	len = ft_strlen(str);
	if (f->flags & FLAG_PRECISION)
		len = f->precision > len ? len : f->precision;
	if (!(f->flags & FLAG_LEFT))
	{
		i = 0;
		while (i++ < (f->width - len))
			putchar_buff(32, buf, f);
	}
	i = 0;
	while (*str && i++ < len)
		putchar_buff(*str++, buf, f);
	if (f->flags & FLAG_LEFT)
	{
		i = 0;
		while (i++ < (f->width - len))
			putchar_buff(32, buf, f);
	}
}

void			format_character(char c, char *buf, t_flags *f)
{
	if (!(f->flags & FLAG_LEFT))
	{
		while (--(f->width) > 0)
			putchar_buff(32, buf, f);
	}
	putchar_buff(c, buf, f);
	if (f->flags & FLAG_LEFT)
	{
		while (--(f->width) > 0)
			putchar_buff(32, buf, f);
	}
}

void			write_ptr(t_flags *f, va_list ap)
{
	int		*ptr;

	ptr = pointer_cast(f, ap);
	*ptr = f->idx + f->i;
}

void			format_address(char *buf, t_flags *f, va_list ap)
{
	if (f->flags & FLAG_PRECISION || f->flags & FLAG_LEFT)
		f->flags &= ~FLAG_ZEROPAD;
	f->flags &= ~(FLAG_PLUS | FLAG_SPACE);
	f->flags |= FLAG_HASH;
	f->base = 16;
	format_number(va_arg(ap, size_t), 0, buf, f);
}
