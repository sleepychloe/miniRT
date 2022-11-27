/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniRT.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhwang <yhwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 16:15:19 by yhwang            #+#    #+#             */
/*   Updated: 2022/11/27 08:54:40 by yhwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

/* parsing error code */
# define ERR_ATOI			-9999
# define ERR_ATOD			-9999.0
# define ERR_MALLOC			1

# define ERR_IDENTIFIER			2
# define ERR_LINE_TOKEN			3
# define ERR_LIGHTING_VALUE		4
# define ERR_FOV_VALUE			5
# define ERR_BRIGHTNESS_VALUE		6
# define ERR_DIAMETER_VALUE		7
# define ERR_HEIGHT_VALUE		8
# define ERR_RGB_TOKEN			9
# define ERR_RGB_VALUE			10
# define ERR_XYZ_POS_TOKEN		11
# define ERR_XYZ_POS_VALUE		12
# define ERR_XYZ_VEC_TOKEN		13
# define ERR_XYZ_VEC_VALUE		14

/* window setting for mlx */
# define ASPECT_RATIO_W			16
# define ASPECT_RATIO_H			9
# define WIN_W				800

/* object */
# define SPHERE				1
# define PLANE				2
# define CYLINDER			3

/* num for math */
# define PI				3.14159265359

/* repeating time for ray tracing */
# define NUM_SAMPLE			2
# define NUM_DEPTH			1

/* checking direction of normal vector */
# define FRONT				1
# define BACK				2

/* cylinder circle */
# define TOP				0
# define BOTTOM				1

/* linux key code */
# define KEY_UP				0xFF52
# define KEY_DOWN			0xFF54
# define KEY_ESC			0xFF1B

# define KEY_1				0x31
# define KEY_2				0x32
# define KEY_3				0x33
# define KEY_4				0x34
# define KEY_5				0x35
# define KEY_6				0x36
# define KEY_7				0x37
# define KEY_8				0x38
# define KEY_9				0x39

# define KEY_Q				0x71
# define KEY_W				0x77
# define KEY_E				0x65
# define KEY_R				0x72
# define KEY_T				0x74
# define KEY_Y				0x79
# define KEY_U				0x75
# define KEY_I				0x69
# define KEY_O				0x6F

# define KEY_A				0x61
# define KEY_S				0x73
# define KEY_D				0x64
# define KEY_F				0x66
# define KEY_G				0x67
# define KEY_H				0x68
# define KEY_J				0x6A
# define KEY_K				0x6B
# define KEY_L				0x6C

# define KEY_Z				0x7A
# define KEY_X				0x78
# define KEY_C				0x63
# define KEY_V				0x76
# define KEY_B				0x62
# define KEY_N				0x6E

# define KEY_POINT			0x2E
# define KEY_SLASH			0x2F
# define KEY_SEMICOLON			0x3B
# define KEY_SINGLE_QUOTE		0x27
# define KEY_SQUARE_BRACKET_LEFT	0x5B
# define KEY_SQUARE_BRACKET_RIGHT	0x5D

# define KEY_F1				0xFFBE
# define KEY_F2				0xFFBF
# define KEY_F3				0xFFC0

/* color */
# define B				"\x1b[0m"
# define R				"\x1b[31m"
# define BLUE				"\x1b[34m"
# define WHITE				"\x1b[7m"

# include "../libft/incs/libft.h"
# include "../libft/incs/get_next_line.h"
# include "../mlx_linux/mlx.h"
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <math.h>

typedef struct s_vec3
{
	double	x;
	double	y;
	double	z;
}	t_vec3;

typedef struct s_rgb3
{
	double	r;
	double	g;
	double	b;
}	t_rgb3;

typedef struct s_ambient
{
	int			check;
	int			err;
	double		lighting;
	t_rgb3		rgb;
}	t_ambient;

typedef struct s_camera
{
	int			check;
	int			err;
	t_vec3	xyz_pos;
	t_vec3		xyz_vec;
	int		 fov;
}	t_camera;

typedef struct s_light
{
	int			check;
	int			err;
	t_vec3		xyz_pos;
	double		brightness;
	t_rgb3		rgb;
}	t_light;

typedef struct s_sphere
{
	int			err;
	t_vec3		xyz_pos;
	double		diameter;
	t_rgb3		rgb;
}	t_sphere;

