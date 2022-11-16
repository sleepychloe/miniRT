/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytracing_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhwang <yhwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 22:13:16 by yhwang            #+#    #+#             */
/*   Updated: 2022/11/16 21:44:09 by yhwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/miniRT.h"

void	set_hit_point(t_data *data, t_hit *hit, double t)
{
	hit->t = t;
	hit->hit_point = vec3_add_vec3(data->ray->point,
			vec3_mul_rn(data->ray->direc, t));
}

void	set_hit_normal_direc(t_data *data, t_hit *hit)
{
	if (vec3_dot_vec3(data->ray->direc, hit->normal_vec) >= 0)
	{
		hit->front = BACK;
		hit->normal_vec = vec3_mul_rn(hit->normal_vec, -1);
	}
	hit->front = FRONT;
}
