/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgarcia- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/26 11:45:15 by mgarcia-          #+#    #+#             */
/*   Updated: 2019/10/26 14:30:20 by mgarcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
/*
char		*readfile(char *str, int fd)
{
	char	buf[BUFFER_SIZE + 1];
	char	*ptr;
	int		ret;

	while ((ret = read(fd, buf, BUFFER_SIZE)) > 0)
	{
		ptr = str;
		buf[ret] = '\0';
		if (!(str = ft_strjoin(str, buf)))
			return (NULL);
		free(ptr);
	}
	return (str);
}
*/
int		get_next_line(int fd, char **line)
{
	static char		buf[BUFFER_SIZE + 1];
	char			*ptr;
	int				ret;
	char			*str;

	buf[0] = '\0';
	if (buf[0] == '\0')
	
	if ((ret = read(fd, buf, BUFFER_SIZE)) > 0)
	{
		ptr = str;
		buf[ret] = '\0';
		if (!(str = ft_strjoin(str, buf)))
			return (NULL);
		free(ptr);
	}
	   *line = str;
}

int main(int ac, char **av)
{
	char	*str;
	int		fd;

	if (ac == 2)
	{
		fd = open(av[1], O_RDWR, 0);
		get_next_line(fd, &str);
		printf("%s", str);
		get_next_line(fd, &str);
		printf("%s", str);
		get_next_line(fd, &str);
		printf("%s", str);
		close(fd);
	}
	return 0;			
}
