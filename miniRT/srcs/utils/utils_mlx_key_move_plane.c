/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_mlx_key_move_plane.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhwang <yhwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 03:57:39 by yhwang            #+#    #+#             */
/*   Updated: 2022/11/15 04:01:21 by yhwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/miniRT.h"

void	mlx_move_plane_x(int key, t_data *data)
{
	int	flag;

	if (key == KEY_A)
		data->scene->plane[0]->xyz_pos
			= vec3_add_vec3(data->scene->plane[0]->xyz_pos, vec3(-0.5, 0, 0));
	if (key == KEY_S)
		data->scene->plane[0]->xyz_pos
			= vec3_add_vec3(data->scene->plane[0]->xyz_pos, vec3(0.5, 0, 0));
	flag = 11;
	rt_start(data, flag);
}

void	mlx_move_plane_y(int key, t_data *data)
{
	int	flag;

	if (key == KEY_D)
		data->scene->plane[0]->xyz_pos
			= vec3_add_vec3(data->scene->plane[0]->xyz_pos, vec3(0, -0.5, 0));
	if (key == KEY_F)
		data->scene->plane[0]->xyz_pos
			= vec3_add_vec3(data->scene->plane[0]->xyz_pos, vec3(0, 0.5, 0));
	flag = 12;
	rt_start(data, flag);
}

void	mlx_move_plane_z(int key, t_data *data)
{
	int	flag;

	if (key == KEY_G)
		data->scene->plane[0]->xyz_pos
			= vec3_add_vec3(data->scene->plane[0]->xyz_pos, vec3(0, 0, -0.5));
	if (key == KEY_H)
		data->scene->plane[0]->xyz_pos
			= vec3_add_vec3(data->scene->plane[0]->xyz_pos, vec3(0, 0, 0.5));
	flag = 13;
	rt_start(data, flag);
}

void	mlx_move_plane(int key, t_data *data)
{
	if (key == KEY_A || key == KEY_S)
		mlx_move_plane_x(key, data);
	if (key == KEY_D || key == KEY_F)
		mlx_move_plane_y(key, data);
	if (key == KEY_G || key == KEY_H)
		mlx_move_plane_z(key, data);
}
