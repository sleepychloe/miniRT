/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_sphere_1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhwang <yhwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 01:08:29 by yhwang            #+#    #+#             */
/*   Updated: 2022/10/21 07:09:50 by yhwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/miniRT.h"

int	parse_sphere_token(t_scene *scene, int i, char ***s)
{
	if (!s[0])
	{
		scene->sphere[i]->err = ERR_MALLOC;
		return (1);
	}
	if (ft_strlen(s[0][0]) != 2)
	{
		scene->sphere[i]->err = ERR_IDENTIFIER;
		ft_free_3d(s);
		return (1);
	}
	if (token_count(s[0], 4))
	{
		scene->sphere[i]->err = ERR_LINE_TOKEN;
		ft_free_3d(s);
		return (1);
	}
	return (0);
}

int	check_value_sphere_xyz_pos(t_scene *scene, int i, char **xyz_pos)
{
	if (ft_atod(xyz_pos[0]) == ERR_ATOD || ft_atod(xyz_pos[1]) == ERR_ATOD
		|| ft_atod(xyz_pos[2]) == ERR_ATOD)
	{
		scene->sphere[i]->err = ERR_XYZ_POS_VALUE;
		return (1);
	}
	return (0);
}

int	parse_sphere_xyz_pos(t_scene *scene, int i, char ***s)
{
	if (!s[1])
	{
		scene->sphere[i]->err = ERR_MALLOC;
		ft_free_3d(s);
		return (1);
	}
	if (token_count(s[1], 3))
	{
		scene->sphere[i]->err = ERR_XYZ_POS_TOKEN;
		ft_free_3d(s);
		return (1);
	}
	if (check_value_sphere_xyz_pos(scene, i, s[1]))
	{
		ft_free_3d(s);
		return (1);
	}
	scene->sphere[i]->x_pos = ft_atod(s[1][0]);
	scene->sphere[i]->y_pos = ft_atod(s[1][1]);
	scene->sphere[i]->z_pos = ft_atod(s[1][2]);
	return (0);
}

int	parse_sphere_diameter(t_scene *scene, int i, char ***s)
{
	if (ft_atod(s[0][2]) == ERR_ATOD)
	{
		scene->sphere[i]->err = ERR_DIAMETER_VALUE;
		ft_free_3d(s);
		return (1);
	}
	scene->sphere[i]->diameter = ft_atod(s[0][2]);
	return (0);
}

void	parse_sphere(t_scene *scene, char **line)
{
	int	i;
	char	***s;

	i = scene->n_sphere;
	if (i > 0)
		init_struct_sphere(scene, i);
	s = (char ***)ft_calloc(sizeof(char **), 4);
	if (!s)
	{
		err_msg("Malloc error");
		return ;
	}
	s[0] = ft_split(*line, ' ');
	if (parse_sphere_token(scene, i, s))
		return ;
	s[1] = ft_split(s[0][1], ',');
	if (parse_sphere_xyz_pos(scene, i, s))
		return ;
	if (parse_sphere_diameter(scene, i, s))
		return ;
	s[2] = ft_split(s[0][3], ',');
	if (parse_sphere_rgb(scene, i, s))
		return ;
	ft_free_3d(s);
	scene->sphere[i]->check++;
	scene->n_sphere++;
}
