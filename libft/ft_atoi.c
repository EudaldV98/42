/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgarcia- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 14:11:18 by mgarcia-          #+#    #+#             */
/*   Updated: 2019/10/07 14:20:31 by mgarcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *str)
{
	unsigned long int   nb;
	int		    neg;

	nb = 0;
	neg = 1;
	while (*str == 32 || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			neg = -1;
		str++;
	}
	while ((*str >= '0' && *str <= '9'))
	    nb = (nb * 10) + *str++ - 48;
	return (nb * neg);
}

#include <stdlib.h>
#include <stdio.h>

int main(int ac, char **av)
{
    if (ac > 1)
    {
	printf("The real atoi = %d\n", atoi(av[1]));
	printf("My sketchy atoi = %d\n", ft_atoi(av[1]));
    }
}
