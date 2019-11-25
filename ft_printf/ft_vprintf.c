/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vprintf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgarcia- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 16:38:23 by mgarcia-          #+#    #+#             */
/*   Updated: 2019/11/25 10:45:07 by mgarcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_specifier(const char **format, t_flags *f, va_list ap)
{
	if (**format == 'd' || **format == 'i' || **format == 'u' || **format == 'x' || **format == 'X')
	{
		format_integer(**format, f, ap);
	}
	else if (**format == 'f')
	{
		//a pastar
	}
	else if (**format == 'e' || **format == 'g')
	{
		//jeje
	}
	else if (**format == 'c')
	{
		format_character(f, ap);
	}
	else if (**format == 's')
	{
		format_string(f, ap);
	}
	else if (**format == 'p')
	{
		format_ptr(f, ap);
	}
	else if (**format)
		_putchar(**format, f);
	(*format)++;
}

#include <stdio.h>

int	ft_vprintf(const char *format, va_list ap)
{
	t_flags		f;

	while (*format)
	{
		if	(*format != '%')
		{
			_putchar(*format++, &f);
			continue;
		}
		else
		{
			format++;
			eval_flags(&format, &f);
			eval_width(&format, &f, ap);
			eval_precision(&format, &f, ap);
			eval_length(&format, &f);
			print_specifier(&format, &f, ap);
		}
	}
	//printf("\n\n\nflags are: %d\n", f.flags);
	//printf("width is : %d\n", f.width);
	//printf("precision is : %d\n", f.precision);
	//ft_putchar('\0');
	return (f.idx);
}
