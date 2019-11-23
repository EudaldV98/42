/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   integer_format.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgarcia- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/22 15:41:58 by mgarcia-          #+#    #+#             */
/*   Updated: 2019/11/23 18:19:36 by mgarcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		add_prefix(int len, int negative, t_flags *f)
{

	if (f->flags & FLAG_PLUS)
		_putchar('+', f);
	else if (f->flags & FLAG_SPACE)
		_putchar(' ', f);
}

static void		add_padding(int len, t_flags *f)
{
	while (len++ < f->width)
	{
		if (f->flags & FLAG_ZEROPAD)
			_putchar(0, f);
		else
			_putchar(32, f);
	}
}

static void		format_number(char *nb, int negative, char fmt, t_flags *f)
{
	int		len;

	len = ft_strlen(nb);
	if (f->width && (negative || f->flags & (FLAG_PLUS | FLAG_SPACE)))
		f->width--;
	if (f->width && (f->flags & FLAG_HASH) && (fmt == 'x' || fmt == 'X'))
		f->width -= (f->width == 1) ? 1 : 2;
	if (!(f->flags & FLAG_LEFT))
	{
		if (!negative && f->flags & (FLAG_PLUS | FLAG_SPACE) && f->flags & FLAG_ZEROPAD)
			add_prefix(len, negative, f);
		add_padding(len, f);
	}
	if (!negative && f->flags & (FLAG_PLUS | FLAG_SPACE) && !(f->flags & FLAG_ZEROPAD))
		add_prefix(len, negative, f);
	while (*nb)
		_putchar(*nb++, f);
	if (f->flags & FLAG_LEFT)
		add_padding(len, f);
}

void		format_integer(char fmt, t_flags *f, va_list ap)
{
	ssize_t		value;
	char		*nb;
	int			base;

	if (fmt == 'x' || fmt == 'X')
	{
		base = 16;
		if (fmt == 'X')
			f->flags |= FLAG_UPPERCASE;
	}
	else
		base = 10;
	if (f->flags & FLAG_PRECISION)
		f->flags &= ~FLAG_ZEROPAD;
	if (fmt == 'i' || fmt == 'd')
	{
		f->flags &= ~FLAG_HASH;
		if (f->flags & (FLAG_LONG_LONG | FLAG_LONG))
		{
			value = va_arg(ap, ssize_t);
			nb = _itoa_base((size_t)(value > 0 ? value : -value), value < 0, base, f);
		}
		else
		{
			value = va_arg(ap, int);
			nb = _itoa_base((size_t)(value > 0 ? value : -value), value < 0, base, f);
		}
		format_number(nb, value < 0, fmt, f);
	}
	else
	{
		f->flags &= ~(FLAG_PLUS | FLAG_SPACE);
		if (f->flags & (FLAG_LONG_LONG | FLAG_LONG))
			nb = _itoa_base(va_arg(ap, size_t), 0, base, f);
		else
			nb = _itoa_base((size_t)va_arg(ap, int), 0, base, f);
		format_number(nb, value < 0, fmt, f);
	}
}
