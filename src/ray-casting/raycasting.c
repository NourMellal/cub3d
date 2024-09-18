#include "../../include/raycasting.h"


void    my_mlx_pixel_put(t_mlx *mlx, int x, int y, int color)
{
    char    *dst;

    dst = mlx->addr + (y * mlx->line_length + x * (mlx->bits_per_pixel / 8));
    *(unsigned int *)dst = color;
}



void    draw_map(t_mlx *mlx)
{
    int x;
    int y;

    y = 0;
    while (y < data()->map_hight * SCALE)
    {
        x = 0;
        while (x < data()->map_width * SCALE)
        {
            if (x % SCALE == 0 || y % SCALE == 0)
                my_mlx_pixel_put(mlx, x, y, RED);
            else if (data()->map[y / SCALE][x / SCALE] == '1')
                my_mlx_pixel_put(mlx, x, y, BLACK);
            else
                my_mlx_pixel_put(mlx, x, y, WHITE);
            x++;
        }
        y++;
    }
}

void    init_mlx_struct(t_mlx *mlx)
{
    mlx->mlx = mlx_init();
    mlx->win = mlx_new_window(mlx->mlx, data()->map_width * SCALE, data()->map_hight * SCALE, "Cub3D");
    mlx->img = mlx_new_image(mlx->mlx, data()->map_width * SCALE, data()->map_hight * SCALE);
    mlx->addr = mlx_get_data_addr(mlx->img, &mlx->bits_per_pixel, &mlx->line_length, &mlx->endian);
    if (!mlx->mlx || !mlx->win || !mlx->img || !mlx->addr)
    {
        printf(MLX_ERROR);
        exit(1);
    }
}

void    start_mlx(void)
{
    t_mlx   mlx;

    init_mlx_struct(&mlx);
    draw_map(&mlx);
    mlx_put_image_to_window(mlx.mlx, mlx.win, mlx.img, 0, 0);
    mlx_loop(mlx.mlx);
}
