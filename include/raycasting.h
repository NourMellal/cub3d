

#ifndef RAYCASTING_H
#define RAYCASTING_H

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include "vec2.h"

#define MLX_ERROR "Error\nmlx failed to initialize\n"

#define GREY 0x808080
#define RED 0xFF0000
#define GREEN 0x00FF00
#define BLUE 0x0000FF
#define WHITE 0xFFFFFF
#define BLACK 0x000000
#define GREY 0x808080

// #define INFINITY 1e30
#define PI 3.14159265359
#define FOV 180
#define R_FOV 60 * M_PI / 180

#define SPEED 3

#define SCALE 30
#define MAP_SCALE 30

#define HEIGHT 600
#define WIDTH 900

#ifdef INPUT_MAC
#define LEFT_KEY 123
#define RIGHT_KEY 124
#define UP_KEY 126
#define DOWN_KEY 125
#define ESC_KEY 53
#else
#define LEFT_KEY 65361
#define RIGHT_KEY 65363
#define UP_KEY 65362
#define DOWN_KEY 65364
#define ESC_KEY 65307
#endif


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

typedef struct s_ray
{
	t_vec2 dir;

} t_ray;


typedef struct s_player
{
    double  angle;
	t_vec2	pos;
	t_vec2 dir;
	t_vec2 plane;
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
void    put_player(t_game *game);
double  degree_to_radian(double degree);
double  radian_to_degree(double radian);

int     key_press(int key, t_game *game);
t_mlx    *init_mlx_struct(t_game *game);
void    start_mlx(void);
void mlx_delete_image(void *mlx_ptr, void *img_ptr);
void    my_mlx_pixel_put(t_mlx *mlx, int x, int y, int color);
void	tmp_raycaster(t_game *game);

int     display(t_game *game);
void my_draw_direction(t_game *game, int px, int py, int px_end, int py_end, int color);
void    draw_map(t_game *game);
void    draw_square(t_game *game, int x, int y);
void    draw_personal_line(t_game *game);
void	setup_plane(t_game *game);
t_vec2	determine_first_xy_side(t_vec2 pos, int map_x, int map_y, t_vec2 delta_side, t_vec2 ray);
t_vec2 determine_xy_steps(t_vec2 raydir);

t_vec2 calculate_plane(t_vec2 dir);


#endif