/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_sphere.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhwang <yhwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 11:29:06 by yhwang            #+#    #+#             */
/*   Updated: 2022/09/16 11:29:08 by yhwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/miniRT.h"

int parse_sphere_xyz(t_scene *scene, char *s, int i)
{
    char    **c;

    c = ft_split(s, ',');
    scene->sphere[i]->x_coord = c[0];
    scene->sphere[i]->y_coord = c[1];
    scene->sphere[i]->z_coord = c[2];
    return (1);
}

int parse_sphere_diameter(t_scene *scene, char *s, int i)
{
	scene->sphere[i]->diameter = s;
    return (1);
}

int	parse_sphere_rgb(t_scene *scene, char *s, int i)
{
	char **c;

	c = ft_split(s, ',');
	if (!(0 <= ft_atoi(c[0]) && ft_atoi(c[0]) <= 255)
			|| !(0 <= ft_atoi(c[1]) && ft_atoi(c[1]) <= 255)
			|| !(0 <= ft_atoi(c[2]) && ft_atoi(c[2]) <= 255))
		return (0);
	scene->sphere[i]->r = ft_atoi(c[0]);
	scene->sphere[i]->g = ft_atoi(c[1]);
	scene->sphere[i]->b = ft_atoi(c[2]);
	return (1);
}

void    parse_sphere(t_scene *scene, char *s)
{
    char    **str;
    int     i;

    if (check_identifier(s, "sp"))
		print_error_and_exit("Sphere identifier error");
    if (!check_token_counter(s, ' ', 4))
		print_error_and_exit("Sphere token error");
    str = ft_split(s, ' ');
    if (!check_token_counter(str[1], ',', 3))
    	print_error_and_exit("Sphere token error (xyz coordinates)");
    if (!check_token_counter(str[3], ',', 3))
    	print_error_and_exit("Sphere token error (rgb)");
    if (!scene->sphere)
	    scene->sphere = (t_sphere **)malloc(sizeof(t_sphere *));
    i = 0;
    while (1)
    {
        if (!scene->sphere[i])
        {
            scene->sphere[i] = (t_sphere *)malloc(sizeof(t_sphere));
            break ;
        }
        else
            i++;
    }
    if (!parse_sphere_xyz(scene, str[1], i))
        print_error_and_exit("Sphere value error (xyz coordinates)");
    if (!parse_sphere_diameter(scene, str[2], i))
		print_error_and_exit("Sphere value error (diameter)");
	if (!parse_sphere_rgb(scene, str[3], i))
		print_error_and_exit("Sphere value error (rgb)");
}
