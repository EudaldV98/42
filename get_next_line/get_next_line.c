/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgarcia- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/26 11:45:15 by mgarcia-          #+#    #+#             */
/*   Updated: 2019/10/30 20:39:00 by mgarcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		unread_fd(int fd, t_list **alst)
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

void	create_fd(int fd, t_list **alst)
{
	t_list			*lst;

	lst = ft_lstnew(fd, NULL);
	ft_lstadd_back(alst, lst);
}

int		get_next_line(int fd, char **line)
{
	static t_list	*alst;
	t_list			*lst;
	char			buf[BUFFER_SIZE];
	int				n;
	int				init;
	int				ret;

	init = 0;
	//printf("EMPESAMO\n");
	if (unread_fd(fd, &alst) == 1) // Itera la lista buscando un elemento dcon lst->fd == al recibido por parametro.
	{
		//printf("HOLAAAA\n");
		create_fd(fd, &alst);
		//printf("FILE DESCRIPTOR DEL AMIJO ALST, JUSTE APRESSS DE LA MAGISTRAL APARICION DE CREATE_FD > %d\n", alst->fd);
	}
	lst = alst;
	//printf("Salimos del primer if, todo bien todo correcto\n");
	//printf("Aqui el fd de lst > %d\n", lst->fd);
	while (lst->next && fd != lst->fd)
		lst = lst->next;
	if (lst->data)
	{
		if ((n = ft_strchr(lst->data, 10)) > 0)
		{
			*line = ft_substr(lst->data, 0, n);
			lst->data = ft_substr(lst->data, n + 1, BUFFER_SIZE);
			return (1);
		}
		else
		{
			*line = ft_strdup(lst->data);
			init = 1;
			lst->data = NULL;
		}//se guarda lo que queda(si queda) del str en lst->data. Si no queda nada, se pone a NULL. (o free casi mej)
	}

	//printf("FIRST HALF CONSEGUIDA WOWOOWOW\nfUCK U SEGFAULT ( ͡° ͜ʖ ͡°)\n");

	while ((ret = read(fd, buf, BUFFER_SIZE)) > 0)
	{
		if ((n = ft_strchr(buf, 10)) > 0)
		{
			//printf("n is equal to %d y init eqs to %d \n", n, init);
			if (init == 0)
				*line = ft_substr(buf, 0, n);
			else
				*line = ft_strjoin(*line, ft_substr(lst->data, 0, n));
			lst->data = ft_substr(buf, n + 1, BUFFER_SIZE); // Si no queda buffer para copiar... que pasa ??	
			return (1);
		}
		else if (init == 0)
		{
			*line = ft_strdup(buf);
			init = 1;
		}
		else
			*line = ft_strjoin(*line, buf);
	}
	//free a to ninio + reestructuracion familiar.
	return (0);
}

int main(int ac, char **av)
{
	char	*str;
	int		fd;
	int		fd2;
	int		n;

	if (ac == 2 || ac == 3)
	{
		fd = open(av[1], O_RDWR, 0);
		fd2 = open(av[2], O_RDWR, 0);
		/*printf("%i\n", get_next_line(fd, &str));
		printf("%s\n", str);
		printf("%i\n", get_next_line(fd, &str));
		printf("%s\n", str);
		printf("%i\n", get_next_line(fd, &str));
		printf("%s\n", str);
		printf("%i\n", get_next_line(fd, &str));
		printf("%s\n", str);
		printf("%i\n", get_next_line(fd, &str));*/
		if ((n = get_next_line(fd, &str)) > 0)
			printf("%s\n", str);
		if ((n = get_next_line(fd2, &str)) > 0)
			printf("%s\n", str);
		if ((n = get_next_line(fd, &str)) > 0)
			printf("%s\n", str);
		if ((n = get_next_line(fd2, &str)) > 0)
			printf("%s\n", str);
		if ((n = get_next_line(fd, &str)) > 0)
			printf("%s\n", str);
		if ((n = get_next_line(fd2, &str)) > 0)
			printf("%s\n", str);
	}
	return 0;			
}
