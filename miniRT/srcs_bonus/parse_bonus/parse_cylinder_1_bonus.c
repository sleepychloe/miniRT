/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_cylinder_1_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhwang <yhwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 07:17:43 by yhwang            #+#    #+#             */
/*   Updated: 2022/12/03 07:31:20 by yhwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs_bonus/miniRT_bonus.h"

int	check_cy_token(t_scene *scene, int i, char ***s)
{
	if (ft_strncmp(s[0][5], "L", 1) == 0
		|| ft_strncmp(s[0][5], "C", 1) == 0
		|| ft_strncmp(s[0][5], "I", 1) == 0
		|| ft_strncmp(s[0][5], "M,", 2) == 0
		|| ft_strncmp(s[0][5], "G", 1) == 0)
	{
		if (token_count(s[0], 7))
		{
			scene->cylinder[i]->err = ERR_LINE_TOKEN;
			return (1);
		}
	}
	if (ft_strncmp(s[0][5], "T", 1) == 0
		|| ft_strncmp(s[0][5], "D", 1) == 0)
	{
		if (token_count(s[0], 8))
		{
			scene->cylinder[i]->err = ERR_LINE_TOKEN;
			return (1);
		}
	}
	return (0);
}

int	parse_cy_token(t_scene *scene, int i, char ***s)
{
	if (!s[0] || !s[0][1] || !s[0][2] || !s[0][3] || !s[0][4] || !s[0][5])
	{
		scene->cylinder[i]->err = ERR_LINE_TOKEN;
		ft_free_3d(s);
		return (1);
	}
	if (ft_strlen(s[0][0]) != 2)
	{
		scene->cylinder[i]->err = ERR_IDENTIFIER;
		ft_free_3d(s);
		return (1);
	}
	if (ft_strncmp(s[0][5], "L", 1) == 0 || ft_strncmp(s[0][5], "C", 1) == 0
		|| ft_strncmp(s[0][5], "T", 1) == 0 || ft_strncmp(s[0][5], "I", 1) == 0
		|| ft_strncmp(s[0][5], "D", 1) == 0 || ft_strncmp(s[0][5], "M,", 2) == 0
		|| ft_strncmp(s[0][5], "G", 1) == 0)
	{
		if (check_cy_token(scene, i, s))
		{
			scene->cylinder[i]->err = ERR_LINE_TOKEN;
			ft_free_3d(s);
			return (1);
		}
	}
	return (0);
}

int	parse_cy_norminette(t_scene *scene, int i, char ***s)
{
	s[1] = ft_split(s[0][1], ',');
	s[2] = ft_split(s[0][2], ',');
	if (ft_strncmp(s[0][5], "L", 1) == 0
		|| ft_strncmp(s[0][5], "C", 1) == 0
		|| ft_strncmp(s[0][5], "M,", 2) == 0
		|| ft_strncmp(s[0][5], "T", 1) == 0)
		s[3] = ft_split(s[0][6], ',');
	if (ft_strncmp(s[0][5], "M,", 2) == 0)
		s[4] = ft_split(s[0][5], ',');
	if (parse_cy_xyz_pos(scene, i, s) || parse_cy_xyz_vec(scene, i, s)
		|| parse_cy_diameter(scene, i, s) || parse_cy_height(scene, i, s)
		|| parse_cy_surface_1(scene, i, s) || parse_cy_surface_2(scene, i, s)
		|| parse_cy_rgb_1(scene, i, s) || parse_cy_rgb_2(scene, i, s)
		|| parse_cy_texture_path(scene, i, s) || parse_cy_img_path(scene, i, s))
	{
		err_check_cy_1(scene, i);
		err_check_cy_2(scene, i);
		return (1);
	}
	ft_free_3d(s);
	scene->n_cylinder++;
	return (0);
}

int	parse_cy(t_scene *scene, char **line)
{
	int		i;
	char	***s;

	i = scene->n_cylinder;
	if (i > 0)
		init_struct_scene_cy(scene, i);
	s = (char ***)ft_calloc(sizeof(char **), 6);
	if (!s)
	{
		err_msg("Malloc error");
		return (1);
	}
	s[0] = ft_split(*line, ' ');
	if (parse_cy_token(scene, i, s))
	{
		err_check_cy_1(scene, i);
		err_check_cy_2(scene, i);
		return (1);
	}
	if (parse_cy_norminette(scene, i, s))
		return (1);
	return (0);
}
