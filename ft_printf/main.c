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
/*
int main()
{
	int r1 = ft_printf("%10s is a string", "this");
	ft_printf("\n");
	int r2 = printf("%10s is a string", "this");
	
	printf("\nMi printf devuelve %d\n", r1);
	printf("El printf de vdad devuelve %d", r2);
	
	return (0);
}
*/
/*
int main()
{
	ft_printf("%k", NULL);
	printf("%s", NULL);
	return (0);
}
*/
/*
int main()
{
	signed char a = 0;
	signed char b = 0;
	char s1[] = "sssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssss";
    char s2[] = "sssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssss";

	
	signed char *p1 = &a;
	signed char *p2 = &b;

    ft_printf("%s%hhn\n", s1, p1);
    printf("%d\n\n", a);
	printf("%s%hhn\n", s2, p2);
    printf("%d\n\n", b);
	return (0);
}
*/

int main()
{
	printf("%f\n", 456.789);
	ft_printf("%f\n", 456.789);
	//ft_printf("%s", "abc");
	//printf("%s", "abc");
	
	return (0);
}
