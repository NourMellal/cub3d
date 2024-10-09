/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmellal <nmellal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 16:00:24 by nmellal           #+#    #+#             */
/*   Updated: 2024/10/09 20:02:47 by nmellal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shared.h"

void    my_mlx_pixel_put(t_mlx *mlx, int x, int y, int color)
{
    char    *dst;

    dst = mlx->addr + (y * mlx->line_length + x * (mlx->bits_per_pixel / 8));
    *(unsigned int *)dst = color;
}

void    mlx_delete_image(void *mlx_ptr, void *img_ptr)
{
    if (img_ptr)
    {
        mlx_destroy_image(mlx_ptr, img_ptr);
        img_ptr = NULL;
    }
}

t_mlx    *init_mlx_struct(t_game *game)
{
    t_mlx *mlx = game->mlx;
    mlx->mlx = mlx_init();
    mlx->win = mlx_new_window(mlx->mlx, WIDTH, HEIGHT, "Raycasting");
    mlx->img = mlx_new_image(mlx->mlx, WIDTH, HEIGHT);
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

int   key_press(int key, t_game *game)
{
    if (key == ESC_KEY)
        exit(0);
    if (key == LEFT_KEY)
	{
		vec2_rotate_vec2(&game->player->dir, -0.1);
		game->player->angle = vec2_to_angle(game->player->dir);
	}
    if (key == RIGHT_KEY)
	{
		vec2_rotate_vec2(&game->player->dir, 0.1);
		game->player->angle = vec2_to_angle(game->player->dir);
	}
    if (key == UP_KEY)
    {
		game->player->pos.x += game->player->dir.x * SPEED;
		game->player->pos.y += game->player->dir.y * SPEED;
    }
    if (key == DOWN_KEY)
    {
		game->player->pos.x -= game->player->dir.x * SPEED;
		game->player->pos.y -= game->player->dir.y * SPEED;
    }
    return 0;
}