/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgarcia- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 13:35:17 by mgarcia-          #+#    #+#             */
/*   Updated: 2019/10/16 21:10:43 by mgarcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*str;
	unsigned int	i;

	i = 0;
	while (s[i])
		i++;
	if (i < start || len == 0)
		return (NULL);
	else if (i < len + start)
		len = i - start;
	if (!(str = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	i = 0;
	while (len-- > 0)
		str[i++] = s[start++];
	str[i] = '\0';
	return (str);
}
