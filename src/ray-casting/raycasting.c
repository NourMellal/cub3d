#include "../../include/shared.h"


int    display(t_game *game)
{
    draw_map(game);
    draw_personal_line(game);
    mlx_put_image_to_window(game->mlx->mlx, game->mlx->win, game->mlx->img, 0, 0);
    return 0;
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
