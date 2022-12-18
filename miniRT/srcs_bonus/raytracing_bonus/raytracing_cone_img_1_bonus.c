/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytracing_cone_img_1_bonus.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhwang <yhwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 06:39:46 by yhwang            #+#    #+#             */
/*   Updated: 2022/12/18 07:34:57 by yhwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs_bonus/miniRT_bonus.h"

t_rgb3	cone_img_mapping(t_data *data, int co_i, double theta, double height)
{
	double	u;
	double	v;
	int		u_int;
	int		v_int;
	int		color;

	u = theta / PI * 0.5;
	v = height / PI;
	u += 0.05;
	u_int = (int)(u * data->obj[co_i]->img_width);
	v_int = (int)(v * data->obj[co_i]->img_height);
	u_int /= 3;
	v_int /= 3;
	color = xpm_img_pixel_get(data, co_i, u_int, v_int);
	return (pixel_to_rgb(color));
}

t_rgb3	cone_circle_img_mapping(t_data *data, int co_i,
				double hit_point_one, double hit_point_two)
{
	double	u;
	double	v;
	int		u_int;
	int		v_int;
	int		color;

	u = hit_point_one;
	v = hit_point_two;
	v *= -1;
	u_int = (int)((u + 1) * data->obj[co_i]->img_width);
	v_int = (int)((v + 1) * data->obj[co_i]->img_height);
	u_int /= 1000;
	v_int /= 1000;
	color = xpm_img_pixel_get(data, co_i, u_int, v_int);
	return (pixel_to_rgb(color));
}

void	cone_img_norminette(t_data *data, t_hit *hit, int co_i)
{
	if (fabs(data->obj[co_i]->xyz_vec.y) > 0.7
		|| (fabs(data->obj[co_i]->xyz_vec.x) != 0
			&& fabs(data->obj[co_i]->xyz_vec.y) > 0.5
			&& fabs(data->obj[co_i]->xyz_vec.z) > 0.7))
		cone_img_zx(data, hit, co_i);
	else if (fabs(data->obj[co_i]->xyz_vec.z) == 1
		|| fabs(data->obj[co_i]->xyz_vec.z) > 0.7
		|| (fabs(data->obj[co_i]->xyz_vec.y) > 0.6
			&& fabs(data->obj[co_i]->xyz_vec.z) > 0.6))
		cone_img_xy(data, hit, co_i);
	else
		cone_img_zy(data, hit, co_i);
}

void	cone_img(t_data *data, t_hit *hit, int co_i)
{
	if ((data->obj[co_i]->xyz_vec.x != 1 && data->obj[co_i]->xyz_vec.x != -1
			&& data->obj[co_i]->xyz_vec.y != 0))
	{
		if (fabs(data->obj[co_i]->xyz_vec.z) == 0)
			cone_img_zx(data, hit, co_i);
		else if (fabs(data->obj[co_i]->xyz_vec.x) == 0
			&& fabs(data->obj[co_i]->xyz_vec.z) == 1)
			cone_img_xy(data, hit, co_i);
		else if (fabs(data->obj[co_i]->xyz_vec.x) != 0)
			cone_img_norminette(data, hit, co_i);
		else
			cone_img_zx(data, hit, co_i);
	}
	else
		cone_img_zy(data, hit, co_i);
}
