/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgarcia- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/10 22:14:33 by mgarcia-          #+#    #+#             */
/*   Updated: 2019/07/12 13:41:45 by mgarcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stock_str.h"
#include <stdlib.h>

int						ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char					*ft_strcpy(char *dest, char *src)
{
	int i;

	i = 0;
	while (*src)
		dest[i++] = *src++;
	dest[i] = '\0';
	return (dest);
}

char					*ft_strdup(char *src, int length)
{
	char	*dup;

	if (!(dup = (char*)malloc(sizeof(char) * (length + 1))))
		return (NULL);
	ft_strcpy(dup, src);
	return (dup);
}

struct s_stock_str		*ft_strs_to_tab(int ac, char **av)
{
	struct s_stock_str	*strarr;
	int					length;
	int					i;

	if (!(strarr = (t_stock_str *)malloc(sizeof(t_stock_str) * (ac + 1))))
		return (NULL);
	i = 0;
	while (i < ac)
	{
		length = ft_strlen(av[i]);
		strarr[i].size = length;
		strarr[i].str = ft_strdup(av[i], length);
		strarr[i].copy = ft_strdup(av[i], length);
		i++;
	}
	strarr[i].str = 0;
	return (strarr);
}
