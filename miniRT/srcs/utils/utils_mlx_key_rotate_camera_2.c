/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_mlx_key_rotate_camera_2.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhwang <yhwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 01:54:39 by yhwang            #+#    #+#             */
/*   Updated: 2022/11/29 02:08:10 by yhwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/miniRT.h"

void	mlx_rotate_camera_x_axis_set_norm_vec(t_data *data,
				double val_cos, double val_sin)
{
	data->x_normal = vec3(1 * data->x_normal.x + 0 * data->x_normal.y
			+ 0 * data->x_normal.z,
			0 * data->x_normal.x + val_cos * data->x_normal.y
			+ -1 * val_sin * data->x_normal.z,
			0 * data->x_normal.x + val_sin * data->x_normal.y
			+ val_cos * data->x_normal.z);
	data->y_normal = vec3(1 * data->y_normal.x + 0 * data->y_normal.y
			+ 0 * data->y_normal.z,
			0 * data->y_normal.x + val_cos * data->y_normal.y
			+ -1 * val_sin * data->y_normal.z,
			0 * data->y_normal.x + val_sin * data->y_normal.y
			+ val_cos * data->y_normal.z);
	data->z_normal = vec3(1 * data->z_normal.x + 0 * data->z_normal.y
			+ 0 * data->z_normal.z,
			0 * data->z_normal.x + val_cos * data->z_normal.y
			+ -1 * val_sin * data->z_normal.z,
			0 * data->z_normal.x + val_sin * data->z_normal.y
			+ val_cos * data->z_normal.z);
}

void	mlx_rotate_camera_y_axis_set_norm_vec(t_data *data,
				double val_cos, double val_sin)
{
	data->x_normal = vec3(val_cos * data->x_normal.x + 0 * data->x_normal.y
			+ val_sin * data->x_normal.z,
			0 * data->x_normal.x + 1 * data->x_normal.y
			+ 0* data->x_normal.z,
			-1 * val_sin * data->x_normal.x + 0 * data->x_normal.y
			+ val_cos * data->x_normal.z);
	data->y_normal = vec3(val_cos * data->y_normal.x + 0 * data->y_normal.y
			+ val_sin * data->y_normal.z,
			0 * data->y_normal.x + 1 * data->y_normal.y
			+ 0 * data->y_normal.z,
			-1 * val_sin * data->y_normal.x + 0 * data->y_normal.y
			+ val_cos * data->y_normal.z);
	data->z_normal = vec3(val_cos * data->z_normal.x + 0 * data->z_normal.y
			+ val_sin * data->z_normal.z,
			0 * data->z_normal.x + 1 * data->z_normal.y
			+ 0 * data->z_normal.z,
			-1 * data->z_normal.x + 0 * data->z_normal.y
			+ val_cos * data->z_normal.z);
}

void	mlx_rotate_camera_z_axis_set_norm_vec(t_data *data,
				double val_cos, double val_sin)
{
	data->x_normal = vec3(val_cos * data->x_normal.x + -1 * val_sin * data->x_normal.y
			+ 0 * data->x_normal.z,
			val_sin * data->x_normal.x + val_cos * data->x_normal.y
			+ 0 * data->x_normal.z,
			0 * data->x_normal.x + 0 * data->x_normal.y
			+ 1 * data->x_normal.z);
	data->y_normal = vec3(val_cos * data->y_normal.x + -1 * val_sin * data->y_normal.y
			+ 0 * data->y_normal.z,
			val_sin * data->y_normal.x + val_cos * data->y_normal.y
			+ 0 * data->y_normal.z,
			0 * data->y_normal.x + 0 * data->y_normal.y
			+ 1 * data->y_normal.z);
	data->z_normal = vec3(val_cos * data->z_normal.x + -1 * val_sin * data->z_normal.y
			+ 0 * data->z_normal.z,
			val_sin * data->z_normal.x + val_cos * data->z_normal.y
			+ 0 * data->z_normal.z,
			0 * data->z_normal.x + 0 * data->z_normal.y
			+ 1 * data->z_normal.z);
}
