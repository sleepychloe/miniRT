/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytracing_main.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhwang <yhwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 20:00:26 by yhwang            #+#    #+#             */
/*   Updated: 2022/11/05 04:37:16 by yhwang           ###   ########.fr       */
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

t_vec3	ray(t_vec3 start, t_vec3 direc, double t)
{
	t_vec3	res;
	
	if (t == '\0')
		return (direc);
	res = vec3_add_vec3(start, vec3_mul_rn(direc, t));
	return (res);
}

double hit_sphere(t_scene *scene, t_vec3 center, double radius, t_vec3 direction)
{
	t_vec3 oc = vec3_sub_vec3(center, scene->camera->xyz_pos);
	double a = vec3_dot_vec3(direction, direction);
	double b = 2.0 * vec3_dot_vec3(oc, direction);
	double c = vec3_dot_vec3(oc, oc) - radius * radius;
	double discriminant = b * b - 4 * a * c;
	if (discriminant > 0)
		return (9999);
	return (0);
}

int	ray_color(t_scene *scene, t_vec3 dir_ray)
{
	if (hit_sphere(scene, scene->sphere[0]->xyz_pos, (scene->sphere[0]->diameter) / 2, dir_ray) == 9999)
		return (0x00FF0000);
	t_vec3 unit_dir_ray = vec3_unit(dir_ray);
	double t = 0.5 * (unit_dir_ray.y + 1.0);
	return ((1 - t) * (1*255+256*256 + 1*255+256 + 1*255)
			+ t * (0.5*255+256*256 + 0.7*255+256 + 1*255));
}

void	raytrace(t_scene *scene, t_mlx *mlx)
{	
	int		i;
	int		j;
	double	u;
	double	v;
	double	focal_length = 2 / tan((scene->camera->fov) * PI / 360);
	double	viewport_width = 2.0;
	double	viewport_height = 2.0 / 16 * 9;
	int		c;

	t_vec3	low_left = vec3(scene->camera->xyz_pos.x - viewport_width / 2,
				scene->camera->xyz_pos.y - viewport_height / 2,
				scene->camera->xyz_pos.z - focal_length);

	i = 0;
	j = WIN_H - 1;
	while (0 <= j)
	{
		while (i < WIN_W)
		{
			u = (double)i / (WIN_W - 1);
			v = (double)j / (WIN_H - 1);
			t_vec3 dir_ray = vec3_sub_vec3(vec3_add_vec3(low_left,
				vec3_add_vec3(vec3(u * viewport_width, 0, 0), vec3(0, v * viewport_height, 0))),
				scene->camera->xyz_pos);
			c = ray_color(scene, vec3_sub_vec3(dir_ray, scene->camera->xyz_pos));
			my_mlx_pixel_put(mlx, i, j, c);
			i++;
		}
		i = 0;
		j--;
	}
}

int	raytracing_main(t_scene *scene)
{
	t_mlx	mlx;

	if (init_window(&mlx))
	{
		err_msg("mlx init error");
		return (1);
	}
	raytrace(scene, &mlx);
	mlx_put_image_to_window(mlx.mlx_ptr, mlx.win, mlx.img_ptr, 0, 0);
	free_scene(scene);
	mlx_hook(mlx.win, 17, 2, mlx_exit, (void *)&mlx);
	mlx_key_hook(mlx.win, mlx_keys, (void *)&mlx);
	mlx_loop(mlx.mlx_ptr);
	return (0);
}
