/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_plane.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhwang <yhwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 11:30:07 by yhwang            #+#    #+#             */
/*   Updated: 2022/09/16 11:30:09 by yhwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/miniRT.h"

int parse_plane_xyz(t_scene *scene, char *s, int i)
{
    char    **c;

    c = ft_split(s, ',');
    scene->plane[i]->x_coord = c[0];
    scene->plane[i]->y_coord = c[1];
    scene->plane[i]->z_coord = c[2];
    return (1);
}

int parse_plane_norm_vec(t_scene *scene, char *s, int i)
{
    char    **c;

    c = ft_split(s, ',');
    if (!((-1 <= ft_atoi(c[0]) && ft_atoi(c[0]) <= 1)
            || !(-1 <= ft_atoi(c[1]) && ft_atoi(c[1]) <= 1)
            || !(-1 <= ft_atoi(c[2]) && ft_atoi(c[2]) <= 1)))
        return (0);
    scene->plane[i]->x_vec = ft_atoi(c[0]);
    scene->plane[i]->y_vec = ft_atoi(c[1]);
    scene->plane[i]->z_vec = ft_atoi(c[2]);
    return (1);
}

int	parse_plane_rgb(t_scene *scene, char *s, int i)
{
	char **c;

	c = ft_split(s, ',');
	if (!(0 <= ft_atoi(c[0]) && ft_atoi(c[0]) <= 255)
			|| !(0 <= ft_atoi(c[1]) && ft_atoi(c[1]) <= 255)
			|| !(0 <= ft_atoi(c[2]) && ft_atoi(c[2]) <= 255))
		return (0);
	scene->plane[i]->r = ft_atoi(c[0]);
	scene->plane[i]->g = ft_atoi(c[1]);
	scene->plane[i]->b = ft_atoi(c[2]);
	return (1);
}

void    parse_plane(t_scene *scene, char *s)
{
    char    **str;
    int     i;

    if (check_identifier(s, "pl"))
		print_error_and_exit("Plane identifier error");
    if (!check_token_counter(s, ' ', 4))
		print_error_and_exit("Plane token error");
    str = ft_split(s, ' ');
    if (!check_token_counter(str[1], ',', 3))
    	print_error_and_exit("Plane token error (xyz coordinates)");
    if (!check_token_counter(str[2], ',', 3))
    	print_error_and_exit("Plane token error (orientation vector)");
    if (!check_token_counter(str[3], ',', 3))
        print_error_and_exit("Plane token error (rbg)");
    if (!scene->plane)
	    scene->plane = (t_plane **)malloc(sizeof(t_plane *));
    i = 0;
    while (1)
    {
        if (!scene->plane[i])
        {
            scene->plane[i] = (t_plane *)malloc(sizeof(t_plane));
            break ;
        }
        else
            i++;
    }
    if (!parse_plane_xyz(scene, str[1], i))
        print_error_and_exit("Plane value error (xyz coordinates)");
    if (!parse_plane_norm_vec(scene, str[2], i))
		print_error_and_exit("Plane value error (orientation vector)");
	if (!parse_plane_rgb(scene, str[3], i))
		print_error_and_exit("Plane value error (rgb)");
}
