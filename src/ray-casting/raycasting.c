#include "../../include/shared.h"


void    my_mlx_pixel_put(t_mlx *mlx, int x, int y, int color)
{
    char    *dst;

    dst = mlx->addr + (y * mlx->line_length + x * (mlx->bits_per_pixel / 8));
    *(unsigned int *)dst = color;
}

void get_player_pos_and_dst(void)
{
    int i;
    int j;

    i = 0;
    while (i < data()->map_hight)
    {
        j = 0;
        while (j < data()->map_width)
        {
            if (data()->map[i][j] == 'N' || data()->map[i][j] == 'S' || data()->map[i][j] == 'E' || data()->map[i][j] == 'W')
            {
                data()->direction = data()->map[i][j];
                data()->pos[0] = j;
                data()->pos[1] = i;
                return ;
            }
            j++;
        }
        i++;
    }
}

void    draw_player_as_square(t_mlx *mlx, int x, int y)
{
    int i;
    int j;

    i = 0;
    while (i < SCALE / 6)
    {
        j = 0;
        while (j < SCALE / 6)
        {
            my_mlx_pixel_put(mlx, x + i, y + j, RED);
            j++;
        }
        i++;
    }
}

void    put_player(t_mlx *mlx)
{
    get_player_pos_and_dst();
    int x = (data()->pos[0] * SCALE) + SCALE / 2;
    int y = (data()->pos[1] * SCALE) + SCALE / 2;
    draw_player_as_square(mlx, x - 5, y - 5);
}

void    draw_map(t_mlx *mlx)
{
    int x;
    int y;

    y = 0;
    while (y < data()->map_hight * SCALE)
    {
        
        x = 0;
        while (x < (data()->map_width * SCALE)-1)
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
void    display(t_mlx *mlx)
{
    draw_map(mlx);
    put_player(mlx);
    mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img, 0, 0);
}

void    start_mlx(void)
{
    t_mlx   mlx;

    init_mlx_struct(&mlx);
    display(&mlx);
    mlx_loop(mlx.mlx);
}
