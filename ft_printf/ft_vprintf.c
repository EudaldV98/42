/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vprintf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgarcia- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 16:38:23 by mgarcia-          #+#    #+#             */
/*   Updated: 2019/11/29 13:08:47 by mgarcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		print_specifier(const char **format, char *buf, t_flags *f,
																	va_list ap)
{
	if (**format == 'd' || **format == 'i' || **format == 'u'
			|| **format == 'o' || **format == 'x' || **format == 'X')
		format_integer(**format, buf, f, ap);
	else if (**format == 'f')
		format_float(float_cast(f, ap), buf, f);
	else if (**format == 'c')
		format_character((char)va_arg(ap, int), buf, f);
	else if (**format == 's')
		format_string(f, buf, ap);
	else if (**format == 'p')
		format_address(buf, f, ap);
	else if (**format == 'n')
		write_ptr(f, ap);
	else if (**format)
		format_character(**format, buf, f);
	(*format)++;
}

int				ft_vprintf(const char *format, va_list ap)
{
	char		buf[BUFFSIZE];
	t_flags		f;

	f.i = 0;
	f.idx = 0;
	while (*format)
	{
		if (*format != '%')
		{
			putchar_buff(*format++, buf, &f);
			continue;
		}
		else
			format++;
		eval_flags(&format, &f);
		eval_width(&format, &f, ap);
		eval_precision(&format, &f, ap);
		eval_length(&format, &f);
		print_specifier(&format, buf, &f, ap);
	}
	write(1, buf, (f.i));
	return (f.idx + f.i);
}
