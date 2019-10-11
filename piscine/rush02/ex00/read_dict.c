/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_dict.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgarcia- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/20 15:16:52 by mgarcia-          #+#    #+#             */
/*   Updated: 2019/07/21 23:11:18 by mgarcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "functions.h"
#define BUFSIZE 1

static char		*readfile(char *str, int fd)
{
	char	buf[BUFSIZE + 1];
	char	*ptr;
	int		ret;

	while ((ret = read(fd, buf, BUFSIZE)) > 0)
	{
		ptr = str;
		buf[ret] = '\0';
		if (!(str = ft_strjoin(str, buf)))
			return (NULL);
		free(ptr);
	}
	return (str);
}

char			*read_dict(int ac, char **av)
{
	char	*str;
	int		fd;

	if (!(str = (char *)malloc(sizeof(char) * (BUFSIZE + 1))))
		return (NULL);
	if (ac == 2)
	{
		if ((fd = open("numbers.dict", O_RDWR, 0)) == -1)
			return (NULL);
		str = readfile(str, fd);
		return (str);
	}
	else if (ac == 3)
	{
		if ((fd = open(av[1], O_RDWR, 0)) == -1)
			return (NULL);
		str = readfile(str, fd);
		return (str);
	}
	return (NULL);
}
