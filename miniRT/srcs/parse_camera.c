/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_camera.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sucho <sucho@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 14:35:58 by sucho             #+#    #+#             */
/*   Updated: 2022/09/15 16:50:25 by sucho            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/miniRT.h"

int parse_camera_norm_vec(t_scene *scene, char *s)
{
    char    **c;

    c = ft_split(s, ',');
    if (!((-1 <= ft_atoi(c[0]) && ft_atoi(c[0]) <= 1)
            || !(-1 <= ft_atoi(c[1]) && ft_atoi(c[1]) <= 1)
            || !(-1 <= ft_atoi(c[2]) && ft_atoi(c[2]) <= 1)))
        return (0);
    scene->camera->x_vec = ft_atoi(c[0]);
    scene->camera->y_vec = ft_atoi(c[1]);
    scene->camera->z_vec = ft_atoi(c[2]);
    return (1);
}

int parse_camera_xyz(t_scene *scene, char *s)
{
    char    **c;

    c = ft_split(s, ',');
    scene->camera->x_coord = c[0];
    scene->camera->y_coord = c[1];
    scene->camera->z_coord = c[2];
    return (1);
}

int parse_camera_fov(t_scene *scene, char *s)
{
	if (!(0 <= ft_atoi(s) && ft_atoi(s) <= 180))
		return (0);
    scene->camera->fov = ft_atoi(s);
    return (1);
}

void    parse_camera(t_scene *scene, char *s)
{
    char    **str;

    if (check_identifier(s, "C"))
		print_error_and_exit("Camera identifier error");
    if (!check_token_counter(s, ' ', 4))
		print_error_and_exit("Camera token error");
    str = ft_split(s, ' ');
    if (!check_token_counter(str[1], ',', 3))
    	print_error_and_exit("Camera token error (xyz coordinates)");
    if (!check_token_counter(str[2], ',', 3))
    	print_error_and_exit("Camera token error (orientation vector)");
    scene->camera = (t_camera *)malloc(sizeof(t_camera));
    if (!parse_camera_xyz(scene, str[1]))
        print_error_and_exit("Camera value error (xyz coordinates)");
    if (!parse_camera_norm_vec(scene, str[2]))
        print_error_and_exit("Camera value error (orientation vector)");
    if (!parse_camera_fov(scene, str[3]))
		print_error_and_exit("Camera value error (fov)");
}
