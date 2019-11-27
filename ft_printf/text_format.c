/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   text_format.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgarcia- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/22 11:51:44 by mgarcia-          #+#    #+#             */
/*   Updated: 2019/11/27 16:44:40 by mgarcia-         ###   ########.fr       */
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
	long	*ptr;

	if (f->flags & (FLAG_LONG_LONG | FLAG_LONG))
		ptr = (long *)va_arg(ap, size_t);
	else if (f->flags & FLAG_SHORT)
		ptr = (short *)va_arg(ap, size_t);
	else if (f->flags & FLAG_CHAR)
		ptr = (signed char *)va_arg(ap, size_t);
	else
		ptr = (int *)va_arg(ap, size_t);
	*ptr = f->idx + f->i;
}
