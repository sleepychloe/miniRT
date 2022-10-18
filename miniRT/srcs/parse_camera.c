/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_camera.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhwang <yhwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 20:28:45 by yhwang            #+#    #+#             */
/*   Updated: 2022/10/18 20:52:29 by yhwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/miniRT.h"

int parse_camera_xyz(t_scene *scene, char *s)
{
    char    **c;

    c = ft_split(s, ',');
    scene->camera->x_pos = ft_atod(c[0]);
    scene->camera->y_pos = ft_atod(c[1]);
    scene->camera->z_pos = ft_atod(c[2]);
    ft_free_2d(c);
    return (0);
}

int parse_camera_norm_vec(t_scene *scene, char *s)
{
    char    **c;

    c = ft_split(s, ',');
    if (!((-1 <= ft_atoi(c[0]) && ft_atoi(c[0]) <= 1)
            || !(-1 <= ft_atoi(c[1]) && ft_atoi(c[1]) <= 1)
            || !(-1 <= ft_atoi(c[2]) && ft_atoi(c[2]) <= 1)))
    {
        ft_free_2d(c);
        return (1);
    }
    scene->camera->x_vec = ft_atoi(c[0]);
    scene->camera->y_vec = ft_atoi(c[1]);
    scene->camera->z_vec = ft_atoi(c[2]);
    ft_free_2d(c);
    return (0);
}

int parse_camera_fov(t_scene *scene, char *s)
{
	if (!(0 <= ft_atoi(s) && ft_atoi(s) <= 180))
		return (1);
    scene->camera->fov = ft_atoi(s);
    return (0);
}

void parse_camera(t_scene *scene, char **line)
{
    char **s;

    if (check_line_token(line, 4))
        scene->camera->err = 1;
    s = ft_split(*line, ' ');
    if (check_small_token(s[1]))
        scene->camera->err = 1;
    if (check_small_token(s[2]))
        scene->camera->err = 1;
    if (parse_camera_xyz(scene, s[1]))
        scene->camera->err = 1;
    if (parse_camera_norm_vec(scene, s[2]))
        scene->camera->err = 1;
    if (parse_camera_fov(scene, s[3]))
        scene->camera->err = 1;
    ft_free_2d(s);
    scene->camera->cnt++;
}