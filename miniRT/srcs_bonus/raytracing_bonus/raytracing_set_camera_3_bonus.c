/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytracing_set_camera_3_bonus.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhwang <yhwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 00:42:37 by yhwang            #+#    #+#             */
/*   Updated: 2022/12/21 00:51:45 by yhwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs_bonus/miniRT_bonus.h"

void	norminette_camera_vec_zeor_y_z(t_data *data,
				double val_cos, double val_sin)
{
	mlx_rotate_camera_x_axis_set_sp(data, val_cos, val_sin);
	mlx_rotate_camera_x_axis_set_pl(data, val_cos, val_sin);
	mlx_rotate_camera_x_axis_set_cy(data, val_cos, val_sin);
	mlx_rotate_camera_x_axis_set_co(data, val_cos, val_sin);
	mlx_rotate_camera_x_axis_set_l(data, val_cos, val_sin);
	mlx_rotate_camera_x_axis_set_norm_vec(data, val_cos, val_sin);
	data->scene->camera->xyz_pos
		= vec3(1 * data->scene->camera->xyz_pos.x
			+ 0 * data->scene->camera->xyz_pos.y
			+ 0 * data->scene->camera->xyz_pos.z,
			0 * data->scene->camera->xyz_pos.x
			+ val_cos * data->scene->camera->xyz_pos.y
			+ -1 * val_sin * data->scene->camera->xyz_pos.z,
			0 * data->scene->camera->xyz_pos.x
			+ val_sin * data->scene->camera->xyz_pos.y
			+ val_cos * data->scene->camera->xyz_pos.z);
}

void	camera_vec_zero_y_z(t_data *data)
{
	double	val_cos;
	double	val_sin;

	val_cos = cos(data->scene->camera->xyz_vec.y
			/ sqrt(data->scene->camera->xyz_vec.y
				* data->scene->camera->xyz_vec.y
				+ data->scene->camera->xyz_vec.z
				* data->scene->camera->xyz_vec.z));
	val_sin = sqrt(1 - val_cos * val_cos);
	if (data->scene->camera->xyz_vec.y < 0
		&& data->scene->camera->xyz_vec.z > 0)
		val_cos *= -1;
	if (data->scene->camera->xyz_vec.y > 0
		&& data->scene->camera->xyz_vec.z > 0)
	{
		val_cos *= -1;
		val_sin *= -1;
	}
	if (data->scene->camera->xyz_vec.y > 0
		&& data->scene->camera->xyz_vec.z < 0)
		val_sin *= -1;
	norminette_camera_vec_zeor_y_z(data, val_cos, val_sin);
}

void	norminette_camera_vec_x_zero_z(t_data *data,
				double val_cos, double val_sin)
{
	mlx_rotate_camera_y_axis_set_sp(data, val_cos, val_sin);
	mlx_rotate_camera_y_axis_set_pl(data, val_cos, val_sin);
	mlx_rotate_camera_y_axis_set_cy(data, val_cos, val_sin);
	mlx_rotate_camera_y_axis_set_co(data, val_cos, val_sin);
	mlx_rotate_camera_y_axis_set_l(data, val_cos, val_sin);
	mlx_rotate_camera_y_axis_set_norm_vec(data, val_cos, val_sin);
	data->scene->camera->xyz_pos
		= vec3(val_cos * data->scene->camera->xyz_pos.x
			+ 0 * data->scene->camera->xyz_pos.y
			+ val_sin * data->scene->camera->xyz_pos.z,
			0 * data->scene->camera->xyz_pos.x
			+ 1 * data->scene->camera->xyz_pos.y
			+ 0 * data->scene->camera->xyz_pos.z,
			-1 * val_sin * data->scene->camera->xyz_pos.x
			+ 0 * data->scene->camera->xyz_pos.y
			+ val_cos * data->scene->camera->xyz_pos.z);
}

void	camera_vec_x_zero_z(t_data *data)
{
	double	val_cos;
	double	val_sin;

	val_cos = cos(data->scene->camera->xyz_vec.z
			/ sqrt(data->scene->camera->xyz_vec.x
				* data->scene->camera->xyz_vec.x
				+ data->scene->camera->xyz_vec.z
				* data->scene->camera->xyz_vec.z));
	val_sin = sqrt(1 - val_cos * val_cos);
	if (data->scene->camera->xyz_vec.x > 0
		&& data->scene->camera->xyz_vec.z > 0)
		val_sin *= -1;
	if (data->scene->camera->xyz_vec.x < 0
		&& data->scene->camera->xyz_vec.z > 0)
	{
		val_cos *= -1;
		val_sin *= -1;
	}
	if (data->scene->camera->xyz_vec.x < 0
		&& data->scene->camera->xyz_vec.z < 0)
		val_sin *= -1;
	norminette_camera_vec_x_zero_z(data, val_sin, val_cos);
}
