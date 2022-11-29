/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_mlx_key_move_light.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhwang <yhwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 03:42:01 by yhwang            #+#    #+#             */
/*   Updated: 2022/11/29 06:25:28 by yhwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/miniRT.h"

void	mlx_move_light_x(int key, t_data *data)
{
	int	flag;

	if (key == KEY_POINT)
	{
		data->scene->light->xyz_pos
			= vec3_add_vec3(data->scene->light->xyz_pos,
				vec3_mul_rn(data->x_normal, -1 * LIGHT_MOVE));
		flag = L_MOVE_X_MINUS;
	}
	if (key == KEY_SLASH)
	{
		data->scene->light->xyz_pos
			= vec3_add_vec3(data->scene->light->xyz_pos,
				vec3_mul_rn(data->x_normal, LIGHT_MOVE));
		flag = L_MOVE_X_PLUS;
	}
	rt_start(data, flag);
}

void	mlx_move_light_y(int key, t_data *data)
{
	int	flag;

	if (key == KEY_SEMICOLON)
	{
		data->scene->light->xyz_pos
			= vec3_add_vec3(data->scene->light->xyz_pos,
				vec3_mul_rn(data->y_normal, -1 * LIGHT_MOVE));
		flag = L_MOVE_Y_MINUS;
	}
	if (key == KEY_SINGLE_QUOTE)
	{
		data->scene->light->xyz_pos
			= vec3_add_vec3(data->scene->light->xyz_pos,
				vec3_mul_rn(data->y_normal, LIGHT_MOVE));
		flag = L_MOVE_Y_PLUS;
	}
	rt_start(data, flag);
}

void	mlx_move_light_z(int key, t_data *data)
{
	int	flag;

	if (key == KEY_SQUARE_BRACKET_LEFT)
	{
		data->scene->light->xyz_pos
			= vec3_add_vec3(data->scene->light->xyz_pos,
				vec3_mul_rn(data->z_normal, -1 * LIGHT_MOVE));
		flag = L_MOVE_Z_MINUS;
	}
	if (key == KEY_SQUARE_BRACKET_RIGHT)
	{
		data->scene->light->xyz_pos
			= vec3_add_vec3(data->scene->light->xyz_pos,
				vec3_mul_rn(data->z_normal, LIGHT_MOVE));
		flag = L_MOVE_Z_PLUS;
	}
	rt_start(data, flag);
}

void	mlx_move_light(int key, t_data *data)
{
	if (key == KEY_POINT || key == KEY_SLASH)
		mlx_move_light_x(key, data);
	if (key == KEY_SEMICOLON || key == KEY_SINGLE_QUOTE)
		mlx_move_light_y(key, data);
	if (key == KEY_SQUARE_BRACKET_LEFT || key == KEY_SQUARE_BRACKET_RIGHT)
		mlx_move_light_z(key, data);
}
