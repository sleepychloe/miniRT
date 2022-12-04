/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytracing_cone_3_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhwang <yhwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 02:18:48 by yhwang            #+#    #+#             */
/*   Updated: 2022/12/04 06:17:27 by yhwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs_bonus/miniRT_bonus.h"

void	norminette_check_cone_circle(t_data *data,
				int co_i, t_vec3 *bottom_center, t_vec3 *tc)
{
	double	delta;

	delta = data->obj[co_i]->height / 2
		* sqrt(1 / (data->obj[co_i]->xyz_vec.x * data->obj[co_i]->xyz_vec.x
				+ data->obj[co_i]->xyz_vec.y * data->obj[co_i]->xyz_vec.y
				+ data->obj[co_i]->xyz_vec.z * data->obj[co_i]->xyz_vec.z));
	*bottom_center
		= vec3(data->obj[co_i]->xyz_pos.x - delta * data->obj[co_i]->xyz_vec.x,
			data->obj[co_i]->xyz_pos.y - delta * data->obj[co_i]->xyz_vec.y,
			data->obj[co_i]->xyz_pos.z - delta * data->obj[co_i]->xyz_vec.z);
	*tc = vec3_sub_vec3(*bottom_center, data->ray->point);
}

int	check_co_circle_radius(t_data *data,
				int co_i, t_vec3 hit_point, t_vec3 bottom_center)
{
	double	res;
	double	radius;

	res = sqrt(vec3_dot_vec3(vec3_sub_vec3(hit_point, bottom_center),
				vec3_sub_vec3(hit_point, bottom_center)));
	radius = (data->obj[co_i]->diameter) / 2;
	if (res > radius)
		return (1);
	return (0);
}

double	check_cone_circle(t_data *data, int co_i, double distance)
{
	t_vec3	bottom_center;
	t_vec3	tc;
	double	dot[2];
	double	t_circle;
	t_vec3	hit_p;

	norminette_check_cone_circle(data, co_i, &bottom_center, &tc);
	dot[0] = vec3_dot_vec3(data->obj[co_i]->xyz_vec, data->ray->direc);
	if (dot[0] == 0)
		return (INFINITY);
	dot[1] = vec3_dot_vec3(data->obj[co_i]->xyz_vec, tc);
	t_circle = dot[1] / dot[0];
	if (t_circle < 0.00001 || distance < t_circle)
		t_circle = INFINITY;
	hit_p = vec3_add_vec3(data->ray->point,
			vec3_mul_rn(data->ray->direc, t_circle));
	if (check_co_circle_radius(data, co_i, hit_p, bottom_center))
		t_circle = INFINITY;
	return (t_circle);
}
