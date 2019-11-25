#include "ft_printf.h"
#include <stdio.h>
/*
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
*/
/*
int main()
{
	int a=10;
	int* ptr =&a;

	ft_printf("%d\n", "hola");
	//printf("%d\n", "hola");
	return (0);
}
*/

#include <stdio.h>

// bit returned at location
int bit_return(int a, int loc)   
{
    int buf = a & 1<<loc;

    if (buf == 0) return 0;
    else return 1; 
}

int main() 
{
    //11000010111011010100000000000000  
    // 1 sign bit | 8 exponent bit | 23 fraction bits
    float a = 17.25/*118.625*/; 
    int *b;
    b = &a;

    int i;
    for (i = 31; i >= 0; i--)
    {
        printf("%d",bit_return(*b,i));
    }

    return 0;
}
