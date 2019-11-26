#include "ft_printf.h"
#include <stdio.h>

/*
int main()
{
	ft_printf("%10.2d\n", 789);
	printf("%10.2d\n", 789);
	return (0);
}
*/
/*
int main()
{
	int a=10;
	int* ptr = &a;

	ft_printf("%p\n", ptr);
	printf("%p\n", ptr);
	return (0);
}
*/

int main()
{
	int r1 = ft_printf("%10s is a string", "this");
	ft_printf("\n");
	int r2 = printf("%10s is a string", "this");
	
	printf("\nMi printf devuelve %d\n", r1);
	printf("El printf de vdad devuelve %d", r2);
	
	return (0);
}

/*
int main()
{
	ft_printf("%k", NULL);
	printf("%s", NULL);
	return (0);
}
*/
