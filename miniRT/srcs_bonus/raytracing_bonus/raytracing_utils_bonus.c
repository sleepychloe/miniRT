/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytracing_utils_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhwang <yhwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 22:13:16 by yhwang            #+#    #+#             */
/*   Updated: 2022/12/18 22:11:41 by yhwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs_bonus/miniRT_bonus.h"

void	set_hit_point(t_data *data, t_hit *hit, double t)
{
	hit->t = t;
	hit->hit_point = vec3_add_vec3(data->ray->point,
			vec3_mul_rn(data->ray->direc, t));
}

void	set_hit_normal_direc(t_data *data, t_hit *hit)
{
	if (vec3_dot_vec3(data->ray->direc, hit->normal_vec) >= 0)
	{
		hit->front = BACK;
		hit->normal_vec = vec3_mul_rn(hit->normal_vec, -1);
	}
	hit->front = FRONT;
}

int	xpm_img_pixel_get(t_data *data, int i, int x, int y)
{
	int	*dst;

	if (x < 0)
		x = 0;
	if (y < 0)
		y = 0;
	if (x > data->obj[i]->img_width - 1)
		x = data->obj[i]->img_width - 1;
	if (y > data->obj[i]->img_height - 1)
		y = data->obj[i]->img_height - 1;
	dst = data->obj[i]->img_addr
		+ (x * data->obj[i]->img_bits_per_pixel / 8)
		+ (y * data->obj[i]->img_line_length + x);
	return (*(unsigned int *)dst);
}

int	xpm_texture_pixel_get(t_data *data, int i, int x, int y)
{
	int	*dst;

	if (x < 0)
		x = 0;
	if (y < 0)
		y = 0;
	if (x > data->obj[i]->texture_width - 1)
		x = data->obj[i]->texture_width - 1;
	if (y > data->obj[i]->texture_height - 1)
		y = data->obj[i]->texture_height - 1;
	dst = data->obj[i]->texture_addr
		+ (x * data->obj[i]->texture_bits_per_pixel / 8)
		+ (y * data->obj[i]->texture_line_length + x);
	return (*(unsigned int *)dst);
}