typedef struct s_plane
{
	int			err;
	t_vec3		xyz_pos;
	t_vec3		xyz_vec;
	t_rgb3		rgb;
}	t_plane;

typedef struct s_cylinder
{
	int			err;
	t_vec3		xyz_pos;
	t_vec3		xyz_vec;
	double		diameter;
	double		height;
	t_rgb3		rgb;
}	t_cylinder;

typedef struct s_scene
{
	t_ambient	*ambient;
	t_camera	*camera;
	t_light		*light;
	t_sphere	**sphere;
	t_plane		**plane;
	t_cylinder	**cylinder;
	int			n_sphere;
	int			n_plane;
	int			n_cylinder;
}	t_scene;

typedef struct s_obj
{
	int			obj_type;
	t_vec3		xyz_pos;
	t_vec3		xyz_vec;
	double		diameter;
	double		height;
	t_rgb3		rgb;
}	t_obj;

typedef struct s_mlx
{
	void		*mlx_ptr;
	void		*win;
	void		*img_ptr;
	char		*addr;
	int			line_length;
	int			bits_per_pixel;
	int			endian;
}	t_mlx;

typedef struct s_rt
{
	double		focal_length;
	double		viewport_width;
	double		viewport_height;
	t_vec3		vp_horizontal;
	t_vec3		vp_vertical;
	t_vec3		vp_low_left;
	t_vec3		cam_xyz_pos;
}	t_rt;

typedef struct s_ray
{
	t_vec3		point;
	t_vec3		direc;
}	t_ray;

typedef struct s_hit
{
	double		t;
	t_vec3		hit_point;
	t_vec3		normal_vec;
	int			front;
	t_rgb3		color;
}	t_hit;

typedef struct s_data
{
	t_scene		*scene;
	t_obj		**obj;
	t_mlx		*mlx;
	t_rt		*rt;
	t_ray		*ray;
	t_hit		*hit;
	int			n_obj;
	int			sp;
	int			pl;
	int			cy;
}	t_data;

/* parse_init_struct_1 */
void	init_struct_a(t_scene *scene);
void	init_struct_c(t_scene *scene);
void	init_struct_l(t_scene *scene);
void	init_struct(t_scene *scene);

/* parse_init_struct_2 */
void	init_struct_sp(t_scene *scene, int i);
void	init_struct_pl(t_scene *scene, int i);
void	init_struct_cy(t_scene *scene, int i);

/* parse_arg */
int		check_extention(char *str);
void	parse_arg(t_scene *scene, char *argv);

/* parse_map */
void	finish_gnl(t_scene *scene, char **line, int fd, int err);
char	**check_line(char **line);
int		check_id(t_scene *scene, char **line);
void	parse_map(t_scene *scene, char *argv);

/* parse_ambient_1 */
int		parse_a_norminette(t_scene *scene, char ***s);
int		parse_a(t_scene *scene, char **line);

/* parse_ambient_2 */
int		parse_a_token(t_scene *scene, char ***s);
int		parse_a_lighting(t_scene *scene, char ***s);
int		check_value_a_rgb(t_scene *scene, char **rgb);
int		parse_a_rgb(t_scene *scene, char ***s);

/* parse_camera_1 */
int		parse_c_token(t_scene *scene, char ***s);
int		check_value_c_xyz_pos(t_scene *scene, char **xyz_pos);
int		parse_c_xyz_pos(t_scene *scene, char ***s);
int		parse_c_norminette(t_scene *scene, char ***s);
int		parse_c(t_scene *scene, char **line);

/* parse_camera_2 */
int		check_value_c_xyz_vec(t_scene *scene, char **xyz_vec);
int		parse_c_xyz_vec(t_scene *scene, char ***s);
int		parse_c_fov(t_scene *scene, char ***s);

/* parse_light_1 */
int		parse_l_token(t_scene *scene, char ***s);
int		check_value_l_xyz_pos(t_scene *scene, char **xyz_pos);
int		parse_l_xyz_pos(t_scene *scene, char ***s);
int		parse_l_norminette(t_scene *scene, char ***s);
int		parse_l(t_scene *scene, char **line);

