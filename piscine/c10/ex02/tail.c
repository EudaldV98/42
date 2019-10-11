/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tail.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgarcia- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/18 17:44:47 by mgarcia-          #+#    #+#             */
/*   Updated: 2019/07/24 12:40:44 by mgarcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"
#define BUFSIZE 100

static char		*readfile(char *str, int fd)
{
	char	buf[BUFSIZE + 1];
	char	*ptr;
	int		ret;

	while ((ret = read(fd, buf, BUFSIZE)) > 0)
	{
		ptr = str;
		buf[ret] = '\0';
		str = ft_strjoin(str, buf);
		free(ptr);
	}
	return (str);
}

void			multiple_files_processing(int ac, char **av, int bytes)
{
	char	*str;
	int		valid;
	int		bol;
	int		fd;
	int		i;

	i = 3;
	valid = 0;
	bol = (ac == 4 ? 1 : 0);
	while (--ac > 2)
	{
		str = (char *)malloc(sizeof(char) * BUFSIZE);
		if ((fd = open(av[i], O_RDONLY, 0)) == -1)
		{
			display_error(av[0], av[i++]);
			continue ;
		}
		str = readfile(str, fd);
		if (bytes < ft_strlen(str))
			str += ft_strlen(str) - bytes;
		valid += 1;
		args_format(av[i], str, valid, bol);
		i++;
	}
}

int				main(int ac, char **av)
{
	char		*str;
	int			bytes;

	if (ac > 2)
	{
		if ((bytes = ft_atoi(av[2])) == -1)
			return (display_error2(av[0], av[2]));
	}
	else if (ac == 2 && ft_strcmp(av[1], "-c") == 0)
		display_error3(av[0]);
	if (ac == 3)
	{
		str = (char *)malloc(sizeof(char) * BUFSIZE);
		if (!(str = readfile(str, 0)))
			display_error(av[0], av[4]);
		if (bytes < ft_strlen(str))
			str += ft_strlen(str) - bytes;
		while (*str)
			write(1, str++, 1);
	}
	else if (ac > 3)
		multiple_files_processing(ac, av, bytes);
	return (0);
}
