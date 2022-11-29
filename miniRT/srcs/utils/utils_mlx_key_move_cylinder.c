/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_mlx_key_move_cylinder.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhwang <yhwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 04:08:42 by yhwang            #+#    #+#             */
/*   Updated: 2022/11/29 02:12:37 by yhwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/miniRT.h"

void	mlx_move_cylinder_x(int key, t_data *data, int i)
{
	int	flag;

	if (key == KEY_Q)
		data->scene->cylinder[i]->xyz_pos
			= vec3_add_vec3(data->scene->cylinder[i]->xyz_pos,
				vec3_mul_rn(data->x_normal, -0.5));
	if (key == KEY_W)
		data->scene->cylinder[i]->xyz_pos
			= vec3_add_vec3(data->scene->cylinder[i]->xyz_pos,
				vec3_mul_rn(data->x_normal, 0.5));
	flag = 15;
	rt_start(data, flag);
}

void	mlx_move_cylinder_y(int key, t_data *data, int i)
{
	int	flag;

	if (key == KEY_E)
		data->scene->cylinder[i]->xyz_pos
			= vec3_add_vec3(data->scene->cylinder[i]->xyz_pos,
				vec3_mul_rn(data->y_normal, -0.5));
	if (key == KEY_R)
		data->scene->cylinder[i]->xyz_pos
			= vec3_add_vec3(data->scene->cylinder[i]->xyz_pos,
				vec3_mul_rn(data->y_normal, 0.5));
	flag = 16;
	rt_start(data, flag);
}

void	mlx_move_cylinder_z(int key, t_data *data, int i)
{
	int	flag;

	if (key == KEY_T)
		data->scene->cylinder[i]->xyz_pos
			= vec3_add_vec3(data->scene->cylinder[i]->xyz_pos,
				vec3_mul_rn(data->z_normal, -0.5));
	if (key == KEY_Y)
		data->scene->cylinder[i]->xyz_pos
			= vec3_add_vec3(data->scene->cylinder[i]->xyz_pos,
				vec3_mul_rn(data->z_normal, 0.5));
	flag = 17;
	rt_start(data, flag);
}

void	mlx_move_cylinder(int key, t_data *data, int i)
{
	int	flag;

	if (key == KEY_Q || key == KEY_W)
		mlx_move_cylinder_x(key, data, i);
	if (key == KEY_E || key == KEY_R)
		mlx_move_cylinder_y(key, data, i);
	if (key == KEY_T || key == KEY_Y)
		mlx_move_cylinder_z(key, data, i);
	if (key == KEY_F3)
	{
		if (data->cy == data->scene->n_cylinder - 1)
			data->cy = 0;
		else
			data->cy++;
		flag = 21;
		rt_start(data, flag);
	}
}
