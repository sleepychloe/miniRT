/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytracing_cone_checkerboard_1_bonus.c             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhwang <yhwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 20:53:05 by yhwang            #+#    #+#             */
/*   Updated: 2022/12/10 22:48:21 by yhwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs_bonus/miniRT_bonus.h"

void	cone_checkerboard_norminette(t_data *data, t_hit *hit, int co_i)
{
	if (fabs(data->obj[co_i]->xyz_vec.y) > 0.7
		|| (fabs(data->obj[co_i]->xyz_vec.x) != 0
			&& fabs(data->obj[co_i]->xyz_vec.y) > 0.5
			&& fabs(data->obj[co_i]->xyz_vec.z) > 0.7))
		cone_checkerboard_zx(data, hit, co_i);
	else if (fabs(data->obj[co_i]->xyz_vec.z) == 1
		|| fabs(data->obj[co_i]->xyz_vec.z) > 0.7
		|| (fabs(data->obj[co_i]->xyz_vec.y) > 0.6
			&& fabs(data->obj[co_i]->xyz_vec.z) > 0.6))
		cone_checkerboard_xy(data, hit, co_i);
	else
		cone_checkerboard_zy(data, hit, co_i);
}

void	cone_checkerboard(t_data *data, t_hit *hit, int co_i)
{
	if ((data->obj[co_i]->xyz_vec.x != 1 && data->obj[co_i]->xyz_vec.x != -1
			&& data->obj[co_i]->xyz_vec.y != 0))
	{
		if (fabs(data->obj[co_i]->xyz_vec.z) == 0)
			cone_checkerboard_zx(data, hit, co_i);
		else if (fabs(data->obj[co_i]->xyz_vec.x) == 0
			&& fabs(data->obj[co_i]->xyz_vec.z) == 1)
			cone_checkerboard_xy(data, hit, co_i);
		else if (fabs(data->obj[co_i]->xyz_vec.x) != 0)
			cone_checkerboard_norminette(data, hit, co_i);
		else
			cone_checkerboard_zx(data, hit, co_i);
	}
	else
		cone_checkerboard_zy(data, hit, co_i);
}
