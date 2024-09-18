#include "../../include/raycasting.h"


void    my_mlx_pixel_put(t_mlx *mlx, int x, int y, int color)
{
    char    *dst;

    dst = mlx->addr + (y * mlx->line_length + x * (mlx->bits_per_pixel / 8));
    *(unsigned int *)dst = color;
}

void    init_mlx_struct(t_mlx *mlx)
{
    mlx->mlx = mlx_init();
    mlx->win = mlx_new_window(mlx->mlx, HEIGHT, WIDTH, "Cub3D");
    mlx->img = mlx_new_image(mlx->mlx, HEIGHT, WIDTH);
    mlx->addr = mlx_get_data_addr(mlx->img, &mlx->bits_per_pixel, &mlx->line_length, &mlx->endian);
    if (!mlx->mlx || !mlx->win || !mlx->img || !mlx->addr)
    {
        printf(MLX_ERROR);
        exit(1);
    }
    mlx->width = HEIGHT;
    mlx->height = WIDTH;
}
