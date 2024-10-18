/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw2Dmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmellal <nmellal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 12:42:46 by nmellal           #+#    #+#             */
/*   Updated: 2024/10/18 02:37:18 by nmellal          ###   ########.fr       */
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
	int hit = 0;

	t_ray	ray;
	t_player*plyr = game->player;
	// int side = 0;


	double scale = 100;

	double x_start = plyr->pos.x + (scale * plyr->dir.x);
	double y_start = plyr->pos.y + (plyr->dir.y * scale);
	double x_end = plyr->pos.x + (plyr->dir.x * scale) + (plyr->plane.x * scale);
	double y_end = plyr->pos.y + (plyr->dir.y * scale) + (plyr->plane.y * scale);
	my_draw_direction(game, x_start, y_start, x_end, y_end, BLUE);


	number_of_rays = 10;
	for (size_t i = 0; i < number_of_rays; i++) {
		double map_x = (int)(game->player->pos.x / SCALE);
		double map_y = (int)(game->player->pos.y / SCALE);

		hit = 0;
		camera_x = 2.0 * (double)((double)i / (double)number_of_rays) - 1.0;

		printf("raynum = %zu, camera_x = %f\n", i, camera_x);

		ray.dir.x = game->player->dir.x + game->player->plane.x * camera_x;
		ray.dir.y = game->player->dir.y + game->player->plane.y * camera_x;
		// my_draw_direction(game, game->player->pos.x, game->player->pos.y, (game->player->pos.x + (ray.x * 100)), game->player->pos.y + ray.y * 100, GREEN);
		vec2_normalized(&ray.dir);

		if (ray.dir.x == 0)
			ray.delta_dist.x = INFINITY;
		else
			ray.delta_dist.x = fabs(1.0 / ray.dir.x);

		if (ray.dir.y == 0)
			ray.delta_dist.y = INFINITY;
		else
			ray.delta_dist.y = fabs(1.0 / ray.dir.y);

		//DDA
		int side = 0;
		ray.side_dist = determine_first_xy_side(plyr->pos, map_x, map_y, &ray);
		while (hit == 0)
		{
			if (ray.side_dist.x < ray.side_dist.y)
			{
				ray.side_dist.x += ray.delta_dist.x;
				map_x += ray.step.x;
				side = 0;
			}
			else
			{
				ray.side_dist.y += ray.delta_dist.y;
				map_y += ray.step.y;
				side = 1;
			}
			printf("mapx = %f, mapy = %f, map[y][x] = %c\n", map_x, map_y, game->parsing->map[(int)map_y][(int)map_x]);
			if (game->parsing->map[(int)map_y][(int)map_x] == '1')
			{
				draw_square(game, map_x * SCALE, map_y * SCALE);
				hit = 1;
			}
		}
	}
}


t_vec2	determine_first_xy_side(t_vec2 pos, int map_x, int map_y, t_ray *ray)
{
	t_vec2 first_side;
	double tile_posx = pos.x / (double)SCALE;
	double tile_posy = pos.y / (double)SCALE;

	if (ray->dir.x < 0)
	{
		first_side.x = (tile_posx - map_x) * ray->delta_dist.x;
		ray->step.x = -1;

	}
	else
	{
		first_side.x = (map_x + 1.0 - tile_posx) * ray->delta_dist.x;
		ray->step.x = 1;
	}
	if (ray->dir.y < 0)
	{
		first_side.y = (tile_posy - map_y) * ray->delta_dist.y;
		ray->step.y = -1;
	}
	else
	{
		first_side.y = (map_y + 1.0 - tile_posy) * ray->delta_dist.y;
		ray->step.y = 1;
	}
	return (first_side);
}

void    draw_personal_line(t_game *game)
{
   my_draw_direction(game, game->player->pos.x - 2, game->player->pos.y + 2, game->player->pos.x + cos(game->player->angle) * 100, game->player->pos.y + sin(game->player->angle) * 100, RED);
	return ;
}

void    draw_square(t_game *game, int x, int y)
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
    draw_square(game, game->player->pos.x - 5, game->player->pos.y - 5);
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