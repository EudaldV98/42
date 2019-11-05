/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgarcia- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/26 11:45:15 by mgarcia-          #+#    #+#             */
/*   Updated: 2019/11/05 16:37:58 by mgarcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int			unread_fd(int fd, t_list **alst)
{
	t_list			*lst;

	lst = *alst;
	if (lst)
	{
		while (lst)
		{
			if (lst->fd == fd)
				return (0);
			lst = lst->next;
		}
	}
	return (1);
}

static int			check_list(int *init, t_list **lst, char **line)
{
	int		n;

	if ((*lst)->data)
	{
		if ((n = ft_strchr((*lst)->data, 10)) >= 0)
		{
			if (n > 0)
			{
				*line = ft_substr((*lst)->data, 0, n);
				*init = 1;
			}
			else if (n == 0)
				*line = ft_strjoin("", "", 0);
			(*lst)->data = (BUFFER_SIZE - n > 1) ?
					ft_substr((*lst)->data, n + 1, BUFFER_SIZE - n - 1) : NULL;
			return (1);
		}
		else
		{
			*line = ft_strjoin((*lst)->data, "", 1);
			(*lst)->data = NULL;
			*init = 1;
		}
	}
	return (0);
}

static int			read_fd(int init, int fd, char **line, t_list *lst)
{
	char		buf[BUFFER_SIZE + 1];
	int			ret;
	int			n;

	while ((ret = read(fd, buf, BUFFER_SIZE)) > 0)
	{
		buf[ret] = '\0';
		if ((n = ft_strchr(buf, 10)) >= 0)
		{
			if (init == 0 && n > 0)
				*line = ft_substr(buf, 0, n);
			else if (n > 0)
				*line = ft_strjoin(*line, ft_substr(buf, 0, n), 2);
			else if (n == 0 && init == 0)
				*line = ft_strjoin("", "", 0);
			lst->data = BUFFER_SIZE - n > 1 ?
							ft_substr(buf, n + 1, BUFFER_SIZE - n - 1) : NULL;
			return (1);
		}
		*line = init == 0 ? ft_strjoin(buf, "", 0) : ft_strjoin(*line, buf, 1);
		init = 1;
	}
	if (init == 0)
		*line = ft_strjoin("", "", 0);
	return (ret);
}

int					get_next_line(int fd, char **line)
{
	static t_list	*alst;
	t_list			*lst;
	int				init;

	init = 0;
	if (unread_fd(fd, &alst) == 1)
	{
		if (!(ft_addnewlst_back(&alst, fd)))
			return (-1);
	}
	lst = alst;
	while (lst->next && fd != lst->fd)
		lst = lst->next;
	if (check_list(&init, &lst, line))
		return (1);
	return (read_fd(init, fd, line, lst));
}
