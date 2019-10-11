/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgarcia- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/11 20:23:49 by mgarcia-          #+#    #+#             */
/*   Updated: 2019/07/24 22:57:30 by mgarcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

static char		*ft_strncpy(char *dest, char *src, unsigned int len)
{
	unsigned int i;

	i = 0;
	while (*src && i < len)
		dest[i++] = *src++;
	dest[i] = '\0';
	return (dest);
}

char			*ft_strndup(char *src, unsigned int len)
{
	char *dup;

	if (!(dup = (char*)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	ft_strncpy(dup, src, len);
	return (dup);
}
