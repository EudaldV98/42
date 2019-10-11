/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgarcia- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/13 15:01:03 by mgarcia-          #+#    #+#             */
/*   Updated: 2019/07/21 23:33:35 by mgarcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FUNCTIONS_H
# define FUNCTIONS_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

/*
** Check functions
*/

int					check_params(int ac, char **av);
int					check_dictionary(char *dict);

/*
** Read functions
*/

char				*read_dict(int ac, char **av);

/*
** Displays the written number
*/

void				write_number(char *str, char *dict);

/*
** Dictionary formating function
*/

char				*dict_cleaner(char *str);

/*
** ft_utils
*/

void				ft_putchar(char c);
void				ft_putstr(char *str);
void				ft_putline(char *str);
int					ft_strlen(char *str);
int					ft_strncmp(char *s1, char *s2, unsigned int n);
char				*ft_strstr(char *str, char *to_find);
char				*ft_strjoin(char *s1, char *s2);

/*
** Error Functions
*/

void				display_error(void);
void				display_dict_error(void);

#endif
