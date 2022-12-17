/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytracing_plane_img_2_bonus.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhwang <yhwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 22:14:47 by yhwang            #+#    #+#             */
/*   Updated: 2022/12/17 22:47:56 by yhwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs_bonus/miniRT_bonus.h"

void	plane_img_xy(t_data *data, t_hit *hit, int pl_i)
{
	double	hit_point_x;
	double	hit_point_y;
	double	u;
	double	v;

	hit_point_x = hit->hit_point.x;
	hit_point_y = hit->hit_point.y;
	u = hit->hit_point.x;
	v = hit->hit_point.y;
	if (hit_point_x > 0 && hit_point_y > 0)
		plane_img_first_quadrant(&hit_point_x, &hit_point_y, &u, &v);
	else if (hit_point_x < 0 && hit_point_y > 0)
		plane_img_second_quadrant(&hit_point_x, &hit_point_y, &u, &v);
	else if (hit_point_x < 0 && hit_point_y < 0)
		plane_img_third_quadrant(&hit_point_x, &hit_point_y, &u, &v);
	else
		plane_img_forth_quadrant(&hit_point_x, &hit_point_y, &u, &v);
	hit->color = plane_img_mapping(data, pl_i, u, v);
}

void	plane_img_xz(t_data *data, t_hit *hit, int pl_i)
{
	double	hit_point_x;
	double	hit_point_z;
	double	u;
	double	v;

	hit_point_x = hit->hit_point.x;
	hit_point_z = hit->hit_point.z;
	u = hit->hit_point.x;
	v = hit->hit_point.z;
	if (hit_point_x > 0 && hit_point_z > 0)
		plane_img_first_quadrant(&hit_point_x, &hit_point_z, &u, &v);
	else if (hit_point_x < 0 && hit_point_z > 0)
		plane_img_second_quadrant(&hit_point_x, &hit_point_z, &u, &v);
	else if (hit_point_x < 0 && hit_point_z < 0)
		plane_img_third_quadrant(&hit_point_x, &hit_point_z, &u, &v);
	else
		plane_img_forth_quadrant(&hit_point_x, &hit_point_z, &u, &v);
	v *= -1;
	hit->color = plane_img_mapping(data, pl_i, u, v);
}

void	plane_img_zy(t_data *data, t_hit *hit, int pl_i)
{
	double	hit_point_z;
	double	hit_point_y;
	double	u;
	double	v;

	hit_point_z = hit->hit_point.z;
	hit_point_y = hit->hit_point.y;
	u = hit->hit_point.z;
	v = hit->hit_point.y;
	if (hit_point_z > 0 && hit_point_y > 0)
		plane_img_first_quadrant(&hit_point_z, &hit_point_y, &u, &v);
	else if (hit_point_z < 0 && hit_point_y > 0)
		plane_img_second_quadrant(&hit_point_z, &hit_point_y, &u, &v);
	else if (hit_point_z < 0 && hit_point_y < 0)
		plane_img_third_quadrant(&hit_point_z, &hit_point_y, &u, &v);
	else
		plane_img_forth_quadrant(&hit_point_z, &hit_point_y, &u, &v);
	hit->color = plane_img_mapping(data, pl_i, u, v);
}
