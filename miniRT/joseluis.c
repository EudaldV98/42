#include <OpenGL/gl3.h>
#include "mlx.h"
#include <stdlib.h>
#include <math.h>

void DrawCircle(void *mlx_ptr, void *win_ptr, int x, int y, int r, int range)
{
      static const double PI = 3.1415926535;
      double i, angle, x1, y1;

      for(i = 0; i < range; i += 0.1)
      {
            angle = i;
            x1 = r * cos(angle * PI / 180);
            y1 = r * sin(angle * PI / 180);
            mlx_pixel_put(mlx_ptr, win_ptr, x + x1, y + y1, 0xffffff);
      }
}

//void	    draw_circle(void *mlx_ptr, void *win_ptr, int r, int x, int y);

int	    main()
{
    void    *mlx_ptr;
    void    *win_ptr;

    int	    i;

    mlx_ptr = mlx_init();
    win_ptr = mlx_new_window(mlx_ptr, 600, 650, "J O S E    L U I S");
    
    
    
    mlx_clear_window(mlx_ptr, win_ptr);
    
    //	pierna derecha
    for (i = 0; i < 100; i++)
    	mlx_pixel_put(mlx_ptr, win_ptr, 400 - i, 500 - i, 0xffffff);
    //	pierna izquierda
    for (i = 0; i < 100; i++)
    	mlx_pixel_put(mlx_ptr, win_ptr, 300 - i, 400 + i, 0xffffff);
    //	cuerpo
    for (i = 0; i < 200; i++)
	mlx_pixel_put(mlx_ptr, win_ptr, 300, 200 + i, 0xffffff);
    //	brazos
    for (i = 0; i < 200; i++)
	mlx_pixel_put(mlx_ptr, win_ptr, 200 + i, 275, 0xffffff);
    //	CABESA
    DrawCircle(mlx_ptr, win_ptr, 300, 150, 50, 360);
    //	ojitos
    DrawCircle(mlx_ptr, win_ptr, 280, 140, 5, 360);
    DrawCircle(mlx_ptr, win_ptr, 320, 140, 5, 360);
    //	regular sonrisa
    /*for (i = 0; i < 40; i++)
	mlx_pixel_put(mlx_ptr, win_ptr, 280 + i, 170, 0xffffff);
    for (i = 0; i < 10; i++)
	mlx_pixel_put(mlx_ptr, win_ptr, 280 - i, 170 - i, 0xffffff);
    for (i = 0; i < 10; i++)
	mlx_pixel_put(mlx_ptr, win_ptr, 320 + i, 170 - i, 0xffffff);
    for (i = 0; i < 10; i++)
	mlx_pixel_put(mlx_ptr, win_ptr, 279 - i, 170 - i, 0xffffff);
    for (i = 0; i < 10; i++)
	mlx_pixel_put(mlx_ptr, win_ptr, 321 + i, 170 - i, 0xffffff);
    
    //	colmillos
    for (i = 0; i < 40; i++)
	mlx_pixel_put(mlx_ptr, win_ptr, 280, 170 + i, 0xffffff);
    for (i = 0; i < 40; i++)
	mlx_pixel_put(mlx_ptr, win_ptr, 320, 170 + i, 0xffffff);*/
    
    //	falsa sonrisa
    /*for (i = 0; i < 21; i++)
	mlx_pixel_put(mlx_ptr, win_ptr, 280 + i, 170 + i, 0xffffff);
    for (i = 0; i < 21; i++)
	mlx_pixel_put(mlx_ptr, win_ptr, 320 - i, 170 + i, 0xffffff);
    for (i = 0; i < 21; i++)
	mlx_pixel_put(mlx_ptr, win_ptr, 279 + i, 170 + i, 0xffffff);
    for (i = 0; i < 21; i++)
	mlx_pixel_put(mlx_ptr, win_ptr, 321 - i, 170 + i, 0xffffff);*/

    //sonrisa profident
    //DrawCircle(mlx_ptr, win_ptr, 300, 160, 25, 180);

    mlx_loop(mlx_ptr);

    return (0);
}
