/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_camera_1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhwang <yhwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 20:42:46 by yhwang            #+#    #+#             */
/*   Updated: 2022/10/23 07:29:38 by yhwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/miniRT.h"

int	parse_c_token(t_scene *scene, char ***s)
{
	if (!s[0])
	{
		scene->camera->err = ERR_MALLOC;
		return (1);
	}
	if (ft_strlen(s[0][0]) != 1)
	{
		scene->camera->err = ERR_IDENTIFIER;
		ft_free_3d(s);
		return (1);
	}
	if (token_count(s[0], 4))
	{
		scene->camera->err = ERR_LINE_TOKEN;
		ft_free_3d(s);
		return (1);
	}
	return (0);
}

int	check_value_c_xyz_pos(t_scene *scene, char **xyz_pos)
{
	if (ft_atod(xyz_pos[0]) == ERR_ATOD || ft_atod(xyz_pos[1]) == ERR_ATOD
		|| ft_atod(xyz_pos[2]) == ERR_ATOD)
	{
		scene->camera->err = ERR_XYZ_POS_VALUE;
		return (1);
	}
	return (0);
}

int	parse_c_xyz_pos(t_scene *scene, char ***s)
{
	if (!s[1])
	{
		scene->camera->err = ERR_MALLOC;
		ft_free_3d(s);
		return (1);
	}
	if (token_count(s[1], 3) || s[0][1][ft_strlen(s[0][1]) - 1] == ',')
	{
		scene->camera->err = ERR_XYZ_POS_TOKEN;
		ft_free_3d(s);
		return (1);
	}
	if (check_value_c_xyz_pos(scene, s[1]))
	{
		ft_free_3d(s);
		return (1);
	}
	scene->camera->x_pos = ft_atod(s[1][0]);
	scene->camera->y_pos = ft_atod(s[1][1]);
	scene->camera->z_pos = ft_atod(s[1][2]);
	return (0);
}

int	parse_c_norminette(t_scene *scene, char ***s)
{
	if (!s[0][1])
	{
		scene->camera->err = ERR_LINE_TOKEN;
		ft_free_3d(s);
		return (1);
	}
	s[1] = ft_split_comma(s[0][1], ',');
	s[2] = ft_split_comma(s[0][2], ',');
	if (parse_c_xyz_pos(scene, s) || parse_c_xyz_vec(scene, s)
		|| parse_c_fov(scene, s))
	{
		err_check_c(scene);
		return (1);
	}
	ft_free_3d(s);
	scene->camera->check++;
	return (0);
}

int	parse_c(t_scene *scene, char **line)
{
	char	***s;

	if (scene->camera->check)
	{
		err_msg("Map error: C: already exists");
		return (1);
	}
	s = (char ***)ft_calloc(sizeof(char **), 4);
	if (!s)
	{
		err_msg("Malloc error");
		return (1);
	}
	s[0] = ft_split(*line, ' ');
	if (parse_c_token(scene, s))
	{
		err_check_c(scene);
		return (1);
	}
	if (parse_c_norminette(scene, s))
		return (1);
	return (0);
}
