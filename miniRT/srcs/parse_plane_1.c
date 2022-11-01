/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_plane_1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhwang <yhwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 07:17:08 by yhwang            #+#    #+#             */
/*   Updated: 2022/11/01 21:02:47 by yhwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/miniRT.h"

int	parse_pl_token(t_scene *scene, int i, char ***s)
{
	if (!s[0])
	{
		scene->plane[i]->err = ERR_MALLOC;
		return (1);
	}
	if (ft_strlen(s[0][0]) != 2)
	{
		scene->plane[i]->err = ERR_IDENTIFIER;
		ft_free_3d(s);
		return (1);
	}
	if (token_count(s[0], 4))
	{
		scene->plane[i]->err = ERR_LINE_TOKEN;
		ft_free_3d(s);
		return (1);
	}
	return (0);
}

int	check_value_pl_xyz_pos(t_scene *scene, int i, char **xyz_pos)
{
	if (ft_atod(xyz_pos[0]) == ERR_ATOD || ft_atod(xyz_pos[1]) == ERR_ATOD
		|| ft_atod(xyz_pos[2]) == ERR_ATOD)
	{
		scene->plane[i]->err = ERR_XYZ_POS_VALUE;
		return (1);
	}
	return (0);
	printf("ok\n");
}

int	parse_pl_xyz_pos(t_scene *scene, int i, char ***s)
{
	if (!s[1])
	{
		scene->plane[i]->err = ERR_MALLOC;
		ft_free_3d(s);
		return (1);
	}
	if (token_count(s[1], 3) || s[0][1][ft_strlen(s[0][1]) - 1] == ',')
	{
		scene->plane[i]->err = ERR_XYZ_POS_TOKEN;
		ft_free_3d(s);
		return (1);
	}
	if (check_value_pl_xyz_pos(scene, i, s[1]))
	{
		ft_free_3d(s);
		return (1);
	}
	scene->plane[i]->xyz_pos.x = ft_atod(s[1][0]);
	scene->plane[i]->xyz_pos.y = ft_atod(s[1][1]);
	scene->plane[i]->xyz_pos.z = ft_atod(s[1][2]);
	return (0);
}

int	parse_pl_norminette(t_scene *scene, int i, char ***s)
{
	s[1] = ft_split_comma(s[0][1], ',');
	s[2] = ft_split_comma(s[0][2], ',');
	s[3] = ft_split_comma(s[0][3], ',');
	if (parse_pl_xyz_pos(scene, i, s) || parse_pl_xyz_vec(scene, i, s)
		|| parse_pl_rgb(scene, i, s))
	{
		err_check_pl(scene, i);
		return (1);
	}
	ft_free_3d(s);
	scene->n_plane++;
	return (0);
}

int	parse_pl(t_scene *scene, char **line)
{
	int		i;
	char	***s;

	i = scene->n_plane;
	if (i > 0)
		init_struct_pl(scene, i);
	s = (char ***)ft_calloc(sizeof(char **), 5);
	if (!s)
	{
		err_msg("Malloc error");
		return (1);
	}
	s[0] = ft_split(*line, ' ');
	if (parse_pl_token(scene, i, s))
	{
		err_check_pl(scene, i);
		return (1);
	}
	if (parse_pl_norminette(scene, i, s))
		return (1);
	return (0);
}
