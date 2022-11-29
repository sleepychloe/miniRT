/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_mlx_key_rotate_camera_x_2.c                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhwang <yhwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 01:43:59 by yhwang            #+#    #+#             */
/*   Updated: 2022/11/29 08:47:40 by yhwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/miniRT.h"

void	mlx_rotate_camera_x_axis_set_cy_vec(t_data *data,
				double val_cos, double val_sin, int i)
{
	data->scene->cylinder[i]->xyz_vec
		= vec3(1 * data->scene->cylinder[i]->xyz_vec.x
			+ 0 * data->scene->cylinder[i]->xyz_vec.y
			+ 0 * data->scene->cylinder[i]->xyz_vec.z,
			0 * data->scene->cylinder[i]->xyz_vec.x
			+ val_cos * data->scene->cylinder[i]->xyz_vec.y
			+ -1 * val_sin * data->scene->cylinder[i]->xyz_vec.z,
			0 * data->scene->cylinder[i]->xyz_vec.x
			+ val_sin * data->scene->cylinder[i]->xyz_vec.y
			+ val_cos * data->scene->cylinder[i]->xyz_vec.z);
}

void	mlx_rotate_camera_x_axis_set_cy(t_data *data,
				double val_cos, double val_sin)
{
	int	i;

	i = 0;
	while (i < data->scene->n_cylinder)
	{
		data->scene->cylinder[i]->xyz_pos
			= vec3(1 * data->scene->cylinder[i]->xyz_pos.x
				+ 0 * data->scene->cylinder[i]->xyz_pos.y
				+ 0 * data->scene->cylinder[i]->xyz_pos.z,
				0 * data->scene->cylinder[i]->xyz_pos.x
				+ val_cos * data->scene->cylinder[i]->xyz_pos.y
				+ -1 * val_sin * data->scene->cylinder[i]->xyz_pos.z,
				0 * data->scene->cylinder[i]->xyz_pos.x
				+ val_sin * data->scene->cylinder[i]->xyz_pos.y
				+ val_cos * data->scene->cylinder[i]->xyz_pos.z);
		mlx_rotate_camera_x_axis_set_cy_vec(data, val_cos, val_sin, i);
		data->scene->cylinder[i]->xyz_pos
			= vec3_add_vec3(data->scene->cylinder[i]->xyz_pos,
				vec3_mul_rn(data->scene->cylinder[i]->xyz_vec, 1e-10));
		i++;
	}
}

void	mlx_rotate_camera_x_axis_set_l(t_data *data,
				double val_cos, double val_sin)
{
	data->scene->light->xyz_pos
		= vec3(1 * data->scene->light->xyz_pos.x
			+ 0 * data->scene->light->xyz_pos.y
			+ 0 * data->scene->light->xyz_pos.z,
			0 * data->scene->light->xyz_pos.x
			+ val_cos * data->scene->light->xyz_pos.y
			+ -1 * val_sin * data->scene->light->xyz_pos.z,
			0 * data->scene->light->xyz_pos.x
			+ val_sin * data->scene->light->xyz_pos.y
			+ val_cos * data->scene->light->xyz_pos.z);
}
