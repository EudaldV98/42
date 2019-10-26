/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgarcia- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/26 11:48:10 by mgarcia-          #+#    #+#             */
/*   Updated: 2019/10/26 21:30:03 by mgarcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
//#include <sys/stat.h>

#define BUFFER_SIZE 10000

int		get_next_line(int fd, char **line);

char	*readfile(char *str, int fd);

char	*ft_strjoin(char const *s1, char const *s2);

size_t	ft_strlen(const char *str);

char	*ft_strcat(char *dest, const char *src);

char	*ft_realloc(char *str, size_t size);

#endif
