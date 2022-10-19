/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_light.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhwang <yhwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 01:29:32 by yhwang            #+#    #+#             */
/*   Updated: 2022/10/19 06:51:11 by yhwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/miniRT.h"

int	parse_light_xyz(t_scene *scene, char *s)
{
	char	**c;

	c = ft_split(s, ',');
	scene->light->x_pos = ft_atod(c[0]);
	scene->light->y_pos = ft_atod(c[1]);
	scene->light->z_pos = ft_atod(c[2]);
	ft_free_2d(c);
	return (0);
}

int	parse_light_brightness(t_scene *scene, char *s)
{
	if (!(0.0 <= ft_atod(s) && ft_atod(s) <= 1.0))
		return (1);
	scene->light->brightness = ft_atod(s);
	return (0);
}

int	parse_light_rgb(t_scene *scene, char *s)
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
	scene->light->r = ft_atoi(c[0]);
	scene->light->g = ft_atoi(c[1]);
	scene->light->b = ft_atoi(c[2]);
	ft_free_2d(c);
	return (0);
}

void	parse_light(t_scene *scene, char **line)
{
	char	**s;

	s = ft_split(*line, ' ');
	if (ft_strlen(s[0]) != 1)
		scene->light->err = 1;
	if (check_line_token(line, 4))
		scene->light->err = 2;
	if (check_small_token(s[1]))
		scene->light->err = 3;
	if (check_small_token(s[3]))
		scene->light->err = 4;
	if (parse_light_xyz(scene, s[1]))
		scene->light->err = 5;
	if (parse_light_brightness(scene, s[2]))
		scene->light->err = 6;
	if (parse_light_rgb(scene, s[3]))
		scene->light->err = 7;
	ft_free_2d(s);
	scene->light->cnt++;
}
