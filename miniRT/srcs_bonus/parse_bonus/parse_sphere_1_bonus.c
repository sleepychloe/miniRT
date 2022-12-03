/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_sphere_1_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhwang <yhwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 01:08:29 by yhwang            #+#    #+#             */
/*   Updated: 2022/12/03 07:32:07 by yhwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs_bonus/miniRT_bonus.h"

int	check_sp_token(t_scene *scene, int i, char ***s)
{
	if (ft_strncmp(s[0][3], "L", 1) == 0
		|| ft_strncmp(s[0][3], "C", 1) == 0
		|| ft_strncmp(s[0][3], "I", 1) == 0
		|| ft_strncmp(s[0][3], "M,", 2) == 0
		|| ft_strncmp(s[0][3], "G", 1) == 0)
	{
		if (token_count(s[0], 5))
		{
			scene->sphere[i]->err = ERR_LINE_TOKEN;
			return (1);
		}
	}
	if (ft_strncmp(s[0][3], "T", 1) == 0
		|| ft_strncmp(s[0][3], "D", 1) == 0)
	{
		if (token_count(s[0], 6))
		{
			scene->sphere[i]->err = ERR_LINE_TOKEN;
			return (1);
		}
	}
	return (0);
}

int	parse_sp_token(t_scene *scene, int i, char ***s)
{
	if (!s[0] || !s[0][1] || !s[0][2] || !s[0][3])
	{
		scene->sphere[i]->err = ERR_LINE_TOKEN;
		ft_free_3d(s);
		return (1);
	}
	if (ft_strlen(s[0][0]) != 2)
	{
		scene->sphere[i]->err = ERR_IDENTIFIER;
		ft_free_3d(s);
		return (1);
	}
	if (ft_strncmp(s[0][3], "L", 1) == 0 || ft_strncmp(s[0][3], "C", 1) == 0
		|| ft_strncmp(s[0][3], "T", 1) == 0 || ft_strncmp(s[0][3], "I", 1) == 0
		|| ft_strncmp(s[0][3], "D", 1) == 0 || ft_strncmp(s[0][3], "M,", 2) == 0
		|| ft_strncmp(s[0][3], "G", 1) == 0)
	{
		if (check_sp_token(scene, i, s))
		{
			scene->sphere[i]->err = ERR_LINE_TOKEN;
			ft_free_3d(s);
			return (1);
		}
	}
	return (0);
}

int	parse_sp_norminette(t_scene *scene, int i, char ***s)
{
	s[1] = ft_split(s[0][1], ',');
	if (ft_strncmp(s[0][3], "L", 1) == 0
		|| ft_strncmp(s[0][3], "C", 1) == 0
		|| ft_strncmp(s[0][3], "M,", 2) == 0
		|| ft_strncmp(s[0][3], "T", 1) == 0)
		s[2] = ft_split(s[0][4], ',');
	if (ft_strncmp(s[0][3], "M,", 2) == 0)
		s[3] = ft_split(s[0][3], ',');
	if (parse_sp_xyz_pos(scene, i, s) || parse_sp_diameter(scene, i, s)
		|| parse_sp_surface_1(scene, i, s) || parse_sp_surface_2(scene, i, s)
		|| parse_sp_rgb_1(scene, i, s) || parse_sp_rgb_2(scene, i, s)
		|| parse_sp_texture_path(scene, i, s) || parse_sp_img_path(scene, i, s))
	{
		err_check_sp_1(scene, i);
		err_check_sp_2(scene, i);
		return (1);
	}
	ft_free_3d(s);
	scene->n_sphere++;
	return (0);
}

int	parse_sp(t_scene *scene, char **line)
{
	int		i;
	char	***s;

	i = scene->n_sphere;
	if (i > 0)
		init_struct_scene_sp(scene, i);
	s = (char ***)ft_calloc(sizeof(char **), 5);
	if (!s)
	{
		err_msg("Malloc error");
		return (1);
	}
	s[0] = ft_split(*line, ' ');
	if (parse_sp_token(scene, i, s))
	{
		err_check_sp_1(scene, i);
		err_check_sp_2(scene, i);
		return (1);
	}
	if (parse_sp_norminette(scene, i, s))
		return (1);
	return (0);
}