/* parse_light_2 */
int		parse_l_brightness(t_scene *scene, char ***s);
int		check_value_l_rgb(t_scene *scene, char **rgb);
int		parse_l_rgb(t_scene *scene, char ***s);

/* parse_sphere_1 */
int		parse_sp_token(t_scene *scene, int i, char ***s);
int		check_value_sp_xyz_pos(t_scene *scene, int i, char **xyz_pos);
int		parse_sp_xyz_pos(t_scene *scene, int i, char ***s);
int		parse_sp_norminette(t_scene *scene, int i, char ***s);
int		parse_sp(t_scene *scene, char **line);

/* parse_sphere_2 */
int		parse_sp_diameter(t_scene *scene, int i, char ***s);
int		check_value_sp_rgb(t_scene *scene, int i, char **rgb);
int		parse_sp_rgb(t_scene *scene, int i, char ***s);

/* parse_plane_1 */
int		parse_pl_token(t_scene *scene, int i, char ***s);
int		check_value_pl_xyz_pos(t_scene *scene, int i, char **xyz_pos);
int		parse_pl_xyz_pos(t_scene *scene, int i, char ***s);
int		parse_pl_norminette(t_scene *scene, int i, char ***s);
int		parse_pl(t_scene *scene, char **line);

/* parse_plane_2 */
int		check_value_pl_xyz_vec(t_scene *scene, int i, char **xyz_vec);
int		parse_pl_xyz_vec(t_scene *scene, int i, char ***s);
int		check_value_pl_rgb(t_scene *scene, int i, char **rgb);
int		parse_pl_rgb(t_scene *scene, int i, char ***s);

/* parse_cylinder_1 */
int		parse_cy_token(t_scene *scene, int i, char ***s);
int		check_value_cy_xyz_pos(t_scene *scene, int i, char **xyz_pos);
int		parse_cy_xyz_pos(t_scene *scene, int i, char ***s);
int		parse_cy_norminette(t_scene *scene, int i, char ***s);
int		parse_cy(t_scene *scene, char **line);

/* parse_cylinder_2 */
int		parse_cy_diameter(t_scene *scene, int i, char ***s);
int		parse_cy_height(t_scene *scene, int i, char ***s);
int		check_value_cy_xyz_vec(t_scene *scene, int i, char **xyz_vec);
int		parse_cy_xyz_vec(t_scene *scene, int i, char ***s);

/* parse_cylinder_3 */
int		check_value_cy_rgb(t_scene *scene, int i, char **rgb);
int		parse_cy_rgb(t_scene *scene, int i, char ***s);

/* parse_err_1 */
void	err_check_a(t_scene *scene);
void	err_check_c(t_scene *scene);
void	err_check_l(t_scene *scene);
int		check_parse_error(t_scene *scene);

/* parse_err_2 */
void	err_check_sp(t_scene *scene, int i);
void	err_check_pl(t_scene *scene, int i);
void	err_check_cy(t_scene *scene, int i);

/* parse_utils */
void	err_msg(char *str);
void	map_err_i(int i, char *id, char *str);
int		token_count(char **token, int cnt);
int		check_comma(char *str);

/* raytracing_main */
int		hittable(t_data *data, t_hit *hit);
t_rgb3	trace(t_data *data, t_ray ray, int depth);
void	ray_tracing(t_data *data);
void	rt_start(t_data *data, int flag);
void	raytracing_main(t_scene *scene, t_mlx *mlx);

/* raytracing_init_struct */
void	put_value_obj_sp_pl(t_scene *scene, t_obj **obj);
void	put_value_obj_cy(t_scene *scene, t_obj **obj);
void	norminette_init_obj(t_scene *scene, t_obj **obj);
t_obj	**init_obj(t_scene *scene);
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

/* utils_free */
void	*ft_realloc(void *old_ptr, size_t old_len, size_t new_len);
void	ft_free_2d(char **str);
void	ft_free_3d(char ***str);
void	free_scene(t_scene *scene);
void	free_obj(t_obj **obj);

/* utils_vec3_1 */
t_vec3	vec3(double x, double y, double z);
t_vec3	vec3_add_vec3(t_vec3 v1, t_vec3 v2);
t_vec3	vec3_sub_vec3(t_vec3 v1, t_vec3 v2);
t_vec3	vec3_mul_rn(t_vec3 v, double rn);
double	vec3_dot_vec3(t_vec3 v1, t_vec3 v2);

