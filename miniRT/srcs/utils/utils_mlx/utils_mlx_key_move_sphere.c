/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_mlx_key_move_sphere.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhwang <yhwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 03:49:41 by yhwang            #+#    #+#             */
/*   Updated: 2022/11/29 10:29:46 by yhwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/miniRT.h"

void	mlx_move_sphere_x(int key, t_data *data, int i)
{
	int	flag;

	if (key == KEY_Z)
	{
		data->scene->sphere[i]->xyz_pos
			= vec3_add_vec3(data->scene->sphere[i]->xyz_pos,
				vec3_mul_rn(data->x_normal, -1 * OBJECT_MOVE));
		flag = SP_MOVE_X_MINUS;
		data->keep_scene->sphere[i]->xyz_pos.x -= OBJECT_MOVE;
	}
	if (key == KEY_X)
	{
		data->scene->sphere[i]->xyz_pos
			= vec3_add_vec3(data->scene->sphere[i]->xyz_pos,
				vec3_mul_rn(data->x_normal, OBJECT_MOVE));
		flag = SP_MOVE_X_PLUS;
		data->keep_scene->sphere[i]->xyz_pos.x += OBJECT_MOVE;
	}
	rt_start(data, flag);
}

void	mlx_move_sphere_y(int key, t_data *data, int i)
{
	int	flag;

	if (key == KEY_C)
	{
		data->scene->sphere[i]->xyz_pos
			= vec3_add_vec3(data->scene->sphere[i]->xyz_pos,
				vec3_mul_rn(data->y_normal, -1 * OBJECT_MOVE));
		flag = SP_MOVE_Y_MINUS;
		data->keep_scene->sphere[i]->xyz_pos.y -= OBJECT_MOVE;
	}
	if (key == KEY_V)
	{
		data->scene->sphere[i]->xyz_pos
			= vec3_add_vec3(data->scene->sphere[i]->xyz_pos,
				vec3_mul_rn(data->y_normal, OBJECT_MOVE));
		flag = SP_MOVE_Y_PLUS;
		data->keep_scene->sphere[i]->xyz_pos.y += OBJECT_MOVE;
	}
	rt_start(data, flag);
}

void	mlx_move_sphere_z(int key, t_data *data, int i)
{
	int	flag;

	if (key == KEY_B)
	{
		data->scene->sphere[i]->xyz_pos
			= vec3_add_vec3(data->scene->sphere[i]->xyz_pos,
				vec3_mul_rn(data->z_normal, -1 * OBJECT_MOVE));
		flag = SP_MOVE_Z_MINUS;
		data->keep_scene->sphere[i]->xyz_pos.z -= OBJECT_MOVE;
	}
	if (key == KEY_N)
	{
		data->scene->sphere[i]->xyz_pos
			= vec3_add_vec3(data->scene->sphere[i]->xyz_pos,
				vec3_mul_rn(data->z_normal, OBJECT_MOVE));
		flag = SP_MOVE_Z_PLUS;
		data->keep_scene->sphere[i]->xyz_pos.z += OBJECT_MOVE;
	}
	rt_start(data, flag);
}

void	mlx_move_sphere(int key, t_data *data, int i)
{
	int	flag;

	if (key == KEY_Z || key == KEY_X)
		mlx_move_sphere_x(key, data, i);
	if (key == KEY_C || key == KEY_V)
		mlx_move_sphere_y(key, data, i);
	if (key == KEY_B || key == KEY_N)
		mlx_move_sphere_z(key, data, i);
	if (key == KEY_F1)
	{
		if (data->sp == data->scene->n_sphere - 1)
			data->sp = 0;
		else
			data->sp++;
		flag = SP_NEXT;
		rt_start(data, flag);
	}
}
