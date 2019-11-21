/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgarcia- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/20 16:53:01 by mgarcia-          #+#    #+#             */
/*   Updated: 2019/11/21 20:49:42 by mgarcia-         ###   ########.fr       */
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

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int main()
{
	ft_printf("asdfh %-235.3hd", 7);
	return (0);
}
