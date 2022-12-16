/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytracing_init_struct_obj_3_bonus.c               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhwang <yhwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 05:01:37 by yhwang            #+#    #+#             */
/*   Updated: 2022/12/16 05:25:51 by yhwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs_bonus/miniRT_bonus.h"

void	put_obj_img_value(t_data *data, t_mlx *img, int i)
{
	data->obj[i]->img_width = img->img_width;
	data->obj[i]->img_height = img->img_height;
	data->obj[i]->img_line_length = img->line_length;
	data->obj[i]->img_bits_per_pixel = img->bits_per_pixel;
}

int	*load_image(t_data *data, int *old_ptr, t_mlx *img, int i)
{
	int	row;
	int	col;
	int	*res;

	img->img_ptr = mlx_xpm_file_to_image(data->mlx->mlx_ptr,
			data->obj[i]->img_path, &img->img_width, &img->img_height);
	if (!(img->img_ptr))
		return (NULL);
	img->img_addr = (int *)mlx_get_data_addr(img->img_ptr,
			&img->bits_per_pixel, &img->line_length, &img->endian);
	if (!(img->img_addr))
		return (NULL);
	res = (int *)ft_calloc(sizeof(int), (img->img_width * img->img_height));
	row = -1;
	while (++row < img->img_height)
	{
		col = -1;
		while (++col < img->img_width)
			res[img->img_width * row + col]
				= img->img_addr[img->img_width * row + col];
	}
	mlx_destroy_image(data->mlx->mlx_ptr, img->img_ptr);
	free(old_ptr);
	put_obj_img_value(data, img, i);
	return (res);
}

void	put_obj_texture_value(t_data *data, t_mlx *img, int i)
{
	data->obj[i]->texture_width = img->img_width;
	data->obj[i]->texture_height = img->img_height;
	data->obj[i]->texture_line_length = img->line_length;
	data->obj[i]->texture_bits_per_pixel = img->bits_per_pixel;
}

int	*load_texture(t_data *data, int *old_ptr, t_mlx *img, int i)
{
	int	row;
	int	col;
	int	*res;

	img->img_ptr = mlx_xpm_file_to_image(data->mlx->mlx_ptr,
			data->obj[i]->texture_path, &img->img_width, &img->img_height);
	if (!(img->img_ptr))
		return (NULL);
	img->img_addr = (int *)mlx_get_data_addr(img->img_ptr,
			&img->bits_per_pixel, &img->line_length, &img->endian);
	if (!(img->img_addr))
		return (NULL);
	res = (int *)ft_calloc(sizeof(int), (img->img_width * img->img_height));
	row = -1;
	while (++row < img->img_height)
	{
		col = -1;
		while (++col < img->img_width)
			res[img->img_width * row + col]
				= img->img_addr[img->img_width * row + col];
	}
	mlx_destroy_image(data->mlx->mlx_ptr, img->img_ptr);
	free(old_ptr);
	put_obj_texture_value(data, img, i);
	return (res);
}

void	init_obj_img_texture(t_data *data)
{
	t_mlx	img;
	int		i;

	i = 0;
	while (i < data->scene->n_sphere + data->scene->n_plane
		+ data->scene->n_cylinder + data->scene->n_cone + data->scene->n_plane)
	{
		if (ft_strncmp(data->obj[i]->img_path, "none", 4))
			data->obj[i]->img_addr = load_image(data,
					data->obj[i]->img_addr, &img, i);
		if (ft_strncmp(data->obj[i]->texture_path, "none", 4))
			data->obj[i]->texture_addr = load_texture(data,
					data->obj[i]->texture_addr, &img, i);
		i++;
	}
}
