/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_mlx_key_rotate_camera_y_1.c                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhwang <yhwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 01:47:03 by yhwang            #+#    #+#             */
/*   Updated: 2022/11/28 07:56:20 by yhwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/miniRT.h"

void	mlx_rotate_camera_y_axis_set_sp(t_data *data,
				double val_cos, double val_sin)
{
	int	i;

	i = 0;
	while (i < data->scene->n_sphere)
	{
		data->scene->sphere[i]->xyz_pos
			= vec3(val_cos * data->scene->sphere[i]->xyz_pos.x
				+ 0 * data->scene->sphere[i]->xyz_pos.y
				+ val_sin * data->scene->sphere[i]->xyz_pos.z,
				0 * data->scene->sphere[i]->xyz_pos.x
				+ 1 * data->scene->sphere[i]->xyz_pos.y
				+ 0 * data->scene->sphere[i]->xyz_pos.z,
				-1 * val_sin * data->scene->sphere[i]->xyz_pos.x
				+ 0 * data->scene->sphere[i]->xyz_pos.y
				+ val_cos * data->scene->sphere[i]->xyz_pos.z);
		i++;
	}
}

void	mlx_rotate_camera_y_axis_set_pl_vec(t_data *data,
				double val_cos, double val_sin, int i)
{
	data->scene->plane[i]->xyz_vec
		= vec3(val_cos * data->scene->plane[i]->xyz_vec.x
			+ 0 * data->scene->plane[i]->xyz_vec.y
			+ val_sin * data->scene->plane[i]->xyz_vec.z,
			0 * data->scene->plane[i]->xyz_vec.x
			+ 1 * data->scene->plane[i]->xyz_vec.y
			+ 0 * data->scene->plane[i]->xyz_vec.z,
			-1 * val_sin * data->scene->plane[i]->xyz_vec.x
			+ 0 * data->scene->plane[i]->xyz_vec.y
			+ val_cos * data->scene->plane[i]->xyz_vec.z);
}

void	mlx_rotate_camera_y_axis_set_pl(t_data *data,
				double val_cos, double val_sin)
{
	int	i;

	i = 0;
	while (i < data->scene->n_plane)
	{
		data->scene->plane[i]->xyz_pos
			= vec3(val_cos * data->scene->plane[i]->xyz_pos.x
				+ 0 * data->scene->plane[i]->xyz_pos.y
				+ val_sin * data->scene->plane[i]->xyz_pos.z,
				0 * data->scene->plane[i]->xyz_pos.x
				+ 1 * data->scene->plane[i]->xyz_pos.y
				+ 0 * data->scene->plane[i]->xyz_pos.z,
				-1 * val_sin * data->scene->plane[i]->xyz_pos.x
				+ 0 * data->scene->plane[i]->xyz_pos.y
				+ val_cos * data->scene->plane[i]->xyz_pos.z);
		mlx_rotate_camera_y_axis_set_pl_vec(data, val_cos, val_sin, i);
		data->scene->plane[i]->xyz_pos
			= vec3_add_vec3(data->scene->plane[i]->xyz_pos,
				vec3_mul_rn(data->scene->plane[i]->xyz_vec, 1e-10));
		i++;
	}
}
