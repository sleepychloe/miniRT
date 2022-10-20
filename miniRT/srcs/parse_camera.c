/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_camera.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhwang <yhwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 20:28:45 by yhwang            #+#    #+#             */
/*   Updated: 2022/10/20 15:35:04 by yhwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/miniRT.h"

int	parse_camera_token(t_scene *scene, char **token)
{
	if (!token)
	{
		scene->camera->err = ERR_MALLOC;
		return (1);
	}
	if (ft_strlen(token[0]) != 1)
	{
		scene->camera->err = ERR_IDENTIFIER;
		ft_free_all_2d(token, NULL, NULL, NULL);
		return (1);
	}
	if (token_count(token, 4))
	{
		scene->camera->err = ERR_LINE_TOKEN;
		ft_free_all_2d(token, NULL, NULL, NULL);
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

int	parse_camera_xyz_pos(t_scene *scene, char **token, char **xyz_pos)
{
	if (!xyz_pos)
	{
		scene->camera->err = ERR_MALLOC;
		ft_free_all_2d(token, NULL, NULL, NULL);
		return (1);
	}
	if (token_count(xyz_pos, 3))
	{
		scene->camera->err = ERR_XYZ_POS_TOKEN;
		ft_free_all_2d(token, xyz_pos, NULL, NULL);
		return (1);
	}
	if (check_value_camera_xyz_pos(scene, xyz_pos))
	{
		ft_free_all_2d(token, xyz_pos, NULL, NULL);
		return (1);
	}
	scene->camera->x_pos = ft_atod(xyz_pos[0]);
	scene->camera->y_pos = ft_atod(xyz_pos[1]);
	scene->camera->z_pos = ft_atod(xyz_pos[2]);
	return (0);
}

int	check_value_camera_xyz_vec(t_scene *scene, char **xyz_vec)
{
	if (ft_atoi(xyz_vec[0]) == ERR_ATOI || ft_atoi(xyz_vec[1]) == ERR_ATOI
		|| ft_atoi(xyz_vec[2]) == ERR_ATOI)
	{
		scene->camera->err = ERR_XYZ_VEC_VALUE;
		return (1);
	}
	if ( !(-1 <= ft_atoi(xyz_vec[0]) && ft_atoi(xyz_vec[0]) <= 1)
		|| !(-1 <= ft_atoi(xyz_vec[1]) && ft_atoi(xyz_vec[1]) <= 1)
		|| !(-1 <= ft_atoi(xyz_vec[2]) && ft_atoi(xyz_vec[2]) <= 1))
	{
		scene->camera->err = ERR_XYZ_VEC_VALUE;
		return (1);
	}
	return (0);
}

int	parse_camera_xyz_vec(t_scene *scene, char **token, char **xyz_pos,
		char **xyz_vec)
{
	if (!xyz_vec)
	{
		scene->camera->err = ERR_MALLOC;
		ft_free_all_2d(token, xyz_pos, NULL, NULL);
		return (1);
	}
	if (token_count(xyz_vec, 3))
	{
		scene->camera->err = ERR_XYZ_VEC_TOKEN;
		ft_free_all_2d(token, xyz_pos, xyz_vec, NULL);
		return (1);
	}
	if (check_value_camera_xyz_vec(scene, xyz_vec))
	{
		ft_free_all_2d(token, xyz_pos, xyz_vec, NULL);
		return (1);
	}
	scene->camera->x_vec = ft_atoi(xyz_vec[0]);
	scene->camera->y_vec = ft_atoi(xyz_vec[1]);
	scene->camera->z_vec = ft_atoi(xyz_vec[2]);
	return (0);
}

int	parse_camera_fov(t_scene *scene, char **token, char **xyz_pos,
		char **xyz_vec)
{
	if (ft_atoi(token[3]) == ERR_ATOI)
	{
		scene->camera->err = ERR_FOV_VALUE;
		ft_free_all_2d(token, xyz_pos, xyz_vec, NULL);
		return (1);
	}
	if (!(0 <= ft_atoi(token[3]) && ft_atoi(token[3]) <= 180))
	{
		scene->camera->err = ERR_FOV_VALUE;
		ft_free_all_2d(token, xyz_pos, xyz_vec, NULL);
		return (1);
	}
	scene->camera->fov = ft_atoi(token[3]);
	return (0);
}

void	parse_camera(t_scene *scene, char **line)
{
	char	**token;
	char	**xyz_pos;
	char	**xyz_vec;

	token = ft_split(*line, ' ');
	if (parse_camera_token(scene, token))
		return ;
	xyz_pos = ft_split(token[1], ',');
	if (parse_camera_xyz_pos(scene, token, xyz_pos))
		return ;
	xyz_vec = ft_split(token[2], ',');
	if (parse_camera_xyz_vec(scene, token, xyz_pos, xyz_vec))
		return ;
	if (parse_camera_fov(scene, token, xyz_pos, xyz_vec))
		return ;
	ft_free_all_2d(token, xyz_pos, xyz_vec, NULL);
	scene->camera->cnt++;
}
