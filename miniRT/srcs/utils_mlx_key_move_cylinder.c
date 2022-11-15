/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_mlx_key_move_cylinder.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhwang <yhwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 04:08:42 by yhwang            #+#    #+#             */
/*   Updated: 2022/11/15 04:35:03 by yhwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/miniRT.h"

void	mlx_move_cylinder_x(int key, t_data *data)
{
	int	flag;

	if (key == KEY_Q)
		data->scene->cylinder[0]->xyz_pos.x
			= data->scene->cylinder[0]->xyz_pos.x - 0.5;
	if (key == KEY_W)
		data->scene->cylinder[0]->xyz_pos.x
			= data->scene->cylinder[0]->xyz_pos.x + 0.5;
	flag = 15;
	rt_start(data, flag);
}

void	mlx_move_cylinder_y(int key, t_data *data)
{
	int	flag;

	if (key == KEY_E)
		data->scene->cylinder[0]->xyz_pos.y
			= data->scene->cylinder[0]->xyz_pos.y - 0.5;
	if (key == KEY_R)
		data->scene->cylinder[0]->xyz_pos.y
			= data->scene->cylinder[0]->xyz_pos.y + 0.5;
	flag = 16;
	rt_start(data, flag);
}

void	mlx_move_cylinder_z(int key, t_data *data)
{
	int	flag;

	if (key == KEY_T)
		data->scene->cylinder[0]->xyz_pos.z
			= data->scene->cylinder[0]->xyz_pos.z - 0.5;
	if (key == KEY_Y)
		data->scene->cylinder[0]->xyz_pos.z
			= data->scene->cylinder[0]->xyz_pos.z + 0.5;
	flag = 17;
	rt_start(data, flag);
}

void	mlx_move_cylinder(int key, t_data *data)
{
	if (key == KEY_Q || key == KEY_W)
		mlx_move_cylinder_x(key, data);
	if (key == KEY_E || key == KEY_R)
		mlx_move_cylinder_y(key, data);
	if (key == KEY_T || key == KEY_Y)
		mlx_move_cylinder_z(key, data);
}
