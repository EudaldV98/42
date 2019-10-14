/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgarcia- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 11:28:10 by mgarcia-          #+#    #+#             */
/*   Updated: 2019/10/09 12:57:58 by mgarcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char			*ft_itoa(int nbr)
{
	char	*nb;
	int		len;
	int		i;

	i = nbr;
	len = 1;
	while (nbr > 9 || nbr < -9)
	{
		nbr = nbr / 10;
		len += 1;
	}
	nbr = i;
	if (!(nb = (char *)malloc(sizeof(char) * len + 2)))
	    return (NULL);
	i = 0;
	while (nbr > 9 || nbr < -9)
	{
	    nb[i++] = nbr > 0 ? 48 + nbr % 10 : 48 + -(nbr % 10);
	    nbr = nbr / 10;
	}
	nb[i++] = nbr > 0 ? 48 + nbr : 48 + (-nbr);
	if (nbr < 0)
	    nb[i++] = '-';
	nb[i++] = '\0';
	return (ft_strrev(nb));
}
