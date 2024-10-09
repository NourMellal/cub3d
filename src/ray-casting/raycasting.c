#include "../../include/shared.h"



int    display(t_game *game)
{
    draw_map(game);
    draw_personal_line(game);
    mlx_put_image_to_window(game->mlx->mlx, game->mlx->win, game->mlx->img, 0, 0);
    return 0;
}


