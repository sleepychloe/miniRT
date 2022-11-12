/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytracing_main.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhwang <yhwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 20:00:26 by yhwang            #+#    #+#             */
/*   Updated: 2022/11/12 20:52:54 by yhwang           ###   ########.fr       */
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

void	init_rt(t_scene *scene, t_rt *rt)
{
	rt->obj = scene->n_sphere; //add more
	rt->focal_length = 1 / tan((scene->camera->fov) * PI / 360);
	rt->viewport_width = 4.0;
	rt->viewport_height = rt->viewport_width / ASPECT_RATIO_W * ASPECT_RATIO_H;
	rt->vp_horizontal = vec3(rt->viewport_width, 0, -1 * (rt->focal_length));
	rt->vp_vertical = vec3(0, -1 * (rt->viewport_height), -1 * (rt->focal_length));
	rt->vp_low_left = vec3(-1 * (rt->vp_horizontal.x) / 2, -1 * (rt->vp_vertical.y) / 2, -1 * (rt->focal_length));
	rt->cam_xyz_pos = scene->camera->xyz_pos;
}

t_ray	ray_set(t_rt *rt, double u, double v)
{
	t_vec3	direc;

	u = (u + random_double()) / (WIN_W - 1);
	v = (v + random_double()) / ((WIN_W / ASPECT_RATIO_W * ASPECT_RATIO_H) - 1);
	direc.x = rt->vp_low_left.x + rt->vp_horizontal.x * u + rt->vp_vertical.x * v
			- rt->cam_xyz_pos.x;
	direc.y = rt->vp_low_left.y + rt->vp_horizontal.y * u + rt->vp_vertical.y * v
			- rt->cam_xyz_pos.y;
	direc.z = rt->vp_low_left.z + rt->vp_horizontal.z * u + rt->vp_vertical.z * v
			- rt->cam_xyz_pos.z;
	return (ray(rt->cam_xyz_pos, vec3_unit(direc)));
}

int	check_sphere(t_scene *scene, t_ray ray_set, double *t, int sp_i)
{
	t_vec3	oc;
	double	a;
	double	b;
	double	c;

	oc = vec3_sub_vec3(ray_set.point, scene->sphere[sp_i]->xyz_pos);
	a = vec3_dot_vec3(ray_set.direc, ray_set.direc);
	b = vec3_dot_vec3(oc, ray_set.direc);
	c = vec3_dot_vec3(oc, oc)
		- (((scene->sphere[sp_i]->diameter) / 2) * ((scene->sphere[sp_i]->diameter) / 2));
	if (b * b - a * c < 0)
		return (1);
	*t = (-1 * b - sqrt(b * b - a * c)) / a;
	if (*t < 0.001 || INFINITY < *t)
	{
		*t = (-1 * b + sqrt(b * b - a * c)) / a;
		if (*t < 0.001 || INFINITY < *t)
			return (8);
	}
	return (0);
}

void	set_hit_point(t_ray ray_set, t_hit *hit, double t)
{
	hit->t = t;
	hit->hit_point = vec3_add_vec3(ray_set.point, vec3_mul_rn(ray_set.direc, t));
}

void	set_hit_normal_direc(t_ray ray_set, t_hit *hit)
{
	if (vec3_dot_vec3(ray_set.direc, hit->normal_vec) >= 0)
	{
		hit->front = BACK;
		hit->normal_vec = vec3_mul_rn(hit->normal_vec, -1);
	}
	hit->front = FRONT;
}

int	hit_sphere(t_scene *scene, t_ray ray_set, t_hit *hit, int sp_i)
{
	double	t;

	if (check_sphere(scene, ray_set, &t, sp_i))
		return (1);
	set_hit_point(ray_set, hit, t);
	hit->normal_vec = vec3_unit(vec3_sub_vec3(hit->hit_point,
				scene->sphere[sp_i]->xyz_pos));
	set_hit_normal_direc(ray_set, hit);
	hit->color = scene->sphere[sp_i]->rgb;
	return (0);
}

int	hittable(t_scene *scene, t_rt *rt, t_ray ray_set, t_hit *hit)
{
	int	i;
	int	hit_flag;

	i = 0;
	hit_flag = 0;
	while (i < rt->obj)
	{
		if (!(hit_sphere(scene, ray_set, hit, i)))
			hit_flag = 1;
		i++;
	}
	return (hit_flag);
}

t_rgb3 ray_trace(t_scene *scene, t_rt *rt, t_ray ray_set)
{
	t_hit	hit;
	t_rgb3	a;
	//t_rgb3	l;

	if (hittable(scene, rt, ray_set, &hit))
	{
		a.r = (scene->ambient->lighting) * (scene->ambient->rgb.r) * hit.color.r * 0.001;
		a.g = (scene->ambient->lighting) * (scene->ambient->rgb.g) * hit.color.g * 0.001;
		a.b = (scene->ambient->lighting) * (scene->ambient->rgb.b) * hit.color.b * 0.001;
		//l = color_add(rgb3(0,0,0), apply_light_color());
		return (a);
	}
	return (rgb3(0,0,0));
}

void	ray_trace_start(t_scene *scene, t_rt *rt, t_mlx *mlx)
{
	int	i;
	int	j;
	int	s;
	t_rgb3	c;

	i = 0;
	j = (WIN_W / ASPECT_RATIO_W * ASPECT_RATIO_H) - 1;
	s = 0;
	while (0 <= j)
	{
		printf("Rendering... %d %%\n",
				((WIN_W / ASPECT_RATIO_W * ASPECT_RATIO_H) - j) * 100
				/ (WIN_W / ASPECT_RATIO_W * ASPECT_RATIO_H));
		while (i <= WIN_W - 1)
		{
			c = rgb3(0, 0, 0);
			while (s < NUM_SAMPLE)
			{
				c = color_add(c, ray_trace(scene, rt, ray_set(rt, i, j)));
				s++;
			}
			c = color_average(c, NUM_SAMPLE);
			my_mlx_pixel_put(mlx, i, j, rgb_color(c));
			s = 0;
			i++;
		}
		i = 0;
		j--;
	}
}

void	raytracing_main(t_scene *scene, t_mlx *mlx)
{
	t_rt	rt;

	if (init_window(mlx))
	{
		err_msg("mlx init error");
		free(scene);
		exit (1);
	}
	init_rt(scene, &rt);
	ray_trace_start(scene, &rt, mlx);
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->win, mlx->img_ptr, 0, 0);
	free_scene(scene);
	mlx_hook(mlx->win, 17, 2, mlx_exit, mlx);
	mlx_key_hook(mlx->win, mlx_keys, mlx);
	mlx_loop(mlx->mlx_ptr);
}
