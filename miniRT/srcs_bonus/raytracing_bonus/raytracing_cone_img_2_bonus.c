/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytracing_cone_img_2_bonus.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhwang <yhwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 06:39:44 by yhwang            #+#    #+#             */
/*   Updated: 2022/12/18 07:35:30 by yhwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs_bonus/miniRT_bonus.h"

void	cone_img_xy_zx_zy_norminette(t_data *data,
				t_hit *hit, int co_i, double *height)
{
	double	delta;
	t_vec3	top_center;
	double	cos_theta;
	t_vec3	pq;
	double	length_pq;

	delta = data->obj[co_i]->height / 2
		* sqrt(1 / (data->obj[co_i]->xyz_vec.x * data->obj[co_i]->xyz_vec.x
				+ data->obj[co_i]->xyz_vec.y * data->obj[co_i]->xyz_vec.y
				+ data->obj[co_i]->xyz_vec.z * data->obj[co_i]->xyz_vec.z));
	top_center
		= vec3(data->obj[co_i]->xyz_pos.x + delta * data->obj[co_i]->xyz_vec.x,
			data->obj[co_i]->xyz_pos.y + delta * data->obj[co_i]->xyz_vec.y,
			data->obj[co_i]->xyz_pos.z + delta * data->obj[co_i]->xyz_vec.z);
	cos_theta = data->obj[co_i]->height
		/ sqrt(data->obj[co_i]->height * data->obj[co_i]->height
			+ (data->obj[co_i]->diameter / 2)
			* (data->obj[co_i]->diameter / 2));
	pq = vec3_sub_vec3(hit->hit_point, top_center);
	length_pq = sqrt(pq.x * pq.x + pq.y * pq.y + pq.z * pq.z);
	*height = (length_pq * cos_theta / data->obj[co_i]->height) * 2
		* (data->obj[co_i]->height / (data->obj[co_i]->diameter));
}

void	cone_img_xy(t_data *data, t_hit *hit, int co_i)
{
	double	theta;
	double	height;

	theta = atan2(hit->normal_vec.y, hit->normal_vec.x) + PI / 2;
	cone_img_xy_zx_zy_norminette(data, hit, co_i, &height);
	if (!(hit->normal_vec.x == data->obj[co_i]->xyz_vec.x
			&& hit->normal_vec.y == data->obj[co_i]->xyz_vec.y
			&& hit->normal_vec.z == data->obj[co_i]->xyz_vec.z)
		&& !(hit->normal_vec.x == data->obj[co_i]->xyz_vec.x * -1
			&& hit->normal_vec.y == data->obj[co_i]->xyz_vec.y * -1
			&& hit->normal_vec.z == data->obj[co_i]->xyz_vec.z * -1))
		hit->color = cone_img_mapping(data, co_i, theta, height);
	else
		hit->color = cone_circle_img_mapping(data, co_i,
				hit->hit_point.x, hit->hit_point.y);
}

void	cone_img_zx(t_data *data, t_hit *hit, int co_i)
{
	double	theta;
	double	height;

	theta = atan2(hit->normal_vec.x, hit->normal_vec.z) + PI / 2;
	cone_img_xy_zx_zy_norminette(data, hit, co_i, &height);
	if (!(hit->normal_vec.x == data->obj[co_i]->xyz_vec.x
			&& hit->normal_vec.y == data->obj[co_i]->xyz_vec.y
			&& hit->normal_vec.z == data->obj[co_i]->xyz_vec.z)
		&& !(hit->normal_vec.x == data->obj[co_i]->xyz_vec.x * -1
			&& hit->normal_vec.y == data->obj[co_i]->xyz_vec.y * -1
			&& hit->normal_vec.z == data->obj[co_i]->xyz_vec.z * -1))
		hit->color = cone_img_mapping(data, co_i, theta, height);
	else
		hit->color = cone_circle_img_mapping(data, co_i,
				hit->hit_point.x, -1 * (hit->hit_point.z));
}

void	cone_img_zy(t_data *data, t_hit *hit, int co_i)
{
	double	theta;
	double	height;

	theta = atan2(hit->normal_vec.y, hit->normal_vec.z) + PI / 2;
	cone_img_xy_zx_zy_norminette(data, hit, co_i, &height);
	if (!(hit->normal_vec.x == data->obj[co_i]->xyz_vec.x
			&& hit->normal_vec.y == data->obj[co_i]->xyz_vec.y
			&& hit->normal_vec.z == data->obj[co_i]->xyz_vec.z)
		&& !(hit->normal_vec.x == data->obj[co_i]->xyz_vec.x * -1
			&& hit->normal_vec.y == data->obj[co_i]->xyz_vec.y * -1
			&& hit->normal_vec.z == data->obj[co_i]->xyz_vec.z * -1))
		hit->color = cone_img_mapping(data, co_i, theta, height);
	else
		hit->color = cone_circle_img_mapping(data, co_i,
				hit->hit_point.z, hit->hit_point.y);
}
