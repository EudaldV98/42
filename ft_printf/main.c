#include "ft_printf.h"
#include <stdio.h>

int main()
{
	printf("%#o\n", 789);
	printf("%#.0o\n", 123);
	printf("%#.0o\n", 0);
	return (0);
}

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
	printf("%#.5o\n", 21);
	ft_printf("%#.5o\n", 21);
	
	return (0);
}*/
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
