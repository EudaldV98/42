/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgarcia- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/26 11:45:15 by mgarcia-          #+#    #+#             */
/*   Updated: 2019/10/26 12:55:57 by mgarcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		get_next_line(int fd, char **line)
{
	char	buf[BUFFER_SIZE];
	int		n;

	if (fd == 0)
	{
		while ((n = read(0, buf, BUFFER_SIZE)) > 0)
			write(1, buf, n);
	}
	else
	{
		*line = (char*)malloc(sizeof(char) * (BUFFER_SIZE + 1));
		*line = readfile(*line, fd);
	}
	return (0);
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
		close(fd);
	}
	return 0;			
}
