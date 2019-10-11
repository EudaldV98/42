/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgarcia- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/03 19:48:01 by mgarcia-          #+#    #+#             */
/*   Updated: 2019/07/07 16:57:39 by mgarcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int		ft_add_one(int *arr, int i, int n)
{
	if (arr[0] == 10 - n)
	{
		arr[0]++;
		return (0);
	}
	else if (arr[i] < (10 - (n - i)))
	{
		arr[i]++;
		i++;
		while (i < n)
		{
			arr[i] = arr[i - 1] + 1;
			i++;
		}
		return (0);
	}
	else
		ft_add_one(arr, i - 1, n);
	return (0);
}

void	ft_print_combn(int n)
{
	int arr[n];
	int i;

	i = 0;
	while (i < n)
	{
		arr[i] = i;
		i++;
	}
	while (arr[0] <= 10 - n && n < 10)
	{
		i = 0;
		while (i < n)
		{
			ft_putchar(arr[i] + '0');
			i++;
		}
		i--;
		if (arr[0] < 10 - n)
		{
			ft_putchar(',');
			ft_putchar(32);
		}
		ft_add_one(arr, i, n);
	}
}
