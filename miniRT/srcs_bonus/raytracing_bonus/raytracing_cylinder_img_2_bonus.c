/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytracing_cylinder_img_2_bonus.c                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhwang <yhwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 04:42:12 by yhwang            #+#    #+#             */
/*   Updated: 2022/12/18 07:35:19 by yhwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs_bonus/miniRT_bonus.h"

void	cylinder_img_xy(t_data *data, t_hit *hit, int cy_i)
{
	t_vec3	cp;
	double	length_cp;
	double	theta;
	double	height;

	theta = atan2(hit->normal_vec.y, hit->normal_vec.x) + PI / 2;
	cp = vec3_sub_vec3(hit->hit_point, data->obj[cy_i]->xyz_pos);
	length_cp = vec3_dot_vec3(cp, data->obj[cy_i]->xyz_vec);
	height = PI + (length_cp / data->obj[cy_i]->height) * 2
		* (data->obj[cy_i]->height / (data->obj[cy_i]->diameter));
	if (!(hit->normal_vec.x == data->obj[cy_i]->xyz_vec.x
			&& hit->normal_vec.y == data->obj[cy_i]->xyz_vec.y
			&& hit->normal_vec.z == data->obj[cy_i]->xyz_vec.z)
		&& !(hit->normal_vec.x == data->obj[cy_i]->xyz_vec.x * -1
			&& hit->normal_vec.y == data->obj[cy_i]->xyz_vec.y * -1
			&& hit->normal_vec.z == data->obj[cy_i]->xyz_vec.z * -1))
		hit->color = cylinder_img_mapping(data, cy_i, theta, height);
	else
		hit->color = cylinder_circle_img_mapping(data, cy_i,
				hit->hit_point.x, hit->hit_point.y);
}

void	cylinder_img_zx(t_data *data, t_hit *hit, int cy_i)
{
	t_vec3	cp;
	double	length_cp;
	double	theta;
	double	height;

	theta = atan2(hit->normal_vec.x, hit->normal_vec.z) + PI / 2;
	cp = vec3_sub_vec3(hit->hit_point, data->obj[cy_i]->xyz_pos);
	length_cp = vec3_dot_vec3(cp, data->obj[cy_i]->xyz_vec);
	height = PI + (length_cp / data->obj[cy_i]->height) * 2
		* (data->obj[cy_i]->height / (data->obj[cy_i]->diameter));
	if (!(hit->normal_vec.x == data->obj[cy_i]->xyz_vec.x
			&& hit->normal_vec.y == data->obj[cy_i]->xyz_vec.y
			&& hit->normal_vec.z == data->obj[cy_i]->xyz_vec.z)
		&& !(hit->normal_vec.x == data->obj[cy_i]->xyz_vec.x * -1
			&& hit->normal_vec.y == data->obj[cy_i]->xyz_vec.y * -1
			&& hit->normal_vec.z == data->obj[cy_i]->xyz_vec.z * -1))
		hit->color = cylinder_img_mapping(data, cy_i, theta, height);
	else
		hit->color = cylinder_circle_img_mapping(data, cy_i,
				hit->hit_point.x, -1 * (hit->hit_point.z));
}

void	cylinder_img_zy(t_data *data, t_hit *hit, int cy_i)
{
	t_vec3	cp;
	double	length_cp;
	double	theta;
	double	height;

	theta = atan2(hit->normal_vec.y, hit->normal_vec.z) + PI / 2;
	cp = vec3_sub_vec3(hit->hit_point, data->obj[cy_i]->xyz_pos);
	length_cp = vec3_dot_vec3(cp, data->obj[cy_i]->xyz_vec);
	height = PI + (length_cp / data->obj[cy_i]->height) * 2
		* (data->obj[cy_i]->height / (data->obj[cy_i]->diameter));
	if (!(hit->normal_vec.x == data->obj[cy_i]->xyz_vec.x
			&& hit->normal_vec.y == data->obj[cy_i]->xyz_vec.y
			&& hit->normal_vec.z == data->obj[cy_i]->xyz_vec.z)
		&& !(hit->normal_vec.x == data->obj[cy_i]->xyz_vec.x * -1
			&& hit->normal_vec.y == data->obj[cy_i]->xyz_vec.y * -1
			&& hit->normal_vec.z == data->obj[cy_i]->xyz_vec.z * -1))
		hit->color = cylinder_img_mapping(data, cy_i, theta, height);
	else
		hit->color = cylinder_circle_img_mapping(data, cy_i,
				hit->hit_point.z, hit->hit_point.y);
}
