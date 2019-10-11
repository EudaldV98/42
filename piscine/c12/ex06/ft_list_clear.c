/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_clear.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgarcia- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/25 19:29:41 by mgarcia-          #+#    #+#             */
/*   Updated: 2019/07/25 21:32:25 by mgarcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
#include <stdlib.h>

void		ft_list_clear(t_list *begin_list, void (*free_fct)(void *))
{
	t_list	*next_link;
	t_list	*link;

	link = begin_list;
	while (link)
	{
		next_link = link->next;
		(*free_fct)(link->data);
		free(link);
		link = next_link;
	}
	begin_list = NULL;
}
