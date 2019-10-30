/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgarcia- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/26 11:48:10 by mgarcia-          #+#    #+#             */
/*   Updated: 2019/10/30 20:39:16 by mgarcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
//#include <sys/stat.h>

#define BUFFER_SIZE 1000000

typedef struct		s_list
{
	int				fd;
	char			*data;
	struct s_list	*next;
}					t_list;

int		get_next_line(int fd, char **line);

char	*readfile(char *str, int fd);

char	*ft_strjoin(char const *s1, char const *s2);

size_t	ft_strlen(const char *str);

char	*ft_strcat(char *dest, const char *src);

t_list	*ft_lstnew(int fd, char *data);

void	ft_lstadd_back(t_list **alst, t_list *new);

char	*ft_strdup(char *src);

int		ft_strchr(const char *s, int c);

char	*ft_substr(char const *s, unsigned int start, size_t len);

#endif
