/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytracing_cylinder_texture_2_bonus.c              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhwang <yhwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 22:25:36 by yhwang            #+#    #+#             */
/*   Updated: 2022/12/18 22:35:29 by yhwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs_bonus/miniRT_bonus.h"

void	cylinder_texture_xy(t_data *data, t_hit *hit, int cy_i)
{
	t_vec3	cp;
	double	length_cp;
	double	theta_height[2];
	double	hit_point[2];

	theta_height[0] = atan2(hit->normal_vec.y, hit->normal_vec.x) + PI / 2;
	cp = vec3_sub_vec3(hit->hit_point, data->obj[cy_i]->xyz_pos);
	length_cp = vec3_dot_vec3(cp, data->obj[cy_i]->xyz_vec);
	theta_height[1] = PI + (length_cp / data->obj[cy_i]->height) * 2
		* (data->obj[cy_i]->height / (data->obj[cy_i]->diameter));
	hit_point[0] = hit->hit_point.x;
	hit_point[1] = hit->hit_point.y;
	if (!(hit->normal_vec.x == data->obj[cy_i]->xyz_vec.x
			&& hit->normal_vec.y == data->obj[cy_i]->xyz_vec.y
			&& hit->normal_vec.z == data->obj[cy_i]->xyz_vec.z)
		&& !(hit->normal_vec.x == data->obj[cy_i]->xyz_vec.x * -1
			&& hit->normal_vec.y == data->obj[cy_i]->xyz_vec.y * -1
			&& hit->normal_vec.z == data->obj[cy_i]->xyz_vec.z * -1))
		hit->normal_vec = cylinder_texture_mapping(data, hit, cy_i, theta_height);
	else
		hit->normal_vec = cylinder_circle_texture_mapping(data, hit, cy_i, hit_point);
	hit->color = data->obj[cy_i]->rgb1;
}

void	cylinder_texture_zx(t_data *data, t_hit *hit, int cy_i)
{
	t_vec3	cp;
	double	length_cp;
	double	theta_height[2];
	double	hit_point[2];

	theta_height[0] = atan2(hit->normal_vec.x, hit->normal_vec.z) + PI / 2;
	cp = vec3_sub_vec3(hit->hit_point, data->obj[cy_i]->xyz_pos);
	length_cp = vec3_dot_vec3(cp, data->obj[cy_i]->xyz_vec);
	theta_height[1] = PI + (length_cp / data->obj[cy_i]->height) * 2
		* (data->obj[cy_i]->height / (data->obj[cy_i]->diameter));
	hit_point[0] = hit->hit_point.x;
	hit_point[1] = hit->hit_point.z * -1;
	if (!(hit->normal_vec.x == data->obj[cy_i]->xyz_vec.x
			&& hit->normal_vec.y == data->obj[cy_i]->xyz_vec.y
			&& hit->normal_vec.z == data->obj[cy_i]->xyz_vec.z)
		&& !(hit->normal_vec.x == data->obj[cy_i]->xyz_vec.x * -1
			&& hit->normal_vec.y == data->obj[cy_i]->xyz_vec.y * -1
			&& hit->normal_vec.z == data->obj[cy_i]->xyz_vec.z * -1))
		hit->normal_vec = cylinder_texture_mapping(data, hit, cy_i, theta_height);
	else
		hit->normal_vec = cylinder_circle_texture_mapping(data, hit, cy_i, hit_point);
	hit->color = data->obj[cy_i]->rgb1;
}

void	cylinder_texture_zy(t_data *data, t_hit *hit, int cy_i)
{
	t_vec3	cp;
	double	length_cp;
	double	theta_height[2];
	double	hit_point[2];

	theta_height[0] = atan2(hit->normal_vec.y, hit->normal_vec.z) + PI / 2;
	cp = vec3_sub_vec3(hit->hit_point, data->obj[cy_i]->xyz_pos);
	length_cp = vec3_dot_vec3(cp, data->obj[cy_i]->xyz_vec);
	theta_height[1] = PI + (length_cp / data->obj[cy_i]->height) * 2
		* (data->obj[cy_i]->height / (data->obj[cy_i]->diameter));
	hit_point[0] = hit->hit_point.z;
	hit_point[1] = hit->hit_point.y;
	if (!(hit->normal_vec.x == data->obj[cy_i]->xyz_vec.x
			&& hit->normal_vec.y == data->obj[cy_i]->xyz_vec.y
			&& hit->normal_vec.z == data->obj[cy_i]->xyz_vec.z)
		&& !(hit->normal_vec.x == data->obj[cy_i]->xyz_vec.x * -1
			&& hit->normal_vec.y == data->obj[cy_i]->xyz_vec.y * -1
			&& hit->normal_vec.z == data->obj[cy_i]->xyz_vec.z * -1))
		hit->normal_vec = cylinder_texture_mapping(data, hit, cy_i, theta_height);
	else
		hit->normal_vec = cylinder_circle_texture_mapping(data, hit, cy_i, hit_point);
	hit->color = data->obj[cy_i]->rgb1;
}
