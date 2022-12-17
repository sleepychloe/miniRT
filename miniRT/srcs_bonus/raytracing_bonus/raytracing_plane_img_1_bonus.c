/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytracing_plane_img_1_bonus.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhwang <yhwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 17:12:30 by yhwang            #+#    #+#             */
/*   Updated: 2022/12/17 22:46:50 by yhwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs_bonus/miniRT_bonus.h"

t_rgb3	plane_img_mapping(t_data *data, int pl_i, double u, double v)
{
	int	u_int;
	int	v_int;
	int	color;

	v *= -1;
	u_int = (int)((u + 7) * data->obj[pl_i]->img_width);
	v_int = (int)((v + 9) * data->obj[pl_i]->img_height);
	u_int /= 70;
	v_int /= 70;
	color = xpm_img_pixel_get(data, pl_i, u_int, v_int);
	return (pixel_to_rgb(color));
}

void	plane_img_norminette_1(t_data *data, t_hit *hit, int pl_i)
{
	if (hit->normal_vec.y == 1 || hit->normal_vec.y == -1)
		plane_img_xz(data, hit, pl_i);
	else if (hit->normal_vec.x == 1 || hit->normal_vec.x == -1)
		plane_img_zy(data, hit, pl_i);
	else
		plane_img_xy(data, hit, pl_i);
}

void	plane_img_norminette_2(t_data *data, t_hit *hit, int pl_i)
{
	if (hit->normal_vec.z == 0)
	{
		if ((hit->normal_vec.y == 1 || hit->normal_vec.y == -1))
			plane_img_xz(data, hit, pl_i);
		else
			plane_img_zy(data, hit, pl_i);
	}
	else
	{
		if (hit->normal_vec.x == 1 || hit->normal_vec.x == -1)
			plane_img_zy(data, hit, pl_i);
		else if (hit->normal_vec.y == 1 || hit->normal_vec.y == -1)
			plane_img_xz(data, hit, pl_i);
		else
			plane_img_xy(data, hit, pl_i);
	}
}


void	plane_img(t_data *data, t_hit *hit, int pl_i)
{
	if (sqrt(hit->normal_vec.x * hit->normal_vec.x
			+ hit->normal_vec.y * hit->normal_vec.y) == 1
		&& hit->normal_vec.x != 0 && hit->normal_vec.y != 0
		&& hit->normal_vec.x != 1 && hit->normal_vec.x != -1
		&& hit->normal_vec.y != 1 && hit->normal_vec.y != -1)
		plane_img_xz(data, hit, pl_i);
	else if (fabs(hit->normal_vec.x) > 0.8
		&& hit->normal_vec.x != 1 && hit->normal_vec.x != -1
		&& hit->normal_vec.y != 0 && hit->normal_vec.z != 0)
		plane_img_zy(data, hit, pl_i);
	else if (fabs(hit->normal_vec.y) > 0.8
		&& hit->normal_vec.y != 1 && hit->normal_vec.y != -1
		&& hit->normal_vec.x != 0 && hit->normal_vec.z != 0)
		plane_img_xz(data, hit, pl_i);
	else if (fabs(hit->normal_vec.z) > 0.8
		&& hit->normal_vec.z != 1 && hit->normal_vec.z != -1
		&& hit->normal_vec.x != 0 && hit->normal_vec.y != 0)
		plane_img_zy(data, hit, pl_i);
	else if (hit->normal_vec.x == 0)
		plane_img_norminette_1(data, hit, pl_i);
	else
		plane_img_norminette_2(data, hit, pl_i);
}