/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgarcia- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 13:35:17 by mgarcia-          #+#    #+#             */
/*   Updated: 2019/10/11 13:12:59 by mgarcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;

	if (!(str = (char *)malloc(sizeof(char) * len + 1)))
		return (NULL);
	if (start < ft_strlen(s))
		return (ft_strncpy(str, &s[start], len));
	return ((char *)s);
}
/*
#include <stdio.h>

int main(int ac, char **av)
{
	if (ac == 4)
		printf("%s", ft_strsub(av[1], atoi(av[2]), atoi(av[3])));
	return (0);
}


si len es 0 ?


*/
