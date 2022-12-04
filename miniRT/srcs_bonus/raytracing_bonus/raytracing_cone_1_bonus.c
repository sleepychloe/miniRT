/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytracing_cone_1_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhwang <yhwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 17:54:17 by yhwang            #+#    #+#             */
/*   Updated: 2022/12/04 02:33:35 by yhwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs_bonus/miniRT_bonus.h"

t_vec3	calc_normal_vec_cone_body(t_data *data, int co_i)
{
	t_vec3	hit_normal;
	double	val_cos;
	double	val_sin;

	val_cos = data->obj[co_i]->height
		/ sqrt(((data->obj[co_i]->diameter) / 2)
			* ((data->obj[co_i]->diameter) / 2)
			+ data->obj[co_i]->height
			* data->obj[co_i]->height);
	val_sin = sqrt(1 - val_cos * val_cos);
	hit_normal
		= vec3(val_cos * data->obj[co_i]->xyz_vec.x
			+ -1 * val_sin * data->obj[co_i]->xyz_vec.y
			+ 0 * data->obj[co_i]->xyz_vec.z,
			val_sin * data->obj[co_i]->xyz_vec.x
			+ val_cos * data->obj[co_i]->xyz_vec.y
			+ 0 * data->obj[co_i]->xyz_vec.z,
			0 * data->obj[co_i]->xyz_vec.x
			+ 0 * data->obj[co_i]->xyz_vec.y
			+ 1 * data->obj[co_i]->xyz_vec.z);
	return (hit_normal);
}

int	hit_cone(t_data *data, t_hit *hit, int co_i, double distance)
{
	double	t_body;
	double	t_circle;

	if (data->obj[co_i]->obj_type != CONE)
		return (1);
	t_body = check_cone_body(data, co_i, distance);
	t_circle = check_cone_circle(data, co_i, distance);
	if (t_body == INFINITY && t_circle == INFINITY)
		return (1);
	if (t_body < t_circle)
	{
		set_hit_point(data, hit, t_body);
		hit->normal_vec = calc_normal_vec_cone_body(data, co_i);
		set_hit_normal_direc(data, hit);
	}
	else
	{
		set_hit_point(data, hit, t_circle);
		hit->normal_vec = data->obj[co_i]->xyz_vec;
		set_hit_normal_direc(data, hit);
	}
	hit->surface = data->obj[co_i]->surface;
	hit->fuzz = data->obj[co_i]->fuzz;
	hit->color = data->obj[co_i]->rgb1;
	return (0);
}

int	light_hit_co(t_data *data, int cy_i, double distance)
{
	double	t_body;
	double	t_circle;

	if (data->obj[cy_i]->obj_type != CONE)
		return (1);
	t_body = check_cone_body(data, cy_i, distance);
	t_circle = check_cone_circle(data, cy_i, distance);
	if (t_body == INFINITY && t_circle == INFINITY)
		return (1);
	return (0);
}
