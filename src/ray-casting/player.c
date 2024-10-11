/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmellal <nmellal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 12:45:50 by nmellal           #+#    #+#             */
/*   Updated: 2024/10/11 02:45:23 by nmellal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycasting.h"

double  degree_to_radian(double degree)
{
    return (degree * PI / 180);
}

double  radian_to_degree(double radian)
{
    return (radian * 180 / PI);
}

void    set_player_angle(t_game *game)
{
    if (game->parsing->direction == 'N')
        game->player->angle = degree_to_radian(90);
    else if (game->parsing->direction == 'S')
        game->player->angle = degree_to_radian(270);
    else if (game->parsing->direction == 'E')
		game->player->angle = 0;
    else if (game->parsing->direction == 'W') {
        game->player->angle = degree_to_radian(180);
	}
	game->player->dir.x = cos(game->player->angle);
	game->player->dir.y = sin(game->player->angle);
	vec2_normalized(&game->player->dir);
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
                game->player->pos.x = (double)(j + 0.5) * SCALE;
                game->player->pos.y = (double)(i + 0.5) * SCALE;
                game->parsing->direction = game->parsing->map[i][j];
                set_player_angle(game);

                return ;
            }
            j++;
        }
        i++;
    }
}