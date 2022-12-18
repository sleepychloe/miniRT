/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytracing_cylinder_img_1_bonus.c                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhwang <yhwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 03:52:09 by yhwang            #+#    #+#             */
/*   Updated: 2022/12/18 07:34:35 by yhwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs_bonus/miniRT_bonus.h"

t_rgb3	cylinder_img_mapping(t_data *data,
				int cy_i, double theta, double height)
{
	double	u;
	double	v;
	int		u_int;
	int		v_int;
	int		color;

	u = theta / PI * 0.5;
	v = height / PI;
	u += 0.05;
	v -= 0.38;
	u_int = (int)(u * data->obj[cy_i]->img_width);
	v_int = (int)((1.0 - v) * data->obj[cy_i]->img_height);
	u_int /= 3;
	v_int /= 3;
	color = xpm_img_pixel_get(data, cy_i, u_int, v_int);
	return (pixel_to_rgb(color));
}

t_rgb3	cylinder_circle_img_mapping(t_data *data, int cy_i,
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
	u_int = (int)((u + 1) * data->obj[cy_i]->img_width);
	v_int = (int)((v + 1) * data->obj[cy_i]->img_height);
	u_int /= 1000;
	v_int /= 1000;
	color = xpm_img_pixel_get(data, cy_i, u_int, v_int);
	return (pixel_to_rgb(color));
}

void	cylinder_img_norminette(t_data *data, t_hit *hit, int cy_i)
{
	if (fabs(data->obj[cy_i]->xyz_vec.y) > 0.7
		|| (fabs(data->obj[cy_i]->xyz_vec.x) != 0
			&& fabs(data->obj[cy_i]->xyz_vec.y) > 0.5
			&& fabs(data->obj[cy_i]->xyz_vec.z) > 0.7))
		cylinder_img_zx(data, hit, cy_i);
	else if (fabs(data->obj[cy_i]->xyz_vec.z) == 1
		|| fabs(data->obj[cy_i]->xyz_vec.z) > 0.7
		|| (fabs(data->obj[cy_i]->xyz_vec.y) > 0.6
			&& fabs(data->obj[cy_i]->xyz_vec.z) > 0.6))
		cylinder_img_xy(data, hit, cy_i);
	else
		cylinder_img_zy(data, hit, cy_i);
}

void	cylinder_img(t_data *data, t_hit *hit, int cy_i)
{
	if ((data->obj[cy_i]->xyz_vec.x != 1 && data->obj[cy_i]->xyz_vec.x != -1
			&& data->obj[cy_i]->xyz_vec.y != 0))
	{
		if (fabs(data->obj[cy_i]->xyz_vec.z) == 0)
			cylinder_img_zx(data, hit, cy_i);
		else if (fabs(data->obj[cy_i]->xyz_vec.x) == 0
			&& fabs(data->obj[cy_i]->xyz_vec.z) == 1)
			cylinder_img_xy(data, hit, cy_i);
		else if (fabs(data->obj[cy_i]->xyz_vec.x) != 0)
			cylinder_img_norminette(data, hit, cy_i);
		else
			cylinder_img_zx(data, hit, cy_i);
	}
	else
		cylinder_img_zy(data, hit, cy_i);
}
