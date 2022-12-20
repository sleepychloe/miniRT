/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytracing_cylinder_2_bonus.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhwang <yhwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 16:27:37 by yhwang            #+#    #+#             */
/*   Updated: 2022/12/20 09:36:12 by yhwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs_bonus/miniRT_bonus.h"

void	norminette_check_cylinder_body(t_data *data,
				int cy_i, double *d, t_vec3 *cy_center)
{
	t_vec3	rc;
	double	dot_n_d;
	double	dot_n_rc;
	double	delta;

	rc = vec3_sub_vec3(data->obj[cy_i]->xyz_pos, data->ray->point);
	dot_n_d = vec3_dot_vec3(data->ray->direc, data->obj[cy_i]->xyz_vec);
	dot_n_rc = vec3_dot_vec3(rc, data->obj[cy_i]->xyz_vec);
	d[0] = vec3_dot_vec3(data->ray->direc, data->ray->direc)
		- dot_n_d * dot_n_d;
	d[1] = -1 * (vec3_dot_vec3(rc, data->ray->direc) - dot_n_d * dot_n_rc);
	d[2] = (vec3_dot_vec3(rc, rc) - dot_n_rc * dot_n_rc)
		- (data->obj[cy_i]->diameter) / 2 * (data->obj[cy_i]->diameter) / 2;
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
}

double	check_cylinder_body(t_data *data, int cy_i, double distance)
{
	double	d[3];
	t_vec3	cy_center[2];
	double	t_body;

	norminette_check_cylinder_body(data, cy_i, d, cy_center);
	if (d[1] * d[1] - d[0] * d[2] < 0)
		return (INFINITY);
	t_body = (-1 * d[1] - sqrt(d[1] * d[1] - d[0] * d[2])) / d[0];
	if (t_body < EPSILON || distance < t_body)
	{
		t_body = (-1 * d[1] + sqrt(d[1] * d[1] - d[0] * d[2])) / d[0];
		if (t_body < EPSILON || distance < t_body)
			return (INFINITY);
	}
	if (vec3_dot_vec3(vec3_sub_vec3(vec3_add_vec3(data->ray->point,
					vec3_mul_rn(data->ray->direc, t_body)),
				cy_center[TOP]), data->obj[cy_i]->xyz_vec) > 0
		|| vec3_dot_vec3(vec3_sub_vec3(vec3_add_vec3(data->ray->point,
					vec3_mul_rn(data->ray->direc, t_body)),
				cy_center[BOTTOM]), data->obj[cy_i]->xyz_vec) < 0)
		return (INFINITY);
	return (t_body);
}
