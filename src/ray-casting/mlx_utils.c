/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmellal <nmellal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 16:00:24 by nmellal           #+#    #+#             */
/*   Updated: 2024/10/08 19:13:22 by nmellal          ###   ########.fr       */
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

int   key_press(int key, t_game *game)
{
    if (key == ESC_KEY)
        exit(0);
    if (key == LEFT_KEY)
		vec2_rotate_vec2(&game->player->dir, -0.1);
    if (key == RIGHT_KEY)
		vec2_rotate_vec2(&game->player->dir, 0.1);
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