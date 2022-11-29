/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_mlx_key_rotate_plane_2.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhwang <yhwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 10:45:53 by yhwang            #+#    #+#             */
/*   Updated: 2022/11/29 10:48:55 by yhwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/miniRT.h"

void	mlx_rotate_plane_x_axis_set_keep_scene(t_data *data, int i,
				double val_cos, double val_sin)
{
	data->keep_scene->plane[i]->xyz_vec
		= vec3(1 * data->keep_scene->plane[i]->xyz_vec.x
			+ 0 * data->keep_scene->plane[i]->xyz_vec.y
			+ 0 * data->keep_scene->plane[i]->xyz_vec.z,
			0 * data->keep_scene->plane[i]->xyz_vec.x
			+ val_cos * data->keep_scene->plane[i]->xyz_vec.y
			+ -1 * val_sin * data->keep_scene->plane[i]->xyz_vec.z,
			0 * data->keep_scene->plane[i]->xyz_vec.x
			+ val_sin * data->keep_scene->plane[i]->xyz_vec.y
			+ val_cos * data->keep_scene->plane[i]->xyz_vec.z);
}

void	mlx_rotate_plane_y_axis_set_keep_scene(t_data *data, int i,
				double val_cos, double val_sin)
{
	data->keep_scene->plane[i]->xyz_vec
		= vec3(val_cos * data->keep_scene->plane[i]->xyz_vec.x
			+ 0 * data->keep_scene->plane[i]->xyz_vec.y
			+ val_sin * data->keep_scene->plane[i]->xyz_vec.z,
			0 * data->keep_scene->plane[i]->xyz_vec.x
			+ 1 * data->keep_scene->plane[i]->xyz_vec.y
			+ 0 * data->keep_scene->plane[i]->xyz_vec.z,
			-1 * val_sin * data->keep_scene->plane[i]->xyz_vec.x
			+ 0 * data->keep_scene->plane[i]->xyz_vec.y
			+ val_cos * data->keep_scene->plane[i]->xyz_vec.z);
}

void	mlx_rotate_plane_z_axis_set_keep_scene(t_data *data, int i,
				double val_cos, double val_sin)
{
	data->keep_scene->plane[i]->xyz_vec
		= vec3(val_cos * data->keep_scene->plane[i]->xyz_vec.x
			+ -1 * val_sin * data->keep_scene->plane[i]->xyz_vec.y
			+ 0 * data->keep_scene->plane[i]->xyz_vec.z,
			val_sin * data->keep_scene->plane[i]->xyz_vec.x
			+ val_cos * data->keep_scene->plane[i]->xyz_vec.y
			+ 0 * data->keep_scene->plane[i]->xyz_vec.z,
			0 * data->keep_scene->plane[i]->xyz_vec.x
			+ 0 * data->keep_scene->plane[i]->xyz_vec.y
			+ 1 * data->keep_scene->plane[i]->xyz_vec.z);
}
