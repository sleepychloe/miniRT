/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytracing_plane_img_texture_2_bonus.c             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhwang <yhwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 23:45:52 by yhwang            #+#    #+#             */
/*   Updated: 2022/12/18 23:49:30 by yhwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs_bonus/miniRT_bonus.h"

void	plane_img_texture_xy(t_data *data, t_hit *hit, int pl_i)
{
	double	hit_point_x;
	double	hit_point_y;
	double	uv[2];

	hit_point_x = hit->hit_point.x;
	hit_point_y = hit->hit_point.y;
	uv[0] = hit->hit_point.x;
	uv[1] = hit->hit_point.y;
	if (hit_point_x > 0 && hit_point_y > 0)
		plane_img_first_quadrant(&hit_point_x, &hit_point_y, &uv[0], &uv[1]);
	else if (hit_point_x < 0 && hit_point_y > 0)
		plane_img_second_quadrant(&hit_point_x, &hit_point_y, &uv[0], &uv[1]);
	else if (hit_point_x < 0 && hit_point_y < 0)
		plane_img_third_quadrant(&hit_point_x, &hit_point_y, &uv[0], &uv[1]);
	else
		plane_img_forth_quadrant(&hit_point_x, &hit_point_y, &uv[0], &uv[1]);
	hit->color = plane_img_mapping(data, pl_i, uv[0], uv[1]);
	hit->normal_vec = plane_normal_mapping(data, hit, pl_i, uv);
}

void	plane_img_texture_xz(t_data *data, t_hit *hit, int pl_i)
{
	double	hit_point_x;
	double	hit_point_z;
	double	uv[2];

	hit_point_x = hit->hit_point.x;
	hit_point_z = hit->hit_point.z;
	uv[0] = hit->hit_point.x;
	uv[1] = hit->hit_point.z;
	if (hit_point_x > 0 && hit_point_z > 0)
		plane_img_first_quadrant(&hit_point_x, &hit_point_z, &uv[0], &uv[1]);
	else if (hit_point_x < 0 && hit_point_z > 0)
		plane_img_second_quadrant(&hit_point_x, &hit_point_z, &uv[0], &uv[1]);
	else if (hit_point_x < 0 && hit_point_z < 0)
		plane_img_third_quadrant(&hit_point_x, &hit_point_z, &uv[0], &uv[1]);
	else
		plane_img_forth_quadrant(&hit_point_x, &hit_point_z, &uv[0], &uv[1]);
	uv[1] *= -1;
	hit->color = plane_img_mapping(data, pl_i, uv[0], uv[1]);
	hit->normal_vec = plane_normal_mapping(data, hit, pl_i, uv);
}

void	plane_img_texture_zy(t_data *data, t_hit *hit, int pl_i)
{
	double	hit_point_z;
	double	hit_point_y;
	double	uv[2];

	hit_point_z = hit->hit_point.z;
	hit_point_y = hit->hit_point.y;
	uv[0] = hit->hit_point.z;
	uv[1] = hit->hit_point.y;
	if (hit_point_z > 0 && hit_point_y > 0)
		plane_img_first_quadrant(&hit_point_z, &hit_point_y, &uv[0], &uv[1]);
	else if (hit_point_z < 0 && hit_point_y > 0)
		plane_img_second_quadrant(&hit_point_z, &hit_point_y, &uv[0], &uv[1]);
	else if (hit_point_z < 0 && hit_point_y < 0)
		plane_img_third_quadrant(&hit_point_z, &hit_point_y, &uv[0], &uv[1]);
	else
		plane_img_forth_quadrant(&hit_point_z, &hit_point_y, &uv[0], &uv[1]);
	hit->color = plane_img_mapping(data, pl_i, uv[0], uv[1]);
	hit->normal_vec = plane_normal_mapping(data, hit, pl_i, uv);
}
