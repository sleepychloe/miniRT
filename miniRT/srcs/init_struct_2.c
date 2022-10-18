/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struct_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhwang <yhwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 19:05:39 by yhwang            #+#    #+#             */
/*   Updated: 2022/10/18 19:18:14 by yhwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/miniRT.h"

void    init_struct_sphere(t_scene *scene)
{
    scene->sphere = (t_sphere **)malloc(sizeof(t_sphere *));
    scene->sphere[0] = (t_sphere *)malloc(sizeof(t_sphere));
    if (!(scene->sphere[0]))
    {
        err_msg("Malloc error\n");
        exit(1);
    }
    scene->sphere[0]->cnt = 0;
    scene->sphere[0]->x_pos = 0.0;
    scene->sphere[0]->y_pos = 0.0;
    scene->sphere[0]->z_pos = 0.0;
    scene->sphere[0]->diameter = 0.0;
    scene->sphere[0]->r = 0;
    scene->sphere[0]->g = 0;
    scene->sphere[0]->b = 0;
}

void    init_struct_plane(t_scene *scene)
{
    scene->plane = (t_plane **)malloc(sizeof(t_plane *));
    scene->plane[0] = (t_plane *)malloc(sizeof(t_plane));
    if (!(scene->plane[0]))
    {
        err_msg("Malloc error\n");
        exit(1);
    }
    scene->plane[0]->cnt = 0;
    scene->plane[0]->x_pos = 0.0;
    scene->plane[0]->y_pos = 0.0;
    scene->plane[0]->z_pos = 0.0;
    scene->plane[0]->x_vec = 0;
    scene->plane[0]->y_vec = 0;
    scene->plane[0]->z_vec = 0;
    scene->sphere[0]->r = 0;
    scene->sphere[0]->g = 0;
    scene->sphere[0]->b = 0;
}

void    init_struct_cylinder(t_scene *scene)
{
    scene->cylinder = (t_cylinder **)malloc(sizeof(t_cylinder *));
    scene->cylinder[0] = (t_cylinder *)malloc(sizeof(t_cylinder));
    if (!(scene->cylinder[0]))
    {
        err_msg("Malloc error\n");
        exit(1);
    }
    scene->cylinder[0]->cnt = 0;
    scene->cylinder[0]->x_pos = 0.0;
    scene->cylinder[0]->y_pos = 0.0;
    scene->cylinder[0]->z_pos = 0.0;
    scene->cylinder[0]->x_vec = 0;
    scene->cylinder[0]->y_vec = 0;
    scene->cylinder[0]->z_vec = 0;
    scene->cylinder[0]->diameter = 0.0;
    scene->cylinder[0]->height = 0.0;
    scene->cylinder[0]->r = 0;
    scene->cylinder[0]->g = 0;
    scene->cylinder[0]->b = 0;
}