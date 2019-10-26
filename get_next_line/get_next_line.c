/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgarcia- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/26 11:45:15 by mgarcia-          #+#    #+#             */
/*   Updated: 2019/10/26 21:29:13 by mgarcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		get_next_line(int fd, char **line)
{		
	static char		buf[BUFFER_SIZE];
	static int		i = BUFFER_SIZE;
	static int		j;
	char			*str;
	int				ret;
	
	if (i == BUFFER_SIZE)
	{
		if (!((ret = read(fd, buf, BUFFER_SIZE)) > 0))
			return (0);
		i = 0;
	}
	if (j == 0)
		str = (char*)malloc(sizeof(char) * (BUFFER_SIZE - i + 1));
	else
		str = ft_realloc(str, BUFFER_SIZE - i + 1);
	while (buf[i] != '\n' && i < BUFFER_SIZE)
		str[j++] = buf[i++];
	if (buf[i] == '\n')
	{
		str[j] = '\0';
		*line = str;
		j = 0;
		i++;
		return (1);
	}
	else if (i == BUFFER_SIZE)
		return (get_next_line(fd, line));
	return (-1);
}

int main(int ac, char **av)
{
	char	*str;
	int		fd;

	if (ac == 2)
	{
		fd = open(av[1], O_RDWR, 0);
		/*printf("%i\n", get_next_line(fd, &str));
		printf("%s\n", str);
		printf("%i\n", get_next_line(fd, &str));
		printf("%s\n", str);
		printf("%i\n", get_next_line(fd, &str));
		printf("%s\n", str);
		printf("%i\n", get_next_line(fd, &str));
		printf("%s\n", str);
		printf("%i\n", get_next_line(fd, &str));*/
		if (get_next_line(fd, &str))
			printf("%s\n", str);
		close(fd);
	}
	return 0;			
}
