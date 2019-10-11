/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgarcia- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/13 12:34:10 by mgarcia-          #+#    #+#             */
/*   Updated: 2019/07/17 16:13:49 by mgarcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		str_is_separator(char *str, char *sep)
{
	while (*sep)
	{
		if (*str == *sep)
			return (1);
		sep++;
	}
	return (0);
}

int		ft_custom_strlen(char *str, char *sep)
{
	int i;

	i = 0;
	while (str[i] && !str_is_separator(&str[i], sep))
		i++;
	return (i);
}

int		ft_count_words(char *str, char *sep)
{
	int words;

	words = 0;
	while (*str)
	{
		while (*str && str_is_separator(str, sep))
			str++;
		if (*str && !str_is_separator(str, sep))
			words++;
		while (*str && !str_is_separator(str, sep))
			str++;
	}
	return (words);
}

char	*ft_custom_strdup(char *src, int len, char *sep)
{
	char	*dup;
	int		i;

	if (!(dup = (char*)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	i = 0;
	while (*src && !str_is_separator(src, sep))
		dup[i++] = *src++;
	dup[i] = '\0';
	return (dup);
}

char	**ft_split(char *str, char *charset)
{
	char	**tab;
	int		words;
	int		len;
	int		i;

	words = ft_count_words(str, charset);
	if (!(tab = (char **)malloc(sizeof(char *) * (words + 1))))
		return (NULL);
	i = 0;
	while (i < words)
	{
		while (*str && str_is_separator(str, charset))
			str++;
		len = ft_custom_strlen(str, charset);
		tab[i] = ft_custom_strdup(str, len, charset);
		while (*str && !str_is_separator(str, charset))
			str++;
		i++;
	}
	tab[i] = 0;
	return (tab);
}
