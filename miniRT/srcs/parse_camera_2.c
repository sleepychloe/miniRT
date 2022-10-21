/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_camera_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhwang <yhwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 20:44:26 by yhwang            #+#    #+#             */
/*   Updated: 2022/10/21 06:49:44 by yhwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/miniRT.h"

int	check_value_camera_xyz_vec(t_scene *scene, char **xyz_vec)
{
	if (ft_atoi(xyz_vec[0]) == ERR_ATOI || ft_atoi(xyz_vec[1]) == ERR_ATOI
		|| ft_atoi(xyz_vec[2]) == ERR_ATOI)
	{
		scene->camera->err = ERR_XYZ_VEC_VALUE;
		return (1);
	}
	if ( !(-1 <= ft_atoi(xyz_vec[0]) && ft_atoi(xyz_vec[0]) <= 1)
		|| !(-1 <= ft_atoi(xyz_vec[1]) && ft_atoi(xyz_vec[1]) <= 1)
		|| !(-1 <= ft_atoi(xyz_vec[2]) && ft_atoi(xyz_vec[2]) <= 1))
	{
		scene->camera->err = ERR_XYZ_VEC_VALUE;
		return (1);
	}
	return (0);
}

int	parse_camera_xyz_vec(t_scene *scene, char ***s)
{
	if (!s[2])
	{
		scene->camera->err = ERR_MALLOC;
		ft_free_3d(s);
		return (1);
	}
	if (token_count(s[2], 3))
	{
		scene->camera->err = ERR_XYZ_VEC_TOKEN;
		ft_free_3d(s);
		return (1);
	}
	if (check_value_camera_xyz_vec(scene, s[2]))
	{
		ft_free_3d(s);
		return (1);
	}
	scene->camera->x_vec = ft_atoi(s[2][0]);
	scene->camera->y_vec = ft_atoi(s[2][1]);
	scene->camera->z_vec = ft_atoi(s[2][2]);
	return (0);
}

int	parse_camera_fov(t_scene *scene, char ***s)
{
	if (ft_atoi(s[0][3]) == ERR_ATOI)
	{
		scene->camera->err = ERR_FOV_VALUE;
		ft_free_3d(s);
		return (1);
	}
	if (!(0 <= ft_atoi(s[0][3]) && ft_atoi(s[0][3]) <= 180))
	{
		scene->camera->err = ERR_FOV_VALUE;
		ft_free_3d(s);
		return (1);
	}
	scene->camera->fov = ft_atoi(s[0][3]);
	return (0);
}
