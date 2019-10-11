/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_functions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgarcia- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/22 16:50:41 by mgarcia-          #+#    #+#             */
/*   Updated: 2019/07/22 18:07:42 by mgarcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "functions.h"

void		addition(int a, int b)
{
	ft_putnbr(a + b);
	ft_putstr("\n");
}

void		substraction(int a, int b)
{
	ft_putnbr(a - b);
	ft_putstr("\n");
}

void		multiplication(int a, int b)
{
	ft_putnbr(a * b);
	ft_putstr("\n");
}

void		division(int a, int b)
{
	if (b == 0)
		ft_putstr("Stop : division by zero");
	else
		ft_putnbr(a / b);
	ft_putstr("\n");
}

void		modulo(int a, int b)
{
	if (b == 0)
		ft_putstr("Stop : modulo by zero");
	else
		ft_putnbr(a % b);
	ft_putstr("\n");
}
