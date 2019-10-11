/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_strs.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgarcia- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/25 19:22:49 by mgarcia-          #+#    #+#             */
/*   Updated: 2019/07/25 19:29:02 by mgarcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

t_list		*ft_list_push_strs(int size, char **strs)
{
	int		i;
	t_list	*list;
	t_list	*tmp;

	list = 0;
	tmp = 0;
	i = 0;
	while (i < size)
	{
		list = ft_create_elem(strs[i]);
		list->next = tmp;
		tmp = list;
		i++;
	}
	return (list);
}
