/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytracing_cone_1_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhwang <yhwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 17:54:17 by yhwang            #+#    #+#             */
/*   Updated: 2022/12/18 06:42:24 by yhwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs_bonus/miniRT_bonus.h"

t_vec3	calc_normal_vec_cone_body(t_data *data, int co_i, double t_body)
{
	double	delta;
	double	cos_theta;
	t_vec3	top_center;
	t_vec3	hit_p;
	double	k;

	delta = data->obj[co_i]->height / 2
		* sqrt(1 / (data->obj[co_i]->xyz_vec.x * data->obj[co_i]->xyz_vec.x
				+ data->obj[co_i]->xyz_vec.y * data->obj[co_i]->xyz_vec.y
				+ data->obj[co_i]->xyz_vec.z * data->obj[co_i]->xyz_vec.z));
	top_center
		= vec3(data->obj[co_i]->xyz_pos.x + delta * data->obj[co_i]->xyz_vec.x,
			data->obj[co_i]->xyz_pos.y + delta * data->obj[co_i]->xyz_vec.y,
			data->obj[co_i]->xyz_pos.z + delta * data->obj[co_i]->xyz_vec.z);
	cos_theta = (data->obj[co_i]->height) / sqrt((data->obj[co_i]->diameter / 2)
			* (data->obj[co_i]->diameter / 2)
			+ data->obj[co_i]->height * data->obj[co_i]->height);
	hit_p = vec3_add_vec3(data->ray->point,
			vec3_mul_rn(data->ray->direc, t_body));
	k = sqrt((hit_p.x - top_center.x) * (hit_p.x - top_center.x)
			+ (hit_p.y - top_center.y) * (hit_p.y - top_center.y)
			+ (hit_p.z - top_center.z) * (hit_p.z - top_center.z)) / cos_theta;
	return (vec3_unit(vec3_sub_vec3(hit_p,
				vec3_sub_vec3(top_center,
					vec3_mul_rn(data->obj[co_i]->xyz_vec, k)))));
}

void	co_put_value_hit_struct(t_data *data, t_hit *hit, int co_i)
{
	hit->surface = data->obj[co_i]->surface;
	hit->fuzz = data->obj[co_i]->fuzz;
	if (data->obj[co_i]->surface == SURFACE_C)
		cone_checkerboard(data, hit, co_i);
	else if (data->obj[co_i]->surface == SURFACE_I)
		cone_img(data, hit, co_i);
	else
		hit->color = data->obj[co_i]->rgb1;
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
		hit->normal_vec = calc_normal_vec_cone_body(data, co_i, t_body);
		set_hit_normal_direc(data, hit);
	}
	else
	{
		set_hit_point(data, hit, t_circle);
		hit->normal_vec = vec3_mul_rn(data->obj[co_i]->xyz_vec, -1);
		set_hit_normal_direc(data, hit);
	}
	co_put_value_hit_struct(data, hit, co_i);
	return (0);
}

int	light_hit_co(t_data *data, int co_i, double distance)
{
	double	t_body;
	double	t_circle;

	if (data->obj[co_i]->obj_type != CONE)
		return (1);
	t_body = check_cone_body(data, co_i, distance);
	t_circle = check_cone_circle(data, co_i, distance);
	if (t_body == INFINITY && t_circle == INFINITY)
		return (1);
	return (0);
}
