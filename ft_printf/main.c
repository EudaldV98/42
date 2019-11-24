#include "ft_printf.h"
#include <stdio.h>

int main(int ac, char **av)
{
	t_flags				f;
	int					r;
	int					r2d2;

	f.flags |= FLAG_UPPERCASE;

   	r = ft_printf(":% :");
	printf("\n");
	r2d2 = printf(":% :");
	printf("\n  my ret is %d\n", r);
	printf("\nRIAL ret is %d\n", r2d2);
	return (0);
}

/*
int main()
{
	int a=10;
	int* ptr =&a;
	size_t		je;
	char		*str;
	t_flags		f;

	f.flags = 0;

	je = (size_t)ptr;
	f.flags |= FLAG_HASH;

	//ft_printf("%p\n", ptr);
	printf("%p\n", ptr);
	str = itoa_base(je, 0, 16, &f);
	format_number(str, 0, 'x', &f);
	return (0);
}
*/
