/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _itoa_base.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgarcia- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/22 15:40:43 by mgarcia-          #+#    #+#             */
/*   Updated: 2019/11/23 15:50:15 by mgarcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		nbrlen(size_t nb, int base)
{
	int		len;

	len = 1;
	while (nb > (base - 1))
	{
		nb /= base;
		len++;
	}
	return (len);
}

char			*_itoa_base(size_t nbr, int neg, int base, t_flags *f)
{
	char	*nb;
	int		digit;	int		len;
	int		i;

	len = nbrlen(nbr, base);
	if (!(nb = (char *)malloc(sizeof(char) * (len + (neg ? 2 : 1)))))
		return (0);
	i = 0;
	while (nbr > 0)
	{
		digit = (nbr > base - 1) ? nbr % base : nbr;
		if (digit < 10)
			nb[i] = digit + '0';
		else
			nb[i] = (f->flags & FLAG_UPPERCASE ? 'A' : 'a') + digit - 10;
		nbr /= base;
		i++;
	}
	if (i == 0)
		nb[i++] = '0';
	if (neg)
		nb[i++] = '-';
	nb[i] = '\0';
	nb = ft_strrev(nb);
	return (nb);
}
