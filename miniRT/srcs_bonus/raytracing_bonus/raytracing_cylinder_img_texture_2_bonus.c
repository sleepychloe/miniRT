/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytracing_cylinder_img_texture_2_bonus.c          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhwang <yhwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 00:01:46 by yhwang            #+#    #+#             */
/*   Updated: 2022/12/19 03:46:38 by yhwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs_bonus/miniRT_bonus.h"

void	cylinder_img_texture_xy_zx_zy_norminette(t_data *data,
				t_hit *hit, int cy_i, double *height)
{
	t_vec3	cp;
	double	length_cp;

	cp = vec3_sub_vec3(hit->hit_point, data->obj[cy_i]->xyz_pos);
	length_cp = vec3_dot_vec3(cp, data->obj[cy_i]->xyz_vec);
	*height = PI + (length_cp / data->obj[cy_i]->height) * 2
		* (data->obj[cy_i]->height / (data->obj[cy_i]->diameter));
}

void	cylinder_img_texture_xy(t_data *data, t_hit *hit, int cy_i)
{
	double	val[2];
	double	hit_p[2];

	val[0] = atan2(hit->normal_vec.y, hit->normal_vec.x) + PI / 2;
	cylinder_img_texture_xy_zx_zy_norminette(data, hit, cy_i, &val[1]);
	hit_p[0] = hit->hit_point.x;
	hit_p[1] = hit->hit_point.y;
	if (!(hit->normal_vec.x == data->obj[cy_i]->xyz_vec.x
			&& hit->normal_vec.y == data->obj[cy_i]->xyz_vec.y
			&& hit->normal_vec.z == data->obj[cy_i]->xyz_vec.z)
		&& !(hit->normal_vec.x == data->obj[cy_i]->xyz_vec.x * -1
			&& hit->normal_vec.y == data->obj[cy_i]->xyz_vec.y * -1
			&& hit->normal_vec.z == data->obj[cy_i]->xyz_vec.z * -1))
	{
		hit->normal_vec = cylinder_texture_mapping(data, hit, cy_i, val);
		hit->color = cylinder_img_mapping(data, cy_i, val[0], val[1]);
	}
	else
	{
		hit->normal_vec
			= cylinder_circle_texture_mapping(data, hit, cy_i, hit_p);
		hit->color
			= cylinder_circle_img_mapping(data, cy_i, hit_p[0], hit_p[1]);
	}
}

void	cylinder_img_texture_zx(t_data *data, t_hit *hit, int cy_i)
{
	double	val[2];
	double	hit_p[2];

	val[0] = atan2(hit->normal_vec.x, hit->normal_vec.z) + PI / 2;
	cylinder_img_texture_xy_zx_zy_norminette(data, hit, cy_i, &val[1]);
	hit_p[0] = hit->hit_point.x;
	hit_p[1] = hit->hit_point.z * -1;
	if (!(hit->normal_vec.x == data->obj[cy_i]->xyz_vec.x
			&& hit->normal_vec.y == data->obj[cy_i]->xyz_vec.y
			&& hit->normal_vec.z == data->obj[cy_i]->xyz_vec.z)
		&& !(hit->normal_vec.x == data->obj[cy_i]->xyz_vec.x * -1
			&& hit->normal_vec.y == data->obj[cy_i]->xyz_vec.y * -1
			&& hit->normal_vec.z == data->obj[cy_i]->xyz_vec.z * -1))
	{
		hit->normal_vec = cylinder_texture_mapping(data, hit, cy_i, val);
		hit->color = cylinder_img_mapping(data, cy_i, val[0], val[1]);
	}
	else
	{
		hit->normal_vec
			= cylinder_circle_texture_mapping(data, hit, cy_i, hit_p);
		hit->color
			= cylinder_circle_img_mapping(data, cy_i, hit_p[0], hit_p[1]);
	}
}

void	cylinder_img_texture_zy(t_data *data, t_hit *hit, int cy_i)
{
	double	val[2];
	double	hit_p[2];

	val[0] = atan2(hit->normal_vec.y, hit->normal_vec.z) + PI / 2;
	cylinder_img_texture_xy_zx_zy_norminette(data, hit, cy_i, &val[1]);
	hit_p[0] = hit->hit_point.z;
	hit_p[1] = hit->hit_point.y;
	if (!(hit->normal_vec.x == data->obj[cy_i]->xyz_vec.x
			&& hit->normal_vec.y == data->obj[cy_i]->xyz_vec.y
			&& hit->normal_vec.z == data->obj[cy_i]->xyz_vec.z)
		&& !(hit->normal_vec.x == data->obj[cy_i]->xyz_vec.x * -1
			&& hit->normal_vec.y == data->obj[cy_i]->xyz_vec.y * -1
			&& hit->normal_vec.z == data->obj[cy_i]->xyz_vec.z * -1))
	{
		hit->normal_vec = cylinder_texture_mapping(data, hit, cy_i, val);
		hit->color = cylinder_img_mapping(data, cy_i, val[0], val[1]);
	}
	else
	{
		hit->normal_vec
			= cylinder_circle_texture_mapping(data, hit, cy_i, hit_p);
		hit->color
			= cylinder_circle_img_mapping(data, cy_i, hit_p[0], hit_p[1]);
	}
}
