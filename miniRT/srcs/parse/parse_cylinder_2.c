/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_cylinder_2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhwang <yhwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 07:17:56 by yhwang            #+#    #+#             */
/*   Updated: 2022/12/21 00:37:57 by yhwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/miniRT.h"

int	parse_cy_diameter(t_scene *scene, int i, char ***s)
{
	if (ft_atod(s[0][3]) == ERR_ATOD)
	{
		scene->cylinder[i]->err = ERR_DIAMETER_VALUE;
		ft_free_3d(s);
		return (1);
	}
	if (ft_atod(s[0][3]) <= 0)
	{
		scene->cylinder[i]->err = ERR_DIAMETER_VALUE;
		ft_free_3d(s);
		return (1);
	}
	scene->cylinder[i]->diameter = ft_atod(s[0][3]);
	return (0);
}

int	parse_cy_height(t_scene *scene, int i, char ***s)
{
	if (ft_atod(s[0][4]) == ERR_ATOD)
	{
		scene->cylinder[i]->err = ERR_HEIGHT_VALUE;
		ft_free_3d(s);
		return (1);
	}
	if (ft_atod(s[0][4]) <= 0)
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
	if (ft_atod(xyz_vec[0]) == ERR_ATOD || ft_atod(xyz_vec[1]) == ERR_ATOD
		|| ft_atod(xyz_vec[2]) == ERR_ATOD)
	{
		scene->cylinder[i]->err = ERR_XYZ_VEC_VALUE;
		return (1);
	}
	if (!(ft_atod(xyz_vec[0]) * ft_atod(xyz_vec[0])
			+ ft_atod(xyz_vec[1]) * ft_atod(xyz_vec[1])
			+ ft_atod(xyz_vec[2]) * ft_atod(xyz_vec[2]) == 1))
	{
		if (!(ft_atod(xyz_vec[0]) * ft_atod(xyz_vec[0])
				+ ft_atod(xyz_vec[1]) * ft_atod(xyz_vec[1])
				+ ft_atod(xyz_vec[2]) * ft_atod(xyz_vec[2])
				> 1 - EPSILON))
		{
			scene->cylinder[i]->err = ERR_XYZ_VEC_VALUE;
			return (1);
		}
	}
	return (0);
}

int	parse_cy_xyz_vec(t_scene *scene, int i, char ***s)
{
	if (!s[2])
	{
		scene->cylinder[i]->err = ERR_LINE_TOKEN;
		ft_free_3d(s);
		return (1);
	}
	if (token_count(s[2], 3) || check_comma(s[0][2]))
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
	scene->cylinder[i]->xyz_vec.x = ft_atod(s[2][0]);
	scene->cylinder[i]->xyz_vec.y = ft_atod(s[2][1]);
	scene->cylinder[i]->xyz_vec.z = ft_atod(s[2][2]);
	return (0);
}
