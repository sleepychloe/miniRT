/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_mlx_key_rotate_camera_z_2_bonus.c            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhwang <yhwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 01:56:05 by yhwang            #+#    #+#             */
/*   Updated: 2022/12/20 09:33:40 by yhwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs_bonus/miniRT_bonus.h"

void	mlx_rotate_camera_z_axis_set_cy_vec(t_data *data,
				double val_cos, double val_sin, int i)
{
	data->scene->cylinder[i]->xyz_vec
		= vec3(val_cos * data->scene->cylinder[i]->xyz_vec.x
			+ -1 * val_sin * data->scene->cylinder[i]->xyz_vec.y
			+ 0 * data->scene->cylinder[i]->xyz_vec.z,
			val_sin * data->scene->cylinder[i]->xyz_vec.x
			+ val_cos * data->scene->cylinder[i]->xyz_vec.y
			+ 0 * data->scene->cylinder[i]->xyz_vec.z,
			0 * data->scene->cylinder[i]->xyz_vec.x
			+ 0 * data->scene->cylinder[i]->xyz_vec.y
			+ 1 * data->scene->cylinder[i]->xyz_vec.z);
}

void	mlx_rotate_camera_z_axis_set_cy(t_data *data,
				double val_cos, double val_sin)
{
	int	i;

	i = 0;
	while (i < data->scene->n_cylinder)
	{
		data->scene->cylinder[i]->xyz_pos
			= vec3(val_cos * data->scene->cylinder[i]->xyz_pos.x
				+ -1 * val_sin * data->scene->cylinder[i]->xyz_pos.y
				+ 0 * data->scene->cylinder[i]->xyz_pos.z,
				val_sin * data->scene->cylinder[i]->xyz_pos.x
				+ val_cos * data->scene->cylinder[i]->xyz_pos.y
				+ 0 * data->scene->cylinder[i]->xyz_pos.z,
				0 * data->scene->cylinder[i]->xyz_pos.x
				+ 0 * data->scene->cylinder[i]->xyz_pos.y
				+ 1 * data->scene->cylinder[i]->xyz_pos.z);
		mlx_rotate_camera_z_axis_set_cy_vec(data, val_cos, val_sin, i);
		data->scene->cylinder[i]->xyz_pos
			= vec3_add_vec3(data->scene->cylinder[i]->xyz_pos,
				vec3_mul_rn(data->scene->cylinder[i]->xyz_vec, DELTA));
		i++;
	}
}

void	mlx_rotate_camera_z_axis_set_co_vec(t_data *data,
				double val_cos, double val_sin, int i)
{
	data->scene->cone[i]->xyz_vec
		= vec3(val_cos * data->scene->cone[i]->xyz_vec.x
			+ -1 * val_sin * data->scene->cone[i]->xyz_vec.y
			+ 0 * data->scene->cone[i]->xyz_vec.z,
			val_sin * data->scene->cone[i]->xyz_vec.x
			+ val_cos * data->scene->cone[i]->xyz_vec.y
			+ 0 * data->scene->cone[i]->xyz_vec.z,
			0 * data->scene->cone[i]->xyz_vec.x
			+ 0 * data->scene->cone[i]->xyz_vec.y
			+ 1 * data->scene->cone[i]->xyz_vec.z);
}

void	mlx_rotate_camera_z_axis_set_co(t_data *data,
				double val_cos, double val_sin)
{
	int	i;

	i = 0;
	while (i < data->scene->n_cone)
	{
		data->scene->cone[i]->xyz_pos
			= vec3(val_cos * data->scene->cone[i]->xyz_pos.x
				+ -1 * val_sin * data->scene->cone[i]->xyz_pos.y
				+ 0 * data->scene->cone[i]->xyz_pos.z,
				val_sin * data->scene->cone[i]->xyz_pos.x
				+ val_cos * data->scene->cone[i]->xyz_pos.y
				+ 0 * data->scene->cone[i]->xyz_pos.z,
				0 * data->scene->cone[i]->xyz_pos.x
				+ 0 * data->scene->cone[i]->xyz_pos.y
				+ 1 * data->scene->cone[i]->xyz_pos.z);
		mlx_rotate_camera_z_axis_set_co_vec(data, val_cos, val_sin, i);
		data->scene->cone[i]->xyz_pos
			= vec3_add_vec3(data->scene->cone[i]->xyz_pos,
				vec3_mul_rn(data->scene->cone[i]->xyz_vec, DELTA));
		i++;
	}
}

void	mlx_rotate_camera_z_axis_set_l(t_data *data,
				double val_cos, double val_sin)
{
	int	i;

	i = 0;
	while (i < data->scene->n_light)
	{
		data->scene->light[i]->xyz_pos
			= vec3(val_cos * data->scene->light[i]->xyz_pos.x
				+ -1 * val_sin * data->scene->light[i]->xyz_pos.y
				+ 0 * data->scene->light[i]->xyz_pos.z,
				val_sin * data->scene->light[i]->xyz_pos.x
				+ val_cos * data->scene->light[i]->xyz_pos.y
				+ 0 * data->scene->light[i]->xyz_pos.z,
				0 * data->scene->light[i]->xyz_pos.x
				+ 0 * data->scene->light[i]->xyz_pos.y
				+ 1 * data->scene->light[i]->xyz_pos.z);
		i++;
	}
}
