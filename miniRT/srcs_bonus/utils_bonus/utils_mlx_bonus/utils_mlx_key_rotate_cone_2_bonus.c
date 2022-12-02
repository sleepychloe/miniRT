/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_mlx_key_rotate_cone_2_bonus.c                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhwang <yhwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 01:29:30 by yhwang            #+#    #+#             */
/*   Updated: 2022/12/02 01:49:28 by yhwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs_bonus/miniRT_bonus.h"

void	mlx_rotate_cone_x_axis_set_keep_scene(t_data *data, int i,
				double val_cos, double val_sin)
{
	data->keep_scene->cone[i]->xyz_vec
		= vec3(1 * data->keep_scene->cone[i]->xyz_vec.x
			+ 0 * data->keep_scene->cone[i]->xyz_vec.y
			+ 0 * data->keep_scene->cone[i]->xyz_vec.z,
			0 * data->keep_scene->cone[i]->xyz_vec.x
			+ val_cos * data->keep_scene->cone[i]->xyz_vec.y
			+ -1 * val_sin * data->keep_scene->cone[i]->xyz_vec.z,
			0 * data->keep_scene->cone[i]->xyz_vec.x
			+ val_sin * data->keep_scene->cone[i]->xyz_vec.y
			+ val_cos * data->keep_scene->cone[i]->xyz_vec.z);
}

void	mlx_rotate_cone_y_axis_set_keep_scene(t_data *data, int i,
				double val_cos, double val_sin)
{
	data->keep_scene->cone[i]->xyz_vec
		= vec3(val_cos * data->keep_scene->cone[i]->xyz_vec.x
			+ 0 * data->keep_scene->cone[i]->xyz_vec.y
			+ val_sin * data->keep_scene->cone[i]->xyz_vec.z,
			0 * data->keep_scene->cone[i]->xyz_vec.x
			+ 1 * data->keep_scene->cone[i]->xyz_vec.y
			+ 0 * data->keep_scene->cone[i]->xyz_vec.z,
			-1 * val_sin * data->keep_scene->cone[i]->xyz_vec.x
			+ 0 * data->keep_scene->cone[i]->xyz_vec.y
			+ val_cos * data->keep_scene->cone[i]->xyz_vec.z);
}

void	mlx_rotate_cone_z_axis_set_keep_scene(t_data *data, int i,
				double val_cos, double val_sin)
{
	data->keep_scene->cone[i]->xyz_vec
		= vec3(val_cos * data->keep_scene->cone[i]->xyz_vec.x
			+ -1 * val_sin * data->keep_scene->cone[i]->xyz_vec.y
			+ 0 * data->keep_scene->cone[i]->xyz_vec.z,
			val_sin * data->keep_scene->cone[i]->xyz_vec.x
			+ val_cos * data->keep_scene->cone[i]->xyz_vec.y
			+ 0 * data->keep_scene->cone[i]->xyz_vec.z,
			0 * data->keep_scene->cone[i]->xyz_vec.x
			+ 0 * data->keep_scene->cone[i]->xyz_vec.y
			+ 1 * data->keep_scene->cone[i]->xyz_vec.z);
}
