/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vprintf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgarcia- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 16:38:23 by mgarcia-          #+#    #+#             */
/*   Updated: 2019/11/26 22:06:26 by mgarcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void			putchar_buff(char c, char *buf, t_flags *f)
{
	if (f->i < BUFFSIZE)
	{
		buf[f->i] = c;
		(f->i)++;
	}
	else
	{
		write(1, buf, BUFFSIZE);
		f->idx += BUFFSIZE;
		f->i = 0;
		buf[f->i] = c;
		(f->i)++;
	}
}

void			write_ptr(t_flags *f, va_list ap)
{
	long	*ptr;;

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

void			putstr_buff(char *s, char *buf, t_flags *f)
{
	while (*s && f->i < BUFFSIZE)
	{
		buf[f->i] = *s++;
		(f->i)++;
	}
	if (f->i == BUFFSIZE)
	{
		write(1, buf, BUFFSIZE);
		f->idx += BUFFSIZE;
		f->i = 0;
		putstr_buff(s, buf, f);
	}
}

static void		print_specifier(const char **format, char *buf, t_flags *f, va_list ap)
{
	if (**format == 'd' || **format == 'i' || **format == 'u'
			|| **format == 'o' || **format == 'x' || **format == 'X')
	{
		format_integer(**format, buf, f, ap);
	}
	else if (**format == 'f')
	{
		///float_format(f, ap);
	}
	else if (**format == 'e' || **format == 'g')
	{
		//jeje
	}
	else if (**format == 'c')
	{
		format_character((char)va_arg(ap, int), buf, f);
	}
	else if (**format == 's')
	{
		format_string(f, buf, ap);
	}
	else if (**format == 'p')
	{
		format_ptr(buf, f, ap);
	}
	else if (**format == 'n')
	{
		write_ptr(f, ap);
	}
	else if (**format)
		format_character(**format, buf, f);
	(*format)++;
}

#include <stdio.h>

int				ft_vprintf(const char *format, va_list ap)
{
	char		buf[BUFFSIZE];
	t_flags		f;

	f.i = 0;
	while (*format)
	{
		if	(*format != '%')
		{
			putchar_buff(*format++, &buf, &f);
			continue;
		}
		else
		{
			format++;
			eval_flags(&format, &f);
			eval_width(&format, &f, ap);
			eval_precision(&format, &f, ap);
			eval_length(&format, &f);
			print_specifier(&format, &buf, &f, ap);
		}
	}
	//printf("\n\n\nflags are: %d\n", f.flags);
	//printf("width is : %d\n", f.width);
	//printf("precision is : %d\n", f.precision);
	//ft_putchar('\0');
	write(1, buf, (f.i));
	return (f.idx + f.i);
}
