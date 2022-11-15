/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_mlx_key_rotate_plane.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhwang <yhwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 03:57:13 by yhwang            #+#    #+#             */
/*   Updated: 2022/11/16 00:29:02 by yhwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/miniRT.h"

void	mlx_rotate_plane_x_axis(t_data *data, int flag, int i)
{
	double	val_cos;
	double	val_sin;

	val_cos = cos(PI / 6);
	val_sin = sqrt(1 - val_cos * val_cos);
	data->scene->plane[i]->xyz_vec
		= vec3(1 * data->scene->plane[i]->xyz_vec.x
			+ 0 * data->scene->plane[i]->xyz_vec.y
			+ 0 * data->scene->plane[i]->xyz_vec.z,
			0 * data->scene->plane[i]->xyz_vec.x
			+ val_cos * data->scene->plane[i]->xyz_vec.y
			+ -1 * val_sin * data->scene->plane[i]->xyz_vec.z,
			0 * data->scene->plane[i]->xyz_vec.x
			+ val_sin * data->scene->plane[i]->xyz_vec.y
			+ val_cos * data->scene->plane[i]->xyz_vec.z);
	data->scene->plane[i]->xyz_pos
		= vec3_add_vec3(data->scene->plane[i]->xyz_pos,
			vec3_mul_rn(data->scene->plane[i]->xyz_vec, 1));
	rt_start(data, flag);
}

void	mlx_rotate_plane_y_axis(t_data *data, int flag, int i)
{
	double	val_cos;
	double	val_sin;

	val_cos = cos(PI / 6);
	val_sin = sqrt(1 - val_cos * val_cos);
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
	data->scene->plane[i]->xyz_pos
		= vec3_add_vec3(data->scene->plane[i]->xyz_pos,
			vec3_mul_rn(data->scene->plane[i]->xyz_vec, 1));
	rt_start(data, flag);
}

void	mlx_rotate_plane_z_axis(t_data *data, int flag, int i)
{
	double	val_cos;
	double	val_sin;

	val_cos = cos(PI / 6);
	val_sin = sqrt(1 - val_cos * val_cos);
	data->scene->plane[i]->xyz_vec
		= vec3(val_cos * data->scene->plane[i]->xyz_vec.x
			+ -1 * val_sin * data->scene->plane[i]->xyz_vec.y
			+ 0 * data->scene->plane[i]->xyz_vec.z,
			val_sin * data->scene->plane[i]->xyz_vec.x
			+ val_cos * data->scene->plane[i]->xyz_vec.y
			+ 0 * data->scene->plane[i]->xyz_vec.z,
			0 * data->scene->plane[i]->xyz_vec.x
			+ 0 * data->scene->plane[i]->xyz_vec.y
			+ 1 * data->scene->plane[i]->xyz_vec.z);
	data->scene->plane[i]->xyz_pos
		= vec3_add_vec3(data->scene->plane[i]->xyz_pos,
			vec3_mul_rn(data->scene->plane[i]->xyz_vec, 1));
	rt_start(data, flag);
}

void	mlx_rotate_plane(int key, t_data *data, int i)
{
        int     flag;

        flag = 14;
	if (key == KEY_J)
		mlx_rotate_plane_x_axis(data, flag, i);
	if (key == KEY_K)
		mlx_rotate_plane_y_axis(data, flag, i);
	if (key == KEY_L)
		mlx_rotate_plane_z_axis(data, flag, i);
}