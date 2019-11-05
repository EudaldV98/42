/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgarcia- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/26 11:48:10 by mgarcia-          #+#    #+#             */
/*   Updated: 2019/11/05 17:42:00 by mgarcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10000
# endif

typedef struct		s_list
{
	int				fd;
	char			*data;
	struct s_list	*next;
}					t_list;

int					get_next_line(int fd, char **line);

size_t				ft_strlen(const char *str);

char				*ft_strcat(char *dest, const char *src);

char				*ft_strjoin(char const *s1, char const *s2, int f);

int					ft_addnewlst_back(t_list **alst, int fd);

int					ft_strchr(const char *s, int c);

char				*ft_substr(char const *s, unsigned int start, size_t len);

#endif
