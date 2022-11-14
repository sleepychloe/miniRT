/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_mlx_key_light.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhwang <yhwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 01:09:42 by yhwang            #+#    #+#             */
/*   Updated: 2022/11/14 01:58:58 by yhwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/miniRT.h"

void	mlx_move_light(int key, t_data *data)
{
	if (key == KEY_POINT)
		data->scene->light->xyz_pos
			= vec3_add_vec3(data->scene->light->xyz_pos, vec3(-1, 0, 0));
	if (key == KEY_SLASH)
		data->scene->light->xyz_pos
			= vec3_add_vec3(data->scene->light->xyz_pos, vec3(1, 0, 0));
	if (key == KEY_SEMICOLON)
		data->scene->light->xyz_pos
			= vec3_add_vec3(data->scene->light->xyz_pos, vec3(0, -1, 0));
	if (key == KEY_SINGLE_QUOTE)
		data->scene->light->xyz_pos
			= vec3_add_vec3(data->scene->light->xyz_pos, vec3(0, 1, 0));
	if (key == KEY_SQUARE_BRACKET_LEFT)
		data->scene->light->xyz_pos
			= vec3_add_vec3(data->scene->light->xyz_pos, vec3(0, 0, -1));
	if (key == KEY_SQUARE_BRACKET_RIGHT)
		data->scene->light->xyz_pos
			= vec3_add_vec3(data->scene->light->xyz_pos, vec3(0, 0, 1));
	rt_start(data);
}
