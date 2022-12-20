/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytracing_set_camera_1_bonus.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhwang <yhwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 11:10:52 by yhwang            #+#    #+#             */
/*   Updated: 2022/12/20 09:37:17 by yhwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs_bonus/miniRT_bonus.h"

void	camera_vec_zero_zero_plusone(t_data *data)
{
	double	val_cos;
	double	val_sin;

	val_cos = cos(PI);
	val_sin = sin(PI);
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

void	camera_vec_minusone_zero_zero(t_data *data)
{
	double	val_cos;
	double	val_sin;

	val_cos = cos(3 * PI / 2);
	val_sin = sin(3 * PI / 2);
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

void	camera_vec_plusone_zero_zero(t_data *data)
{
	double	val_cos;
	double	val_sin;

	val_cos = cos(PI / 2);
	val_sin = sin(PI / 2);
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

void	raytracing_set_camera(t_data *data)
{
	if (data->keep_scene->camera->xyz_vec.x == 0
		&& data->keep_scene->camera->xyz_vec.y == 0
		&& data->keep_scene->camera->xyz_vec.z == 1)
		camera_vec_zero_zero_plusone(data);
	if (data->keep_scene->camera->xyz_vec.x == -1
		&& data->keep_scene->camera->xyz_vec.y == 0
		&& data->keep_scene->camera->xyz_vec.z == 0)
		camera_vec_minusone_zero_zero(data);
	if (data->keep_scene->camera->xyz_vec.x == 1
		&& data->keep_scene->camera->xyz_vec.y == 0
		&& data->keep_scene->camera->xyz_vec.z == 0)
		camera_vec_plusone_zero_zero(data);
	if (data->keep_scene->camera->xyz_vec.x == 0
		&& data->keep_scene->camera->xyz_vec.y == -1
		&& data->keep_scene->camera->xyz_vec.z == 0)
		camera_vec_zero_minusone_zero(data);
	if (data->keep_scene->camera->xyz_vec.x == 0
		&& data->keep_scene->camera->xyz_vec.y == 1
		&& data->keep_scene->camera->xyz_vec.z == 0)
		camera_vec_zero_plusone_zero(data);
	data->scene->camera->xyz_pos
		= vec3_add_vec3(data->scene->camera->xyz_pos,
			vec3_mul_rn(data->scene->camera->xyz_vec, DELTA));
}
