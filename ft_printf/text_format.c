/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   text_format.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgarcia- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/22 11:51:44 by mgarcia-          #+#    #+#             */
/*   Updated: 2019/11/26 21:32:24 by mgarcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		format_string(t_flags *f, char *buf, va_list ap)
{
	char	*str;
	int		len;
	int		i;

	i = 0;
	str = va_arg(ap, char *);
	if (!str)
	{
		putstr_buff("(null)", buf, f);
		return ;
	}
	len = ft_strlen(str);
	if (f->flags & FLAG_PRECISION)
		len = f->precision > len ? len : f->precision;
	if (!(f->flags & FLAG_LEFT))
	{
		i = 0;
		while (i++ < (f->width - len))
			putchar_buff(32, buf, f);
	}
	i = 0;
	while (*str && i++ < len)
		putchar_buff(*str++, buf, f);
	if (f->flags & FLAG_LEFT)
	{
		i = 0;
		while (i++ < (f->width - len))
			putchar_buff(32, buf, f);
	}
}

void		format_character(char c, char *buf, t_flags *f)
{
	if (!(f->flags & FLAG_LEFT))
	{
		while (--(f->width) > 0)
			putchar_buff(32, buf, f);
	}
	putchar_buff(c, buf, f);
	if (f->flags & FLAG_LEFT)
	{
		while (--(f->width) > 0)
			putchar_buff(32, buf, f);
	
	}
}
