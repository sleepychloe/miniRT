/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_mlx_key_rotate_camera_3.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhwang <yhwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 10:07:33 by yhwang            #+#    #+#             */
/*   Updated: 2022/11/29 10:55:04 by yhwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/miniRT.h"

void	mlx_rotate_camera_x_axis_set_keep_scene(t_data *data,
				double val_cos, double val_sin)
{
	data->keep_scene->camera->xyz_pos
		= vec3(1 * data->keep_scene->camera->xyz_pos.x
			+ 0 * data->keep_scene->camera->xyz_pos.y
			+ 0 * data->keep_scene->camera->xyz_pos.z,
			0 * data->keep_scene->camera->xyz_pos.x
			+ val_cos * data->keep_scene->camera->xyz_pos.y
			+ -1 * -1 * val_sin * data->keep_scene->camera->xyz_pos.z,
			0 * data->keep_scene->camera->xyz_pos.x
			+ -1 * val_sin * data->keep_scene->camera->xyz_pos.y
			+ val_cos * data->keep_scene->camera->xyz_pos.z);
	data->keep_scene->camera->xyz_vec = data->scene->camera->xyz_vec;
}

void	mlx_rotate_camera_y_axis_set_keep_scene(t_data *data,
				double val_cos, double val_sin)
{
	data->keep_scene->camera->xyz_pos
		= vec3(val_cos * data->keep_scene->camera->xyz_pos.x
			+ 0 * data->keep_scene->camera->xyz_pos.y
			+ -1 * val_sin * data->keep_scene->camera->xyz_pos.z,
			0 * data->keep_scene->camera->xyz_pos.x
			+ 1 * data->keep_scene->camera->xyz_pos.y
			+ 0 * data->keep_scene->camera->xyz_pos.z,
			-1 * -1 * val_sin * data->keep_scene->camera->xyz_pos.x
			+ 0 * data->keep_scene->camera->xyz_pos.y
			+ val_cos * data->keep_scene->camera->xyz_pos.z);
	data->keep_scene->camera->xyz_vec = data->scene->camera->xyz_vec;
}

void	mlx_rotate_camera_z_axis_set_keep_scene(t_data *data,
				double val_cos, double val_sin)
{
	data->keep_scene->camera->xyz_pos
		= vec3(val_cos * data->keep_scene->camera->xyz_pos.x
			+ -1 * -1 * val_sin * data->keep_scene->camera->xyz_pos.y
			+ 0 * data->keep_scene->camera->xyz_pos.z,
			-1 * val_sin * data->keep_scene->camera->xyz_pos.x
			+ val_cos * data->keep_scene->camera->xyz_pos.y
			+ 0 * data->keep_scene->camera->xyz_pos.z,
			0 * data->keep_scene->camera->xyz_pos.x
			+ 0 * data->keep_scene->camera->xyz_pos.y
			+ 1 * data->keep_scene->camera->xyz_pos.z);
	data->keep_scene->camera->xyz_vec = data->scene->camera->xyz_vec;
}
