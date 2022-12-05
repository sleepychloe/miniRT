/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytracing_cone_2_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhwang <yhwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 17:54:32 by yhwang            #+#    #+#             */
/*   Updated: 2022/12/05 07:47:48 by yhwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs_bonus/miniRT_bonus.h"

void	norminette_check_cone_body(t_data *data,
				int co_i, double *d, t_vec3 *top_center)
{
	double	delta;
	double	dot_rq_n;
	t_vec3	rq;
	double	val_cos;

	delta = data->obj[co_i]->height / 2
		* sqrt(1 / (data->obj[co_i]->xyz_vec.x * data->obj[co_i]->xyz_vec.x
				+ data->obj[co_i]->xyz_vec.y * data->obj[co_i]->xyz_vec.y
				+ data->obj[co_i]->xyz_vec.z * data->obj[co_i]->xyz_vec.z));
	*top_center
		= vec3(data->obj[co_i]->xyz_pos.x + delta * data->obj[co_i]->xyz_vec.x,
			data->obj[co_i]->xyz_pos.y + delta * data->obj[co_i]->xyz_vec.y,
			data->obj[co_i]->xyz_pos.z + delta * data->obj[co_i]->xyz_vec.z);
	rq = vec3_sub_vec3(*top_center, data->ray->point);
	dot_rq_n = vec3_dot_vec3(rq, data->obj[co_i]->xyz_vec);
	val_cos = data->obj[co_i]->height / sqrt((data->obj[co_i]->diameter / 2)
			* (data->obj[co_i]->diameter / 2)
			+ data->obj[co_i]->height * data->obj[co_i]->height);
	d[0] = vec3_dot_vec3(data->ray->direc, data->obj[co_i]->xyz_vec)
		* vec3_dot_vec3(data->ray->direc, data->obj[co_i]->xyz_vec)
		- vec3_dot_vec3(data->ray->direc, data->ray->direc) * val_cos * val_cos;
	d[1] = -1 * (dot_rq_n * vec3_dot_vec3(data->ray->direc,
				data->obj[co_i]->xyz_vec)
			- vec3_dot_vec3(rq, data->ray->direc) * val_cos * val_cos);
	d[2] = dot_rq_n * dot_rq_n - vec3_dot_vec3(rq, rq) * val_cos * val_cos;
}

int	check_cone_body_range(t_data *data,
				int co_i, t_vec3 top_center, t_vec3 hit_p)
{
	t_vec3	top_center_bottom_center;
	t_vec3	top_center_hit_p;
	t_vec3	bottom_center;
	double	delta;

	if (sqrt((hit_p.x - top_center.x) * (hit_p.x - top_center.x)
			+ (hit_p.y - top_center.y) * (hit_p.y - top_center.y)
			+ (hit_p.z - top_center.z) * (hit_p.z - top_center.z))
		> sqrt((data->obj[co_i]->diameter / 2) * (data->obj[co_i]->diameter / 2)
			+ data->obj[co_i]->height * data->obj[co_i]->height))
		return (1);
	delta = data->obj[co_i]->height / 2
		* sqrt(1 / (data->obj[co_i]->xyz_vec.x * data->obj[co_i]->xyz_vec.x
				+ data->obj[co_i]->xyz_vec.y * data->obj[co_i]->xyz_vec.y
				+ data->obj[co_i]->xyz_vec.z * data->obj[co_i]->xyz_vec.z));
	bottom_center
		= vec3(data->obj[co_i]->xyz_pos.x - delta * data->obj[co_i]->xyz_vec.x,
			data->obj[co_i]->xyz_pos.y - delta * data->obj[co_i]->xyz_vec.y,
			data->obj[co_i]->xyz_pos.z - delta * data->obj[co_i]->xyz_vec.z);
	top_center_bottom_center = vec3_sub_vec3(top_center, bottom_center);
	top_center_hit_p = vec3_sub_vec3(hit_p, top_center);
	if (vec3_dot_vec3(top_center_bottom_center, top_center_hit_p) > 0)
		return (1);
	return (0);
}

double	check_cone_body(t_data *data, int co_i, double distance)
{
	double	d[3];
	t_vec3	top_center;
	double	t_body;
	t_vec3	hit_p;

	norminette_check_cone_body(data, co_i, d, &top_center);
	if (d[1] * d[1] - d[0] * d[2] < 0)
		return (INFINITY);
	t_body = (-1 * d[1] + sqrt(d[1] * d[1] - d[0] * d[2])) / d[0];
	if (t_body < 0.00001 || distance < t_body)
	{
		t_body = (-1 * d[1] - sqrt(d[1] * d[1] - d[0] * d[2])) / d[0];
		if (t_body < 0.00001 || distance < t_body)
			return (INFINITY);
	}
	hit_p = vec3_add_vec3(data->ray->point,
			vec3_mul_rn(data->ray->direc, t_body));
	if (check_cone_body_range(data, co_i, top_center, hit_p))
		return (INFINITY);
	return (t_body);
}
