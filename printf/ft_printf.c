/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgarcia- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/20 16:53:01 by mgarcia-          #+#    #+#             */
/*   Updated: 2019/11/20 19:19:15 by mgarcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int ft_printf(const char *format, ...)
{
	va_list	arg;
	int		done;

	va_start(arg, format);
	done = ft_vprintf(format, arg);
	va_end(arg);

	return (done);
}
