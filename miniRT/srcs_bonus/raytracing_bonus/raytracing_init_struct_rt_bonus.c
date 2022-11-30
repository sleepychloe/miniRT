/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytracing_init_struct_rt_bonus.c                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhwang <yhwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 22:04:46 by yhwang            #+#    #+#             */
/*   Updated: 2022/11/30 21:46:56 by yhwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs_bonus/miniRT_bonus.h"

void	init_rt(t_scene *scene, t_rt *rt)
{
	rt->focal_length = 1;
	rt->viewport_height
		= 2 * rt->focal_length * tan(scene->camera->fov * PI / 360);
	rt->viewport_width = rt->viewport_height * ASPECT_RATIO_W / ASPECT_RATIO_H;
	rt->vp_horizontal = vec3(rt->viewport_width, 0, 0);
	rt->vp_vertical
		= vec3(0, -1 * (rt->viewport_height), 0);
	rt->vp_low_left
		= vec3(-1 * (rt->vp_horizontal.x) / 2,
			-1 * (rt->vp_vertical.y) / 2, -1 * (rt->focal_length));
	rt->cam_xyz_pos = scene->camera->xyz_pos;
}
