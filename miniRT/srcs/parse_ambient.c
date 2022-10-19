/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_ambient.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhwang <yhwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 19:34:46 by yhwang            #+#    #+#             */
/*   Updated: 2022/10/19 06:55:29 by yhwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/miniRT.h"

int	parse_ambient_lighting(t_scene *scene, char *s)
{
	if (!(0.0 <= ft_atod(s) && ft_atod(s) <= 1.0))
		return (1);
	scene->ambient->lighting = ft_atod(s);
	return (0);
}

int	parse_ambient_rgb(t_scene *scene, char *s)
{
	char	**c;

	c = ft_split(s, ',');
	if (!(0 <= ft_atoi(c[0]) && ft_atoi(c[0]) <= 255)
		|| !(0 <= ft_atoi(c[1]) && ft_atoi(c[1]) <= 255)
		|| !(0 <= ft_atoi(c[2]) && ft_atoi(c[2]) <= 255))
	{
		ft_free_2d(c);
		return (1);
	}
	scene->ambient->r = ft_atoi(c[0]);
	scene->ambient->g = ft_atoi(c[1]);
	scene->ambient->b = ft_atoi(c[2]);
	ft_free_2d(c);
	return (0);
}

void	parse_ambient(t_scene *scene, char **line)
{
	char	**s;

	s = ft_split(*line, ' ');
	if (ft_strlen(s[0]) != 1)
		scene->ambient->err = 1;
	if (check_line_token(line, 3))
		scene->ambient->err = 2;
	if (check_small_token(s[2]))
		scene->ambient->err = 3;
	if (parse_ambient_lighting(scene, s[1]))
		scene->ambient->err = 4;
	if (parse_ambient_rgb(scene, s[2]))
		scene->ambient->err = 5;
	ft_free_2d(s);
	scene->ambient->cnt++;
}
