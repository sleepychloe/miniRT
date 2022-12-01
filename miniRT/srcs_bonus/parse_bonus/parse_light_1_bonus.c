/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_light_1_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhwang <yhwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 20:46:18 by yhwang            #+#    #+#             */
/*   Updated: 2022/12/01 04:39:48 by yhwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs_bonus/miniRT_bonus.h"

int	parse_l_token(t_scene *scene, int i, char ***s)
{
	if (!s[0])
	{
		scene->light[i]->err = ERR_MALLOC;
		return (1);
	}
	if (ft_strlen(s[0][0]) != 1)
	{
		scene->light[i]->err = ERR_IDENTIFIER;
		ft_free_3d(s);
		return (1);
	}
	if (token_count(s[0], 4))
	{
		scene->light[i]->err = ERR_LINE_TOKEN;
		ft_free_3d(s);
		return (1);
	}
	return (0);
}

int	check_value_l_xyz_pos(t_scene *scene, int i, char **xyz_pos)
{
	if (ft_atod(xyz_pos[0]) == ERR_ATOD || ft_atod(xyz_pos[1]) == ERR_ATOD
		|| ft_atod(xyz_pos[2]) == ERR_ATOD)
	{
		scene->light[i]->err = ERR_XYZ_POS_VALUE;
		return (1);
	}
	return (0);
}

int	parse_l_xyz_pos(t_scene *scene, int i, char ***s)
{
	if (!s[1])
	{
		scene->light[i]->err = ERR_MALLOC;
		ft_free_3d(s);
		return (1);
	}
	if (token_count(s[1], 3) || check_comma(s[0][1]))
	{
		scene->light[i]->err = ERR_XYZ_POS_TOKEN;
		ft_free_3d(s);
		return (1);
	}
	if (check_value_l_xyz_pos(scene, i, s[1]))
	{
		ft_free_3d(s);
		return (1);
	}
	scene->light[i]->xyz_pos.x = ft_atod(s[1][0]);
	scene->light[i]->xyz_pos.y = ft_atod(s[1][1]);
	scene->light[i]->xyz_pos.z = ft_atod(s[1][2]);
	return (0);
}

int	parse_l_norminette(t_scene *scene, int i, char ***s)
{
	s[1] = ft_split(s[0][1], ',');
	s[2] = ft_split(s[0][3], ',');
	if (parse_l_xyz_pos(scene, i, s) || parse_l_brightness(scene, i, s)
		|| parse_l_rgb(scene, i, s))
	{
		err_check_l(scene, i);
		return (1);
	}
	ft_free_3d(s);
	scene->n_light++;
	return (0);
}

int	parse_l(t_scene *scene, char **line)
{
	int		i;
	char	***s;

	i = scene->n_light;
	if (i > 0)
		init_struct_scene_l(scene, i);
	s = (char ***)ft_calloc(sizeof(char **), 4);
	if (!s)
	{
		err_msg("Malloc error");
		return (1);
	}
	s[0] = ft_split(*line, ' ');
	if (parse_l_token(scene, i, s))
	{
		err_check_l(scene, i);
		return (1);
	}
	if (parse_l_norminette(scene, i, s))
		return (1);
	return (0);
}
