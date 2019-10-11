/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgarcia- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/23 11:50:42 by mgarcia-          #+#    #+#             */
/*   Updated: 2019/07/24 22:57:28 by mgarcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BSQ_H
# define BSQ_H

# include "structs.h"
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

/*
** bsq functions
*/

char			*read_file(char *av, int bol);
int				check_data(char *str, t_map_info *code);
unsigned int	**map_creator(char *str, t_map_info *code, unsigned int *s);
void			solve(unsigned int **tab, t_map_info *map_info, t_square *chp);
void			print_bsq(char *str, t_map_info *mi, t_square *chp);
void			free_tab(unsigned int **tab, int lines);

/*
** ft_utils
*/

void			ft_putchar(char c);
void			ft_putstr(char *str);
int				ft_strlen(char *str);
int				ft_atoi(char *str);
char			*ft_strndup(char *src, unsigned int len);
char			*ft_strjoin(char *s1, char *s2);

#endif
