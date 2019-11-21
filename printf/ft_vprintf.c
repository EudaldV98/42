/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vprintf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgarcia- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 16:38:23 by mgarcia-          #+#    #+#             */
/*   Updated: 2019/11/21 20:57:59 by mgarcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		is_digit(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int		_atoi(const char **str)
{
	int i;
   
	i = 0;
	while (is_digit(**str))
    	i = i * 10 + (*((*str)++) - '0');
  return i;
}

void	print_specifier(char **format, t_info *data)
{
	//TO_DO
}

#include <stdio.h>

int	ft_vprintf(const char *format, va_list ap)
{
	t_info	data;

	while (*format)
	{
		if	(*format != '%')
		{
			ft_putchar(*format++);
			data.idx++;
			continue;
		}
		else
		{
			format++;
			eval_flags(&format, &data);
			eval_width(&format, &data, ap);
			eval_precision(&format, &data, ap);
			eval_length(&format, &data);
			//print_specifier(&format, &data);
		}
	}
	printf("\n\nflags are: %d\n", data.flags);
	printf("width is : %d\n", data.width);
	printf("precision is : %d\n", data.precision);
	ft_putchar('\0');
	return (data.idx);
}
