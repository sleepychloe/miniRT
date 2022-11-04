/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytracing_main.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhwang <yhwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 20:00:26 by yhwang            #+#    #+#             */
/*   Updated: 2022/11/04 23:16:50 by yhwang           ###   ########.fr       */
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

int hit_sphere(t_vec3 center, double radius, t_vec3 direction)
{
	t_vec3 oc = vec3_sub_vec3(center, vec3(0,0,0));
	double a = vec3_dot_vec3(direction, direction);
	double b = 2.0 * vec3_dot_vec3(oc, direction);
	double c = vec3_dot_vec3(oc, oc) - radius * radius;
	double discriminant = b * b - 4 * a * c;
	if (discriminant > 0)
		return (9999);
	return ((-b - sqrt(discriminant)) / (2.0 * a));
}

t_vec3	ray(t_vec3 start, t_vec3 direc, double t)
{
	t_vec3	res;
	
	if (t == '\0')
		return (direc);
	res = vec3_add_vec3(start, vec3_mul_rn(direc, t));
	return (res);
}

int ray_color(t_scene *scene, double u, double v)
{
	double focal_length = 0.3;
	double viewport_width = 2 * focal_length * tan(PI / 360 * scene->camera->fov);
	double viewport_height = viewport_width / ASPECT_RATIO_W * ASPECT_RATIO_H;
	//double t;
	t_vec3 vec_ray_direc;
	t_vec3 vec_ray_uv_direc;

	//t_vec3 horizontal = vec3(viewport_width, 0, 0);
	//t_vec3 vertical = vec3(0, viewport_height, 0);
	/*
	t_vec3 lower_left_corner = vec3_sub_vec3(scene->camera->xyz_pos, vec3_add_vec3(vec3_add_vec3(vec3_mul_rn(horizontal, 0.5),
			vec3_mul_rn(vertical, 0.5)),vec3(0, 0, focal_length)));
	t = hit_sphere(scene->sphere[0]->xyz_pos,
			(scene->sphere[0]->diameter)/2,
			vec3_sub_vec3(vec3_add_vec3(vec3_add_vec3(lower_left_corner,vec3_mul_rn(horizontal, u)),vec3_mul_rn(vertical, v)), scene->camera->xyz_pos));
	t_vec3 direc = vec3_sub_vec3(vec3_add_vec3(vec3_add_vec3(lower_left_corner,vec3_mul_rn(horizontal, u)),vec3_mul_rn(vertical, v)), scene->camera->xyz_pos);
	if (t > 0.0)
	{
		t_vec3 N = vec3_unit(vec3_sub_vec3(vec3_add_vec3(scene->camera->xyz_pos, vec3_mul_rn(direc, t)), vec3(0, 0, -1)));
		return (0.5 * ((N.x + 1) * 255 * 255 + (N.y + 1) * 255 + N.z + 1));
	}
	t_vec3 unit_direction = vec3_unit(vec3_sub_vec3(vec3_add_vec3(vec3_add_vec3(lower_left_corner,vec3_mul_rn(horizontal, u)),vec3_mul_rn(vertical, v)), scene->camera->xyz_pos));
	t = 0.5 * (unit_direction.y + 1.0);
	return ((1.0 - t) * (t*255*255 + t*255 + t) * (0.5 * 255 * 255 + 0.7 * 255 + 1));
	*/
	vec_ray_direc = vec3_sub_vec3(vec3(-(viewport_width / 2), viewport_height / 2, 0), scene->camera->xyz_pos);
	vec_ray_uv_direc = vec3_add_vec3(vec3_add_vec3(vec_ray_direc, vec3_mul_rn(vec3(u, 0, 0), viewport_width)), vec3_mul_rn(vec3(0, v, 0), viewport_height));
	if (hit_sphere(scene->sphere[0]->xyz_pos, ((scene->sphere[0]->diameter) / 2), vec3_sub_vec3(vec_ray_uv_direc, scene->sphere[0]->xyz_pos)) == 9999)
		return (0x00FF0000);
	return (0x00000000);
}	

void	raytrace(t_scene *scene, t_mlx *mlx)
{	
	int		i;
	int		j;
	double	u;
	double	v;
	int		c;

	i = 0;
	j = WIN_H - 1;
	while (0 <= j)
	{
		while (i < WIN_W)
		{
			u = (double)i / (WIN_W - 1);
			v = (double)j / (WIN_H - 1);
			c = ray_color(scene, u, v);
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
