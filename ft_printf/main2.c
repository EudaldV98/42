#include "ft_printf.h"
#include <stdio.h>

int main()
{
	//struct lconv	*lc;
	int 			n = 12345678;

	setlocale(LC_NUMERIC, "es_US");

	//lc = localeconv();
	//printf("%s\n", lc->thousands_sep);
	printf("%'d\n", n);
	ft_printf("%'d\n", n);
	return (0);
}


/*
int main()
{
	char	*str;
	int		len;

	str = "(null)";
	len = ft_strlen(str);
	printf("%d", len);
	return (0);
}
*/
