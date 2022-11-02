/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytracing_main.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhwang <yhwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 20:00:26 by yhwang            #+#    #+#             */
/*   Updated: 2022/11/02 04:18:56 by yhwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/miniRT.h"

int	init_window(t_mlx *mlx)
{
	mlx->mlx_ptr = mlx_init();
	if (!(mlx->mlx_ptr))
		return (1);
	mlx->win = mlx_new_window(mlx->mlx_ptr, WIN_W, WIN_H, "miniRT");
	if ((!mlx->win))
		return (1);
	mlx->img_ptr = mlx_new_image(mlx->mlx_ptr, WIN_W, WIN_H);
	if (!(mlx->img_ptr))
		return (1);
	mlx->addr = mlx_get_data_addr(mlx->img_ptr, &mlx->bits_per_pixel,
			&mlx->line_length, &mlx->endian);
	if (!(mlx->addr))
		return (1);
	return (0);
}

t_vec3	ray(t_vec3 origin, t_vec3 direction, double t)
{
	t_vec3	res;

	res = vec3_add_vec3(origin, vec3_mul_rn(direction, t));
	return (res);
}

int hit_sphere(t_vec3 center, double radius, t_vec3 direction)
{
	t_vec3 oc = vec3_sub_vec3(center, vec3(0,0,0));
	double a = vec3_dot_vec3(direction, direction);
	double b = 2.0 * vec3_dot_vec3(oc, direction);
	double c = vec3_dot_vec3(oc, oc) - radius * radius;
	double discriminant = b * b - 4 * a * c;
	if (discriminant > 0)
		return (1);
	return (0);
}

int ray_color(double u, double v)
{
	int ratio = 16 / 9;
	double viewport_height = 2.0;
	double viewport_width = ratio * viewport_height;
	double focal_length = 1.0;
	t_vec3 origin = vec3(0, 0, 0);
	t_vec3 horizontal = vec3(viewport_width, 0, 0);
	t_vec3 vertical = vec3(0, viewport_height, 0);
	t_vec3 lower_left_corner = vec3_sub_vec3(origin, vec3_add_vec3(vec3_add_vec3(vec3_mul_rn(horizontal, 0.5),
			vec3_mul_rn(vertical, 0.5)),vec3(0, 0, focal_length)));
	if (hit_sphere(vec3(0, 0, -1), 0.5, vec3_sub_vec3(vec3_add_vec3(vec3_add_vec3(lower_left_corner,vec3_mul_rn(horizontal, u)),vec3_mul_rn(vertical, v)), origin)))
		return (1);
	return (0);
}

int	raytrace(t_mlx *mlx)
{
	int image_width = 800;
	int image_height = 800 / 16 * 9;

	for (int j = image_height - 1; j >= 0; --j)
	{
		for (int i = 0; i < image_width; ++i)
		{
			double u = (double)i / (image_width - 1);
			double v = (double)j / (image_height - 1);
			if (ray_color(u, v))
				my_mlx_pixel_put(mlx, i, j, 0x00FF0000);
			else
				my_mlx_pixel_put(mlx, i, j, 0x00000000);
		}
	}
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->win, mlx->img_ptr, 0, 0);
	return (0);
}

int	raytracing_main(t_scene *scene)
{
	t_mlx	mlx;

	if (init_window(&mlx))
	{
		err_msg("mlx init error");
		return (1);
	}
	raytrace(&mlx);
	mlx_hook(mlx.win, 17, 2, mlx_exit, (void *)scene);
	mlx_key_hook(mlx.win, mlx_keys, (void *)scene);
	mlx_loop(mlx.mlx_ptr);
	return (0);
}
