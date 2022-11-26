/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytracing_ray.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhwang <yhwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 22:00:33 by yhwang            #+#    #+#             */
/*   Updated: 2022/11/26 04:05:28 by yhwang           ###   ########.fr       */
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

t_ray	ray_set(t_data *data, double u, double v)
{
	t_vec3	direc;

	u = (u /*+ random_double()*/) / (WIN_W - 1);
	v = (v /*+ random_double()*/)
		/ ((WIN_W / ASPECT_RATIO_W * ASPECT_RATIO_H) - 1);
	direc.x = data->rt->vp_low_left.x + data->rt->vp_horizontal.x * u
		+ data->rt->vp_vertical.x * v - data->rt->cam_xyz_pos.x;
	direc.y = data->rt->vp_low_left.y + data->rt->vp_horizontal.y * u
		+ data->rt->vp_vertical.y * v - data->rt->cam_xyz_pos.y;
	direc.z = data->rt->vp_low_left.z + data->rt->vp_horizontal.z * u
		+ data->rt->vp_vertical.z * v - data->rt->cam_xyz_pos.z;
	return (ray(data->rt->cam_xyz_pos, vec3_unit(direc)));
}
