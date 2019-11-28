/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   float_format.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgarcia- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/26 14:04:55 by mgarcia-          #+#    #+#             */
/*   Updated: 2019/11/28 14:32:33 by mgarcia-         ###   ########.fr       */
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

static void			print_float(t_float fl, char *buf, t_flags *f)
{
	int i;

	i = 0;
	if (!(f->flags & FLAG_LEFT))
	{
		while (i++ + nbrlen(fl.whole, 10) + f->precision + 1 < f->width)
			putchar_buff(' ', buf, f);
	}
	if (fl.neg)
		putchar_buff('-', buf, f);
	putnbr_buff(fl.whole, 1, buf, f);
	putchar_buff('.', buf, f);
	putnbr_buff(fl.frac, 1, buf, f);
	if (f->flags & FLAG_LEFT)
	{
		while (i++ + nbrlen(fl.whole, 10) + f->precision + 1 < f->width)
			putchar_buff(' ', buf, f);
	}
}

void				format_float(double value, char *buf, t_flags *f)
{
	t_float		fl;

	f->base = 10;
	if (!(f->flags & FLAG_PRECISION))
		f->precision = DEFAULT_FLOAT_PRECISION;
	else
		f->flags &= ~FLAG_PRECISION;
	fl.neg = value < 0 ? 1 : 0;
	value = value < 0 ? -value : value;
	fl.whole = (int)value;
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
	print_float(fl, buf, f);
}
