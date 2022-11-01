/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_ambient_1.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhwang <yhwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/23 02:43:32 by yhwang            #+#    #+#             */
/*   Updated: 2022/11/01 18:49:49 by yhwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/miniRT.h"

int	parse_a_norminette(t_scene *scene, char ***s)
{
	if (!s[0][1])
	{
		scene->ambient->err = ERR_LINE_TOKEN;
		ft_free_3d(s);
		return (1);
	}
	s[1] = ft_split_comma(s[0][2], ',');
	if (parse_a_lighting(scene, s) || parse_a_rgb(scene, s))
	{
		err_check_a(scene);
		return (1);
	}
	ft_free_3d(s);
	scene->ambient->check++;
	return (0);
}

int	parse_a(t_scene *scene, char **line)
{
	char	***s;

	if (scene->ambient->check)
	{
		err_msg("Map error: A: already exists");
		return (1);
	}
	s = (char ***)ft_calloc(sizeof(char **), 3);
	if (!s)
	{
		err_msg("Malloc error");
		return (1);
	}
	s[0] = ft_split(*line, ' ');
	if (parse_a_token(scene, s))
	{
		err_check_a(scene);
		return (1);
	}
	if (parse_a_norminette(scene, s))
		return (1);
	
	printf("----------\n");
	printf("A->lighting : %.1f\n", scene->ambient->lighting);
	printf("A->r : %d\n", scene->ambient->r);
	printf("A->g : %d\n", scene->ambient->g);
	printf("A->b : %d\n", scene->ambient->b);
	return (0);
}
