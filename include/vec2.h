#ifndef VEC2_H
#define VEC2_H

 #include "shared.h"
typedef struct vec2
{
    double x;
    double y;
} t_vec2;


t_vec2	vec2_add_vec2(t_vec2 a, t_vec2 b);
t_vec2	 vec2_sub_vec2(t_vec2 a, t_vec2 b);
t_vec2	 	vec2_scale(t_vec2 a, double b);
t_vec2	 vec2_mul_vec2(t_vec2 a, t_vec2 b);
void	vec2_normalized(t_vec2 *vec);
void	vec2_rotate_vec2(t_vec2 *vec, double angle);
double vec2_to_angle(t_vec2 vec2);
double vec2_mag(t_vec2 vec);

#endif
// t_vec2 point;
// t_vec2 direction;
// t_vec2 u;

// t_vec target;

// pixel = 122;

// (122 / 1080) * 2 -1 = -0.88


// target = vec2_add_vec2(point, direction);
// target = vec2_add_vec2(target, vec2_scale(u, -0.88));

// 0 -> 1080
// 0 -> 1920
// (x / 1080) * 2 - 1
// (y / 1920)
// #ifndef