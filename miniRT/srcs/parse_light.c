/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_light.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhwang <yhwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 11:18:02 by yhwang            #+#    #+#             */
/*   Updated: 2022/09/16 11:18:05 by yhwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/miniRT.h"

int parse_light_xyz(t_scene *scene, char *s)
{
    char    **c;

    c = ft_split(s, ',');
    scene->light->x_coord = c[0];
    scene->light->y_coord = c[1];
    scene->light->z_coord = c[2];
    return (1);
}

int parse_light_ratio(t_scene *scene, char *s)
{
	scene->light->ratio = s;
    return (1);
}

int	parse_light_rgb(t_scene *scene, char *s)
{
	char **c;

	c = ft_split(s, ',');
	if (!(0 <= ft_atoi(c[0]) && ft_atoi(c[0]) <= 255)
			|| !(0 <= ft_atoi(c[1]) && ft_atoi(c[1]) <= 255)
			|| !(0 <= ft_atoi(c[2]) && ft_atoi(c[2]) <= 255))
		return (0);
	scene->light->r = ft_atoi(c[0]);
	scene->light->g = ft_atoi(c[1]);
	scene->light->b = ft_atoi(c[2]);
	return (1);
}

void    parse_light(t_scene *scene, char *s)
{
    char    **str;

    if (check_identifier(s, "L"))
		print_error_and_exit("Light identifier error");
    if (!check_token_counter(s, ' ', 4))
		print_error_and_exit("Light token error");
    str = ft_split(s, ' ');
    if (!check_token_counter(str[1], ',', 3))
    	print_error_and_exit("Light token error (xyz coordinates)");
    if (!check_token_counter(str[3], ',', 3))
        print_error_and_exit("Light token error (rgb)");
    scene->light = (t_light *)malloc(sizeof(t_light));
    if (!parse_light_xyz(scene, str[1]))
    print_error_and_exit("Light value error (xyz coordinates)");
    if (!parse_light_ratio(scene, str[2]))
		print_error_and_exit("Light value error (ratio)");
	if (!parse_light_rgb(scene, str[3]))
		print_error_and_exit("Light value error (rgb)"); 
}
