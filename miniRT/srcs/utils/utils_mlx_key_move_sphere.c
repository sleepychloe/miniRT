/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_mlx_key_move_sphere.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhwang <yhwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 03:49:41 by yhwang            #+#    #+#             */
/*   Updated: 2022/11/15 03:55:50 by yhwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/miniRT.h"

void	mlx_move_sphere_x(int key, t_data *data)
{
	int	flag;

	if (key == KEY_Z)
		data->scene->sphere[0]->xyz_pos
			= vec3_add_vec3(data->scene->sphere[0]->xyz_pos, vec3(-0.5, 0, 0));
	if (key == KEY_X)
		data->scene->sphere[0]->xyz_pos
			= vec3_add_vec3(data->scene->sphere[0]->xyz_pos, vec3(0.5, 0, 0));
	flag = 8;
	rt_start(data, flag);
}

void	mlx_move_sphere_y(int key, t_data *data)
{
	int	flag;

	if (key == KEY_C)
		data->scene->sphere[0]->xyz_pos
			= vec3_add_vec3(data->scene->sphere[0]->xyz_pos, vec3(0, -0.5, 0));
	if (key == KEY_V)
		data->scene->sphere[0]->xyz_pos
			= vec3_add_vec3(data->scene->sphere[0]->xyz_pos, vec3(0, 0.5, 0));
	flag = 9;
	rt_start(data, flag);
}

void	mlx_move_sphere_z(int key, t_data *data)
{
	int	flag;

	if (key == KEY_B)
		data->scene->sphere[0]->xyz_pos
			= vec3_add_vec3(data->scene->sphere[0]->xyz_pos, vec3(0, 0, -0.5));
	if (key == KEY_N)
		data->scene->sphere[0]->xyz_pos
			= vec3_add_vec3(data->scene->sphere[0]->xyz_pos, vec3(0, 0, 0.5));
	flag = 10;
	rt_start(data, flag);
}

void	mlx_move_sphere(int key, t_data *data)
{
	if (key == KEY_Z || key == KEY_X)
		mlx_move_sphere_x(key, data);
	if (key == KEY_C || key == KEY_V)
		mlx_move_sphere_y(key, data);
	if (key == KEY_B || key == KEY_N)
		mlx_move_sphere_z(key, data);
}
