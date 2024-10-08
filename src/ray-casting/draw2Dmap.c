/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw2Dmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmellal <nmellal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 12:42:46 by nmellal           #+#    #+#             */
/*   Updated: 2024/10/08 18:52:19 by nmellal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycasting.h"
void my_draw_direction(t_game *game, int px, int py)
{
    // Get the direction vector from the player structure
    int len = SCALE;  // Length of the vector (you can adjust it)
    int px_end = px + (int)(game->player->dir.x * len);
    int py_end = py + (int)(game->player->dir.y * len);

    // Bresenham's line algorithm setup
    int dx = abs(px_end - px);
    int dy = abs(py_end - py);
    int sx = (px < px_end) ? 1 : -1;
    int sy = (py < py_end) ? 1 : -1;
    int err = dx - dy;
    int e2;

    // Draw the line using Bresenham's algorithm
    while (1)
    {
        if (px < 0 || px >= game->parsing->map_width * SCALE || py < 0 || py >= game->parsing->map_hight * SCALE)
            break;

        // Put the pixel (to draw the vector)
        my_mlx_pixel_put(game->mlx, px, py, GREEN);

        // Check if we have reached the end point
        if (px == px_end && py == py_end)
            break;

        // Error calculation and step
        e2 = 2 * err;
        if (e2 > -dy)
        {
            err -= dy;
            px += sx;
        }
        if (e2 < dx)
        {
            err += dx;
            py += sy;
        }
    }
}


void    draw_personal_line(t_game *game)
{
    my_draw_direction(game, game->player->pos.x+ 1, game->player->pos.y + 1);
}

void    draw_player_as_square(t_game *game, int x, int y)
{
    int i;
    int j;

    i = 0;
    while (i < 3)
    {
        j = 0;
        while (j < 3)
        {
            my_mlx_pixel_put(game->mlx, x + i, y + j, RED);
            j++;
        }
        i++;
    }
}

void    put_player(t_game *game)
{
    draw_player_as_square(game, game->player->pos.x, game->player->pos.y);
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
                my_mlx_pixel_put(game->mlx, j, i, GREY);
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