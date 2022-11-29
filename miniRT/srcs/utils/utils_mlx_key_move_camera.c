/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_mlx_key_move_camera.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhwang <yhwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 03:20:39 by yhwang            #+#    #+#             */
/*   Updated: 2022/11/29 03:31:59 by yhwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/miniRT.h"

void	mlx_move_camera_x(int key, t_data *data)
{
	int	flag;

	if (key == KEY_1)
		data->scene->camera->xyz_pos
			= vec3_add_vec3(data->scene->camera->xyz_pos,
				vec3(-1 * CAMERA_MOVE, 0, 0));
	if (key == KEY_2)
		data->scene->camera->xyz_pos
			= vec3_add_vec3(data->scene->camera->xyz_pos,
				vec3(CAMERA_MOVE, 0, 0));
	flag = 1;
	rt_start(data, flag);
}

void	mlx_move_camera_y(int key, t_data *data)
{
	int	flag;

	if (key == KEY_3)
		data->scene->camera->xyz_pos
			= vec3_add_vec3(data->scene->camera->xyz_pos,
				vec3(0, -1 * CAMERA_MOVE, 0));
	if (key == KEY_4)
		data->scene->camera->xyz_pos
			= vec3_add_vec3(data->scene->camera->xyz_pos,
				vec3(0, CAMERA_MOVE, 0));
	flag = 2;
	rt_start(data, flag);
}

void	mlx_move_camera_z(int key, t_data *data)
{
	int	flag;

	if (key == KEY_5)
		data->scene->camera->xyz_pos
			= vec3_add_vec3(data->scene->camera->xyz_pos,
				vec3(0, 0, -1 * CAMERA_MOVE));
	if (key == KEY_6)
		data->scene->camera->xyz_pos
			= vec3_add_vec3(data->scene->camera->xyz_pos,
				vec3(0, 0, CAMERA_MOVE));
	if (key == KEY_UP)
		data->scene->camera->xyz_pos
			= vec3_add_vec3(data->scene->camera->xyz_pos,
				vec3(0, 0, -1 * ZOOM));
	if (key == KEY_DOWN)
		data->scene->camera->xyz_pos
			= vec3_add_vec3(data->scene->camera->xyz_pos,
				vec3(0, 0, ZOOM));
	flag = 3;
	rt_start(data, flag);
}

void	mlx_move_camera(int key, t_data *data)
{
	if (key == KEY_1 || key == KEY_2)
		mlx_move_camera_x(key, data);
	if (key == KEY_3 || key == KEY_4)
		mlx_move_camera_y(key, data);
	if (key == KEY_5 || key == KEY_6 || key == KEY_UP || key == KEY_DOWN)
		mlx_move_camera_z(key, data);
}
