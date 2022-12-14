/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytracing_main.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhwang <yhwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 20:00:26 by yhwang            #+#    #+#             */
/*   Updated: 2022/12/16 04:19:24 by yhwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/miniRT.h"

int	hittable(t_data *data, t_hit *hit)
{
	int		i;
	int		hit_flag;
	double	distance;

	i = 0;
	hit_flag = 0;
	distance = INFINITY;
	while (i < data->n_obj + data->scene->n_plane)
	{
		if (!(hit_sphere(data, hit, i, distance))
			|| !(hit_plane(data, hit, i, distance))
			|| !(hit_cylinder(data, hit, i, distance)))
		{
			hit_flag = 1;
			distance = hit->t;
		}
		i++;
	}
	return (hit_flag);
}

t_rgb3	trace(t_data *data, t_ray ray_set)
{
	t_hit	hit;
	t_rgb3	ambient;
	t_rgb3	light;

	data->ray = &ray_set;
	if (hittable(data, &hit))
	{
		ambient.r = (data->scene->ambient->lighting)
			* (data->scene->ambient->rgb.r) * hit.color.r * 0.001;
		ambient.g = (data->scene->ambient->lighting)
			* (data->scene->ambient->rgb.g) * hit.color.g * 0.001;
		ambient.b = (data->scene->ambient->lighting)
			* (data->scene->ambient->rgb.b) * hit.color.b * 0.001;
		light = apply_light(data, &hit);
		return (color_add(ambient, light));
	}
	return (rgb3(0, 0, 0));
}

void	ray_tracing(t_data *data)
{
	int		i;
	int		j;
	int		s;
	t_rgb3	color;

	j = (WIN_W / ASPECT_RATIO_W * ASPECT_RATIO_H);
	printf("%sRendering... %s", WHITE, B);
	while (0 <= --j)
	{
		printf("Rendering... %d %%\n",
			((WIN_W / ASPECT_RATIO_W * ASPECT_RATIO_H) - j) * 100
			/ (WIN_W / ASPECT_RATIO_W * ASPECT_RATIO_H));
		i = -1;
		while (++i <= WIN_W - 1)
		{
			color = rgb3(0, 0, 0);
			s = -1;
			while (++s < NUM_SAMPLE)
				color = color_add(color,
						trace(data, ray_set(data, i, j)));
			color = color_average(color);
			my_mlx_pixel_put(data->mlx, i, j, color_convert_to_int(color));
		}
	}
	printf("%s%sDone%s\n", WHITE, R, B);
}

void	rt_start(t_data *data, int flag)
{
	t_rt	rt;

	data->obj = init_obj(data->scene);
	data->rt = &rt;
	mlx_clear_window(data->mlx->mlx_ptr, data->mlx->win);
	init_rt(data->scene, data->rt);
	ray_tracing(data);
	mlx_put_image_to_window(data->mlx->mlx_ptr, data->mlx->win,
		data->mlx->img_ptr, 0, 0);
	show_guide();
	print_scene_info(data, data->keep_scene, flag);
}

void	raytracing_main(t_scene *scene, t_scene *keep_scene, t_mlx *mlx)
{
	t_data	data;

	data.keep_scene = keep_scene;
	data.scene = scene;
	data.mlx = mlx;
	data.n_obj = scene->n_sphere + scene->n_plane + scene->n_cylinder;
	data.sp = 0;
	data.pl = 0;
	data.cy = 0;
	data.x_normal = vec3(1, 0, 0);
	data.y_normal = vec3(0, 1, 0);
	data.z_normal = vec3(0, 0, 1);
	if (mlx_init_window(mlx))
	{
		err_msg("mlx init error");
		free_scene(scene);
		free_scene(keep_scene);
		exit (1);
	}
	if (data.keep_scene->camera->xyz_vec.z != -1)
		raytracing_set_camera(&data);
	rt_start(&data, 0);
	mlx_key_hook(mlx->win, mlx_keys, (void *)&data);
	mlx_hook(mlx->win, 17, 2, mlx_exit, (void *)&data);
	mlx_loop(mlx->mlx_ptr);
}