/* utils_vec3_2 */
double	vec3_length(t_vec3 v);
t_vec3	vec3_unit(t_vec3 v);

/* utils_color */
t_rgb3	rgb3(double r, double g, double b);
t_rgb3	color_add(t_rgb3 c1, t_rgb3 c2);
double	color_clamp(double c);
t_rgb3	color_average(t_rgb3 c);
int		color_convert_to_int(t_rgb3 rgb);

/* utils_random */
double	random_double(void);
t_vec3	random_double_xyz(void);

/* utils_mlx */
int		mlx_init_window(t_mlx *mlx);
void	my_mlx_pixel_put(t_mlx *mlx, int x, int y, int color);
int		mlx_exit(t_data *data);
int		mlx_keys(int key, t_data *data);

/* utils_mlx_key_move_camera */
void	mlx_move_camera_x(int key, t_data *data);
void	mlx_move_camera_y(int key, t_data *data);
void	mlx_move_camera_z(int key, t_data *data);
void	mlx_move_camera(int key, t_data *data);

/* utils_mlx_key_rotate_camera */
void	mlx_rotate_camera_x_axis(t_data *data, int flag);
void	mlx_rotate_camera_y_axis(t_data *data, int flag);
void	mlx_rotate_camera_z_axis(t_data *data, int flag);
void	mlx_rotate_camera(int key, t_data *data);

/* utils_mlx_key_move_light */
void	mlx_move_light_x(int key, t_data *data);
void	mlx_move_light_y(int key, t_data *data);
void	mlx_move_light_z(int key, t_data *data);
void	mlx_move_light(int key, t_data *data);

/* utils_mlx_key_move_sphere */
void	mlx_move_sphere_x(int key, t_data *data, int i);
void	mlx_move_sphere_y(int key, t_data *data, int i);
void	mlx_move_sphere_z(int key, t_data *data, int i);
void	mlx_move_sphere(int key, t_data *data, int i);

/* utils_mlx_key_move_plane */
void	mlx_move_plane_x(int key, t_data *data, int i);
void	mlx_move_plane_y(int key, t_data *data, int i);
void	mlx_move_plane_z(int key, t_data *data, int i);
void	mlx_move_plane(int key, t_data *data, int i);

/* utils_mlx_key_rotate_plane */
void	mlx_rotate_plane_x_axis(t_data *data, int flag, int i);
void	mlx_rotate_plane_y_axis(t_data *data, int flag, int i);
void	mlx_rotate_plane_z_axis(t_data *data, int flag, int i);
void	mlx_rotate_plane(int key, t_data *data, int i);

/* utils_mlx_key_move_cylinder */
void	mlx_move_cylinder_x(int key, t_data *data, int i);
void	mlx_move_cylinder_y(int key, t_data *data, int i);
void	mlx_move_cylinder_z(int key, t_data *data, int i);
void	mlx_move_cylinder(int key, t_data *data, int i);

/* utils_mlx_key_rotate_cylinder */
void	mlx_rotate_cylinder_x_axis(t_data *data, int flag, int i);
void	mlx_rotate_cylinder_y_axis(t_data *data, int flag, int i);
void	mlx_rotate_cylinder_z_axis(t_data *data, int flag, int i);
void	mlx_rotate_cylinder(int key, t_data *data, int i);

/* utils_msg_1 */
void	show_guide_1(void);
void	show_guide_2(void);
void	show_guide_3(void);
void	show_guide_3(void);
void	show_guide(void);

/* utils_msg_2 */
void	print_info_1(t_data *data, t_scene *scene, int flag);
void	print_info_2(t_data *data, t_scene *scene, int flag);
void	print_info_3(t_data *data, t_scene *scene, int flag);
void	print_info_4(t_data *data, t_scene *scene, int flag);
void	print_scene_info(t_data *data, t_scene *scene, int flag);

/* utils_msg_3 */
void	print_info_5(t_data *data, t_scene *scene, int flag);
void	print_info_6(t_data *data, t_scene *scene, int flag);
void	print_info_7(t_data *data, t_scene *scene, int flag);

/* main */
int		minirt_main(char **argv);
int		main(int argc, char **argv);

#endif