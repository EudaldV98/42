#include <OpenGL/gl3.h>
#include <math.h>
#include "mlx.h"

int	    sqexp(int  n)
{
    return (n * n);
}

double	    dist(int x, int y, int a, int b)
{
    if (x == a)
	return (y - b < 0 ? -(y - b) : y - b);
    else if (y == b)
	return (x - a < 0 ? -(x - a) : x - a);
    else
	return (sqrt((double)(sqexp((x -a < 0 ? -(x - a) : x - a)) + sqexp((y - b < 0 ? -(y - b) : y - b)))));
}

void	    draw_circle(void *mlx_ptr, void *win_ptr, int r, int x, int y)
{
    int i = 0;
    int	j = 0;

    for (i = y - r; i < y + r; i++)
    {
	j = x;
	while (dist(i, j, x, y) < r)
	    j++;
	mlx_pixel_put(mlx_ptr, win_ptr, j, i, 0xffffff);
    }

    while (i > y - r)
    {
	j = x;
	while (dist(i, j, x, y) < r)
	    j--;
	mlx_pixel_put(mlx_ptr, win_ptr, j, i, 0xffffff);
	i--;
    }
}
