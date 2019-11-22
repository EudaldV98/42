/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   integer_format.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgarcia- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/22 15:41:58 by mgarcia-          #+#    #+#             */
/*   Updated: 2019/11/22 18:05:24 by mgarcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void		format_integer(char fmt, t_flags *f, va_list ap)
{
	if (f->flags & FLAG_PRECISION)
		f->flags &= ~FLAG_ZEROPAD;
	if (fmt == 'i' || fmt == 'd')
	{
		f->flags &= ~FLAG_HASH;
		if (f->flags & FLAG_LONG_LONG)
		{
			//aja
		}
		else if (f->flags & FLAG_LONG)
		{
			//eje
		}
		else
		{
			//ojo
		}

	}
	else
	{
		f->flags &= ~(FLAG_PLUS | FLAG_SPACE);
	}
}
