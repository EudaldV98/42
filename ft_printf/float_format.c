/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   float_format.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgarcia- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/26 14:04:55 by mgarcia-          #+#    #+#             */
/*   Updated: 2019/11/27 18:40:48 by mgarcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t		pwr(int base, int exp)
{
	size_t	nb;
	
	nb = 1;
	while (exp--)
		nb *= base;
	return (nb);
}

#include <stdio.h>

void		float_format(t_flags *f, char * buf, va_list ap)
{
	double	fl;
	size_t	whole;
	size_t 	decimal;

	if (!(f->flags & FLAG_PRECISION))
	{
		//f->flags |= FLAG_PRECISION;
		f->precision = 6;
	}
	fl = va_arg(ap, double);
	printf("cogemos %f\n", fl);
	whole = (size_t)fl;
	printf("cuya parte entera es %d\n", whole);
	fl -= whole;
	printf("fl despues de la restita %f\n", fl);
	decimal = fl * pwr(10, f->precision);
	printf("tenemos que decimal es %d\n", decimal);
	putnbr_buff(whole, 1, buf, f);
	putchar_buff('.', buf, f);
	putnbr_buff(decimal, 1, buf, f);
}
