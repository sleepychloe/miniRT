/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_mlx_key_move_cone_bonus.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhwang <yhwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 01:21:58 by yhwang            #+#    #+#             */
/*   Updated: 2022/12/02 01:53:45 by yhwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs_bonus/miniRT_bonus.h"

void	mlx_move_cone_x(int key, t_data *data, int i)
{
	int	flag;

	if (key == KEY_1)
	{
		data->scene->cone[i]->xyz_pos
			= vec3_add_vec3(data->scene->cone[i]->xyz_pos,
				vec3_mul_rn(data->x_normal, -1 * OBJECT_MOVE));
		flag = CO_MOVE_X_MINUS;
		data->keep_scene->cone[i]->xyz_pos.x -= OBJECT_MOVE;
	}
	if (key == KEY_2)
	{
		data->scene->cone[i]->xyz_pos
			= vec3_add_vec3(data->scene->cone[i]->xyz_pos,
				vec3_mul_rn(data->x_normal, OBJECT_MOVE));
		flag = CO_MOVE_X_PLUS;
		data->keep_scene->cone[i]->xyz_pos.x += OBJECT_MOVE;
	}
	rt_start(data, flag);
}

void	mlx_move_cone_y(int key, t_data *data, int i)
{
	int	flag;

	if (key == KEY_3)
	{
		data->scene->cone[i]->xyz_pos
			= vec3_add_vec3(data->scene->cone[i]->xyz_pos,
				vec3_mul_rn(data->y_normal, -1 * OBJECT_MOVE));
		flag = CO_MOVE_Y_MINUS;
		data->keep_scene->cone[i]->xyz_pos.y -= OBJECT_MOVE;
	}
	if (key == KEY_4)
	{
		data->scene->cone[i]->xyz_pos
			= vec3_add_vec3(data->scene->cone[i]->xyz_pos,
				vec3_mul_rn(data->y_normal, OBJECT_MOVE));
		flag = CO_MOVE_Y_PLUS;
		data->keep_scene->cone[i]->xyz_pos.y += OBJECT_MOVE;
	}
	rt_start(data, flag);
}

void	mlx_move_cone_z(int key, t_data *data, int i)
{
	int	flag;

	if (key == KEY_5)
	{
		data->scene->cone[i]->xyz_pos
			= vec3_add_vec3(data->scene->cone[i]->xyz_pos,
				vec3_mul_rn(data->z_normal, -1 * OBJECT_MOVE));
		flag = CO_MOVE_Z_MINUS;
		data->keep_scene->cone[i]->xyz_pos.z -= OBJECT_MOVE;
	}
	if (key == KEY_6)
	{
		data->scene->cone[i]->xyz_pos
			= vec3_add_vec3(data->scene->cone[i]->xyz_pos,
				vec3_mul_rn(data->z_normal, OBJECT_MOVE));
		flag = CO_MOVE_Z_PLUS;
		data->keep_scene->cone[i]->xyz_pos.z += OBJECT_MOVE;
	}
	rt_start(data, flag);
}

void	mlx_move_cone(int key, t_data *data, int i)
{
	int	flag;

	if (key == KEY_1 || key == KEY_2)
		mlx_move_cone_x(key, data, i);
	if (key == KEY_3 || key == KEY_4)
		mlx_move_cone_y(key, data, i);
	if (key == KEY_5 || key == KEY_6)
		mlx_move_cone_z(key, data, i);
	if (key == KEY_GRAVE_ACCENT)
	{
		if (data->co == data->scene->n_cone - 1)
			data->co = 0;
		else
			data->co++;
		flag = CO_NEXT;
		rt_start(data, flag);
	}
}
