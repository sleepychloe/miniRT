/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytracing_cone_checkerboard_2_bonus.c             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhwang <yhwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 22:12:53 by yhwang            #+#    #+#             */
/*   Updated: 2022/12/10 22:59:14 by yhwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs_bonus/miniRT_bonus.h"

void	cone_find_k(t_data *data, t_hit *hit, int co_i, double *k)
{
	double	delta;
	t_vec3	top_center;
	double	tan_theta;

	delta = data->obj[co_i]->height / 2
		* sqrt(1 / (data->obj[co_i]->xyz_vec.x * data->obj[co_i]->xyz_vec.x
				+ data->obj[co_i]->xyz_vec.y * data->obj[co_i]->xyz_vec.y
				+ data->obj[co_i]->xyz_vec.z * data->obj[co_i]->xyz_vec.z));
	top_center
		= vec3(data->obj[co_i]->xyz_pos.x + delta * data->obj[co_i]->xyz_vec.x,
			data->obj[co_i]->xyz_pos.y + delta * data->obj[co_i]->xyz_vec.y,
			data->obj[co_i]->xyz_pos.z + delta * data->obj[co_i]->xyz_vec.z);
	tan_theta = (data->obj[co_i]->diameter / 2) / data->obj[co_i]->height;
	*k = sqrt((hit->hit_point.x - top_center.x)
			* (hit->hit_point.x - top_center.x)
			+ (hit->hit_point.y - top_center.y)
			* (hit->hit_point.y - top_center.y)
			+ (hit->hit_point.z - top_center.z)
			* (hit->hit_point.z - top_center.z))
		* tan_theta;
}

void	cone_checkerboard_xy_zx_zy_norminette(t_data *data,
				t_hit *hit, int co_i, double *height)
{
	t_vec3	pc;
	double	pc_length;
	double	k;

	cone_find_k(data, hit, co_i, &k);
	pc = vec3_sub_vec3(data->obj[co_i]->xyz_pos, hit->hit_point);
	pc_length = sqrt(pc.x * pc.x + pc.y * pc.y + pc.z * pc.z);
	*height = 1.5 + sqrt(pc_length * pc_length + k * k);
	if (data->obj[co_i]->diameter >= data->obj[co_i]->height)
		*height = sqrt(pc_length * pc_length + k * k);
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
