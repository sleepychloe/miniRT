/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytracing_cylinder_checkerboard_1_bonus.c         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhwang <yhwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 22:57:21 by yhwang            #+#    #+#             */
/*   Updated: 2022/12/10 22:44:02 by yhwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs_bonus/miniRT_bonus.h"

void	cylinder_checkerboard_xy(t_data *data, t_hit *hit, int cy_i)
{
	t_vec3	pc;
	double	pc_length;
	double	theta;
	double	height;

	pc = vec3_sub_vec3(data->obj[cy_i]->xyz_pos, hit->hit_point);
	pc_length = sqrt(pc.x * pc.x + pc.y * pc.y + pc.z * pc.z);
	theta = atan2(hit->normal_vec.y, hit->normal_vec.x) + PI / 2;
	height = 10 + (sqrt(pc_length * pc_length - (data->obj[cy_i]->diameter / 2)
				* ((data->obj[cy_i]->diameter) / 2)));
	if (!(hit->normal_vec.x == data->obj[cy_i]->xyz_vec.x
			&& hit->normal_vec.y == data->obj[cy_i]->xyz_vec.y
			&& hit->normal_vec.z == data->obj[cy_i]->xyz_vec.z)
		&& !(hit->normal_vec.x == data->obj[cy_i]->xyz_vec.x * -1
			&& hit->normal_vec.y == data->obj[cy_i]->xyz_vec.y * -1
			&& hit->normal_vec.z == data->obj[cy_i]->xyz_vec.z * -1))
	{
		if (((int)(theta * PI) + (int)(height * PI)) % 2 == 0)
			hit->color = data->obj[cy_i]->rgb1;
		else
			hit->color = data->obj[cy_i]->rgb2;
	}
	else
		cylinder_circle_checkerboard_xy(data, hit, cy_i);
}

void	cylinder_checkerboard_zx(t_data *data, t_hit *hit, int cy_i)
{
	t_vec3	pc;
	double	pc_length;
	double	theta;
	double	height;

	pc = vec3_sub_vec3(data->obj[cy_i]->xyz_pos, hit->hit_point);
	pc_length = sqrt(pc.x * pc.x + pc.y * pc.y + pc.z * pc.z);
	theta = atan2(hit->normal_vec.x, hit->normal_vec.z) + PI / 2;
	height = 10 + (sqrt(pc_length * pc_length - (data->obj[cy_i]->diameter / 2)
				* ((data->obj[cy_i]->diameter) / 2)));
	if (!(hit->normal_vec.x == data->obj[cy_i]->xyz_vec.x
			&& hit->normal_vec.y == data->obj[cy_i]->xyz_vec.y
			&& hit->normal_vec.z == data->obj[cy_i]->xyz_vec.z)
		&& !(hit->normal_vec.x == data->obj[cy_i]->xyz_vec.x * -1
			&& hit->normal_vec.y == data->obj[cy_i]->xyz_vec.y * -1
			&& hit->normal_vec.z == data->obj[cy_i]->xyz_vec.z * -1))
	{
		if (((int)(theta * PI) + (int)(height * PI)) % 2 == 0)
			hit->color = data->obj[cy_i]->rgb1;
		else
			hit->color = data->obj[cy_i]->rgb2;
	}
	else
		cylinder_circle_checkerboard_zx(data, hit, cy_i);
}

void	cylinder_checkerboard_zy(t_data *data, t_hit *hit, int cy_i)
{
	t_vec3	pc;
	double	pc_length;
	double	theta;
	double	height;

	pc = vec3_sub_vec3(data->obj[cy_i]->xyz_pos, hit->hit_point);
	pc_length = sqrt(pc.x * pc.x + pc.y * pc.y + pc.z * pc.z);
	theta = atan2(hit->normal_vec.y, hit->normal_vec.z) + PI / 2;
	height = 10 + (sqrt(pc_length * pc_length - (data->obj[cy_i]->diameter / 2)
				* ((data->obj[cy_i]->diameter) / 2)));
	if (!(hit->normal_vec.x == data->obj[cy_i]->xyz_vec.x
			&& hit->normal_vec.y == data->obj[cy_i]->xyz_vec.y
			&& hit->normal_vec.z == data->obj[cy_i]->xyz_vec.z)
		&& !(hit->normal_vec.x == data->obj[cy_i]->xyz_vec.x * -1
			&& hit->normal_vec.y == data->obj[cy_i]->xyz_vec.y * -1
			&& hit->normal_vec.z == data->obj[cy_i]->xyz_vec.z * -1))
	{
		if (((int)(theta * PI) + (int)(height * PI)) % 2 == 0)
			hit->color = data->obj[cy_i]->rgb1;
		else
			hit->color = data->obj[cy_i]->rgb2;
	}
	else
		cylinder_circle_checkerboard_zy(data, hit, cy_i);
}

void	cylinder_checkerboard_norminette(t_data *data, t_hit *hit, int cy_i)
{
	if (fabs(data->obj[cy_i]->xyz_vec.y) > 0.7
		|| (fabs(data->obj[cy_i]->xyz_vec.x) != 0
			&& fabs(data->obj[cy_i]->xyz_vec.y) > 0.5
			&& fabs(data->obj[cy_i]->xyz_vec.z) > 0.7))
		cylinder_checkerboard_zx(data, hit, cy_i);
	else if (fabs(data->obj[cy_i]->xyz_vec.z) == 1
		|| fabs(data->obj[cy_i]->xyz_vec.z) > 0.7
		|| (fabs(data->obj[cy_i]->xyz_vec.y) > 0.6
			&& fabs(data->obj[cy_i]->xyz_vec.z) > 0.6))
		cylinder_checkerboard_xy(data, hit, cy_i);
	else
		cylinder_checkerboard_zy(data, hit, cy_i);
}

void	cylinder_checkerboard(t_data *data, t_hit *hit, int cy_i)
{
	if ((data->obj[cy_i]->xyz_vec.x != 1 && data->obj[cy_i]->xyz_vec.x != -1
			&& data->obj[cy_i]->xyz_vec.y != 0))
	{
		if (fabs(data->obj[cy_i]->xyz_vec.z) == 0)
			cylinder_checkerboard_zx(data, hit, cy_i);
		else if (fabs(data->obj[cy_i]->xyz_vec.x) == 0
			&& fabs(data->obj[cy_i]->xyz_vec.z) == 1)
			cylinder_checkerboard_xy(data, hit, cy_i);
		else if (fabs(data->obj[cy_i]->xyz_vec.x) != 0)
			cylinder_checkerboard_norminette(data, hit, cy_i);
		else
			cylinder_checkerboard_zx(data, hit, cy_i);
	}
	else
		cylinder_checkerboard_zy(data, hit, cy_i);
}
