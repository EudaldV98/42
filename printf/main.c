#include "ft_printf.h"
#include <stdio.h>

int main(int ac, char **av)
{
	t_flags				f;
	int					r;

	f.flags |= FLAG_UPPERCASE;


   	r = ft_printf(":%0+10i:", 4);
	printf("\nret is %d\n", r);
	return (0);
}
