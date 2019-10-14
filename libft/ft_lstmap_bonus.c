/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgarcia- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/14 10:18:51 by mgarcia-          #+#    #+#             */
/*   Updated: 2019/10/14 11:15:32 by mgarcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(void *))
{
	t_list	*begin_list;

	begin_list = NULL;
	while (lst)
	{
		ft_lstadd_back(&begin_list, (*f)(lst->content));
		lst = lst->next;
	}
	return (begin_list);
}
