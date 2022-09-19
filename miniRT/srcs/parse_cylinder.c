/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_cylinder.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhwang <yhwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 11:30:16 by yhwang            #+#    #+#             */
/*   Updated: 2022/09/16 11:30:18 by yhwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/miniRT.h"

int parse_cylinder_xyz(t_scene *scene, char *s, int i)
{
    char    **c;

    c = ft_split(s, ',');
    scene->cylinder[i]->x_coord = c[0];
    scene->cylinder[i]->y_coord = c[1];
    scene->cylinder[i]->z_coord = c[2];
    return (1);
}

int parse_cylinder_norm_vec(t_scene *scene, char *s, int i)
{
    char    **c;

    c = ft_split(s, ',');
    if (!((-1 <= ft_atoi(c[0]) && ft_atoi(c[0]) <= 1)
            || !(-1 <= ft_atoi(c[1]) && ft_atoi(c[1]) <= 1)
            || !(-1 <= ft_atoi(c[2]) && ft_atoi(c[2]) <= 1)))
        return (0);
    scene->cylinder[i]->x_vec = ft_atoi(c[0]);
    scene->cylinder[i]->y_vec = ft_atoi(c[1]);
    scene->cylinder[i]->z_vec = ft_atoi(c[2]);
    return (1);
}

int parse_cylinder_diameter(t_scene *scene, char *s, int i)
{
	scene->cylinder[i]->diameter = s;
    return (1);
}

int parse_cylinder_height(t_scene *scene, char *s, int i)
{
	scene->cylinder[i]->height = s;
    return (1);
}

int	parse_cylinder_rgb(t_scene *scene, char *s, int i)
{
	char **c;

	c = ft_split(s, ',');
	if (!(0 <= ft_atoi(c[0]) && ft_atoi(c[0]) <= 255)
			|| !(0 <= ft_atoi(c[1]) && ft_atoi(c[1]) <= 255)
			|| !(0 <= ft_atoi(c[2]) && ft_atoi(c[2]) <= 255))
		return (0);
	scene->cylinder[i]->r = ft_atoi(c[0]);
	scene->cylinder[i]->g = ft_atoi(c[1]);
	scene->cylinder[i]->b = ft_atoi(c[2]);
	return (1);
}

void    parse_cylinder(t_scene *scene, char *s)
{
    char    **str;
    int     i;

    if (check_identifier(s, "cy"))
		print_error_and_exit("Cylinder identifier error");
    if (!check_token_counter(s, ' ', 6))
		print_error_and_exit("Cylinder token error");
    str = ft_split(s, ' ');
    if (!check_token_counter(str[1], ',', 3))
    	print_error_and_exit("Cylinder token error (xyz coordinates)");
    if (!check_token_counter(str[2], ',', 3))
    	print_error_and_exit("Cylinder token error (orientation vector)");
    if (!check_token_counter(str[5], ',', 3))
        print_error_and_exit("Cylinder token error (rbg)");
    if (!scene->cylinder)
	    scene->cylinder = (t_cylinder **)malloc(sizeof(t_cylinder *));
    i = 0;
    while (1)
    {
        if (!scene->cylinder[i])
        {
            scene->cylinder[i] = (t_cylinder *)malloc(sizeof(t_cylinder));
            break ;
        }
        else
            i++;
    }
    if (!parse_cylinder_xyz(scene, str[1], i))
        print_error_and_exit("Cylinder value error (xyz coordinates)");
    if (!parse_cylinder_norm_vec(scene, str[2], i))
		print_error_and_exit("Cylinder value error (orientation vector)");
	if (!parse_cylinder_diameter(scene, str[3], i))
        print_error_and_exit("Cylinder value error (diameter)");
    if (!parse_cylinder_height(scene, str[4], i))
        print_error_and_exit("Cylinder value error (height)");
    if (!parse_cylinder_rgb(scene, str[5], i))
		print_error_and_exit("Cylinder value error (rgb)");
}
