

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


typedef struct s_player
{
    double  angle;

} t_player;

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
    t_player            *player;
}   t_parse;

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



void    init_mlx_struct(t_mlx *mlx);
void    start_mlx(void);
void    draw_map(t_mlx *mlx);
void    my_mlx_pixel_put(t_mlx *mlx, int x, int y, int color);
void    put_player(t_mlx *mlx);
#endif