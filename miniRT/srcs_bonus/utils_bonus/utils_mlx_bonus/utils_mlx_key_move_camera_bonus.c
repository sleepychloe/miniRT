/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_mlx_key_move_camera_bonus.c                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhwang <yhwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 03:20:39 by yhwang            #+#    #+#             */
/*   Updated: 2022/12/01 05:29:47 by yhwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs_bonus/miniRT_bonus.h"

void	mlx_move_camera_x(int key, t_data *data)
{
	int	flag;

	if (key == KEY_F1)
	{
		data->scene->camera->xyz_pos
			= vec3_add_vec3(data->scene->camera->xyz_pos,
				vec3(-1 * CAMERA_MOVE, 0, 0));
		flag = C_MOVE_X_MINUS;
		data->keep_scene->camera->xyz_pos.x -= CAMERA_MOVE;
	}
	if (key == KEY_F2)
	{
		data->scene->camera->xyz_pos
			= vec3_add_vec3(data->scene->camera->xyz_pos,
				vec3(CAMERA_MOVE, 0, 0));
		flag = C_MOVE_X_PLUS;
		data->keep_scene->camera->xyz_pos.x += CAMERA_MOVE;
	}
	rt_start(data, flag);
}

void	mlx_move_camera_y(int key, t_data *data)
{
	int	flag;

	if (key == KEY_F3)
	{
		data->scene->camera->xyz_pos
			= vec3_add_vec3(data->scene->camera->xyz_pos,
				vec3(0, -1 * CAMERA_MOVE, 0));
		flag = C_MOVE_Y_MINUS;
		data->keep_scene->camera->xyz_pos.y -= CAMERA_MOVE;
	}
	if (key == KEY_F4)
	{
		data->scene->camera->xyz_pos
			= vec3_add_vec3(data->scene->camera->xyz_pos,
				vec3(0, CAMERA_MOVE, 0));
		flag = C_MOVE_Y_PLUS;
		data->keep_scene->camera->xyz_pos.y += CAMERA_MOVE;
	}
	rt_start(data, flag);
}

void	mlx_move_camera_z(int key, t_data *data)
{
	int	flag;

	if (key == KEY_F5)
	{
		data->scene->camera->xyz_pos
			= vec3_add_vec3(data->scene->camera->xyz_pos,
				vec3(0, 0, -1 * CAMERA_MOVE));
		flag = C_MOVE_Z_MINUS;
		data->keep_scene->camera->xyz_pos.z -= CAMERA_MOVE;
	}
	if (key == KEY_F6)
	{
		data->scene->camera->xyz_pos
			= vec3_add_vec3(data->scene->camera->xyz_pos,
				vec3(0, 0, CAMERA_MOVE));
		flag = C_MOVE_Z_PLUS;
		data->keep_scene->camera->xyz_pos.z += CAMERA_MOVE;
	}
	rt_start(data, flag);
}

void	mlx_move_camera_zoom(int key, t_data *data)
{
	int	flag;

	if (key == KEY_UP)
	{
		data->scene->camera->xyz_pos
			= vec3_add_vec3(data->scene->camera->xyz_pos,
				vec3(0, 0, -1 * ZOOM));
		flag = C_MOVE_Z_MINUS;
		data->keep_scene->camera->xyz_pos.z -= ZOOM;
	}
	if (key == KEY_DOWN)
	{
		data->scene->camera->xyz_pos
			= vec3_add_vec3(data->scene->camera->xyz_pos,
				vec3(0, 0, ZOOM));
		flag = C_MOVE_Z_PLUS;
		data->keep_scene->camera->xyz_pos.z += ZOOM;
	}
	rt_start(data, flag);
}

void	mlx_move_camera(int key, t_data *data)
{
	if (key == KEY_F1 || key == KEY_F2)
		mlx_move_camera_x(key, data);
	if (key == KEY_F3 || key == KEY_F4)
		mlx_move_camera_y(key, data);
	if (key == KEY_F5 || key == KEY_F6)
		mlx_move_camera_z(key, data);
	if (key == KEY_UP || key == KEY_DOWN)
		mlx_move_camera_zoom(key, data);
}
