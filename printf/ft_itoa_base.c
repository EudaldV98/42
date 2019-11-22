/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgarcia- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/22 15:40:43 by mgarcia-          #+#    #+#             */
/*   Updated: 2019/11/22 15:41:26 by mgarcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int		check_base(char *base)
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

static char		*int_to_char(int nbr, int i, int len, char *base)
{
	char	*nb;
	int		j;

	if (!(nb = (char *)malloc(sizeof(char) * len + 2)))
		return (0);
	j = 0;
	while (nbr > (i - 1) || nbr < -(i - 1))
	{
		nb[j] = nbr > 0 ? base[nbr % i] : base[-(nbr % i)];
		nbr = nbr / i;
		j++;
	}
	nb[j++] = nbr > 0 ? base[nbr] : base[-nbr];
	if (nbr < 0)
		nb[j++] = '-';
	nb[j--] = '\0';
	i = 0;
	while (i < j)
	{
		nbr = nb[i];
		nb[i++] = nb[j];
		nb[j--] = nbr;
	}
	return (nb);
}

char			*ft_itoa_base(int nbr, char *base)
{
	char	*nb;
	int		len;
	int		swap;
	int		i;

	i = 0;
	if (!check_base(base))
		return (0);
	while (*(base + i))
		i++;
	swap = nbr;
	len = 1;
	while (nbr > i - 1 || nbr < -(i - 1))
	{
		nbr = nbr / i;
		len += 1;
	}
	nbr = swap;
	nb = int_to_char(nbr, i, len, base);
	return (nb);
}
