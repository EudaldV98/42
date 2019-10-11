/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgarcia- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/15 14:56:13 by mgarcia-          #+#    #+#             */
/*   Updated: 2019/07/16 18:33:38 by mgarcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char		*ft_itoa_base(int nbr, char *base);

static int	check_base(char *base)
{
	int i;

	if (!*base++ || !*base)
		return (0);
	base--;
	while (*base)
	{
		if (*base <= 32 || *base == 43 || *base == 45)
			return (0);
		i = 1;
		while (*(base + i))
		{
			if (*base == *(base + i))
				return (0);
			i++;
		}
		base++;
	}
	return (1);
}

static int	change_base(char *str, char *base, int nb)
{
	int i;
	int j;

	while (*str)
	{
		i = 0;
		while (*(base + i))
		{
			if (*str == *(base + i))
				break ;
			i++;
		}
		if (!*(base + i))
			return (nb);
		while (*(base + i))
			i++;
		j = 0;
		while (*str != *(base + j))
			j++;
		nb = (nb * i) + j;
		str++;
	}
	return (nb);
}

int			ft_atoi_base(char *str, char *base)
{
	int nb;
	int neg;

	nb = 0;
	neg = 0;
	while (*str == 32 || (*str >= 9 && *str <= 13))
		str++;
	while (*str == '+' || *str == '-')
	{
		if (*str == '-')
			neg++;
		str++;
	}
	nb = change_base(str, base, nb);
	if (neg % 2 != 0)
		nb = -nb;
	return (nb);
}

char		*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	int		nb;
	char	*str;

	if (!(check_base(base_from)))
		return (0);
	nb = ft_atoi_base(nbr, base_from);
	str = ft_itoa_base(nb, base_to);
	return (str);
}
