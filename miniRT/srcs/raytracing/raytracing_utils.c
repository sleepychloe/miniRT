/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytracing_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhwang <yhwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 22:13:16 by yhwang            #+#    #+#             */
/*   Updated: 2022/11/14 03:39:13 by yhwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/miniRT.h"

void	set_hit_point(t_ray ray_set, t_hit *hit, double t)
{
	hit->t = t;
	hit->hit_point = vec3_add_vec3(ray_set.point,
			vec3_mul_rn(ray_set.direc, t));
}

void	set_hit_normal_direc(t_ray ray_set, t_hit *hit)
{
	if (vec3_dot_vec3(ray_set.direc, hit->normal_vec) >= 0)
	{
		hit->front = BACK;
		hit->normal_vec = vec3_mul_rn(hit->normal_vec, -1);
	}
	hit->front = FRONT;
}
