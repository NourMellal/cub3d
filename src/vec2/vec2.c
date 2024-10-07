/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmellal <nmellal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 21:08:00 by nmellal           #+#    #+#             */
/*   Updated: 2024/10/04 21:29:22 by nmellal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vec2.h"

t_vec2 vec2_add_vec2(t_vec2 a, t_vec2 b)
{
    t_vec2 res;

    res.x = a.x + b.x;
    res.y = a.y + b.y;
    return (res);
}

t_vec2 vec2_sub_vec2(t_vec2 a, t_vec2 b)
{
    t_vec2 res;

    res.x = a.x - b.x;
    res.y = a.y - b.y;
    return (res);
}
t_vec2 vec2_mul_vec2(t_vec2 a, t_vec2 b)
{
    t_vec2 res;

    res.x = a.x * b.x;
    res.y = a.y * b.y;
    return (res);
}

t_vec2 vec2_scale(t_vec2 a, double b)
{
    t_vec2 res;

    res.x = a.x * b;
    res.y = a.y * b;
    return (res);
}
