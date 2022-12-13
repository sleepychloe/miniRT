/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytracing_sphere_img_bonus.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhwang <yhwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 18:17:14 by yhwang            #+#    #+#             */
/*   Updated: 2022/12/12 01:47:52 by yhwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs_bonus/miniRT_bonus.h"

typedef struct s_xpm_image
{
	void	*img;
	char	*data;
	int		bpp;
	int		line;
	int		endian;
	int		height;
	int		width;
}	t_xpm_image;

t_rgb3	pixel_to_rgb(int color)
{
	t_rgb3 rgb;

	rgb.r = (double)((color >> 16) & 0xFF) / 256;
	rgb.g = (double)((color >> 8) & 0xFF) / 256;
	rgb.b = (double)((color >> 0) & 0xFF) / 256;
	return (rgb);
}

int	xpm_pixel_get(t_xpm_image *img, int x, int y)
{
	char	*dst;
	unsigned int	*c;

	if (x < 0)
		x = 0;
	if (y < 0)
		y = 0;
	if (x > img->width - 1)
		x = img->width - 1;
	if (y > img->height - 1)
		y = img->height - 1;
	dst = img->data + (y * img->line + x * (img->bpp / 8));
	c = (unsigned int *)dst;
	return (*c);
}

t_rgb3	image_mapping(double u, double v, t_xpm_image *img)
{
	int		u_int;
	int		v_int;
	int		mlx_color;

	u_int = (int)((u) * (img->width));
	v_int = (int)((1 - v) * (img->height));
	mlx_color = xpm_pixel_get(img, u_int, v_int);
	return (pixel_to_rgb(mlx_color));
}

void	sphere_img(t_data *data, t_hit *hit, int sp_i)
{
	t_xpm_image img;
	double	theta;
	double	pi;
	double		u;
	double		v;

	(void)sp_i;
	theta = acos((hit->normal_vec.y));
	pi = atan2((hit->normal_vec.x), hit->normal_vec.z) + PI / 2;
	u = theta * PI;//
	v = pi * PI;//
	img.img = mlx_xpm_file_to_image(data->mlx->mlx_ptr, "./map_img/north.xpm",
			&img.width, &img.height);
	img.data = mlx_get_data_addr(data->mlx->mlx_ptr, &img.bpp, &img.line, &img.endian);
	hit->color = image_mapping(u, v, &img);
}
