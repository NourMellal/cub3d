/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw2Dmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmellal <nmellal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 12:42:46 by nmellal           #+#    #+#             */
/*   Updated: 2024/10/11 17:00:48 by nmellal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycasting.h"

void my_draw_direction(t_game *game, int px, int py, int px_end, int py_end, int color) {
	// Bresenham's line algorithm setup
	int dx = abs(px_end - px);
	int dy = abs(py_end - py);
	int sx = (px < px_end) ? 1 : -1;  // Step for x-direction
	int sy = (py < py_end) ? 1 : -1;  // Step for y-direction
	int err = dx - dy;
	int e2;

	// Draw the starting pixel first
	my_mlx_pixel_put(game->mlx, px, py, color);

	// Bresenham's algorithm loop
	while (px != px_end || py != py_end) {
		e2 = 2 * err;
		if (e2 > -dy) {  // Adjust x if necessary
			err -= dy;
			px += sx;
		}
		if (e2 < dx) {  // Adjust y if necessary
			err += dx;
			py += sy;
		}

		// Check if we are outside map bounds
		if (px < 0 || px >= game->parsing->map_width * SCALE || py < 0 || py >= game->parsing->map_hight * SCALE)
			break;

		// Plot the next pixel
		my_mlx_pixel_put(game->mlx, px, py, color);
	}
}


void	tmp_raycaster(t_game *game) {
	size_t number_of_rays;
	double camera_x;
	t_vec2 ray;

	setup_plane(game);
	number_of_rays = 10;
	for (size_t i = 0; i < number_of_rays; i++) {

		camera_x = 2 * (double)((double)i / (double)number_of_rays) - 1;
		ray.x = game->player->dir.x + game->player->plane.x * camera_x;
		ray.y = game->player->dir.y + game->player->plane.y * camera_x;

		int ray_length = 100;
		int px_end = (int)(game->player->pos.x + ray.x * (double)ray_length);  // X component of ray endpoint
		int py_end = (int)(game->player->pos.y + ray.y * (double)ray_length);  // Y component of ray endpoint
		my_draw_direction(game, game->player->pos.x, game->player->pos.y, px_end, py_end, BLACK);
	}
}

void    draw_personal_line(t_game *game)
{
    my_draw_direction(game, game->player->pos.x - 2, game->player->pos.y + 2, game->player->pos.x + cos(game->player->angle) * 100, game->player->pos.y + sin(game->player->angle) * 100, RED);
	return ;
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
    draw_player_as_square(game, game->player->pos.x - 5, game->player->pos.y - 5);
    draw_personal_line(game);
	tmp_raycaster(game);
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
            else if (game->parsing->map[i / SCALE][j / SCALE] == '0' || ft_isalpha(game->parsing->map[i / SCALE][j / SCALE]))
                my_mlx_pixel_put(game->mlx, j, i, WHITE);
			else
				my_mlx_pixel_put(game->mlx, j, i, GREY);
            j++;
        }
        i++;
    }
    put_player(game);
}