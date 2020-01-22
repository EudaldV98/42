#include <stdio.h>

int			ft_isdigit(int c)
{
	if (c >= 48 && c <= 57)
		return (1);
	return (0);
}

double		stof(char **str)
{
	int		w;
	double	d;

	w = 0;
	while (ft_isdigit(**str))
		w = w * 10 + (*((*str)++) - '0');
	if (**str == '.')
		(*str)++;
	d = 0.0;
	while(ft_isdigit(**str))
		d = d * 10 + (*((*str)++) - '0');
	while (d > 1)
		d /= 10;
	d += w;
	return (d);
}

int main()
{
	char *str = "123.532";

	//printf("%s", str);
	printf("%f", stof(&str));
	return (0);
}
