/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_mlx_key_rotate_cylinder.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhwang <yhwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 04:08:59 by yhwang            #+#    #+#             */
/*   Updated: 2022/11/15 04:35:50 by yhwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/miniRT.h"

void	mlx_rotate_cylinder_x_axis(t_data *data, int flag)
{
	double	val_cos;
	double	val_sin;

	val_cos = cos(PI / 6);
	val_sin = sqrt(1 - val_cos * val_cos);
	data->scene->cylinder[0]->xyz_vec
		= vec3(1 * data->scene->cylinder[0]->xyz_vec.x
			+ 0 * data->scene->cylinder[0]->xyz_vec.y
			+ 0 * data->scene->cylinder[0]->xyz_vec.z,
			0 * data->scene->cylinder[0]->xyz_vec.x
			+ val_cos * data->scene->cylinder[0]->xyz_vec.y
			+ -1 * val_sin * data->scene->cylinder[0]->xyz_vec.z,
			0 * data->scene->cylinder[0]->xyz_vec.x
			+ val_sin * data->scene->cylinder[0]->xyz_vec.y
			+ val_cos * data->scene->cylinder[0]->xyz_vec.z);
	data->scene->cylinder[0]->xyz_pos
		= vec3_add_vec3(data->scene->cylinder[0]->xyz_pos,
			vec3_mul_rn(data->scene->cylinder[0]->xyz_vec, 1));
	rt_start(data, flag);
}

void	mlx_rotate_cylinder_y_axis(t_data *data, int flag)
{
	double	val_cos;
	double	val_sin;

	val_cos = cos(PI / 6);
	val_sin = sqrt(1 - val_cos * val_cos);
	data->scene->cylinder[0]->xyz_vec
		= vec3(val_cos * data->scene->cylinder[0]->xyz_vec.x
			+ 0 * data->scene->cylinder[0]->xyz_vec.y
			+ val_sin * data->scene->cylinder[0]->xyz_vec.z,
			0 * data->scene->cylinder[0]->xyz_vec.x
			+ 1 * data->scene->cylinder[0]->xyz_vec.y
			+ 0 * data->scene->cylinder[0]->xyz_vec.z,
			-1 * val_sin * data->scene->cylinder[0]->xyz_vec.x
			+ 0 * data->scene->cylinder[0]->xyz_vec.y
			+ val_cos * data->scene->cylinder[0]->xyz_vec.z);
	data->scene->cylinder[0]->xyz_pos
		= vec3_add_vec3(data->scene->cylinder[0]->xyz_pos,
			vec3_mul_rn(data->scene->cylinder[0]->xyz_vec, 1));
	rt_start(data, flag);
}

void	mlx_rotate_cylinder_z_axis(t_data *data, int flag)
{
	double	val_cos;
	double	val_sin;

	val_cos = cos(PI / 6);
	val_sin = sqrt(1 - val_cos * val_cos);
	data->scene->cylinder[0]->xyz_vec
		= vec3(val_cos * data->scene->cylinder[0]->xyz_vec.x
			+ -1 * val_sin * data->scene->cylinder[0]->xyz_vec.y
			+ 0 * data->scene->cylinder[0]->xyz_vec.z,
			val_sin * data->scene->cylinder[0]->xyz_vec.x
			+ val_cos * data->scene->cylinder[0]->xyz_vec.y
			+ 0 * data->scene->cylinder[0]->xyz_vec.z,
			0 * data->scene->cylinder[0]->xyz_vec.x
			+ 0 * data->scene->cylinder[0]->xyz_vec.y
			+ 1 * data->scene->cylinder[0]->xyz_vec.z);
	data->scene->cylinder[0]->xyz_pos
		= vec3_add_vec3(data->scene->cylinder[0]->xyz_pos,
			vec3_mul_rn(data->scene->cylinder[0]->xyz_vec, 1));
	rt_start(data, flag);
}

void	mlx_rotate_cylinder(int key, t_data *data)
{
	int	flag;

	flag = 18;
	if (key == KEY_U)
		mlx_rotate_cylinder_x_axis(data, flag);
	if (key == KEY_I)
		mlx_rotate_cylinder_y_axis(data, flag);
	if (key == KEY_O)
		mlx_rotate_cylinder_z_axis(data, flag);
}
