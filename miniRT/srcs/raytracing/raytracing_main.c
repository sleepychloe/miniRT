/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytracing_main.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhwang <yhwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 20:00:26 by yhwang            #+#    #+#             */
/*   Updated: 2022/11/16 22:00:22 by yhwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/miniRT.h"

int	hittable(t_data *data, t_hit *hit)
{
	int		i;
	int		hit_flag;
	double	lim;

	i = 0;
	hit_flag = 0;
	lim = INFINITY;
	while (i < data->rt->obj)
	{
		if (!(hit_sphere(data, hit, i, lim)))
		{
			hit_flag = 1;
			lim = hit->t;
		}
		i++;
	}
	return (hit_flag);
}

t_rgb3	trace(t_data *data, t_ray ray_set)
{
	t_hit	hit;
	t_rgb3	a;
	t_rgb3	l;

	data->ray = &ray_set;
	if (hittable(data, &hit))
	{
		a.r = (data->scene->ambient->lighting)
			* (data->scene->ambient->rgb.r) * hit.color.r * 0.001;
		a.g = (data->scene->ambient->lighting)
			* (data->scene->ambient->rgb.g) * hit.color.g * 0.001;
		a.b = (data->scene->ambient->lighting)
			* (data->scene->ambient->rgb.b) * hit.color.b * 0.001;
		l = apply_light(data, &hit);
		return (color_add(a, l));
	}
	return (rgb3(0, 0, 0));
}

void	ray_tracing(t_data *data)
{
	int		i;
	int		j;
	int		s;
	t_rgb3	c;

	j = (WIN_W / ASPECT_RATIO_W * ASPECT_RATIO_H);
	while (0 <= --j)
	{
		if (j == (WIN_W / ASPECT_RATIO_W * ASPECT_RATIO_H) - 1)
			printf("%sRendering...%s\n", WHITE, B);
		i = -1;
		while (++i <= WIN_W - 1)
		{
			c = rgb3(0, 0, 0);
			s = -1;
			while (++s < NUM_SAMPLE)
			{
				c = color_add(c, trace(data, ray_set(data, i, j)));
			}
			c = color_average(c, NUM_SAMPLE);
			my_mlx_pixel_put(data->mlx, i, j, color_convert_to_int(c));
		}
	}
}

void	rt_start(t_data *data, int flag)
{
	mlx_clear_window(data->mlx->mlx_ptr, data->mlx->win);
	init_rt(data->scene, data->rt);
	ray_tracing(data);
	mlx_put_image_to_window(data->mlx->mlx_ptr, data->mlx->win,
		data->mlx->img_ptr, 0, 0);
	show_guide();
	print_scene_info(data, data->scene, flag);
}

void	raytracing_main(t_scene *scene, t_mlx *mlx)
{
	t_data	data;
	t_rt	rt;

	data.scene = scene;
	data.mlx = mlx;
	data.rt = &rt;
	data.sp = 0;
	data.pl = 0;
	data.cy = 0;
	if (mlx_init_window(mlx))
	{
		err_msg("mlx init error");
		free(scene);
		exit (1);
	}
	rt_start(&data, 0);
	mlx_key_hook(mlx->win, mlx_keys, (void *)&data);
	mlx_hook(mlx->win, 17, 2, mlx_exit, (void *)&data);
	mlx_loop(mlx->mlx_ptr);
}
