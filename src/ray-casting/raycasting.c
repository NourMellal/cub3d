#include "../../include/shared.h"

void	setup_plane(t_game *game)
{	
	double	plane_width;

	plane_width = tan(R_FOV / 2);
	game->player->plane.x = -game->player->dir.y * plane_width;
	game->player->plane.y = game->player->dir.x * plane_width;
}
int    display(t_game *game)
{
    draw_map(game);
    draw_personal_line(game);
    mlx_put_image_to_window(game->mlx->mlx, game->mlx->win, game->mlx->img, 0, 0);
    return 0;
}


