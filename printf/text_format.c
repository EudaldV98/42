/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   text_format.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgarcia- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/22 11:51:44 by mgarcia-          #+#    #+#             */
/*   Updated: 2019/11/22 14:50:41 by mgarcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		format_string(t_flags *f, va_list ap)
{
	char	*str;
	int		len;
	int		i;

	str = va_arg(ap, char *);
	len = ft_strlen(str);
	if (f->flags & FLAG_PRECISION)
		len = f->precision > len ? len : f->precision;
	if (!(f->flags & FLAG_LEFT))
	{
		i = 0;
		while (i++ < (f->width - len))
		{
			ft_putchar(32);
			f->idx++;
		}
	}
	i = 0;
	while (*str && i++ < len)
	{
		ft_putchar(*str++);
		f->idx++;
	}
	if (f->flags & FLAG_LEFT)
	{
		i = 0;
		while (i++ < (f->width - len))
		{
			ft_putchar(32);
			f->idx++;
		}
	}
}

void		format_character(t_flags *f, va_list ap)
{
	char	c;

	c = va_arg(ap, int);
	if (!(f->flags & FLAG_LEFT))
	{
		while (--(f->width))
		{
			ft_putchar(32);
			f->idx++;
		}
	}
	ft_putchar(c);
	f->idx++;
	if (f->flags & FLAG_LEFT)
	{
		while (--(f->width))
		{
			ft_putchar(32);
			f->idx++;
		}
	
	}
	
}
