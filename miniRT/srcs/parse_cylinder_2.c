/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_cylinder_2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhwang <yhwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 07:17:56 by yhwang            #+#    #+#             */
/*   Updated: 2022/10/23 00:41:09 by yhwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/miniRT.h"

int	parse_cy_height(t_scene *scene, int i, char ***s)
{
	if (ft_atod(s[0][4]) == ERR_ATOD)
	{
		scene->cylinder[i]->err = ERR_HEIGHT_VALUE;
		ft_free_3d(s);
		return (1);
	}
	scene->cylinder[i]->height = ft_atod(s[0][4]);
	return (0);
}

int	check_value_cy_xyz_vec(t_scene *scene, int i, char **xyz_vec)
{
	if (ft_atoi(xyz_vec[0]) == ERR_ATOI || ft_atoi(xyz_vec[1]) == ERR_ATOI
		|| ft_atoi(xyz_vec[2]) == ERR_ATOI)
	{
		scene->cylinder[i]->err = ERR_XYZ_VEC_VALUE;
		return (1);
	}
	if (!(-1 <= ft_atoi(xyz_vec[0]) && ft_atoi(xyz_vec[0]) <= 1)
		|| !(-1 <= ft_atoi(xyz_vec[1]) && ft_atoi(xyz_vec[1]) <= 1)
		|| !(-1 <= ft_atoi(xyz_vec[2]) && ft_atoi(xyz_vec[2]) <= 1))
	{
		scene->cylinder[i]->err = ERR_XYZ_VEC_VALUE;
		return (1);
	}
	return (0);
}

int	parse_cy_xyz_vec(t_scene *scene, int i, char ***s)
{
	if (!s[2])
	{
		scene->cylinder[i]->err = ERR_MALLOC;
		ft_free_3d(s);
		return (1);
	}
	if (token_count(s[2], 3))
	{
		scene->cylinder[i]->err = ERR_XYZ_VEC_TOKEN;
		ft_free_3d(s);
		return (1);
	}
	if (check_value_cy_xyz_vec(scene, i, s[2]))
	{
		ft_free_3d(s);
		return (1);
	}
	scene->cylinder[i]->x_vec = ft_atoi(s[2][0]);
	scene->cylinder[i]->y_vec = ft_atoi(s[2][1]);
	scene->cylinder[i]->z_vec = ft_atoi(s[2][2]);
	return (0);
}

int	check_value_cy_rgb(t_scene *scene, int i, char **rgb)
{
	if (ft_atoi(rgb[0]) == ERR_ATOI || ft_atoi(rgb[1]) == ERR_ATOI
		|| ft_atoi(rgb[2]) == ERR_ATOI)
	{
		scene->cylinder[i]->err = ERR_RGB_VALUE;
		return (1);
	}
	if (!(0 <= ft_atoi(rgb[0]) && ft_atoi(rgb[0]) <= 255)
		|| !(0 <= ft_atoi(rgb[1]) && ft_atoi(rgb[1]) <= 255)
		|| !(0 <= ft_atoi(rgb[2]) && ft_atoi(rgb[2]) <= 255))
	{
		scene->cylinder[i]->err = ERR_RGB_VALUE;
		return (1);
	}
	return (0);
}

int	parse_cy_rgb(t_scene *scene, int i, char ***s)
{
	if (!s[3])
	{
		scene->cylinder[i]->err = ERR_MALLOC;
		ft_free_3d(s);
		return (1);
	}
	if (token_count(s[3], 3))
	{
		scene->cylinder[i]->err = ERR_RGB_TOKEN;
		ft_free_3d(s);
		return (1);
	}
	if (check_value_cy_rgb(scene, i, s[3]))
	{
		ft_free_3d(s);
		return (1);
	}
	scene->cylinder[i]->r = ft_atoi(s[3][0]);
	scene->cylinder[i]->g = ft_atoi(s[3][1]);
	scene->cylinder[i]->b = ft_atoi(s[3][2]);
	return (0);
}
