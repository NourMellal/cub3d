

#ifndef RAYCASTING_H
#define RAYCASTING_H

#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#define MLX_ERROR "Error\nmlx failed to initialize\n"

#define GREY 0x808080
#define RED 0xFF0000
#define GREEN 0x00FF00
#define BLUE 0x0000FF
#define WHITE 0xFFFFFF
#define BLACK 0x000000

#define PI 3.14159265359

#define SCALE 60

#define HEIGHT 600
#define WIDTH 800


#define LEFT_KEY 65361
#define RIGHT_KEY 65363
#define UP_KEY 65362
#define DOWN_KEY 65364
#define ESC_KEY 65307



typedef struct					s_parse
{
	size_t 				longest;
	int					map_hight;
	int					map_width;
	char				**file;
	char				**map;
	int					pos[2];
	int					fd;
	int					lines;
	char				*elemets[6];
	char				direction;
	int					mapcolor[2][3];
}   t_parse;


typedef struct s_player
{
    double  angle;
    double  x;
    double  y;

} t_player;


typedef struct s_mlx
{
    void    *mlx;
    void    *win;
    void    *img;
    char    *addr;
    int     bits_per_pixel;
    int     line_length;
    int     endian;
    int     width;
    int     height;
}          t_mlx;

typedef struct s_game
{
    t_parse *parsing;
    t_mlx   *mlx;
    t_player    *player;
}   t_game;

t_parse	*data(void);
void    set_player_angle(t_game *game);
void    get_player_pos_and_dst(t_game *game);
void    draw_player_as_square(t_game *game, int x, int y);
void    put_player(t_game *game);
void    draw_map(t_game *game);
int     key_press(int key, t_game *game);
int     display(t_game *game);
t_mlx    *init_mlx_struct(t_game *game);
void    my_mlx_pixel_put(t_mlx *mlx, int x, int y, int color);
void    draw_personal_line(t_game *game);
void    start_mlx(void);

#endif