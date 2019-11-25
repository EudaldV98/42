/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   integer_format.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgarcia- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/22 15:41:58 by mgarcia-          #+#    #+#             */
/*   Updated: 2019/11/25 13:19:57 by mgarcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void			format_ptr(t_flags *f, va_list ap)
{
	char		*s;

	f->flags |= FLAG_HASH;
	s = itoa_base(va_arg(ap, size_t), 0, 16, f);
	format_number(s, 0, 'x', f);
}

ssize_t			signed_cast(t_flags *f, va_list ap)
{
	if (f->flags & (FLAG_LONG_LONG | FLAG_LONG))
		return (va_arg(ap, ssize_t));
	if (f->flags & FLAG_CHAR)
		return ((signed char)va_arg(ap, int));
	if (f->flags & FLAG_SHORT)
		return ((short)va_arg(ap, int));
	return (va_arg(ap, int));
}

size_t			unsigned_cast(t_flags *f, va_list ap)
{
	if (f->flags & (FLAG_LONG_LONG | FLAG_LONG))
		return (va_arg(ap, size_t));
	if (f->flags & FLAG_CHAR)
		return ((unsigned char)va_arg(ap, int));
	if (f->flags & FLAG_SHORT)
		return ((unsigned short)va_arg(ap, int));
	return ((unsigned int)va_arg(ap, int));
}

static void		add_prefix(int len, int negative, t_flags *f)
{
	if (negative || f->flags & (FLAG_PLUS | FLAG_SPACE))
	{
		if (negative)
			_putchar('-', f);
		else if (f->flags & FLAG_PLUS)
			_putchar('+', f);
		else if (f->flags & FLAG_SPACE)
			_putchar(' ', f);
	}
	else if (f->flags & FLAG_HASH)
	{
		_putchar('0', f);
		if (f->flags & FLAG_UPPERCASE)
			_putchar('X', f);
		else
			_putchar('x', f);
	}
}

static void		add_padding(int len, t_flags *f)
{
	while (len++ < f->width)
	{
		if (f->flags & FLAG_ZEROPAD)
			_putchar('0', f);
		else
			_putchar(32, f);
	}
}

void		format_number(char *nb, int negative, int base, t_flags *f)
{
	int		len;

	len = ft_strlen(nb);
	if (f->width && (negative || f->flags & (FLAG_PLUS | FLAG_SPACE)))
		f->width--;
	if (f->width && (f->flags & FLAG_HASH) && base == 16)
		f->width -= (f->width == 1) ? 1 : 2;
	if (!(f->flags & FLAG_LEFT))
	{
		if (f->flags & FLAG_ZEROPAD)
			add_prefix(len, negative, f);
		add_padding(len, f);
	}
	if (!(f->flags & FLAG_ZEROPAD))
		add_prefix(len, negative, f);
	while (*nb)
		_putchar(*nb++, f);
	if (f->flags & FLAG_LEFT)
		add_padding(len, f);
}

void			format_integer(char fmt, t_flags *f, va_list ap)
{
	ssize_t		val;
	size_t		uval;
	char		*nb;
	int			base;

	if (fmt == 'x' || fmt == 'X')
		base = 16;
	else
		base = 10;
	if (fmt == 'X')
		f->flags |= FLAG_UPPERCASE;
	if (f->flags & FLAG_PRECISION || f->flags & FLAG_LEFT)
		f->flags &= ~FLAG_ZEROPAD;
	if (fmt == 'i' || fmt == 'd')
	{
		f->flags &= ~FLAG_HASH;
	
		val = signed_cast(f, ap);
		nb = itoa_base((val > 0 ? val : -val), val < 0, base, f);
		format_number(nb, val < 0, base, f);
	}
	else
	{
		f->flags &= ~(FLAG_PLUS | FLAG_SPACE);
		
		uval = unsigned_cast(f, ap);
		nb = itoa_base(uval, 0, base, f);
		format_number(nb, 0, base, f);
	}
}
