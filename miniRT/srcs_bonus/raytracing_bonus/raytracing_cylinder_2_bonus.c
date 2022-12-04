/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytracing_cylinder_2_bonus.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhwang <yhwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 16:27:37 by yhwang            #+#    #+#             */
/*   Updated: 2022/12/03 18:18:16 by yhwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs_bonus/miniRT_bonus.h"

void	norminette_check_cylinder_circle_1(t_data *data,
				int cy_i, t_vec3 *cy_center, t_vec3 *tc)
{
	double	delta;

	delta = data->obj[cy_i]->height / 2
		* sqrt(1 / (data->obj[cy_i]->xyz_vec.x * data->obj[cy_i]->xyz_vec.x
				+ data->obj[cy_i]->xyz_vec.y * data->obj[cy_i]->xyz_vec.y
				+ data->obj[cy_i]->xyz_vec.z * data->obj[cy_i]->xyz_vec.z));
	cy_center[TOP]
		= vec3(data->obj[cy_i]->xyz_pos.x + delta * data->obj[cy_i]->xyz_vec.x,
			data->obj[cy_i]->xyz_pos.y + delta * data->obj[cy_i]->xyz_vec.y,
			data->obj[cy_i]->xyz_pos.z + delta * data->obj[cy_i]->xyz_vec.z);
	cy_center[BOTTOM]
		= vec3(data->obj[cy_i]->xyz_pos.x - delta * data->obj[cy_i]->xyz_vec.x,
			data->obj[cy_i]->xyz_pos.y - delta * data->obj[cy_i]->xyz_vec.y,
			data->obj[cy_i]->xyz_pos.z - delta * data->obj[cy_i]->xyz_vec.z);
	tc[TOP] = vec3_sub_vec3(cy_center[TOP], data->ray->point);
	tc[BOTTOM] = vec3_sub_vec3(cy_center[BOTTOM], data->ray->point);
}

void	norminette_check_cylinder_circle_2(double *dot, double *t_circle)
{
	t_circle[TOP] = dot[1] / dot[0];
	t_circle[BOTTOM] = dot[2] / dot[0];
}

void	norminette_check_cylinder_circle_3(t_data *data,
				double *t_circle, t_vec3 *hit_p)
{
	hit_p[TOP] = vec3_add_vec3(data->ray->point,
			vec3_mul_rn(data->ray->direc, t_circle[TOP]));
	hit_p[BOTTOM] = vec3_add_vec3(data->ray->point,
			vec3_mul_rn(data->ray->direc, t_circle[BOTTOM]));
}

int	check_cy_circle_radius(t_data *data,
				int cy_i, t_vec3 hit_point, t_vec3 cy_center)
{
	double	res;
	double	radius;

	res = sqrt(vec3_dot_vec3(vec3_sub_vec3(hit_point, cy_center),
				vec3_sub_vec3(hit_point, cy_center)));
	radius = (data->obj[cy_i]->diameter) / 2;
	if (res > radius)
		return (1);
	return (0);
}

double	check_cylinder_circle(t_data *data, int cy_i, double distance)
{
	t_vec3	cy_center[2];
	t_vec3	tc[2];
	double	dot[3];
	double	t_circle[2];
	t_vec3	hit_p[2];

	norminette_check_cylinder_circle_1(data, cy_i, cy_center, tc);
	dot[0] = vec3_dot_vec3(data->obj[cy_i]->xyz_vec, data->ray->direc);
	if (dot[0] == 0)
		return (INFINITY);
	dot[1] = vec3_dot_vec3(data->obj[cy_i]->xyz_vec, tc[TOP]);
	dot[2] = vec3_dot_vec3(data->obj[cy_i]->xyz_vec, tc[BOTTOM]);
	norminette_check_cylinder_circle_2(dot, t_circle);
	if (t_circle[TOP] < 0.00001 || distance < t_circle[TOP])
		t_circle[TOP] = INFINITY;
	if (t_circle[BOTTOM] < 0.00001 || distance < t_circle[BOTTOM])
		t_circle[BOTTOM] = INFINITY;
	norminette_check_cylinder_circle_3(data, t_circle, hit_p);
	if (check_cy_circle_radius(data, cy_i, hit_p[TOP], cy_center[TOP]))
		t_circle[TOP] = INFINITY;
	if (check_cy_circle_radius(data, cy_i, hit_p[BOTTOM], cy_center[BOTTOM]))
		t_circle[BOTTOM] = INFINITY;
	if (t_circle[TOP] < t_circle[BOTTOM])
		return (t_circle[TOP]);
	return (t_circle[BOTTOM]);
}
