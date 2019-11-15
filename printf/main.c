/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgarcia- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/15 16:51:01 by mgarcia-          #+#    #+#             */
/*   Updated: 2019/11/15 17:40:44 by mgarcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdarg.h>
#include "libft.h"

void		miniprintf(char *fmt, ...)
{
	va_list		ap;
	char		*p;
	char		*sval;
	int			ival;
	double		dval;

	va_start(ap, fmt);
	p = fmt;
	while (*p)
	{
		if (*p != '%')
		{
			ft_putchar(*p++);
			continue;
		}
		if (*++p == 'd')
		{
			ival = va_arg(ap, int);
			printf("%d", ival);
		}
		else if (*p == 'f')
		{
			dval = va_arg(ap, double);
			printf("%f", dval);
		}
		else if (*p == 's')
		{
			for (sval = va_arg(ap, char *); *sval; sval++)
				ft_putchar(*sval);
		}
		p++;
	}
	va_end(ap);
}

int main(int ac, char **av)
{
	char	d[] = "dani";

	miniprintf("Hola yo me llamo %s como te llamas tu\n%f", d, 235.029342);
	return (0);
}
