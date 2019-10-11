/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgarcia- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/13 15:01:03 by mgarcia-          #+#    #+#             */
/*   Updated: 2019/07/16 11:07:10 by mgarcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FUNCTIONS_H
# define FUNCTIONS_H

# include <unistd.h>
# include <stdlib.h>

/*
** declare structure
*/

typedef struct		s_points_of_view
{
	int	colup[4];
	int	coldown[4];
	int	rowleft[4];
	int	rowright[4];
}					t_pov;

/*
** ft_utils
*/

void				ft_putchar(char c);
void				ft_putstr(char *str);
int					ft_strlen(char *str);
void				display_error(void);

/*
** Initialize tab and struct
*/

int					**tab_allocate(void);
void				get_params(char **argv, t_pov *pov);

/*
** algorithm
*/

int					algorithm(t_pov *pov, int **tab);
int					find_blanks(int *ptr, int *ptr2, int **tab);
int					valid_solution(t_pov *pov, int **tab);
int					is_possible(int value, int i, int j, int **tab);

/*
** print solution
*/

void				print_solution(int **tab);

#endif
