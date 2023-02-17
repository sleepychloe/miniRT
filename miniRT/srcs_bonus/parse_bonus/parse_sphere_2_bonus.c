/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_sphere_2_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhwang <yhwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 01:08:45 by yhwang            #+#    #+#             */
/*   Updated: 2022/12/22 01:48:43 by yhwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs_bonus/miniRT_bonus.h"

int	check_value_sp_xyz_pos(t_scene *scene, int i, char **xyz_pos)
{
	if (ft_atod(xyz_pos[0]) == ERR_ATOD || ft_atod(xyz_pos[1]) == ERR_ATOD
		|| ft_atod(xyz_pos[2]) == ERR_ATOD)
	{
		scene->sphere[i]->err = ERR_XYZ_POS_VALUE;
		return (1);
	}
	return (0);
}

int	parse_sp_xyz_pos(t_scene *scene, int i, char ***s)
{
	if (!s[1])
	{
		scene->sphere[i]->err = ERR_LINE_TOKEN;
		ft_free_3d(s);
		return (1);
	}
	if (token_count(s[1], 3) || check_comma(s[0][1]))
	{
		scene->sphere[i]->err = ERR_XYZ_POS_TOKEN;
		ft_free_3d(s);
		return (1);
	}
	if (check_value_sp_xyz_pos(scene, i, s[1]))
	{
		ft_free_3d(s);
		return (1);
	}
	scene->sphere[i]->xyz_pos.x = ft_atod(s[1][0]);
	scene->sphere[i]->xyz_pos.y = ft_atod(s[1][1]);
	scene->sphere[i]->xyz_pos.z = ft_atod(s[1][2]);
	return (0);
}

int	parse_sp_diameter(t_scene *scene, int i, char ***s)
{
	if (ft_atod(s[0][2]) == ERR_ATOD)
	{
		scene->sphere[i]->err = ERR_DIAMETER_VALUE;
		ft_free_3d(s);
		return (1);
	}
	if (ft_atod(s[0][2]) <= 0)
	{
		scene->sphere[i]->err = ERR_DIAMETER_VALUE;
		ft_free_3d(s);
		return (1);
	}
	scene->sphere[i]->diameter = ft_atod(s[0][2]);
	return (0);
}

int	parse_sp_surface_1(t_scene *scene, int i, char ***s)
{
	if (!((ft_strncmp(s[0][3], "L", 1) == 0 && ft_strlen(s[0][3]) == 1)
		|| (ft_strncmp(s[0][3], "C", 1) == 0 && ft_strlen(s[0][3]) == 1)
		|| (ft_strncmp(s[0][3], "T", 1) == 0 && ft_strlen(s[0][3]) == 1)
		|| (ft_strncmp(s[0][3], "I", 1) == 0 && ft_strlen(s[0][3]) == 1)
		|| (ft_strncmp(s[0][3], "D", 1) == 0 && ft_strlen(s[0][3]) == 1)
		|| (ft_strncmp(s[0][3], "M,", 2) == 0)))
	{
		scene->sphere[i]->err = ERR_SURFACE_FLAG;
		ft_free_3d(s);
		return (1);
	}
	if (ft_strncmp(s[0][3], "L", 1) == 0)
	{
		scene->sphere[i]->surface = SURFACE_L;
	}
	else if (ft_strncmp(s[0][3], "C", 1) == 0)
		scene->sphere[i]->surface = SURFACE_C;
	else if (ft_strncmp(s[0][3], "T", 1) == 0)
		scene->sphere[i]->surface = SURFACE_T;
	else if (ft_strncmp(s[0][3], "I", 1) == 0)
		scene->sphere[i]->surface = SURFACE_I;
	else if (ft_strncmp(s[0][3], "D", 1) == 0)
		scene->sphere[i]->surface = SURFACE_D;
	return (0);
}

int	parse_sp_surface_2(t_scene *scene, int i, char ***s)
{
	if (ft_strncmp(s[0][3], "M,", 2) == 0)
	{
		if (!s[3] || !s[3][0] || !s[3][1])
		{
			scene->sphere[i]->err = ERR_LINE_TOKEN;
			ft_free_3d(s);
			return (1);
		}
		if (token_count(s[3], 2) || check_comma_surface_flag(s[0][3]))
		{
			scene->sphere[i]->err = ERR_SURFACE_FLAG;
			ft_free_3d(s);
			return (1);
		}
		if (parse_sp_surface_metal_fuzz(scene, i, s))
		{
			scene->sphere[i]->err = ERR_FUZZ_VALUE;
			ft_free_3d(s);
			return (1);
		}
	}
	return (0);
}
