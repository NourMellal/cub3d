#include "../../include/shared.h"


void    my_mlx_pixel_put(t_mlx *mlx, int x, int y, int color)
{
    char    *dst;

    dst = mlx->addr + (y * mlx->line_length + x * (mlx->bits_per_pixel / 8));
    *(unsigned int *)dst = color;
}

void    my_draw_direction(t_game *game, int px, int py, double angle)
{
    int len = 100;
    while (len)
    {
        if (px < 0 || px >= game->parsing->map_width * SCALE|| py < 0 || py >= game->parsing->map_hight * SCALE)
            break;
        my_mlx_pixel_put(game->mlx, px, py, GREEN);
        px += cos(angle);
        py -= sin(angle);
        len--;
    }
}

void    draw_personal_line(t_game *game)
{
    my_draw_direction(game, game->player->x, game->player->y, game->player->angle);
}

void    set_player_angle(t_game *game)
{
    if (game->parsing->direction == 'N')
        game->player->angle = 3 * M_PI_2;
    else if (game->parsing->direction == 'S')
        game->player->angle = M_PI_2;
    else if (game->parsing->direction == 'E')
        game->player->angle = 0;
    else if (game->parsing->direction == 'W')
        game->player->angle = M_PI;
}

void get_player_pos_and_dst(t_game *game)
{
    int i;
    int j;

    i = 0;
    while (i < game->parsing->map_hight)
    {
        j = 0;
        while (j < game->parsing->map_width)
        {
            if (game->parsing->map[i][j] == 'N' || game->parsing->map[i][j] == 'S' || game->parsing->map[i][j] == 'E' || game->parsing->map[i][j] == 'W')
            {
                game->player->x = (double)(j + 0.5) * SCALE;
                game->player->y = (double)(i + 0.5) * SCALE;
                game->parsing->direction = game->parsing->map[i][j];
                set_player_angle(game);
                printf("angle = %f\n", game->player->angle);
                return ;
            }
            j++;
        }
        i++;
    }
}

void    draw_player_as_square(t_game *game, int x, int y)
{
    int i;
    int j;

    i = 0;
    while (i < 10)
    {
        j = 0;
        while (j < 10)
        {
            my_mlx_pixel_put(game->mlx, x + i, y + j, RED);
            j++;
        }
        i++;
    }
}

void    put_player(t_game *game)
{
    draw_player_as_square(game, game->player->x, game->player->y);
    draw_personal_line(game);
}

void    draw_map(t_game *game)
{
    int i;
    int j;

    i = 0;
    while (i < game->parsing->map_hight * SCALE)
    {
        j = 0;
        while (j < game->parsing->map_width * SCALE)
        {
            if (i % SCALE == 0 || j % SCALE == 0)
                my_mlx_pixel_put(game->mlx, j, i, RED);
            else if (game->parsing->map[i / SCALE][j / SCALE] == '1')
                my_mlx_pixel_put(game->mlx, j, i, BLACK);
            else
                my_mlx_pixel_put(game->mlx, j, i, WHITE);
            j++;
        }
        i++;
    }
    put_player(game);
}


int   key_press(int key, t_game *game)
{
    if (key == ESC_KEY)
        exit(0);
    if (key == LEFT_KEY)
    {
        game->player->angle -= 0.9;
    }
    if (key == RIGHT_KEY)
        game->player->angle += 0.9;
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
