/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytracing_sphere_img_bonus.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhwang <yhwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 18:17:14 by yhwang            #+#    #+#             */
/*   Updated: 2022/12/16 05:30:07 by yhwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs_bonus/miniRT_bonus.h"

t_rgb3	pixel_to_rgb(int color)
{
	t_rgb3	rgb;

	rgb.r = (double)((color >> 16) & 0xFF);
	rgb.g = (double)((color >> 8) & 0xFF);
	rgb.b = (double)((color >> 0) & 0xFF);
	return (rgb);
}

unsigned int	xpm_pixel_get(t_data *data, int sp_i, int x, int y)
{
	int	*dst;

	if (x < 0)
		x = 0;
	if (y < 0)
		y = 0;
	if (x > data->obj[sp_i]->img_width - 1)
		x = data->obj[sp_i]->img_width - 1;
	if (y > data->obj[sp_i]->img_height - 1)
		y = data->obj[sp_i]->img_height - 1;
	dst = data->obj[sp_i]->img_addr
		+ ((x / 2) * data->obj[sp_i]->img_bits_per_pixel / 8)
		+ ((y / 4) * data->obj[sp_i]->img_line_length + (x / 2));
	//dst = data->obj[sp_i]->img_addr
	//	+ ((x / 2) * data->obj[sp_i]->img_bits_per_pixel / 8)
	//	+ ((y / 2) * data->obj[sp_i]->img_line_length + (x / 2));
	return (*(unsigned int *)dst);
}

t_rgb3	image_mapping(t_data *data, int sp_i, double u, double v)
{
	int		u_int;
	int		v_int;
	int		mlx_color;

	u_int = (int)((u) * (data->obj[sp_i]->img_width));
	v_int = (int)((1.0 - v) * (data->obj[sp_i]->img_height));
	mlx_color = xpm_pixel_get(data, sp_i, u_int, v_int);
	return (pixel_to_rgb(mlx_color));
}

void	sphere_img(t_data *data, t_hit *hit, int sp_i)
{
	double	theta;
	double	pi;
	double	u;
	double	v;

	theta = acos(-1 * (hit->normal_vec.y));
	pi = atan2(hit->normal_vec.x, hit->normal_vec.z) + PI / 2;
	u = pi / PI * 0.5;
	v = theta / PI;
	hit->color = image_mapping(data, sp_i, u, v);
}
