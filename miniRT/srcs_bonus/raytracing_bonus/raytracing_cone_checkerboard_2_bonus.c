/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytracing_cone_checkerboard_2_bonus.c             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhwang <yhwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 22:12:53 by yhwang            #+#    #+#             */
/*   Updated: 2022/12/11 01:16:46 by yhwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs_bonus/miniRT_bonus.h"

void	cone_checkerboard_xy_zx_zy_norminette(t_data *data,
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

void	cone_checkerboard_xy(t_data *data, t_hit *hit, int co_i)
{
	double	theta;
	double	height;

	theta = atan2(hit->normal_vec.y, hit->normal_vec.x) + PI / 2;
	cone_checkerboard_xy_zx_zy_norminette(data, hit, co_i, &height);
	if (!(hit->normal_vec.x == data->obj[co_i]->xyz_vec.x
			&& hit->normal_vec.y == data->obj[co_i]->xyz_vec.y
			&& hit->normal_vec.z == data->obj[co_i]->xyz_vec.z)
		&& !(hit->normal_vec.x == data->obj[co_i]->xyz_vec.x * -1
			&& hit->normal_vec.y == data->obj[co_i]->xyz_vec.y * -1
			&& hit->normal_vec.z == data->obj[co_i]->xyz_vec.z * -1))
	{
		if (((int)(theta * PI) + (int)(height * PI)) % 2 == 0)
			hit->color = data->obj[co_i]->rgb1;
		else
			hit->color = data->obj[co_i]->rgb2;
	}
	else
		cone_circle_checkerboard_xy(data, hit, co_i);
}

void	cone_checkerboard_zx(t_data *data, t_hit *hit, int co_i)
{
	double	theta;
	double	height;

	theta = atan2(hit->normal_vec.x, hit->normal_vec.z) + PI / 2;
	cone_checkerboard_xy_zx_zy_norminette(data, hit, co_i, &height);
	if (!(hit->normal_vec.x == data->obj[co_i]->xyz_vec.x
			&& hit->normal_vec.y == data->obj[co_i]->xyz_vec.y
			&& hit->normal_vec.z == data->obj[co_i]->xyz_vec.z)
		&& !(hit->normal_vec.x == data->obj[co_i]->xyz_vec.x * -1
			&& hit->normal_vec.y == data->obj[co_i]->xyz_vec.y * -1
			&& hit->normal_vec.z == data->obj[co_i]->xyz_vec.z * -1))
	{
		if (((int)(theta * PI) + (int)(height * PI)) % 2 == 0)
			hit->color = data->obj[co_i]->rgb1;
		else
			hit->color = data->obj[co_i]->rgb2;
	}
	else
		cone_circle_checkerboard_zx(data, hit, co_i);
}

void	cone_checkerboard_zy(t_data *data, t_hit *hit, int co_i)
{
	double	theta;
	double	height;

	theta = atan2(hit->normal_vec.y, hit->normal_vec.z) + PI / 2;
	cone_checkerboard_xy_zx_zy_norminette(data, hit, co_i, &height);
	if (!(hit->normal_vec.x == data->obj[co_i]->xyz_vec.x
			&& hit->normal_vec.y == data->obj[co_i]->xyz_vec.y
			&& hit->normal_vec.z == data->obj[co_i]->xyz_vec.z)
		&& !(hit->normal_vec.x == data->obj[co_i]->xyz_vec.x * -1
			&& hit->normal_vec.y == data->obj[co_i]->xyz_vec.y * -1
			&& hit->normal_vec.z == data->obj[co_i]->xyz_vec.z * -1))
	{
		if (((int)(theta * PI) + (int)(height * PI)) % 2 == 0)
			hit->color = data->obj[co_i]->rgb1;
		else
			hit->color = data->obj[co_i]->rgb2;
	}
	else
		cone_circle_checkerboard_zy(data, hit, co_i);
}
