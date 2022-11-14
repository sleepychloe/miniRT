/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_mlx_key_camera.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhwang <yhwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 22:42:02 by yhwang            #+#    #+#             */
/*   Updated: 2022/11/14 04:21:09 by yhwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/miniRT.h"

void	mlx_move_camera(int key, t_data *data)
{
	if (key == KEY_1)
		data->scene->camera->xyz_pos
			= vec3_add_vec3(data->scene->camera->xyz_pos, vec3(-1, 0, 0));
	if (key == KEY_2)
		data->scene->camera->xyz_pos
			= vec3_add_vec3(data->scene->camera->xyz_pos, vec3(1, 0, 0));
	if (key == KEY_3)
		data->scene->camera->xyz_pos
			= vec3_add_vec3(data->scene->camera->xyz_pos, vec3(0, -1, 0));
	if (key == KEY_4)
		data->scene->camera->xyz_pos
			= vec3_add_vec3(data->scene->camera->xyz_pos, vec3(0, 1, 0));
	if (key == KEY_5)
		data->scene->camera->xyz_pos
			= vec3_add_vec3(data->scene->camera->xyz_pos, vec3(0, 0, -1));
	if (key == KEY_6)
		data->scene->camera->xyz_pos
			= vec3_add_vec3(data->scene->camera->xyz_pos, vec3(0, 0, 1));
	if (key == KEY_UP)
		data->scene->camera->xyz_pos
			= vec3_add_vec3(data->scene->camera->xyz_pos, vec3(0, 0, -10));
	if (key == KEY_DOWN)
		data->scene->camera->xyz_pos
			= vec3_add_vec3(data->scene->camera->xyz_pos, vec3(0, 0, +10));
	rt_start(data);
}

void	mlx_rotate_camera_x_axis(t_data *data)
{
	double	val_cos;
	double	val_sin;

	val_cos = cos(PI / 6);
	val_sin = sqrt(1 - val_cos * val_cos);
	data->scene->camera->xyz_vec
		= vec3(1 * data->scene->camera->xyz_vec.x
			+ 0 * data->scene->camera->xyz_vec.y
			+ 0 * data->scene->camera->xyz_vec.z,
			0 * data->scene->camera->xyz_vec.x
			+ val_cos * data->scene->camera->xyz_vec.y
			+ -1 * val_sin * data->scene->camera->xyz_vec.z,
			0 * data->scene->camera->xyz_vec.x
			+ val_sin * data->scene->camera->xyz_vec.y
			+ val_cos * data->scene->camera->xyz_vec.z);
	data->scene->camera->xyz_pos
		= vec3_add_vec3(data->scene->camera->xyz_pos,
			vec3_mul_rn(data->scene->camera->xyz_vec, 1));
	rt_start(data);
}

void	mlx_rotate_camera_y_axis(t_data *data)
{
	double	val_cos;
	double	val_sin;

	val_cos = cos(PI / 6);
	val_sin = sqrt(1 - val_cos * val_cos);
	data->scene->camera->xyz_vec
		= vec3(val_cos * data->scene->camera->xyz_vec.x
			+ 0 * data->scene->camera->xyz_vec.y
			+ val_sin * data->scene->camera->xyz_vec.z,
			0 * data->scene->camera->xyz_vec.x
			+ 1 * data->scene->camera->xyz_vec.y
			+ 0 * data->scene->camera->xyz_vec.z,
			-1 * val_sin * data->scene->camera->xyz_vec.x
			+ 0 * data->scene->camera->xyz_vec.y
			+ val_cos * data->scene->camera->xyz_vec.z);
	data->scene->camera->xyz_pos
		= vec3_add_vec3(data->scene->camera->xyz_pos,
			vec3_mul_rn(data->scene->camera->xyz_vec, 1));
	rt_start(data);
}

void	mlx_rotate_camera_z_axis(t_data *data)
{
	double	val_cos;
	double	val_sin;

	val_cos = cos(PI / 6);
	val_sin = sqrt(1 - val_cos * val_cos);
	data->scene->camera->xyz_vec
		= vec3(val_cos * data->scene->camera->xyz_vec.x
			+ -1 * val_sin * data->scene->camera->xyz_vec.y
			+ 0 * data->scene->camera->xyz_vec.z,
			val_sin * data->scene->camera->xyz_vec.x
			+ val_cos * data->scene->camera->xyz_vec.y
			+ 0 * data->scene->camera->xyz_vec.z,
			0 * data->scene->camera->xyz_vec.x
			+ 0 * data->scene->camera->xyz_vec.y
			+ 1 * data->scene->camera->xyz_vec.z);
	data->scene->camera->xyz_pos
		= vec3_add_vec3(data->scene->camera->xyz_pos,
			vec3_mul_rn(data->scene->camera->xyz_vec, 1));
	rt_start(data);
}

void	mlx_rotate_camera(int key, t_data *data)
{
	if (key == KEY_7)
		mlx_rotate_camera_x_axis(data);
	if (key == KEY_8)
		mlx_rotate_camera_y_axis(data);
	if (key == KEY_9)
		mlx_rotate_camera_z_axis(data);
}
