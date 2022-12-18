/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytracing_cone_texture_2_bonus.c                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhwang <yhwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 22:42:25 by yhwang            #+#    #+#             */
/*   Updated: 2022/12/18 22:58:58 by yhwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs_bonus/miniRT_bonus.h"

void	cone_texture_xy(t_data *data, t_hit *hit, int co_i)
{
	double	theta_height[2];
	double	hit_point[2];

	theta_height[0] = atan2(hit->normal_vec.y, hit->normal_vec.x) + PI / 2;
	cone_img_xy_zx_zy_norminette(data, hit, co_i, &theta_height[1]);
	hit_point[0] = hit->hit_point.x;
	hit_point[1] = hit->hit_point.y;
	if (!(hit->normal_vec.x == data->obj[co_i]->xyz_vec.x
			&& hit->normal_vec.y == data->obj[co_i]->xyz_vec.y
			&& hit->normal_vec.z == data->obj[co_i]->xyz_vec.z)
		&& !(hit->normal_vec.x == data->obj[co_i]->xyz_vec.x * -1
			&& hit->normal_vec.y == data->obj[co_i]->xyz_vec.y * -1
			&& hit->normal_vec.z == data->obj[co_i]->xyz_vec.z * -1))
		hit->normal_vec = cone_texture_mapping(data, hit, co_i, theta_height);
	else
		hit->normal_vec = cone_circle_texture_mapping(data, hit, co_i, hit_point);
	hit->color = data->obj[co_i]->rgb1;
}

void	cone_texture_zx(t_data *data, t_hit *hit, int co_i)
{
	double	theta_height[2];
	double	hit_point[2];

	theta_height[0] = atan2(hit->normal_vec.x, hit->normal_vec.z) + PI / 2;
	cone_img_xy_zx_zy_norminette(data, hit, co_i, &theta_height[1]);
	hit_point[0] = hit->hit_point.x;
	hit_point[1] = hit->hit_point.z * -1;
	if (!(hit->normal_vec.x == data->obj[co_i]->xyz_vec.x
			&& hit->normal_vec.y == data->obj[co_i]->xyz_vec.y
			&& hit->normal_vec.z == data->obj[co_i]->xyz_vec.z)
		&& !(hit->normal_vec.x == data->obj[co_i]->xyz_vec.x * -1
			&& hit->normal_vec.y == data->obj[co_i]->xyz_vec.y * -1
			&& hit->normal_vec.z == data->obj[co_i]->xyz_vec.z * -1))
		hit->normal_vec = cone_texture_mapping(data, hit, co_i, theta_height);
	else
		hit->normal_vec = cone_circle_texture_mapping(data, hit, co_i, hit_point);
	hit->color = data->obj[co_i]->rgb1;
}

void	cone_texture_zy(t_data *data, t_hit *hit, int co_i)
{
	double	theta_height[2];
	double	hit_point[2];

	theta_height[0] = atan2(hit->normal_vec.y, hit->normal_vec.z) + PI / 2;
	cone_img_xy_zx_zy_norminette(data, hit, co_i, &theta_height[1]);
	hit_point[0] = hit->hit_point.z;
	hit_point[1] = hit->hit_point.y;
	if (!(hit->normal_vec.x == data->obj[co_i]->xyz_vec.x
			&& hit->normal_vec.y == data->obj[co_i]->xyz_vec.y
			&& hit->normal_vec.z == data->obj[co_i]->xyz_vec.z)
		&& !(hit->normal_vec.x == data->obj[co_i]->xyz_vec.x * -1
			&& hit->normal_vec.y == data->obj[co_i]->xyz_vec.y * -1
			&& hit->normal_vec.z == data->obj[co_i]->xyz_vec.z * -1))
		hit->normal_vec = cone_texture_mapping(data, hit, co_i, theta_height);
	else
		hit->normal_vec = cone_circle_texture_mapping(data, hit, co_i, hit_point);
	hit->color = data->obj[co_i]->rgb1;
}
