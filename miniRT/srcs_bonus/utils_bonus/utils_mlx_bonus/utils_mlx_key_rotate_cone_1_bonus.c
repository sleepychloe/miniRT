/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_mlx_key_rotate_cone_1_bonus.c                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhwang <yhwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 01:29:13 by yhwang            #+#    #+#             */
/*   Updated: 2022/12/20 09:34:00 by yhwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs_bonus/miniRT_bonus.h"

void	mlx_rotate_cone_x_axis(t_data *data, int flag, int i)
{
	double	rad;
	double	val_cos;
	double	val_sin;

	rad = ROTATE_ANGLE * PI / 180;
	val_cos = cos(rad);
	val_sin = sqrt(1 - val_cos * val_cos);
	data->scene->cone[i]->xyz_vec
		= vec3(1 * data->scene->cone[i]->xyz_vec.x
			+ 0 * data->scene->cone[i]->xyz_vec.y
			+ 0 * data->scene->cone[i]->xyz_vec.z,
			0 * data->scene->cone[i]->xyz_vec.x
			+ val_cos * data->scene->cone[i]->xyz_vec.y
			+ -1 * val_sin * data->scene->cone[i]->xyz_vec.z,
			0 * data->scene->cone[i]->xyz_vec.x
			+ val_sin * data->scene->cone[i]->xyz_vec.y
			+ val_cos * data->scene->cone[i]->xyz_vec.z);
	data->scene->cone[i]->xyz_pos
		= vec3_add_vec3(data->scene->cone[i]->xyz_pos,
			vec3_mul_rn(data->scene->cone[i]->xyz_vec, DELTA));
	mlx_rotate_cone_x_axis_set_keep_scene(data, i, val_cos, val_sin);
	rt_start(data, flag);
}

void	mlx_rotate_cone_y_axis(t_data *data, int flag, int i)
{
	double	rad;
	double	val_cos;
	double	val_sin;

	rad = ROTATE_ANGLE * PI / 180;
	val_cos = cos(rad);
	val_sin = sqrt(1 - val_cos * val_cos);
	data->scene->cone[i]->xyz_vec
		= vec3(val_cos * data->scene->cone[i]->xyz_vec.x
			+ 0 * data->scene->cone[i]->xyz_vec.y
			+ val_sin * data->scene->cone[i]->xyz_vec.z,
			0 * data->scene->cone[i]->xyz_vec.x
			+ 1 * data->scene->cone[i]->xyz_vec.y
			+ 0 * data->scene->cone[i]->xyz_vec.z,
			-1 * val_sin * data->scene->cone[i]->xyz_vec.x
			+ 0 * data->scene->cone[i]->xyz_vec.y
			+ val_cos * data->scene->cone[i]->xyz_vec.z);
	data->scene->cone[i]->xyz_pos
		= vec3_add_vec3(data->scene->cone[i]->xyz_pos,
			vec3_mul_rn(data->scene->cone[i]->xyz_vec, DELTA));
	mlx_rotate_cone_y_axis_set_keep_scene(data, i, val_cos, val_sin);
	rt_start(data, flag);
}

void	mlx_rotate_cone_z_axis(t_data *data, int flag, int i)
{
	double	rad;
	double	val_cos;
	double	val_sin;

	rad = ROTATE_ANGLE * PI / 180;
	val_cos = cos(rad);
	val_sin = sqrt(1 - val_cos * val_cos);
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
	data->scene->cone[i]->xyz_pos
		= vec3_add_vec3(data->scene->cone[i]->xyz_pos,
			vec3_mul_rn(data->scene->cone[i]->xyz_vec, DELTA));
	mlx_rotate_cone_z_axis_set_keep_scene(data, i, val_cos, val_sin);
	rt_start(data, flag);
}

void	mlx_rotate_cone(int key, t_data *data, int i)
{
	if (key == KEY_7)
		mlx_rotate_cone_x_axis(data, CO_ROTATE_X, i);
	if (key == KEY_8)
		mlx_rotate_cone_y_axis(data, CO_ROTATE_Y, i);
	if (key == KEY_9)
		mlx_rotate_cone_z_axis(data, CO_ROTATE_Z, i);
}
