/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_light_1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhwang <yhwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 20:46:18 by yhwang            #+#    #+#             */
/*   Updated: 2022/10/23 04:19:31 by yhwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/miniRT.h"

int	parse_l_token(t_scene *scene, char ***s)
{
	if (!s[0])
	{
		scene->light->err = ERR_MALLOC;
		return (1);
	}
	if (ft_strlen(s[0][0]) != 1)
	{
		scene->light->err = ERR_IDENTIFIER;
		ft_free_3d(s);
		return (1);
	}
	if (token_count(s[0], 4))
	{
		scene->light->err = ERR_LINE_TOKEN;
		ft_free_3d(s);
		return (1);
	}
	return (0);
}

int	check_value_l_xyz_pos(t_scene *scene, char **xyz_pos)
{
	if (ft_atod(xyz_pos[0]) == ERR_ATOD || ft_atod(xyz_pos[1]) == ERR_ATOD
		|| ft_atod(xyz_pos[2]) == ERR_ATOD)
	{
		scene->light->err = ERR_XYZ_POS_VALUE;
		return (1);
	}
	return (0);
}

int	parse_l_xyz_pos(t_scene *scene, char ***s)
{
	if (!s[1])
	{
		scene->light->err = ERR_MALLOC;
		ft_free_3d(s);
		return (1);
	}
	if (token_count(s[1], 3))
	{
		scene->light->err = ERR_XYZ_POS_TOKEN;
		ft_free_3d(s);
		return (1);
	}
	if (check_value_l_xyz_pos(scene, s[1]))
	{
		ft_free_3d(s);
		return (1);
	}
	scene->light->x_pos = ft_atod(s[1][0]);
	scene->light->y_pos = ft_atod(s[1][1]);
	scene->light->z_pos = ft_atod(s[1][2]);
	return (0);
}

int	parse_l_norminette(t_scene *scene, char ***s)
{
	if (!s[0][1])
	{
		scene->light->err = ERR_LINE_TOKEN;
		ft_free_3d(s);
		return (1);
	}
	s[1] = ft_split(s[0][1], ',');
	s[2] = ft_split(s[0][3], ',');
	if (parse_l_xyz_pos(scene, s) || parse_l_brightness(scene, s)
		|| parse_l_rgb(scene, s))
	{
		err_check_l(scene);
		return (1);
	}
	ft_free_3d(s);
	scene->light->check++;
	return (0);
}

int	parse_l(t_scene *scene, char **line)
{
	char	***s;

	if (scene->light->check)
	{
		err_msg("Map error: L: already exists");
		return (1);
	}
	s = (char ***)ft_calloc(sizeof(char **), 4);
	if (!s)
	{
		err_msg("Malloc error");
		return (1);
	}
	s[0] = ft_split(*line, ' ');
	if (parse_l_token(scene, s))
	{
		err_check_l(scene);
		return (1);
	}
	if (parse_l_norminette(scene, s))
		return (1);
	return (0);
}
