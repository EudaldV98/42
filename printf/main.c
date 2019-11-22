#include "ft_printf.h"
#include <stdio.h>

int main(int ac, char **av)
{
	char	s[] = "OHLALA";
	int		r;

	r = ft_printf("%-*c\n", 10, 'c');
	printf("\nret = %d\n", r);
	return (0);
}
