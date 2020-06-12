#include "get_next_line.h"

int main(int ac, char **av)
{
    int	    fd = open(av[1], 0);
    char    *str;
    int	    ret;
    (void)ac;

    while ((ret = get_next_line(fd, &str)) > 0)
    {
	printf("==%d== %s\n", ret, str);
	free(str);
    }
    printf("==%d== %s\n", ret, str);
    free(str);
}
