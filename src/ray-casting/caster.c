#include "raycasting.h"

t_vec3 vec3_scale(t_vec3 a, float s)
{
	a.x *= s;
	a.y *= s;
	a.z *= s;
	return a;
}

t_vec3 vec3_cross(t_vec3 a, t_vec3 b)
{
	t_vec3 result;

	result.x = (a.y * b.z) - (a.z * b.y);
	result.y = (a.z * b.x) - (a.x * b.z);
	result.z = (a.x * b.y) - (a.y * b.x);

	return result;
}

t_vec2 calculate_plane(t_vec2 dir)
{
    t_vec3 result;

    result = vec3_cross((t_vec3){dir.x, dir.y, 0}, (t_vec3){0, 0, 1});
    result = vec3_scale(result, sin((R_FOV / 2)));

    return (t_vec2) {result.x, result.y};
}