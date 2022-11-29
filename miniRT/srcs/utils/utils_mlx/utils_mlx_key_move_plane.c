/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_mlx_key_move_plane.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhwang <yhwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 03:57:39 by yhwang            #+#    #+#             */
/*   Updated: 2022/11/29 10:31:49 by yhwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/miniRT.h"

void	mlx_move_plane_x(int key, t_data *data, int i)
{
	int	flag;

	if (key == KEY_A)
	{
		data->scene->plane[i]->xyz_pos
			= vec3_add_vec3(data->scene->plane[i]->xyz_pos,
				vec3_mul_rn(data->x_normal, -1 * OBJECT_MOVE));
		flag = PL_MOVE_X_MINUS;
		data->keep_scene->plane[i]->xyz_pos.x -= OBJECT_MOVE;
	}
	if (key == KEY_S)
	{
		data->scene->plane[i]->xyz_pos
			= vec3_add_vec3(data->scene->plane[i]->xyz_pos,
				vec3_mul_rn(data->x_normal, OBJECT_MOVE));
		flag = PL_MOVE_X_PLUS;
		data->keep_scene->plane[i]->xyz_pos.x += OBJECT_MOVE;
	}
	rt_start(data, flag);
}

void	mlx_move_plane_y(int key, t_data *data, int i)
{
	int	flag;

	if (key == KEY_D)
	{
		data->scene->plane[i]->xyz_pos
			= vec3_add_vec3(data->scene->plane[i]->xyz_pos,
				vec3_mul_rn(data->y_normal, -1 * OBJECT_MOVE));
		flag = PL_MOVE_Y_MINUS;
		data->keep_scene->plane[i]->xyz_pos.y -= OBJECT_MOVE;
	}
	if (key == KEY_F)
	{
		data->scene->plane[i]->xyz_pos
			= vec3_add_vec3(data->scene->plane[i]->xyz_pos,
				vec3_mul_rn(data->y_normal, OBJECT_MOVE));
		flag = PL_MOVE_Y_PLUS;
		data->keep_scene->plane[i]->xyz_pos.y += OBJECT_MOVE;
	}
	rt_start(data, flag);
}

void	mlx_move_plane_z(int key, t_data *data, int i)
{
	int	flag;

	if (key == KEY_G)
	{
		data->scene->plane[i]->xyz_pos
			= vec3_add_vec3(data->scene->plane[i]->xyz_pos,
				vec3_mul_rn(data->z_normal, -1 * OBJECT_MOVE));
		flag = PL_MOVE_Z_MINUS;
		data->keep_scene->plane[i]->xyz_pos.z -= OBJECT_MOVE;
	}
	if (key == KEY_H)
	{
		data->scene->plane[i]->xyz_pos
			= vec3_add_vec3(data->scene->plane[i]->xyz_pos,
				vec3_mul_rn(data->z_normal, OBJECT_MOVE));
		flag = PL_MOVE_Z_PLUS;
		data->keep_scene->plane[i]->xyz_pos.z += OBJECT_MOVE;
	}
	rt_start(data, flag);
}

void	mlx_move_plane(int key, t_data *data, int i)
{
	int	flag;

	if (key == KEY_A || key == KEY_S)
		mlx_move_plane_x(key, data, i);
	if (key == KEY_D || key == KEY_F)
		mlx_move_plane_y(key, data, i);
	if (key == KEY_G || key == KEY_H)
		mlx_move_plane_z(key, data, i);
	if (key == KEY_F2)
	{
		if (data->pl == data->scene->n_plane - 1)
			data->pl = 0;
		else
			data->pl++;
		flag = PL_NEXT;
		rt_start(data, flag);
	}
}
