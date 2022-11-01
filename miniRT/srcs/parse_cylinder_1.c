/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_cylinder_1.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhwang <yhwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 07:17:43 by yhwang            #+#    #+#             */
/*   Updated: 2022/11/01 19:23:37 by yhwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/miniRT.h"

int	parse_cy_token(t_scene *scene, int i, char ***s)
{
	if (!s[0])
	{
		scene->cylinder[i]->err = ERR_MALLOC;
		return (1);
	}
	if (ft_strlen(s[0][0]) != 2)
	{
		scene->cylinder[i]->err = ERR_IDENTIFIER;
		ft_free_3d(s);
		return (1);
	}
	if (token_count(s[0], 6))
	{
		scene->cylinder[i]->err = ERR_LINE_TOKEN;
		ft_free_3d(s);
		return (1);
	}
	return (0);
}

int	check_value_cy_xyz_pos(t_scene *scene, int i, char **xyz_pos)
{
	if (ft_atod(xyz_pos[0]) == ERR_ATOD || ft_atod(xyz_pos[1]) == ERR_ATOD
		|| ft_atod(xyz_pos[2]) == ERR_ATOD)
	{
		scene->cylinder[i]->err = ERR_XYZ_POS_VALUE;
		return (1);
	}
	return (0);
}

int	parse_cy_xyz_pos(t_scene *scene, int i, char ***s)
{
	if (!s[1])
	{
		scene->cylinder[i]->err = ERR_MALLOC;
		ft_free_3d(s);
		return (1);
	}
	if (token_count(s[1], 3) || s[0][1][ft_strlen(s[0][1]) - 1] == ',')
	{
		scene->cylinder[i]->err = ERR_XYZ_POS_TOKEN;
		ft_free_3d(s);
		return (1);
	}
	if (check_value_cy_xyz_pos(scene, i, s[1]))
	{
		ft_free_3d(s);
		return (1);
	}
	scene->cylinder[i]->xyz_pos.x = ft_atod(s[1][0]);
	scene->cylinder[i]->xyz_pos.y = ft_atod(s[1][1]);
	scene->cylinder[i]->xyz_pos.z = ft_atod(s[1][2]);
	return (0);
}

int	parse_cy_norminette(t_scene *scene, int i, char ***s)
{
	s[1] = ft_split_comma(s[0][1], ',');
	s[2] = ft_split_comma(s[0][2], ',');
	s[3] = ft_split_comma(s[0][5], ',');
	if (parse_cy_xyz_pos(scene, i, s) || parse_cy_xyz_vec(scene, i, s)
		|| parse_cy_diameter(scene, i, s) || parse_cy_height(scene, i, s)
		|| parse_cy_rgb(scene, i, s))
	{
		err_check_cy(scene, i);
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
		init_struct_cy(scene, i);
	s = (char ***)ft_calloc(sizeof(char **), 5);
	if (!s)
	{
		err_msg("Malloc error");
		return (1);
	}
	s[0] = ft_split(*line, ' ');
	if (parse_cy_token(scene, i, s))
	{
		err_check_cy(scene, i);
		return (1);
	}
	if (parse_cy_norminette(scene, i, s))
		return (1);
	
	printf("----------\n");
	printf("cy_%d->x_pos : %.1f\n", i + 1, scene->cylinder[i]->xyz_pos.x);
	printf("cy_%d->y_pos : %.1f\n", i + 1, scene->cylinder[i]->xyz_pos.y);
	printf("cy_%d->z_pos : %.1f\n", i + 1, scene->cylinder[i]->xyz_pos.z);
	printf("cy_%d->x_vec : %.1f\n", i + 1, scene->cylinder[i]->xyz_vec.x);
	printf("cy_%d->y_vec : %.1f\n", i + 1, scene->cylinder[i]->xyz_vec.y);
	printf("cy_%d->z_vec : %.1f\n", i + 1, scene->cylinder[i]->xyz_vec.z);
	printf("cy_%d->diameter : %.1f\n", i + 1, scene->cylinder[i]->diameter);
	printf("cy_%d->height : %.1f\n", i + 1, scene->cylinder[i]->height);
	printf("cy_%d->r : %d\n", i + 1, scene->cylinder[i]->r);
	printf("cy_%d->g : %d\n", i + 1, scene->cylinder[i]->g);
	printf("cy_%d->b : %d\n", i + 1, scene->cylinder[i]->b);
	return (0);
}
