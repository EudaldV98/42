/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_alpha.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgarcia- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/05 11:15:36 by mgarcia-          #+#    #+#             */
/*   Updated: 2019/07/07 20:56:38 by mgarcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_str_is_alpha(char *str)
{
	while (*str)
	{
		if ((*str < 65 || *str > 90) && (*str < 97 || *str > 122))
			return (0);
		str++;
	}
	return (1);
}
