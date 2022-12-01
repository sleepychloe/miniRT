/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniRT_raytracing.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhwang <yhwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 22:20:12 by yhwang            #+#    #+#             */
/*   Updated: 2022/12/01 03:14:40 by yhwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_RAYTRACING_H
# define MINIRT_RAYTRACING_H

/* object */
# define SPHERE				1
# define PLANE				2
# define CYLINDER			3

/* num for math */
# define PI				3.14159265359

/* repeating time for ray tracing */
# define NUM_SAMPLE			2

/* checking direction of normal vector */
# define FRONT				1
# define BACK				2

/* cylinder circle */
# define TOP				0
# define BOTTOM				1

# include "./miniRT.h"

/* raytracing_main */
int		hittable(t_data *data, t_hit *hit);
t_rgb3	trace(t_data *data, t_ray ray);
void	ray_tracing(t_data *data);
void	rt_start(t_data *data, int flag);
void	raytracing_main(t_scene *scene, t_scene *keep_scene, t_mlx *mlx);

/* raytracing_set_camera_1 */
void	camera_vec_zero_zero_plusone(t_data *data);
void	camera_vec_minusone_zero_zero(t_data *data);
void	camera_vec_plusone_zero_zero(t_data *data);
void	raytracing_set_camera(t_data *data);

/* raytracing_set_camera_2 */
void	camera_vec_zero_minusone_zero(t_data *data);
void	camera_vec_zero_plusone_zero(t_data *data);

/* raytracing_init_struct_obj_1 */
void	norminette_init_obj(t_scene *scene, t_obj **obj, int n_obj);
t_obj	**init_obj(t_scene *scene);

/* raytracing_init_struct_obj_2 */
void	put_value_obj_sp(t_scene *scene, t_obj **obj);
void	put_value_obj_pl(t_scene *scene, t_obj **obj);
void	put_value_obj_cy(t_scene *scene, t_obj **obj);
void	put_value_obj_pl_dup_1(t_scene *scene, t_obj **obj, int n_obj);
void	put_value_obj_pl_dup_2(t_scene *scene, t_obj **obj, int n_obj);

/* raytracing_init_struct_rt */
void	init_rt(t_scene *scene, t_rt *rt);

/* raytracing_ray */
t_ray	ray(t_vec3 point, t_vec3 direc);
t_ray	ray_set(t_data *data, double u, double v);

/* raytracing_light */
int		check_light_hit_obj(t_data *data, double distance);
int		calculate_light(t_data *data, t_hit *hit,
			double *light_intensity, t_rgb3 *light_color);
t_rgb3	apply_light(t_data *data, t_hit *hit);

/* raytracing_sphere */
int		check_sphere(t_data *data, double *t, int sp_i, double distance);
int		hit_sphere(t_data *data, t_hit *hit, int sp_i, double distance);
int		light_hit_sp(t_data *data, int sp_i, double distance);

/* raytracing_plane */
int		check_plane(t_data *data, double *t, int pl_i, double distance);
int		hit_plane(t_data *data, t_hit *hit, int pl_i, double distance);
int		light_hit_pl(t_data *data, int pl_i, double distance);

/* raytracing_cylinder_1 */
void	norminette_check_cylinder_body(t_data *data,
			int cy_i, double *d, t_vec3 *cy_center);
double	check_cylinder_body(t_data *data, int cy_i, double distance);
t_vec3	calc_normal_vec_cylinder_body(t_data *data, t_hit *hit, int cy_i);
int		hit_cylinder(t_data *data, t_hit *hit, int cy_i, double distance);
int		light_hit_cy(t_data *data, int cy_i, double distance);

/* raytracing_cylinder_2 */
void	norminette_check_cylinder_circle_1(t_data *data,
			int cy_i, t_vec3 *cy_center, t_vec3 *tc);
void	norminette_check_cylinder_circle_2(double *dot, double *t_circle);
void	norminette_check_cylinder_circle_3(t_data *data,
			double *t_circle, t_vec3 *hit_p);
int		check_circle_radius(t_data *data,
			int cy_i, t_vec3 hit_point, t_vec3 cy_center);
double	check_cylinder_circle(t_data *data, int cy_i, double distance);

/* raytracing_utils */
void	set_hit_point(t_data *data, t_hit *hit, double t);
void	set_hit_normal_direc(t_data *data, t_hit *hit);

#endif