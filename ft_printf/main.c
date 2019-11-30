#include "ft_printf.h"
#include <stdio.h>

int main()
{
	printf("%");
	printf("\n");
	ft_printf(NULL);
	ft_printf("\n");
	printf("{%.*s}\n", -5, "42");
	ft_printf("{%.*s}\n", -5, "42");
	printf("  printf  %%o      >> %o\n", 123);
	ft_printf("ft_printf %%o      >> %o\n", 123);
	printf("  printf  %%10o    >> %10o\n", 123);
	ft_printf("ft_printf %%10o    >> %10o\n", 123);
	printf("  printf  %%#o     >> %#o\n", 123);
	ft_printf("ft_printf %%#o     >> %#o\n", 123);
	printf("  printf  %%#10o   >> %#10o\n", 123);
	ft_printf("ft_printf %%#10o   >> %#10o\n", 123);
	printf("  printf  %%#.5o   >> %#.5o\n", 123);
	ft_printf("ft_printf %%#.5o   >> %#.5o\n", 123);
	printf("  printf  %%#10.5o >> %#10.5o\n", 123);
	ft_printf("ft_printf %%#10.5o >> %#10.5o\n", 123);
	printf("  printf  %%#.5o   >> %#.5o\n", 5263);
	ft_printf("ft_printf %%#.5o   >> %#.5o\n", 5263);
	printf("  printf  %%#3o    >> %#3o\n", 0);
	ft_printf("ft_printf %%#3o    >> %#3o\n", 0);
	printf("  printf  %%#10.0o >> %#10.o\n", 0);
	ft_printf("ft_printf %%#10.0o >> %#10.o\n", 0);
	printf("  printf  %%#.0o   >> %#.o\n", 0);
	ft_printf("ft_printf %%#.0o   >> %#.o\n", 0);
	printf("  printf  %%10.0o  >> %10.o\n", 0);
	ft_printf("ft_printf %%10.0o  >> %10.o\n", 0);

	return (0);
}



/*
int main()
{
	long double fl = 456.78987654321;
	int	ip = 0;
	int	ia = 0;
	int *p = &ip;
	int *a = &ia;

	printf("%p\n", NULL);
	ft_printf("%p\n", NULL);
	ft_printf("%f\n", 1.0/0.0);
	printf("%f\n", 1.0/0.0);
	
	return (0);
}
*/
