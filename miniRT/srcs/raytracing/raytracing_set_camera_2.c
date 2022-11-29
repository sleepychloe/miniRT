/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytracing_set_camera_2.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhwang <yhwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 12:02:58 by yhwang            #+#    #+#             */
/*   Updated: 2022/11/29 12:03:24 by yhwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/miniRT.h"

void	camera_vec_zero_minusone_zero(t_data *data)
{
	double	val_cos;
	double	val_sin;

	val_cos = cos(PI / 2);
	val_sin = sin(PI / 2);
	mlx_rotate_camera_x_axis_set_sp(data, val_cos, val_sin);
	mlx_rotate_camera_x_axis_set_pl(data, val_cos, val_sin);
	mlx_rotate_camera_x_axis_set_cy(data, val_cos, val_sin);
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

void	camera_vec_zero_plusone_zero(t_data *data)
{
	double	val_cos;
	double	val_sin;

	val_cos = cos(3 * PI / 2);
	val_sin = sin(3 * PI / 2);
	mlx_rotate_camera_x_axis_set_sp(data, val_cos, val_sin);
	mlx_rotate_camera_x_axis_set_pl(data, val_cos, val_sin);
	mlx_rotate_camera_x_axis_set_cy(data, val_cos, val_sin);
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
