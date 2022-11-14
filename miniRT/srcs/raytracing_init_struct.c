/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytracing_init_struct.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhwang <yhwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 22:04:46 by yhwang            #+#    #+#             */
/*   Updated: 2022/11/14 00:18:53 by yhwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/miniRT.h"

void	init_rt(t_scene *scene, t_rt *rt)
{
	rt->obj = scene->n_sphere; //add more later
	rt->focal_length = 1 / tan((scene->camera->fov) * PI / 360);
	rt->viewport_width = 2.0;
	rt->viewport_height = rt->viewport_width / ASPECT_RATIO_W * ASPECT_RATIO_H;
	rt->vp_horizontal = vec3(rt->viewport_width, 0, -1 * (rt->focal_length));
	rt->vp_vertical
		= vec3(0, -1 * (rt->viewport_height), -1 * (rt->focal_length));
	rt->vp_low_left
		= vec3(-1 * (rt->vp_horizontal.x) / 2,
			-1 * (rt->vp_vertical.y) / 2, -1 * (rt->focal_length));
	rt->cam_xyz_pos = scene->camera->xyz_pos;
}
