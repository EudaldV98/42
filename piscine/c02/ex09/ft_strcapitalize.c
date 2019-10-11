/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgarcia- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/05 12:27:00 by mgarcia-          #+#    #+#             */
/*   Updated: 2019/07/06 16:28:58 by mgarcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_strlowcase(char *str)
{
	while (*str)
	{
		if (*str > 64 && *str < 91)
			*str += 32;
		str++;
	}
}

char	*ft_strcapitalize(char *str)
{
	int i;

	i = 0;
	ft_strlowcase(str);
	while (str[i])
	{
		if (str[i] > 96 && str[i] < 123)
		{
			if (i == 0)
				str[i] -= 32;
			else if (str[i - 1] == '\t' || (str[i - 1] > 31 && str[i - 1] < 48)
					|| (str[i - 1] > 57 && str[i - 1] < 65)
					|| (str[i - 1] > 90 && str[i - 1] < 97)
					|| (str[i - 1] > 122 && str[i - 1] < 127))
				str[i] -= 32;
		}
		i++;
	}
	return (str);
}
