/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_mlx_key_move_light_bonus.c                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhwang <yhwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 03:42:01 by yhwang            #+#    #+#             */
/*   Updated: 2022/12/02 01:53:20 by yhwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs_bonus/miniRT_bonus.h"

void	mlx_move_light_x(int key, t_data *data, int i)
{
	int	flag;

	if (key == KEY_POINT)
	{
		data->scene->light[i]->xyz_pos
			= vec3_add_vec3(data->scene->light[i]->xyz_pos,
				vec3_mul_rn(data->x_normal, -1 * LIGHT_MOVE));
		flag = L_MOVE_X_MINUS;
		data->keep_scene->light[i]->xyz_pos.x -= LIGHT_MOVE;
	}
	if (key == KEY_SLASH)
	{
		data->scene->light[i]->xyz_pos
			= vec3_add_vec3(data->scene->light[i]->xyz_pos,
				vec3_mul_rn(data->x_normal, LIGHT_MOVE));
		flag = L_MOVE_X_PLUS;
		data->keep_scene->light[i]->xyz_pos.x += LIGHT_MOVE;
	}
	rt_start(data, flag);
}

void	mlx_move_light_y(int key, t_data *data, int i)
{
	int	flag;

	if (key == KEY_SEMICOLON)
	{
		data->scene->light[i]->xyz_pos
			= vec3_add_vec3(data->scene->light[i]->xyz_pos,
				vec3_mul_rn(data->y_normal, -1 * LIGHT_MOVE));
		flag = L_MOVE_Y_MINUS;
		data->keep_scene->light[i]->xyz_pos.y -= LIGHT_MOVE;
	}
	if (key == KEY_SINGLE_QUOTE)
	{
		data->scene->light[i]->xyz_pos
			= vec3_add_vec3(data->scene->light[i]->xyz_pos,
				vec3_mul_rn(data->y_normal, LIGHT_MOVE));
		flag = L_MOVE_Y_PLUS;
		data->keep_scene->light[i]->xyz_pos.y += LIGHT_MOVE;
	}
	rt_start(data, flag);
}

void	mlx_move_light_z(int key, t_data *data, int i)
{
	int	flag;

	if (key == KEY_SQUARE_BRACKET_LEFT)
	{
		data->scene->light[i]->xyz_pos
			= vec3_add_vec3(data->scene->light[i]->xyz_pos,
				vec3_mul_rn(data->z_normal, -1 * LIGHT_MOVE));
		flag = L_MOVE_Z_MINUS;
		data->keep_scene->light[i]->xyz_pos.z -= LIGHT_MOVE;
	}
	if (key == KEY_SQUARE_BRACKET_RIGHT)
	{
		data->scene->light[i]->xyz_pos
			= vec3_add_vec3(data->scene->light[i]->xyz_pos,
				vec3_mul_rn(data->z_normal, LIGHT_MOVE));
		flag = L_MOVE_Z_PLUS;
		data->keep_scene->light[i]->xyz_pos.z += LIGHT_MOVE;
	}
	rt_start(data, flag);
}

void	mlx_move_light(int key, t_data *data, int i)
{
	int	flag;

	if (key == KEY_POINT || key == KEY_SLASH)
		mlx_move_light_x(key, data, i);
	if (key == KEY_SEMICOLON || key == KEY_SINGLE_QUOTE)
		mlx_move_light_y(key, data, i);
	if (key == KEY_SQUARE_BRACKET_LEFT || key == KEY_SQUARE_BRACKET_RIGHT)
		mlx_move_light_z(key, data, i);
	if (key == KEY_LEFT_CTRL)
	{
		if (data->l == data->scene->n_light - 1)
			data->l = 0;
		else
			data->l++;
		flag = L_NEXT;
		rt_start(data, flag);
	}
}
