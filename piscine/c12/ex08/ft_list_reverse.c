/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_reverse.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgarcia- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/25 20:07:20 by mgarcia-          #+#    #+#             */
/*   Updated: 2019/07/25 21:05:53 by mgarcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void		ft_list_reverse(t_list **begin_list)
{
	t_list	*list;
	t_list	*tmp;

	list = 0;
	while (*begin_list)
	{
		tmp = (*begin_list)->next;
		(*begin_list)->next = list;
		list = *begin_list;
		*begin_list = tmp;
	}
	*begin_list = list;
}
