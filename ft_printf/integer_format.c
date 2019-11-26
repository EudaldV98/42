/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   integer_format.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgarcia- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/22 15:41:58 by mgarcia-          #+#    #+#             */
/*   Updated: 2019/11/26 21:18:55 by mgarcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void			format_ptr(char *buf, t_flags *f, va_list ap)
{
	char		*s;

	f->flags |= FLAG_HASH;
	s = itoa_base(va_arg(ap, size_t), 0, 16, f);
	format_number(s, buf, 0, 16, f);
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

static void		add_prefix(int len, int negative, int base, char *buf, t_flags *f)
{
	if (negative || f->flags & (FLAG_PLUS | FLAG_SPACE))
	{
		if (negative)
			putchar_buff('-', buf, f);
		else if (f->flags & FLAG_PLUS)
			putchar_buff('+', buf, f);
		else if (f->flags & FLAG_SPACE)
			putchar_buff(' ', buf, f);
	}
	else if (f->flags & FLAG_HASH)
	{
		putchar_buff('0', buf, f);
		if (f->flags & FLAG_UPPERCASE)
			putchar_buff('X', buf, f);
		else if (base == 16)
			putchar_buff('x', buf, f);
	}
}

static void		add_padding(int len, char *buf, t_flags *f)
{
	while (len++ < f->width)
	{
		if (f->flags & FLAG_ZEROPAD)
			putchar_buff('0', buf, f);
		else
			putchar_buff(32, buf, f);
	}
}

void		format_number(char *nb, char *buf, int negative, int base, t_flags *f)
{
	int		len;

	len = ft_strlen(nb);
	if (f->width && (negative || f->flags & (FLAG_PLUS | FLAG_SPACE)))
		f->width--;
	if (f->width && (f->flags & FLAG_HASH) && (base == 16 || base == 8))
	{
		if (base == 16)
			f->width -= (f->width == 1) ? 1 : 2;
		else if (base == 8)
			f->width -= 1;
	}
	if (!(f->flags & FLAG_LEFT))
	{
		if (f->flags & FLAG_ZEROPAD)
			add_prefix(len, negative, base, buf, f);
		add_padding(len, buf, f);
	}
	if (!(f->flags & FLAG_ZEROPAD))
		add_prefix(len, negative, base, buf, f);
	putstr_buff(nb, buf, f);
	if (f->flags & FLAG_LEFT)
		add_padding(len, buf, f);
}

void			format_integer(char fmt, char *buf, t_flags *f, va_list ap)
{
	ssize_t		val;
	size_t		uval;
	char		*nb;
	int			base;

	if (fmt == 'x' || fmt == 'X')
		base = 16;
	else if (fmt == 'o')
		base = 8;
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
		format_number(nb, buf, val < 0, base, f);
	}
	else
	{
		f->flags &= ~(FLAG_PLUS | FLAG_SPACE);
		
		uval = unsigned_cast(f, ap);
		nb = itoa_base(uval, 0, base, f);
		format_number(nb, buf, 0, base, f);
	}
}
