/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_mlx_key_sphere.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhwang <yhwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 00:59:34 by yhwang            #+#    #+#             */
/*   Updated: 2022/11/14 01:51:49 by yhwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/miniRT.h"

void	mlx_move_sphere(int key, t_data *data)
{
	if (key == KEY_Z)
		data->scene->sphere[0]->xyz_pos
			= vec3_add_vec3(data->scene->sphere[0]->xyz_pos, vec3(-0.5, 0, 0));
	if (key == KEY_X)
		data->scene->sphere[0]->xyz_pos
			= vec3_add_vec3(data->scene->sphere[0]->xyz_pos, vec3(0.5, 0, 0));
	if (key == KEY_C)
		data->scene->sphere[0]->xyz_pos
			= vec3_add_vec3(data->scene->sphere[0]->xyz_pos, vec3(0, -0.5, 0));
	if (key == KEY_V)
		data->scene->sphere[0]->xyz_pos
			= vec3_add_vec3(data->scene->sphere[0]->xyz_pos, vec3(0, 0.5, 0));
	if (key == KEY_B)
		data->scene->sphere[0]->xyz_pos
			= vec3_add_vec3(data->scene->sphere[0]->xyz_pos, vec3(0, 0, -0.5));
	if (key == KEY_N)
		data->scene->sphere[0]->xyz_pos
			= vec3_add_vec3(data->scene->sphere[0]->xyz_pos, vec3(0, 0, 0.5));
	rt_start(data);
}
