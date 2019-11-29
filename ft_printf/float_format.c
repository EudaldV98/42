/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   float_format.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgarcia- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/26 14:04:55 by mgarcia-          #+#    #+#             */
/*   Updated: 2019/11/29 15:56:48 by mgarcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static size_t		pwr(int base, int exp)
{
	size_t	nb;
	
	nb = 1;
	while (exp--)
		nb *= base;
	return (nb);
}

static void			add_prefix(int *i, t_float fl, char *buf, t_flags *f)
{
	if (fl.neg || f->flags & (FLAG_PLUS | FLAG_SPACE))
	{
		if (fl.neg)
			putchar_buff('-', buf, f);
		else if (f->flags & FLAG_PLUS)
			putchar_buff('+', buf, f);
		else if (f->flags & FLAG_SPACE)
			putchar_buff(' ', buf, f);
	}
}

static void			add_padding(t_float fl, char *buf, t_flags *f)
{
	int i;

	i = 0;
	while (i++ + nbrlen(fl.whole, 10) + f->precision + ((f->precision || f->flags & FLAG_HASH) ? 1 : 0 ) < f->width)
	{
		if (f->flags & FLAG_ZEROPAD)
			putchar_buff('0', buf, f);
		else
			putchar_buff(' ', buf, f);
	}
}

static void			print_float(t_float fl, char *buf, t_flags *f)
{
	int i;

	i = 0;
	if (f->width && (fl.neg || f->flags & (FLAG_PLUS | FLAG_SPACE)))
		f->width--;
	if (!(f->flags & FLAG_LEFT))
	{
		if (f->flags & FLAG_ZEROPAD)
			add_prefix(&i, fl, buf, f);
		add_padding(fl, buf, f);
	}
	if (!(f->flags & FLAG_ZEROPAD))
		add_prefix(&i, fl, buf, f);
	putnbr_buff(fl.whole, 1, buf, f);
	if (f->precision || f->flags & FLAG_HASH)
		putchar_buff('.', buf, f);
	if (nbrlen(fl.frac, 10) != f->precision)
	{
		i = 0;
		if (!fl.frac)
		{
			while (i++ < f->precision)
				putchar_buff('0', buf, f);
		}
		else
		{
			while (i++ < f->precision - nbrlen(fl.frac, 10))
				putchar_buff('0', buf, f);
			putnbr_buff(fl.frac, 1, buf, f);
		}
	}
	else
		putnbr_buff(fl.frac, 1, buf, f);
	if (f->flags & FLAG_LEFT)
		add_padding(fl, buf,f);
}

static int			valid_double(long double value, char *buf, t_flags *f)
{
	if (value != value)
	{
		putstr_buff("nan", buf, f);
		return (0);
	}
	if (value < -DBL_MAX)
	{
		putstr_buff("-inf", buf, f);
		return (0);
	}
	if (value > DBL_MAX)
	{
		putstr_buff((f->flags & FLAG_PLUS ? "+inf" : "inf"), buf, f);
		return (0);
	}
	return (1);
}

void				format_float(long double value, char *buf, t_flags *f)
{
	t_float		fl;

	f->base = 10;
	if (!valid_double(value, buf, f))
		return ;
	if (f->flags & FLAG_LEFT)
		f->flags &= ~FLAG_ZEROPAD;
	if (!(f->flags & FLAG_PRECISION))
		f->precision = DEFAULT_FLOAT_PRECISION;
	else
		f->flags &= ~FLAG_PRECISION;
	fl.neg = value < 0 ? 1 : 0;
	value = value < 0 ? -value : value;
	fl.whole = (ssize_t)value;
	fl.tmp = (value - fl.whole) * pwr(10, f->precision);
  	fl.frac = (size_t)fl.tmp;
  	fl.diff = fl.tmp - fl.frac;
	if (fl.diff > 0.5)
	{
		fl.frac++;
		if (nbrlen(fl.frac, f->base) > f->precision)
		{
			fl.frac = 0;
			fl.whole++;
		}
	}
	if (!f->precision && (fl.diff == 0.5) && (fl.whole & 1))
		fl.whole++;
	//fl.frac *= pwr(10, f->precision - nbrlen(fl.frac, 10));
	print_float(fl, buf, f);
}
