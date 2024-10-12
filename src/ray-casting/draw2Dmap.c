/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw2Dmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmellal <nmellal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 12:42:46 by nmellal           #+#    #+#             */
/*   Updated: 2024/10/12 05:08:48 by nmellal          ###   ########.fr       */
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
	t_vec2 delta_side;
	t_vec2 step;
	t_vec2 side_dest;
	int hit = 0;
	// int side = 0;

	int map_x = (int)(game->player->pos.x / SCALE);
	int map_y = (int)(game->player->pos.y / SCALE);


	setup_plane(game);
	number_of_rays = 10;
	for (size_t i = 0; i < number_of_rays; i++) {
		printf("\n\n");
		hit = 0;
		camera_x = 2 * (double)((double)i / (double)number_of_rays) - 1;
		ray.x = game->player->dir.x + game->player->plane.x * camera_x;
		ray.y = game->player->dir.y + game->player->plane.y * camera_x;
		vec2_normalized(&ray);
		printf("ray number %zu : ray.x = %f, ray.y = %f\n",i , ray.x, ray.y);
		if (ray.x == 0)
			delta_side.x = INFINITY;
		else
			delta_side.x = fabs(1.0 / ray.x);

		if (ray.y == 0)
			delta_side.y = INFINITY;
		else
			delta_side.y = fabs(1.0 / ray.y);
		printf("delta_side.y = %f\n", delta_side.y);
		step = determine_xy_steps(ray);
		printf("step.x = %f, step.y = %f\n", step.x, step.y);
		side_dest = determine_first_xy_side(game->player->pos, map_x, map_y, delta_side, ray);
		while (hit == 0)
		{
			if (side_dest.x < side_dest.y)
			{
				side_dest.x += delta_side.x;
				map_x += step.x;
				// side = 0;
			}
			else
			{
				side_dest.y += delta_side.y;
				map_y += step.y;
				// side = 1;
			}
			printf("side_dest.y = %f\n", side_dest.y);
			if ((map_x >= 0 && map_x < game->parsing->map_width) && (map_y >= 0 && map_y < game->parsing->map_hight))
			{
				printf("At map_x = %d, map_y = %d, map value = %c\n", map_x, map_y, game->parsing->map[map_y][map_x]);
				if (game->parsing->map[map_y][map_x] > '0')
				{
					puts("DRAW");
					hit = 1;
					draw_player_as_square(game, map_x, map_y);
					my_draw_direction(game, game->player->pos.x, game->player->pos.y, map_x, map_y, GREEN);
					break;
				}
			}
			else {
				printf("Ray is out of bounds: map_x = %d, map_y = %d\n", map_x, map_y);
				hit = 1;
			}
		}
		// int px_end = (int)(game->player->pos.x + ray.x * (double)ray_length);  // X component of ray endpoint
		// int py_end = (int)(game->player->pos.y + ray.y * (double)ray_length);  // Y component of ray endpoint
		// my_draw_direction(game, game->player->pos.x, game->player->pos.y, px_end, py_end, BLACK);
	}
}

t_vec2 determine_xy_steps(t_vec2 raydir)
{
	t_vec2 step;

	if (raydir.x < 0)
		step.x = -1;
	else
		step.x = 1;
	if (raydir.y < 0)
		step.y = -1;
	else
		step.y = 1;
	return (step);
}

t_vec2	determine_first_xy_side(t_vec2 pos, int map_x, int map_y, t_vec2 delta_side, t_vec2 ray)
{
	t_vec2 first_side;
	double tile_posx = pos.x / (double)SCALE;
	double tile_posy = pos.y / (double)SCALE;

	printf("posx / SCALE = %f, posy / SCALE = %f\n", tile_posx, tile_posx);
	if (ray.x < 0)
	{
		first_side.x = (tile_posx - map_x) * delta_side.x;
	}
	else
	{
		first_side.x = (map_x + 1.0 - tile_posx) * delta_side.x;
	}
	if (ray.y < 0)
	{
		first_side.y = (tile_posy - map_y) * delta_side.y;
	}
	else
	{
		first_side.y = (map_y + 1.0 - tile_posy) * delta_side.y;
	}
	return (first_side);
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