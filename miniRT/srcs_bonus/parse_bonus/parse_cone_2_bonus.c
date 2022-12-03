/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_cone_2_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhwang <yhwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 23:56:04 by yhwang            #+#    #+#             */
/*   Updated: 2022/12/03 06:03:36 by yhwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs_bonus/miniRT_bonus.h"

int	check_value_co_xyz_pos(t_scene *scene, int i, char **xyz_pos)
{
	if (ft_atod(xyz_pos[0]) == ERR_ATOD || ft_atod(xyz_pos[1]) == ERR_ATOD
		|| ft_atod(xyz_pos[2]) == ERR_ATOD)
	{
		scene->cone[i]->err = ERR_XYZ_POS_VALUE;
		return (1);
	}
	return (0);
}

int	parse_co_xyz_pos(t_scene *scene, int i, char ***s)
{
	if (!s[1])
	{
		scene->cone[i]->err = ERR_LINE_TOKEN;
		ft_free_3d(s);
		return (1);
	}
	if (token_count(s[1], 3) || check_comma(s[0][1]))
	{
		scene->cone[i]->err = ERR_XYZ_POS_TOKEN;
		ft_free_3d(s);
		return (1);
	}
	if (check_value_co_xyz_pos(scene, i, s[1]))
	{
		ft_free_3d(s);
		return (1);
	}
	scene->cone[i]->xyz_pos.x = ft_atod(s[1][0]);
	scene->cone[i]->xyz_pos.y = ft_atod(s[1][1]);
	scene->cone[i]->xyz_pos.z = ft_atod(s[1][2]);
	return (0);
}

int	check_value_co_xyz_vec(t_scene *scene, int i, char **xyz_vec)
{
	if (ft_atod(xyz_vec[0]) == ERR_ATOD || ft_atod(xyz_vec[1]) == ERR_ATOD
		|| ft_atod(xyz_vec[2]) == ERR_ATOD)
	{
		scene->cone[i]->err = ERR_XYZ_VEC_VALUE;
		return (1);
	}
	if (!(ft_atod(xyz_vec[0]) * ft_atod(xyz_vec[0])
			+ ft_atod(xyz_vec[1]) * ft_atod(xyz_vec[1])
			+ ft_atod(xyz_vec[2]) * ft_atod(xyz_vec[2]) == 1))
	{
		scene->cone[i]->err = ERR_XYZ_VEC_VALUE;
		return (1);
	}
	return (0);
}

int	parse_co_xyz_vec(t_scene *scene, int i, char ***s)
{
	if (!s[2])
	{
		scene->cone[i]->err = ERR_LINE_TOKEN;
		ft_free_3d(s);
		return (1);
	}
	if (token_count(s[2], 3) || check_comma(s[0][2]))
	{
		scene->cone[i]->err = ERR_XYZ_VEC_TOKEN;
		ft_free_3d(s);
		return (1);
	}
	if (check_value_co_xyz_vec(scene, i, s[2]))
	{
		ft_free_3d(s);
		return (1);
	}
	scene->cone[i]->xyz_vec.x = ft_atoi(s[2][0]);
	scene->cone[i]->xyz_vec.y = ft_atoi(s[2][1]);
	scene->cone[i]->xyz_vec.z = ft_atoi(s[2][2]);
	return (0);
}
