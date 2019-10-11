/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgarcia- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/06 18:57:52 by mgarcia-          #+#    #+#             */
/*   Updated: 2019/07/07 17:07:29 by mgarcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	int i;

	i = 0;
	if (size > 0)
	{
		while (dest[i])
		{
			size--;
			i++;
		}
		while (*src && size > 1)
		{
			dest[i++] = *src++;
			size--;
		}
		dest[i] = '\0';
	}
	while (*src++)
		i++;
	return (i);
}
