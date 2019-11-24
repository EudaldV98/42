/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   itoa_base.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgarcia- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/24 11:34:01 by mgarcia-          #+#    #+#             */
/*   Updated: 2019/11/24 20:39:53 by mgarcia-         ###   ########.fr       */
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

char			*itoa_base(size_t nbr, int neg, int base, t_flags *f)
{
	char	*nb;
	int		digit;
	int		len;
	int		i;

	if (!(f->flags & (FLAG_LONG_LONG | FLAG_LONG | FLAG_SHORT | FLAG_CHAR)))
		nbr = (unsigned int)nbr;
	else if (f->flags & FLAG_SHORT)
		nbr = (short)nbr;
	else if (f->flags & FLAG_CHAR)
		nbr = (char)nbr;
	if (f->flags & FLAG_PRECISION && f->precision == 0 && !nbr)
	{
		if (!(nb = (char *)malloc(sizeof(char) * 1)))
		return (0);
		nb[0] = '\0';
		f->flags &= ~FLAG_HASH;
		return (nb);
	}
	len = nbrlen(nbr, base);
	if (!(nb = (char *)malloc(sizeof(char) * (len + (neg ? 2 : 1) + 100))))
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
	{
		nb[i++] = '0';
		f->flags &= ~FLAG_HASH;
	}
	if (f->flags & FLAG_PRECISION)
	{
		while (f->precision > len++)
			nb[i++] = '0';
	}
	nb[i] = '\0';
	nb = ft_strrev(nb);

	//printf("\nBase is : %d\n", base);
	//printf("itoa returns %s\n", nb);

	return (nb);
}
