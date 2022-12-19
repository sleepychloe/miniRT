/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytracing_cylinder_img_texture_1_bonus.c          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhwang <yhwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 00:01:30 by yhwang            #+#    #+#             */
/*   Updated: 2022/12/19 00:12:55 by yhwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs_bonus/miniRT_bonus.h"

void	cylinder_img_texture_norminette(t_data *data, t_hit *hit, int cy_i)
{
	if (fabs(data->obj[cy_i]->xyz_vec.y) > 0.7
		|| (fabs(data->obj[cy_i]->xyz_vec.x) != 0
			&& fabs(data->obj[cy_i]->xyz_vec.y) > 0.5
			&& fabs(data->obj[cy_i]->xyz_vec.z) > 0.7))
		cylinder_img_texture_zx(data, hit, cy_i);
	else if (fabs(data->obj[cy_i]->xyz_vec.z) == 1
		|| fabs(data->obj[cy_i]->xyz_vec.z) > 0.7
		|| (fabs(data->obj[cy_i]->xyz_vec.y) > 0.6
			&& fabs(data->obj[cy_i]->xyz_vec.z) > 0.6))
		cylinder_img_texture_xy(data, hit, cy_i);
	else
		cylinder_img_texture_zy(data, hit, cy_i);
}

void	cylinder_img_texture(t_data *data, t_hit *hit, int cy_i)
{
	if ((data->obj[cy_i]->xyz_vec.x != 1 && data->obj[cy_i]->xyz_vec.x != -1
			&& data->obj[cy_i]->xyz_vec.y != 0))
	{
		if (fabs(data->obj[cy_i]->xyz_vec.z) == 0)
			cylinder_img_texture_zx(data, hit, cy_i);
		else if (fabs(data->obj[cy_i]->xyz_vec.x) == 0
			&& fabs(data->obj[cy_i]->xyz_vec.z) == 1)
			cylinder_img_texture_xy(data, hit, cy_i);
		else if (fabs(data->obj[cy_i]->xyz_vec.x) != 0)
			cylinder_img_texture_norminette(data, hit, cy_i);
		else
			cylinder_img_texture_zx(data, hit, cy_i);
	}
	else
		cylinder_img_texture_zy(data, hit, cy_i);
}
