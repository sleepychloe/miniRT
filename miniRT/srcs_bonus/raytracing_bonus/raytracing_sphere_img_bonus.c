/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytracing_sphere_img_bonus.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhwang <yhwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 18:17:14 by yhwang            #+#    #+#             */
/*   Updated: 2022/12/15 08:21:38 by yhwang           ###   ########.fr       */
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

	rgb.r = (double)((color >> 16) & 0xFF);
	rgb.g = (double)((color >> 8) & 0xFF);
	rgb.b = (double)((color >> 0) & 0xFF);
	return (rgb);
}

int	*load_image(t_mlx_img *img, t_data *data)
{
	int	row;
	int	col;
	int	*result;

	if (!(img->img_ptr = mlx_xpm_file_to_image(data->mlx->mlx_ptr, "./texture_img/earth.xpm", &img->img_width, &img->img_height)))
		return (0);
	img->addr = (int *)mlx_get_data_addr(img->img_ptr, &img->bits_per_pixel, &img->line_length, &img->endian);
	result = malloc(sizeof(int) * (img->img_width * img->img_height));
	row = -1;
	while (++row < img->img_height)
	{
		col = -1;
		while (++col < img->img_width)
		{
			result[img->img_width * row + col] = img->addr[img->img_width * row + col];
		}
	}
	mlx_destroy_image(data->mlx->mlx_ptr, img->img_ptr);
	return (result);
}

unsigned int	xpm_pixel_get(int *result, int x, int y, t_mlx_img *img)
{
	int	*dst;

	if (x < 0)
		x = 0;
	if (y < 0)
		y = 0;
	if (x > img->img_width - 1)
		x = img->img_width - 1;
	if (y > img->img_height - 1)
		y = img->img_height - 1;
	dst = result + ((x / 2) * img->bits_per_pixel / 8) + ((y / 4) * img->line_length + (x / 2));
	//dst = result + ((x / 2) * img->bits_per_pixel / 8) + ((y / 2) * img->line_length + (x / 2));
	return (*(unsigned int *)dst);
}

t_rgb3	image_mapping(double u, double v, int *result, t_mlx_img *img)
{
	int		u_int;
	int		v_int;
	int		mlx_color;

	u_int = (int)((u) * (img->img_width));
	v_int = (int)((1.0 - v) * (img->img_height));
	//printf("img_w: %d, img_h: %d\n", img->img_width, img->img_width);
	mlx_color = xpm_pixel_get(result, u_int, v_int, img);
	return (pixel_to_rgb(mlx_color));
}

void	sphere_img(t_data *data, t_hit *hit, int sp_i)
{
	t_mlx_img	img;
	int	*result;
	double	theta;
	double	pi;
	double		u;
	double		v;
	(void)sp_i;
	(void)data;
	theta = acos(-1 * (hit->normal_vec.y));
	pi = atan2(hit->normal_vec.x, hit->normal_vec.z) + PI / 2;
	u = pi / PI * 0.5;
	v = theta / PI;
	result = load_image(&img, data);
	hit->color = image_mapping(u, v, result, &img);
	free(result);
}
