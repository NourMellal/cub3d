

#ifndef RAYCASTING_H
#define RAYCASTING_H

#include <math.h>
#include "shared.h"

#define MLX_ERROR "Error\nmlx failed to initialize\n"

#define SCALE 64

#define HEIGHT 600
#define WIDTH 800

typedef struct mlx_data
{
    void    *mlx;
    void    *win;
    void    *img;
    char    *addr;
    int     bits_per_pixel;
    int     line_length;
    int     endian;
    int     width;
    int     height;
}          t_mlx;

void    help(void);

#endif