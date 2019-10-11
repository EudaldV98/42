/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgarcia- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/22 16:19:48 by mgarcia-          #+#    #+#             */
/*   Updated: 2019/07/22 18:08:23 by mgarcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FUNCTIONS_H
# define FUNCTIONS_H

# include <unistd.h>

typedef struct		s_op_ptr
{
	char	*op;
	void	(*ptr)(int, int);
}					t_op_ptr;

/*
** do_op functions
*/
void				addition(int a, int b);
void				substraction(int a, int b);
void				multiplication(int a, int b);
void				division(int a, int b);
void				modulo(int a, int b);

/*
** ft_utils
*/
void				ft_putchar(char c);
void				ft_putstr(char *str);
void				ft_putnbr(int nb);
int					ft_strcmp(char *s1, char *s2);
int					ft_atoi(char *str);

#endif
