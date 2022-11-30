/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_plane_2_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhwang <yhwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 07:17:30 by yhwang            #+#    #+#             */
/*   Updated: 2022/11/30 21:44:38 by yhwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs_bonus/miniRT_bonus.h"

int	check_value_pl_xyz_vec(t_scene *scene, int i, char **xyz_vec)
{
	if (ft_atod(xyz_vec[0]) == ERR_ATOD || ft_atod(xyz_vec[1]) == ERR_ATOD
		|| ft_atod(xyz_vec[2]) == ERR_ATOD)
	{
		scene->plane[i]->err = ERR_XYZ_VEC_VALUE;
		return (1);
	}
	if (!(ft_atod(xyz_vec[0]) * ft_atod(xyz_vec[0])
			+ ft_atod(xyz_vec[1]) * ft_atod(xyz_vec[1])
			+ ft_atod(xyz_vec[2]) * ft_atod(xyz_vec[2]) == 1))
	{
		scene->plane[i]->err = ERR_XYZ_VEC_VALUE;
		return (1);
	}
	return (0);
}

int	parse_pl_xyz_vec(t_scene *scene, int i, char ***s)
{
	if (!s[2])
	{
		scene->plane[i]->err = ERR_MALLOC;
		ft_free_3d(s);
		return (1);
	}
	if (token_count(s[2], 3) || check_comma(s[0][2]))
	{
		scene->plane[i]->err = ERR_XYZ_VEC_TOKEN;
		ft_free_3d(s);
		return (1);
	}
	if (check_value_pl_xyz_vec(scene, i, s[2]))
	{
		ft_free_3d(s);
		return (1);
	}
	scene->plane[i]->xyz_vec.x = ft_atoi(s[2][0]);
	scene->plane[i]->xyz_vec.y = ft_atoi(s[2][1]);
	scene->plane[i]->xyz_vec.z = ft_atoi(s[2][2]);
	return (0);
}

int	check_value_pl_rgb(t_scene *scene, int i, char **rgb)
{
	if (ft_atoi(rgb[0]) == ERR_ATOI || ft_atoi(rgb[1]) == ERR_ATOI
		|| ft_atoi(rgb[2]) == ERR_ATOI)
	{
		scene->plane[i]->err = ERR_RGB_VALUE;
		return (1);
	}
	if (!(0 <= ft_atoi(rgb[0]) && ft_atoi(rgb[0]) <= 255)
		|| !(0 <= ft_atoi(rgb[1]) && ft_atoi(rgb[1]) <= 255)
		|| !(0 <= ft_atoi(rgb[2]) && ft_atoi(rgb[2]) <= 255))
	{
		scene->plane[i]->err = ERR_RGB_VALUE;
		return (1);
	}
	return (0);
}

int	parse_pl_rgb(t_scene *scene, int i, char ***s)
{
	if (!s[3])
	{
		scene->plane[i]->err = ERR_MALLOC;
		ft_free_3d(s);
		return (1);
	}
	if (token_count(s[3], 3) || check_comma(s[0][3]))
	{
		scene->plane[i]->err = ERR_RGB_TOKEN;
		ft_free_3d(s);
		return (1);
	}
	if (check_value_pl_rgb(scene, i, s[3]))
	{
		ft_free_3d(s);
		return (1);
	}
	scene->plane[i]->rgb.r = ft_atoi(s[3][0]);
	scene->plane[i]->rgb.g = ft_atoi(s[3][1]);
	scene->plane[i]->rgb.b = ft_atoi(s[3][2]);
	return (0);
}
