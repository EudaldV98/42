/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cat.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgarcia- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/18 12:20:17 by mgarcia-          #+#    #+#             */
/*   Updated: 2019/07/19 14:02:53 by mgarcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <string.h>
#include <libgen.h>
#define BUFSIZE 1

void	ft_putstr(char *str)
{
	while (*str)
		write(2, str++, 1);
}

void	display_error(char *path, char *file)
{
	ft_putstr(basename(path));
	ft_putstr(": ");
	ft_putstr(file);
	ft_putstr(": ");
	ft_putstr(strerror(errno));
	ft_putstr("\n");
}

int		main(int ac, char **av)
{
	char	buf[BUFSIZE];
	int		fd;
	int		n;
	int		i;

	if (ac == 1)
	{
		while ((n = read(0, buf, BUFSIZE)) > 0)
			write(1, buf, n);
	}
	else
	{
		i = 1;
		while (--ac > 0)
		{
			if ((fd = open(av[i], O_RDWR, 0)) == -1)
				display_error(av[0], av[i]);
			while ((n = read(fd, buf, BUFSIZE)) > 0)
				write(1, buf, n);
			close(fd);
			i++;
		}
	}
	return (0);
}
