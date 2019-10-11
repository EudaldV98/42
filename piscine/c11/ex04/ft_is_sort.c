/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgarcia- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/22 15:54:37 by mgarcia-          #+#    #+#             */
/*   Updated: 2019/07/22 20:15:21 by mgarcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int			ascending_sort(int *tab, int length, int (*f)(int, int))
{
	int		i;

	i = 0;
	while (i < (length - 1))
	{
		if ((*f)(tab[i], tab[i + 1]) > 0)
			return (0);
		i++;
	}
	return (1);
}

int			descending_sort(int *tab, int length, int (*f)(int, int))
{
	int		i;

	i = 0;
	while (i < (length - 1))
	{
		if ((*f)(tab[i], tab[i + 1]) < 0)
			return (0);
		i++;
	}
	return (1);
}

int			ft_is_sort(int *tab, int length, int (*f)(int, int))
{
	if (ascending_sort(tab, length, f))
		return (1);
	else if (descending_sort(tab, length, f))
		return (1);
	return (0);
}
