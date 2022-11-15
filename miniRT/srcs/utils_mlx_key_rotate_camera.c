/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_mlx_key_rotate_camera.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhwang <yhwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 03:20:37 by yhwang            #+#    #+#             */
/*   Updated: 2022/11/15 03:41:05 by yhwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/miniRT.h"

void	mlx_rotate_camera_x_axis(t_data *data, int flag)
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
	rt_start(data, flag);
}

void	mlx_rotate_camera_y_axis(t_data *data, int flag)
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
	rt_start(data, flag);
}

void	mlx_rotate_camera_z_axis(t_data *data, int flag)
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
	rt_start(data, flag);
}

void	mlx_rotate_camera(int key, t_data *data)
{
	int	flag;

	flag = 4;
	if (key == KEY_7)
		mlx_rotate_camera_x_axis(data, flag);
	if (key == KEY_8)
		mlx_rotate_camera_y_axis(data, flag);
	if (key == KEY_9)
		mlx_rotate_camera_z_axis(data, flag);
}
