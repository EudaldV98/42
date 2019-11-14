/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgarcia- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/31 14:52:10 by mgarcia-          #+#    #+#             */
/*   Updated: 2019/11/14 15:00:00 by mgarcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int main(int ac, char **av)
{
	char	*str;
	int		fd;
	//int		fd2;
	int		n;

	n = 0;
	if (ac == 2 || ac == 3)
	{
		
		fd = open(av[1], O_RDWR, 0);
		//fd2 = open(av[2], O_RDWR, 0);
		/*printf("%i - ", get_next_line(-3, &str));
		printf("%s\n", str);
		printf("%i - ", get_next_line(fd, &str));
		printf("%s\n", str);
		printf("%i - ", get_next_line(fd, &str));
		printf("%s\n", str);
		printf("%i - ", get_next_line(fd, &str));
		printf("%s\n", str);
		printf("%i - ", get_next_line(fd, &str));
		printf("%s\n", str);
		printf("%i - ", get_next_line(fd, &str));
		printf("%s\n", str);
		*/
		while ((n = get_next_line(fd, &str)) > 0)
		{
			printf("%s\n", str);
			free(str);
		}
		//while (1);
		/*		
		if ((n = get_next_line(fd, &str)) > -2)
			printf("fd = %d, return = %d, line = %s\n", fd, n, str);
		free(str);
		if ((n = get_next_line(fd2, &str)) > -2)
			printf("fd = %d, return = %d, line = %s\n", fd2, n, str);
		free(str);
		if ((n = get_next_line(fd, &str)) > -2)
			printf("fd = %d, return = %d, line = %s\n", fd, n, str);
		free(str);
		if ((n = get_next_line(fd2, &str)) > -2)
			printf("fd = %d, return = %d, line = %s\n", fd2, n, str);
		free(str);
		if ((n = get_next_line(fd2, &str)) > -2)
			printf("fd = %d, return = %d, line = %s\n", fd, n, str);
		free(str);
		if ((n = get_next_line(fd2, &str)) > -2)
			printf("fd = %d, return = %d, line = %s\n", fd2, n, str);
		free(str);
		if ((n = get_next_line(fd, &str)) > -2)
			printf("fd = %d, return = %d, line = %s\n", fd, n, str);
		free(str);
		if ((n = get_next_line(fd2, &str)) > -2)
			printf("fd = %d, return = %d, line = %s\n", fd2, n, str);
		free(str);
		if ((n = get_next_line(fd, &str)) > -2)
			printf("fd = %d, return = %d, line = %s\n", fd, n, str);
		free(str);
		if ((n = get_next_line(fd2, &str)) > -2)
			printf("fd = %d, return = %d, line = %s\n", fd2, n, str);
		free(str);
		if ((n = get_next_line(fd, &str)) > -2)
			printf("fd = %d, return = %d, line = %s\n", fd, n, str);	
		free(str);
		close(fd);
		close(fd2);*/
	}
	//while (1);
	return 0;
}
