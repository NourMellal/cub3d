#include "../../include/shared.h"


void    my_mlx_pixel_put(t_mlx *mlx, int x, int y, int color)
{
    char    *dst;

    dst = mlx->addr + (y * mlx->line_length + x * (mlx->bits_per_pixel / 8));
    *(unsigned int *)dst = color;
}

void    my_draw_direction(t_mlx *mlx, int px, int py, double angle)
{
    int len = 100;
    while (len)
    {
        my_mlx_pixel_put(mlx, px, py, GREEN);
        px += cos(angle);
        py -= sin(angle);
        len--;
    }
}

void    draw_personal_line(t_mlx *mlx)
{
    int start_x = (data()->pos[0] * SCALE) + SCALE / 2;  // J = 10
    int start_y = (data()->pos[1] * SCALE) + SCALE / 2;  // O = 15

    my_draw_direction(mlx, start_x, start_y, data()->player->angle);
}

void    set_player_angle(void)
{
    char c = data()->direction;
    if (c == 'N')
        data()->player->angle = M_PI_2;
    else if (c == 'E')
        data()->player->angle = 0;
    else if (c == 'W')
        data()->player->angle = PI;
    else
        data()->player->angle = 3 * M_PI_2;
}

void get_player_pos_and_dst(void)
{
    int i;
    int j;

    i = 0;
    while (i < data()->map_hight)
    {
        j = 0;
        while (j < data()->map_width)
        {
            if (data()->map[i][j] == 'N' || data()->map[i][j] == 'S' || data()->map[i][j] == 'E' || data()->map[i][j] == 'W')
            {
                data()->pos[0] = j;
                data()->pos[1] = i;
                data()->direction = data()->map[i][j];
                set_player_angle();
                puts("Player position found");
                return ;
            }
            j++;
        }
        i++;
    }
}

void    draw_player_as_square(t_mlx *mlx, int x, int y)
{
    int i;
    int j;

    i = 0;
    while (i < SCALE / 6)
    {
        j = 0;
        while (j < SCALE / 6)
        {
            my_mlx_pixel_put(mlx, x + i, y + j, RED);
            j++;
        }
        i++;
    }
}

void    put_player(t_mlx *mlx)
{
    get_player_pos_and_dst();
    int x = (data()->pos[0] * SCALE) + SCALE / 2;
    int y = (data()->pos[1] * SCALE) + SCALE / 2;
    draw_player_as_square(mlx, x - 5, y - 5);
}

void    draw_map(t_mlx *mlx)
{
    int x;
    int y;

    y = 0;
    while (y < data()->map_hight * SCALE)
    {
        
        x = 0;
        while (x < (data()->map_width * SCALE)-1)
        {
            if (x % SCALE == 0 || y % SCALE == 0)
                my_mlx_pixel_put(mlx, x, y, RED);
            else if (data()->map[y / SCALE][x / SCALE] == '1')
                my_mlx_pixel_put(mlx, x, y, BLACK);
            else
                my_mlx_pixel_put(mlx, x, y, WHITE);
            x++;
        }
        y++;
    }
}

void    init_mlx_struct(t_mlx *mlx)
{
    mlx->mlx = mlx_init();
    mlx->win = mlx_new_window(mlx->mlx, data()->map_width * SCALE, data()->map_hight * SCALE, "Cub3D");
    mlx->img = mlx_new_image(mlx->mlx, data()->map_width * SCALE, data()->map_hight * SCALE);
    mlx->addr = mlx_get_data_addr(mlx->img, &mlx->bits_per_pixel, &mlx->line_length, &mlx->endian);
}


int   key_press(int key)
{
    if (key == RIGHT_KEY)
        data()->player->angle -= 0.2;
    else if (key == LEFT_KEY)
        data()->player->angle += 0.2;
    return 0;
}
int    display(t_mlx *mlx)
{
    puts("here");
    draw_map(mlx);
    put_player(mlx);
    draw_personal_line(mlx);
    mlx_hook(mlx->win, 2, 1L << 0, key_press, &mlx);
    mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img, 0, 0);
    return 0;
}
int freexpm(t_mlx *mlx)
{
    int i = -1;
    while(++i < 4)
        free(mlx->texture[i]);
    mlx_destroy_image(mlx->mlx,mlx->img);
    mlx_destroy_window(mlx->mlx,mlx->win);
   mlx_destroy_display(mlx->mlx);
   free(mlx->mlx);
    return 1;
}
void xpmfile(t_mlx *mlx)
{
    void *tmp;
    int i = 0;
    int x;
    int y;

    while(i < 4)
    {
        tmp = mlx->texture[i];
        mlx->texture[i]=mlx_xpm_file_to_image(mlx->mlx,(char *)mlx->texture[i],&x,&y);
        free(tmp);
        if(!mlx->texture[i])
           {
             printf("Error\nin xpm file\n");
             exit(freexpm(mlx)+freefile(data()->map)+freeelement());
           }
    i++;
    }
}
void check_texture(t_mlx *mlx)
{
    int i =0;
    char **split;
    while(i <  4)
    {
        split = ft_splits(data()->elemets[i]);
        if(split[0][0] == 'N')
            mlx->texture[0]=ft_strdup(split[1]);
        else if(split[0][0] == 'S')
            mlx->texture[1]=ft_strdup(split[1]);
        else if(split[0][0] == 'W')
            mlx->texture[2]=ft_strdup(split[1]);
        else if(split[0][0] == 'E')
            mlx->texture[3]=ft_strdup(split[1]);
        freedouble(split);
    i++;
    }
    xpmfile(mlx);
}
void    start_mlx(void)
{
    t_mlx   mlx;

    init_mlx_struct(&mlx);
    check_texture(&mlx);
    display(&mlx);

    // mlx_loop_hook(&mlx.mlx, display, &mlx);
    mlx_loop(mlx.mlx);
}
