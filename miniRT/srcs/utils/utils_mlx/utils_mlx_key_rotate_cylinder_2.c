/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_mlx_key_rotate_cylinder_2.c                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhwang <yhwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 10:46:09 by yhwang            #+#    #+#             */
/*   Updated: 2022/11/29 10:51:56 by yhwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/miniRT.h"

void	mlx_rotate_cylinder_x_axis_set_keep_scene(t_data *data, int i,
				double val_cos, double val_sin)
{
	data->keep_scene->cylinder[i]->xyz_vec
		= vec3(1 * data->keep_scene->cylinder[i]->xyz_vec.x
			+ 0 * data->keep_scene->cylinder[i]->xyz_vec.y
			+ 0 * data->keep_scene->cylinder[i]->xyz_vec.z,
			0 * data->keep_scene->cylinder[i]->xyz_vec.x
			+ val_cos * data->keep_scene->cylinder[i]->xyz_vec.y
			+ -1 * val_sin * data->keep_scene->cylinder[i]->xyz_vec.z,
			0 * data->keep_scene->cylinder[i]->xyz_vec.x
			+ val_sin * data->keep_scene->cylinder[i]->xyz_vec.y
			+ val_cos * data->keep_scene->cylinder[i]->xyz_vec.z);
}

void	mlx_rotate_cylinder_y_axis_set_keep_scene(t_data *data, int i,
				double val_cos, double val_sin)
{
	data->keep_scene->cylinder[i]->xyz_vec
		= vec3(val_cos * data->keep_scene->cylinder[i]->xyz_vec.x
			+ 0 * data->keep_scene->cylinder[i]->xyz_vec.y
			+ val_sin * data->keep_scene->cylinder[i]->xyz_vec.z,
			0 * data->keep_scene->cylinder[i]->xyz_vec.x
			+ 1 * data->keep_scene->cylinder[i]->xyz_vec.y
			+ 0 * data->keep_scene->cylinder[i]->xyz_vec.z,
			-1 * val_sin * data->keep_scene->cylinder[i]->xyz_vec.x
			+ 0 * data->keep_scene->cylinder[i]->xyz_vec.y
			+ val_cos * data->keep_scene->cylinder[i]->xyz_vec.z);
}

void	mlx_rotate_cylinder_z_axis_set_keep_scene(t_data *data, int i,
				double val_cos, double val_sin)
{
	data->keep_scene->cylinder[i]->xyz_vec
		= vec3(val_cos * data->keep_scene->cylinder[i]->xyz_vec.x
			+ -1 * val_sin * data->keep_scene->cylinder[i]->xyz_vec.y
			+ 0 * data->keep_scene->cylinder[i]->xyz_vec.z,
			val_sin * data->keep_scene->cylinder[i]->xyz_vec.x
			+ val_cos * data->keep_scene->cylinder[i]->xyz_vec.y
			+ 0 * data->keep_scene->cylinder[i]->xyz_vec.z,
			0 * data->keep_scene->cylinder[i]->xyz_vec.x
			+ 0 * data->keep_scene->cylinder[i]->xyz_vec.y
			+ 1 * data->keep_scene->cylinder[i]->xyz_vec.z);
}
