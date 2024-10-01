#include "../../include/shared.h"


double	degree_to_radian(double degree)
{
	return (degree * (M_PI / 180));
}

double	radian_to_degree(double radian)
{
	return (radian * (180 / M_PI));
}

void    my_mlx_pixel_put(t_mlx *mlx, int x, int y, int color)
{
    char    *dst;

    dst = mlx->addr + (y * mlx->line_length + x * (mlx->bits_per_pixel / 8));
    *(unsigned int *)dst = color;
}



int   key_press(int key, t_game *game)
{
    if (key == ESC_KEY)
        exit(0);
    if (key == LEFT_KEY)
    {
        game->player->angle += 0.1;
		if (game->player->angle > 2 * M_PI)
			game->player->angle -= 2 * M_PI;
    }
    if (key == RIGHT_KEY)
	{
        game->player->angle -= 0.1;
		if (game->player->angle < 0)
			game->player->angle += 2 * M_PI;
	}
    if (key == UP_KEY)
    {
        game->player->x += cos(game->player->angle) * 10;
        game->player->y -= sin(game->player->angle) * 10;
    }
    if (key == DOWN_KEY)
    {
        game->player->x -= cos(game->player->angle) * 10;
        game->player->y += sin(game->player->angle) * 10;
    }
    return 0;
}
int    display(t_game *game)
{
    mlx_clear_window(game->mlx->mlx, game->mlx->win);
    draw_map(game);
    draw_personal_line(game);
    mlx_put_image_to_window(game->mlx->mlx, game->mlx->win, game->mlx->img, 0, 0);
    return 0;
}

t_mlx    *init_mlx_struct(t_game *game)
{
    t_mlx *mlx = game->mlx;
    mlx->mlx = mlx_init();
    mlx->win = mlx_new_window(mlx->mlx, game->parsing->map_width * SCALE, game->parsing->map_hight * SCALE, "Raycasting");
    mlx->img = mlx_new_image(mlx->mlx, game->parsing->map_width * SCALE, game->parsing->map_hight * SCALE);
    mlx->addr = mlx_get_data_addr(mlx->img, &mlx->bits_per_pixel, &mlx->line_length, &mlx->endian);
    mlx->width = WIDTH;
    mlx->height = HEIGHT;
    return (mlx);
}
void    start_mlx(void)
{
    t_game  game = {data(), malloc(sizeof(t_mlx)), malloc(sizeof(t_player))};
    game.mlx = init_mlx_struct(&game);
    get_player_pos_and_dst(&game);
    mlx_hook(game.mlx->win, 2, 1L << 0, key_press, &game);
    mlx_loop_hook(game.mlx->mlx, display, &game);
    mlx_loop(game.mlx->mlx);
}
