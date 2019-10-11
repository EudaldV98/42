/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgarcia- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/04 14:45:23 by mgarcia-          #+#    #+#             */
/*   Updated: 2019/07/04 17:08:40 by mgarcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_sort_int_tab(int *tab, int size)
{
	int i;
	int j;
	int swap;
	int bol;

	size -= 1;
	bol = 1;
	i = 0;
	while (bol == 1)
	{
		bol = 0;
		j = 0;
		while (j < size - 1)
		{
			if (tab[j] > tab[j + 1])
			{
				bol = 1;
				swap = tab[j];
				tab[j] = tab[j + 1];
				tab[j + 1] = swap;
			}
			j++;
		}
		i++;
	}
}
