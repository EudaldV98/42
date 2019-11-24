/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   text_format.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgarcia- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/22 11:51:44 by mgarcia-          #+#    #+#             */
/*   Updated: 2019/11/24 17:02:46 by mgarcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		format_string(t_flags *f, va_list ap)
{
	char	*str;
	int		len;
	int		i;

	str = va_arg(ap, char *);
	if (!str)
	{
		ft_putstr("(null)");
		f->idx += 6;
		return ;
	}
	len = ft_strlen(str);
	if (f->flags & FLAG_PRECISION)
		len = f->precision > len ? len : f->precision;
	if (!(f->flags & FLAG_LEFT))
	{
		i = 0;
		while (i++ < (f->width - len))
			_putchar(32, f);
	}
	i = 0;
	while (*str && i++ < len)
		_putchar(*str++, f);
	if (f->flags & FLAG_LEFT)
	{
		i = 0;
		while (i++ < (f->width - len))
			_putchar(32, f);
	}
}

void		format_character(t_flags *f, va_list ap)
{
	char	c;

	c = va_arg(ap, int);
	if (!(f->flags & FLAG_LEFT))
	{
		while (--(f->width) > 0)
			_putchar(32, f);
	}
	_putchar(c, f);
	if (f->flags & FLAG_LEFT)
	{
		while (--(f->width) > 0)
			_putchar(32, f);
	
	}
	
}
