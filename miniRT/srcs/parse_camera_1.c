/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_camera_1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhwang <yhwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 20:42:46 by yhwang            #+#    #+#             */
/*   Updated: 2022/10/22 22:41:12 by yhwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/miniRT.h"

int	parse_camera_token(t_scene *scene, char ***s)
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

int	check_value_camera_xyz_pos(t_scene *scene, char **xyz_pos)
{
	if (ft_atod(xyz_pos[0]) == ERR_ATOD || ft_atod(xyz_pos[1]) == ERR_ATOD
		|| ft_atod(xyz_pos[2]) == ERR_ATOD)
	{
		scene->camera->err = ERR_XYZ_POS_VALUE;
		return (1);
	}
	return (0);
}

int	parse_camera_xyz_pos(t_scene *scene, char ***s)
{
	if (!s[1])
	{
		scene->camera->err = ERR_MALLOC;
		ft_free_3d(s);
		return (1);
	}
	if (token_count(s[1], 3))
	{
		scene->camera->err = ERR_XYZ_POS_TOKEN;
		ft_free_3d(s);
		return (1);
	}
	if (check_value_camera_xyz_pos(scene, s[1]))
	{
		ft_free_3d(s);
		return (1);
	}
	scene->camera->x_pos = ft_atod(s[1][0]);
	scene->camera->y_pos = ft_atod(s[1][1]);
	scene->camera->z_pos = ft_atod(s[1][2]);
	return (0);
}

void	parse_camera(t_scene *scene, char **line)
{
	char	***s;

	if (scene->camera->check)
	{
		err_msg("Map error: C: already exists");
		return ;
	}
	s = (char ***)ft_calloc(sizeof(char **), 4);
	if (!s)
	{
		err_msg("Malloc error");
		return ;
	}
	s[0] = ft_split(*line, ' ');
	s[1] = ft_split(s[0][1], ',');
	s[2] = ft_split(s[0][2], ',');
	if (parse_camera_token(scene, s) || parse_camera_xyz_pos(scene, s)
		|| parse_camera_xyz_vec(scene, s) || parse_camera_fov(scene, s))
		return ;
	ft_free_3d(s);
	scene->camera->check++;
}
