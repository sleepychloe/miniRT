/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytracing_cone_img_texture_1_bonus.c              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhwang <yhwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 00:13:58 by yhwang            #+#    #+#             */
/*   Updated: 2022/12/19 00:15:57 by yhwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs_bonus/miniRT_bonus.h"

void	cone_img_texture_norminette(t_data *data, t_hit *hit, int co_i)
{
	if (fabs(data->obj[co_i]->xyz_vec.y) > 0.7
		|| (fabs(data->obj[co_i]->xyz_vec.x) != 0
			&& fabs(data->obj[co_i]->xyz_vec.y) > 0.5
			&& fabs(data->obj[co_i]->xyz_vec.z) > 0.7))
		cone_img_texture_zx(data, hit, co_i);
	else if (fabs(data->obj[co_i]->xyz_vec.z) == 1
		|| fabs(data->obj[co_i]->xyz_vec.z) > 0.7
		|| (fabs(data->obj[co_i]->xyz_vec.y) > 0.6
			&& fabs(data->obj[co_i]->xyz_vec.z) > 0.6))
		cone_img_texture_xy(data, hit, co_i);
	else
		cone_img_texture_zy(data, hit, co_i);
}

void	cone_img_texture(t_data *data, t_hit *hit, int co_i)
{
	if ((data->obj[co_i]->xyz_vec.x != 1 && data->obj[co_i]->xyz_vec.x != -1
			&& data->obj[co_i]->xyz_vec.y != 0))
	{
		if (fabs(data->obj[co_i]->xyz_vec.z) == 0)
			cone_img_texture_zx(data, hit, co_i);
		else if (fabs(data->obj[co_i]->xyz_vec.x) == 0
			&& fabs(data->obj[co_i]->xyz_vec.z) == 1)
			cone_img_texture_xy(data, hit, co_i);
		else if (fabs(data->obj[co_i]->xyz_vec.x) != 0)
			cone_img_texture_norminette(data, hit, co_i);
		else
			cone_img_texture_zx(data, hit, co_i);
	}
	else
		cone_img_texture_zy(data, hit, co_i);
}
