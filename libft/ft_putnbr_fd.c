/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgarcia- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 14:15:54 by mgarcia-          #+#    #+#             */
/*   Updated: 2019/10/09 10:13:02 by mgarcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>

void	ft_putnbr_fd(int nb, int fd)
{
	if (nb > 9 || nb < -9)
		ft_putnbr_fd(nb / 10, fd);
	else if (nb < 0)
		ft_putchar_fd('-', fd);
	ft_putchar_fd(nb > 0 ? nb % 10 + 48 : -(nb % 10) + 48, fd);
}
