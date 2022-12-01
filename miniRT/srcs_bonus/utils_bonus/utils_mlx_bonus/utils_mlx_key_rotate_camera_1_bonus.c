/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_mlx_key_rotate_camera_1_bonus.c              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhwang <yhwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 03:20:37 by yhwang            #+#    #+#             */
/*   Updated: 2022/12/01 05:31:51 by yhwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs_bonus/miniRT_bonus.h"

void	mlx_rotate_camera_x_axis(t_data *data, int flag,
				double val_cos, double val_sin)
{
	mlx_rotate_camera_x_axis_set_sp(data, val_cos, val_sin);
	mlx_rotate_camera_x_axis_set_pl(data, val_cos, val_sin);
	mlx_rotate_camera_x_axis_set_cy(data, val_cos, val_sin);
	mlx_rotate_camera_x_axis_set_l(data, val_cos, val_sin);
	data->scene->camera->xyz_vec
		= vec3(1 * data->scene->camera->xyz_vec.x
			+ 0 * data->scene->camera->xyz_vec.y
			+ 0 * data->scene->camera->xyz_vec.z,
			0 * data->scene->camera->xyz_vec.x
			+ val_cos * data->scene->camera->xyz_vec.y
			+ -1 * -1 * val_sin * data->scene->camera->xyz_vec.z,
			0 * data->scene->camera->xyz_vec.x
			+ -1 * val_sin * data->scene->camera->xyz_vec.y
			+ val_cos * data->scene->camera->xyz_vec.z);
	data->scene->camera->xyz_pos
		= vec3_add_vec3(data->scene->camera->xyz_pos,
			vec3_mul_rn(data->scene->camera->xyz_vec, 1e-10));
	mlx_rotate_camera_x_axis_set_norm_vec(data, val_cos, val_sin);
	mlx_rotate_camera_x_axis_set_keep_scene(data, val_cos, val_sin);
	rt_start(data, flag);
}

void	mlx_rotate_camera_y_axis(t_data *data, int flag,
				double val_cos, double val_sin)
{
	mlx_rotate_camera_y_axis_set_sp(data, val_cos, val_sin);
	mlx_rotate_camera_y_axis_set_pl(data, val_cos, val_sin);
	mlx_rotate_camera_y_axis_set_cy(data, val_cos, val_sin);
	mlx_rotate_camera_y_axis_set_l(data, val_cos, val_sin);
	data->scene->camera->xyz_vec
		= vec3(val_cos * data->scene->camera->xyz_vec.x
			+ 0 * data->scene->camera->xyz_vec.y
			+ -1 * val_sin * data->scene->camera->xyz_vec.z,
			0 * data->scene->camera->xyz_vec.x
			+ 1 * data->scene->camera->xyz_vec.y
			+ 0 * data->scene->camera->xyz_vec.z,
			-1 * -1 * val_sin * data->scene->camera->xyz_vec.x
			+ 0 * data->scene->camera->xyz_vec.y
			+ val_cos * data->scene->camera->xyz_vec.z);
	data->scene->camera->xyz_pos
		= vec3_add_vec3(data->scene->camera->xyz_pos,
			vec3_mul_rn(data->scene->camera->xyz_vec, 1e-10));
	mlx_rotate_camera_y_axis_set_norm_vec(data, val_cos, val_sin);
	mlx_rotate_camera_y_axis_set_keep_scene(data, val_cos, val_sin);
	rt_start(data, flag);
}

void	mlx_rotate_camera_z_axis(t_data *data, int flag,
				double val_cos, double val_sin)
{
	mlx_rotate_camera_z_axis_set_sp(data, val_cos, val_sin);
	mlx_rotate_camera_z_axis_set_pl(data, val_cos, val_sin);
	mlx_rotate_camera_z_axis_set_cy(data, val_cos, val_sin);
	mlx_rotate_camera_z_axis_set_l(data, val_cos, val_sin);
	data->scene->camera->xyz_vec
		= vec3(val_cos * data->scene->camera->xyz_vec.x
			+ -1 * -1 * val_sin * data->scene->camera->xyz_vec.y
			+ 0 * data->scene->camera->xyz_vec.z,
			-1 * val_sin * data->scene->camera->xyz_vec.x
			+ val_cos * data->scene->camera->xyz_vec.y
			+ 0 * data->scene->camera->xyz_vec.z,
			0 * data->scene->camera->xyz_vec.x
			+ 0 * data->scene->camera->xyz_vec.y
			+ 1 * data->scene->camera->xyz_vec.z);
	data->scene->camera->xyz_pos
		= vec3_add_vec3(data->scene->camera->xyz_pos,
			vec3_mul_rn(data->scene->camera->xyz_vec, 1e-10));
	mlx_rotate_camera_z_axis_set_norm_vec(data, val_cos, val_sin);
	mlx_rotate_camera_z_axis_set_keep_scene(data, val_cos, val_sin);
	rt_start(data, flag);
}

void	mlx_rotate_camera(int key, t_data *data)
{
	double	rad;
	double	val_cos;
	double	val_sin;

	rad = ROTATE_ANGLE * PI / 180;
	val_cos = cos(rad);
	val_sin = sqrt(1 - val_cos * val_cos);
	if (key == KEY_F7)
		mlx_rotate_camera_x_axis(data, C_ROTATE_X, val_cos, val_sin);
	if (key == KEY_F8)
		mlx_rotate_camera_y_axis(data, C_ROTATE_Y, val_cos, val_sin);
	if (key == KEY_F9)
		mlx_rotate_camera_z_axis(data, C_ROTATE_Z, val_cos, val_sin);
}
