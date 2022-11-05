/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytracing_main.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhwang <yhwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 20:00:26 by yhwang            #+#    #+#             */
/*   Updated: 2022/11/05 11:03:22 by yhwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/miniRT.h"

int	init_window(t_mlx *mlx)
{
	mlx->mlx_ptr = mlx_init();
	if (!(mlx->mlx_ptr))
		return (1);
	mlx->win = mlx_new_window(mlx->mlx_ptr,
			WIN_W, WIN_W / ASPECT_RATIO_W * ASPECT_RATIO_H, "miniRT");
	if ((!mlx->win))
		return (1);
	mlx->img_ptr = mlx_new_image(mlx->mlx_ptr, WIN_W,
			WIN_W / ASPECT_RATIO_W * ASPECT_RATIO_H);
	if (!(mlx->img_ptr))
		return (1);
	mlx->addr = mlx_get_data_addr(mlx->img_ptr, &mlx->bits_per_pixel,
			&mlx->line_length, &mlx->endian);
	if (!(mlx->addr))
		return (1);
	return (0);
}

double	hit_sphere(t_scene *scene, t_vec3 center, double radius, t_vec3 direc)
{
	t_vec3	oc;
	double	a;
	double	b;
	double	c;
	double	discriminant;

	oc = vec3_sub_vec3(center, scene->camera->xyz_pos);
	a = vec3_dot_vec3(direc, direc);
	b = 2.0 * vec3_dot_vec3(oc, direc);
	c = vec3_dot_vec3(oc, oc) - radius * radius;
	discriminant = b * b - 4 * a * c;
	if (discriminant < 0)
		return (-1);
	return ((-b - sqrt(discriminant)) / (2.0 * a));
}

int	ray_color(t_scene *scene, t_vec3 dir_ray)
{
	double	t;
	t_vec3	normal_vec;
	t_vec3	unit_dir_ray;
	t_vec3	target;

	t = hit_sphere(scene, scene->sphere[0]->xyz_pos,
			(scene->sphere[0]->diameter) / 2, dir_ray);
	if (t != -1)
	{
		normal_vec = vec3_unit(vec3_sub_vec3(ray(scene->camera->xyz_pos,
						dir_ray, t), scene->camera->xyz_vec));
		target = vec3_add_vec3(vec3_add_vec3(ray(scene->camera->xyz_pos, dir_ray, t),
						normal_vec), random_double_xyz());
		//return (rgb_color(scene->sphere[0]->rgb)
		//	+ 0.00001 * rgb_unit(normal_vec.x + 1,
		//		normal_vec.y + 1, normal_vec.z + 1));
		return (0.8 * rgb_color(scene->sphere[0]->rgb)
				+ 0.2 * rgb_color(rgb3(sqrt(vec3_sub_vec3(target, scene->camera->xyz_pos).x * 255 / 100),
					sqrt(vec3_sub_vec3(target, scene->camera->xyz_pos).y * 255 / 100),
					sqrt(vec3_sub_vec3(target, scene->camera->xyz_pos).z * 255 / 100))));
	}
	unit_dir_ray = vec3_unit(dir_ray);
	t = 0.00001 * (unit_dir_ray.y + 1.0);
	return ((1 - t) * rgb_unit(1, 1, 1) + t * rgb_unit(0.5, 0.7, 1));
}

void	raytrace(t_scene *scene, t_mlx *mlx)
{	
	int		i;
	int		j;
	//int		k;
	double	u;
	double	v;
	double	focal_length;
	double	viewport_width;
	double	viewport_height;
	int		c;
	t_vec3	low_left;
	t_vec3	dir_ray;

	focal_length = 1 / tan((scene->camera->fov) * PI / 360);
	viewport_width = 2.0;
	viewport_height = 2.0 / 16 * 9;
	low_left = vec3(scene->camera->xyz_pos.x - viewport_width / 2,
			scene->camera->xyz_pos.y - viewport_height / 2,
			scene->camera->xyz_pos.z - focal_length);
	i = 0;
	j = (WIN_W / ASPECT_RATIO_W * ASPECT_RATIO_H) - 1;
	//k = 0;
	while (0 <= j)
	{
		printf("Rendering... %d %%\n", ((WIN_W / ASPECT_RATIO_W * ASPECT_RATIO_H) - j) * 100
				/ (WIN_W / ASPECT_RATIO_W * ASPECT_RATIO_H));
		while (i < WIN_W)
		{
			c = rgb_unit(0, 0, 0);
			//while (k < 100)
			//{
				u = ((double)i /*+ random_double()*/) / (WIN_W - 1);
				v = ((double)j /*+ random_double()*/) / ((WIN_W / ASPECT_RATIO_W * ASPECT_RATIO_H) - 1);
				dir_ray = vec3_sub_vec3(vec3_add_vec3(low_left,
							vec3_add_vec3(vec3(u * viewport_width, 0, 0),
								vec3(0, v * viewport_height, 0))),
						scene->camera->xyz_pos);
				c += ray_color(scene,
						vec3_sub_vec3(dir_ray, scene->camera->xyz_pos));
				my_mlx_pixel_put(mlx, i, j, c);
			//	k++;
			//}
			i++;
		}
		i = 0;
		j--;
	}
	printf("Done\n");
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
