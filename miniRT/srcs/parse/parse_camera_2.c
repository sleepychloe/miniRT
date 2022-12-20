/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_camera_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhwang <yhwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 20:44:26 by yhwang            #+#    #+#             */
/*   Updated: 2022/12/20 09:07:26 by yhwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/miniRT.h"

int	check_value_c_xyz_vec(t_scene *scene, char **xyz_vec)
{
	if (ft_atod(xyz_vec[0]) == ERR_ATOD || ft_atod(xyz_vec[1]) == ERR_ATOD
		|| ft_atod(xyz_vec[2]) == ERR_ATOD)
	{
		scene->camera->err = ERR_XYZ_VEC_VALUE;
		return (1);
	}
	if (!(ft_atod(xyz_vec[0]) * ft_atod(xyz_vec[0])
			+ ft_atod(xyz_vec[1]) * ft_atod(xyz_vec[1])
			+ ft_atod(xyz_vec[2]) * ft_atod(xyz_vec[2]) == 1))
	{
		scene->camera->err = ERR_XYZ_VEC_VALUE;
		return (1);
	}
	return (0);
}

int	parse_c_xyz_vec(t_scene *scene, char ***s)
{
	if (!s[2])
	{
		scene->camera->err = ERR_MALLOC;
		ft_free_3d(s);
		return (1);
	}
	if (token_count(s[2], 3) || check_comma(s[0][2]))
	{
		scene->camera->err = ERR_XYZ_VEC_TOKEN;
		ft_free_3d(s);
		return (1);
	}
	if (check_value_c_xyz_vec(scene, s[2]))
	{
		ft_free_3d(s);
		return (1);
	}
	scene->camera->xyz_vec.x = ft_atod(s[2][0]);
	scene->camera->xyz_vec.y = ft_atod(s[2][1]);
	scene->camera->xyz_vec.z = ft_atod(s[2][2]);
	return (0);
}

int	parse_c_fov(t_scene *scene, char ***s)
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
