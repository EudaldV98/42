/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_file.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgarcia- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/18 09:57:38 by mgarcia-          #+#    #+#             */
/*   Updated: 2019/07/18 17:34:19 by mgarcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>
#define BUFSIZE 1

int		main(int ac, char **av)
{
	char	buf[BUFSIZE];
	int		fd;
	int		n;

	if (ac == 1)
	{
		write(2, "File name missing.\n", 19);
		return (0);
	}
	else if (ac > 2)
	{
		write(2, "Too many arguments.\n", 20);
		return (0);
	}
	if ((fd = open(av[1], O_RDONLY, 0)) == -1)
	{
		write(2, "Cannot read file.\n", 18);
		return (0);
	}
	while ((n = read(fd, buf, BUFSIZE)) > 0)
		write(1, buf, n);
	close(fd);
	return (0);
}
