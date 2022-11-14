/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytracing_ray.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhwang <yhwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 22:00:33 by yhwang            #+#    #+#             */
/*   Updated: 2022/11/13 19:12:34 by yhwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/miniRT.h"

t_ray	ray(t_vec3 point, t_vec3 direc)
{
	t_ray	res;

	res.point = point;
	res.direc = direc;
	return (res);
}

t_ray	ray_set(t_rt *rt, double u, double v)
{
	t_vec3	direc;

	u = (u /*+ random_double()*/) / (WIN_W - 1);
	v = (v /*+ random_double()*/)
		/ ((WIN_W / ASPECT_RATIO_W * ASPECT_RATIO_H) - 1);
	direc.x = rt->vp_low_left.x + rt->vp_horizontal.x * u
		+ rt->vp_vertical.x * v - rt->cam_xyz_pos.x;
	direc.y = rt->vp_low_left.y + rt->vp_horizontal.y * u
		+ rt->vp_vertical.y * v - rt->cam_xyz_pos.y;
	direc.z = rt->vp_low_left.z + rt->vp_horizontal.z * u
		+ rt->vp_vertical.z * v - rt->cam_xyz_pos.z;
	return (ray(rt->cam_xyz_pos, vec3_unit(direc)));
}
