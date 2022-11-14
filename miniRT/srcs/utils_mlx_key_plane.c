/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_mlx_key_plane.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhwang <yhwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 01:34:32 by yhwang            #+#    #+#             */
/*   Updated: 2022/11/14 01:53:46 by yhwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/miniRT.h"

void	mlx_move_plane(int key, t_data *data)
{
	if (key == KEY_A)
		data->scene->plane[0]->xyz_pos
			= vec3_add_vec3(data->scene->plane[0]->xyz_pos, vec3(-0.5, 0, 0));
	if (key == KEY_S)
		data->scene->plane[0]->xyz_pos
			= vec3_add_vec3(data->scene->plane[0]->xyz_pos, vec3(0.5, 0, 0));
	if (key == KEY_D)
		data->scene->plane[0]->xyz_pos
			= vec3_add_vec3(data->scene->plane[0]->xyz_pos, vec3(0, -0.5, 0));
	if (key == KEY_F)
		data->scene->plane[0]->xyz_pos
			= vec3_add_vec3(data->scene->plane[0]->xyz_pos, vec3(0, 0.5, 0));
	if (key == KEY_G)
		data->scene->plane[0]->xyz_pos
			= vec3_add_vec3(data->scene->plane[0]->xyz_pos, vec3(0, 0, -0.5));
	if (key == KEY_H)
		data->scene->plane[0]->xyz_pos
			= vec3_add_vec3(data->scene->plane[0]->xyz_pos, vec3(0, 0, 0.5));
	rt_start(data);
}

void	mlx_rotate_plane_x_axis(t_data *data)
{
	double	val_cos;
	double	val_sin;

	val_cos = cos(PI / 6);
	val_sin = sqrt(1 - val_cos * val_cos);
	data->scene->plane[0]->xyz_vec
		= vec3(1 * data->scene->plane[0]->xyz_vec.x
			+ 0 * data->scene->plane[0]->xyz_vec.y
			+ 0 * data->scene->plane[0]->xyz_vec.z,
			0 * data->scene->plane[0]->xyz_vec.x
			+ val_cos * data->scene->plane[0]->xyz_vec.y
			+ -1 * val_sin * data->scene->plane[0]->xyz_vec.z,
			0 * data->scene->plane[0]->xyz_vec.x
			+ val_sin * data->scene->plane[0]->xyz_vec.y
			+ val_cos * data->scene->plane[0]->xyz_vec.z);
	data->scene->plane[0]->xyz_pos
		= vec3_add_vec3(data->scene->plane[0]->xyz_pos,
			vec3_mul_rn(data->scene->plane[0]->xyz_vec, 1));
	rt_start(data);
}

void	mlx_rotate_plane_y_axis(t_data *data)
{
	double	val_cos;
	double	val_sin;

	val_cos = cos(PI / 6);
	val_sin = sqrt(1 - val_cos * val_cos);
	data->scene->plane[0]->xyz_vec
		= vec3(val_cos * data->scene->plane[0]->xyz_vec.x
			+ 0 * data->scene->plane[0]->xyz_vec.y
			+ val_sin * data->scene->plane[0]->xyz_vec.z,
			0 * data->scene->plane[0]->xyz_vec.x
			+ 1 * data->scene->plane[0]->xyz_vec.y
			+ 0 * data->scene->plane[0]->xyz_vec.z,
			-1 * val_sin * data->scene->plane[0]->xyz_vec.x
			+ 0 * data->scene->plane[0]->xyz_vec.y
			+ val_cos * data->scene->plane[0]->xyz_vec.z);
	data->scene->plane[0]->xyz_pos
		= vec3_add_vec3(data->scene->plane[0]->xyz_pos,
			vec3_mul_rn(data->scene->plane[0]->xyz_vec, 1));
	rt_start(data);
}

void	mlx_rotate_plane_z_axis(t_data *data)
{
	double	val_cos;
	double	val_sin;

	val_cos = cos(PI / 6);
	val_sin = sqrt(1 - val_cos * val_cos);
	data->scene->plane[0]->xyz_vec
		= vec3(val_cos * data->scene->plane[0]->xyz_vec.x
			+ -1 * val_sin * data->scene->plane[0]->xyz_vec.y
			+ 0 * data->scene->plane[0]->xyz_vec.z,
			val_sin * data->scene->plane[0]->xyz_vec.x
			+ val_cos * data->scene->plane[0]->xyz_vec.y
			+ 0 * data->scene->plane[0]->xyz_vec.z,
			0 * data->scene->plane[0]->xyz_vec.x
			+ 0 * data->scene->plane[0]->xyz_vec.y
			+ 1 * data->scene->plane[0]->xyz_vec.z);
	data->scene->plane[0]->xyz_pos
		= vec3_add_vec3(data->scene->plane[0]->xyz_pos,
			vec3_mul_rn(data->scene->plane[0]->xyz_vec, 1));
	rt_start(data);
}

void	mlx_rotate_plane(int key, t_data *data)
{
	if (key == KEY_J)
		mlx_rotate_plane_x_axis(data);
	if (key == KEY_K)
		mlx_rotate_plane_y_axis(data);
	if (key == KEY_L)
		mlx_rotate_plane_z_axis(data);
}
