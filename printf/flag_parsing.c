/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_parsing.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgarcia- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 17:32:11 by mgarcia-          #+#    #+#             */
/*   Updated: 2019/11/21 21:01:29 by mgarcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	eval_flags(const char **format, t_info *data)
{
	data->flags = 0U;

	while (**format == '#' || **format == '+' || **format == '-' || **format == ' ' || **format == '0')
	{
		if (**format == '#')
			data->flags |= FLAG_HASH;
		else if (**format == '+')
			data->flags |= FLAG_PLUS;
		else if (**format == '-')
			data->flags |= FLAG_LEFT;
		else if (**format == ' ')
			data->flags |= FLAG_SPACE;
		else if (**format == '0')
			data->flags |= FLAG_ZEROPAD;
		(*format)++;
	}
}

void	eval_width(const char **format, t_info *data, va_list ap)
{
	data->width = 0U;

	if (is_digit(**format))
		data->width = _atoi(format);
	else if (**format == '*')
	{
		data->width = va_arg(ap, int);
		if (data->width < 0)
		{
			data->width = -(data->width);
			data->flags |= FLAG_LEFT;
		}
		(*format)++;
	}
}

void	eval_precision(const char **format, t_info *data, va_list ap)
{
	data->precision = 0U;

	if (**format == '.')
	{
		data->flags |= FLAG_PRECISION;
		(*format)++;
		if (is_digit(**format))
			data->precision = _atoi(format);
		else if (**format == '*')
		{
			data->precision = va_arg(ap, int);
			if (data->precision < 0)
				data->precision = 0;
			(*format)++;
		}
	}
}

void	eval_length(const char **format, t_info *data)
{
	if (**format == 'l')
	{
		data->flags |= FLAG_LONG;
		(*format)++;
		if (**format == 'l')
		{
			data->flags |= FLAG_LONG_LONG;
			(*format)++;
		}
	}
	else if (**format == 'h')
	{
		data->flags |= FLAG_SHORT;
		(*format)++;
		if (**format == 'h')
		{
			data->flags |= FLAG_CHAR;
			(*format)++;
		}
	}
}
