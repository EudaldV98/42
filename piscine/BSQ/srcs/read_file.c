/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgarcia- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/23 11:35:11 by mgarcia-          #+#    #+#             */
/*   Updated: 2019/07/24 23:27:28 by mgarcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"
#define BUFSIZE 6000000

static char		*readfile(char *str, int fd)
{
	char	buf[BUFSIZE + 1];
	char	*ptr;
	int		ret;
	int		bol;

	bol = 0;
	while ((ret = read(fd, buf, BUFSIZE)) > 0)
	{
		if (bol == 0)
		{
			bol = 1;
			if (buf[0] < '0' || buf[0] > '9')
				return (0);
		}
		ptr = str;
		buf[ret] = '\0';
		if (!(str = ft_strjoin(str, buf)))
			return (NULL);
		free(ptr);
	}
	return (str);
}

char			*read_file(char *av, int bol)
{
	char	*str;
	int		fd;

	if (!(str = (char *)malloc(sizeof(char) * (BUFSIZE + 1))))
		return (NULL);
	if (bol == 1)
	{
		 if ((fd = open(av, O_RDONLY | O_NOFOLLOW)) == -1)
			return (NULL);
		if (!(str = readfile(str, fd)))
			return (NULL);
		close(fd);
		return (str);
	}
	else if (bol == 0)
	{
		if (!(str = readfile(str, 0)))
			return (NULL);
		return (str);
	}
	return (NULL);
}
