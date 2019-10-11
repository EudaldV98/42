/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_numbers.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgarcia- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/03 18:11:53 by mgarcia-          #+#    #+#             */
/*   Updated: 2019/07/03 20:36:21 by mgarcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_numbers(void)
{
	char nbr;

	nbr = '0';
	while (nbr <= '9')
	{
		write(1, &nbr, 1);
		nbr++;
	}
}
