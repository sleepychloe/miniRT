/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniRT_utils_mlx.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhwang <yhwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 22:20:07 by yhwang            #+#    #+#             */
/*   Updated: 2022/11/30 22:36:31 by yhwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_UTILS_MLX_H
# define MINIRT_UTILS_MLX_H

/* mlx window setting */
# define ASPECT_RATIO_W			16
# define ASPECT_RATIO_H			9
# define WIN_W				800

/* translating rotating */
# define ROTATE_ANGLE			45
# define CAMERA_MOVE			1
# define LIGHT_MOVE			1
# define OBJECT_MOVE			0.5
# define ZOOM				10

/* translating roatating flag */
# define C_MOVE_X_MINUS			1
# define C_MOVE_X_PLUS			2
# define C_MOVE_Y_MINUS			3
# define C_MOVE_Y_PLUS			4
# define C_MOVE_Z_MINUS			5
# define C_MOVE_Z_PLUS			6
# define C_ROTATE_X			7
# define C_ROTATE_Y			8
# define C_ROTATE_Z			9

# define L_MOVE_X_MINUS			10
# define L_MOVE_X_PLUS			11
# define L_MOVE_Y_MINUS			12
# define L_MOVE_Y_PLUS			13
# define L_MOVE_Z_MINUS			14
# define L_MOVE_Z_PLUS			15

# define SP_MOVE_X_MINUS		16
# define SP_MOVE_X_PLUS			17
# define SP_MOVE_Y_MINUS		18
# define SP_MOVE_Y_PLUS			19
# define SP_MOVE_Z_MINUS		20
# define SP_MOVE_Z_PLUS			21
# define SP_NEXT			22

# define PL_MOVE_X_MINUS		23
# define PL_MOVE_X_PLUS			24
# define PL_MOVE_Y_MINUS		25
# define PL_MOVE_Y_PLUS			26
# define PL_MOVE_Z_MINUS		27
# define PL_MOVE_Z_PLUS			28
# define PL_ROTATE_X			29
# define PL_ROTATE_Y			30
# define PL_ROTATE_Z			31
# define PL_NEXT			32

# define CY_MOVE_X_MINUS		33
# define CY_MOVE_X_PLUS			34
# define CY_MOVE_Y_MINUS		35
# define CY_MOVE_Y_PLUS			36
# define CY_MOVE_Z_MINUS		37
# define CY_MOVE_Z_PLUS			38
# define CY_ROTATE_X			39
# define CY_ROTATE_Y			40
# define CY_ROTATE_Z			41
# define CY_NEXT			42

# include "./miniRT.h"

/* utils_mlx */
int		mlx_init_window(t_mlx *mlx);
void	my_mlx_pixel_put(t_mlx *mlx, int x, int y, int color);
int		mlx_exit(t_data *data);
int		mlx_keys(int key, t_data *data);

/* utils_mlx_key_move_camera */
void	mlx_move_camera_x(int key, t_data *data);
void	mlx_move_camera_y(int key, t_data *data);
void	mlx_move_camera_z(int key, t_data *data);
void	mlx_move_camera_zoom(int key, t_data *data);
void	mlx_move_camera(int key, t_data *data);

/* utils_mlx_key_rotate_camera_1 */
void	mlx_rotate_camera_x_axis(t_data *data, int flag,
			double val_cos, double val_sin);
void	mlx_rotate_camera_y_axis(t_data *data, int flag,
			double val_cos, double val_sin);
void	mlx_rotate_camera_z_axis(t_data *data, int flag,
			double val_cos, double val_sin);
void	mlx_rotate_camera(int key, t_data *data);

/* utils_mlx_key_rotate_camera_2 */
void	mlx_rotate_camera_x_axis_set_norm_vec(t_data *data,
			double val_cos, double val_sin);
void	mlx_rotate_camera_y_axis_set_norm_vec(t_data *data,
			double val_cos, double val_sin);
void	mlx_rotate_camera_z_axis_set_norm_vec(t_data *data,
			double val_cos, double val_sin);

/* utils_mlx_key_rotate_camera_3 */
void	mlx_rotate_camera_x_axis_set_keep_scene(t_data *data,
			double val_cos, double val_sin);
void	mlx_rotate_camera_y_axis_set_keep_scene(t_data *data,
			double val_cos, double val_sin);
void	mlx_rotate_camera_z_axis_set_keep_scene(t_data *data,
			double val_cos, double val_sin);

/* utils_mlx_key_rotate_camera_x_1 */
void	mlx_rotate_camera_x_axis_set_sp(t_data *data,
			double val_cos, double val_sin);
void	mlx_rotate_camera_x_axis_set_pl_vec(t_data *data,
			double val_cos, double val_sin, int i);
void	mlx_rotate_camera_x_axis_set_pl(t_data *data,
			double val_cos, double val_sin);

/* utils_mlx_key_rotate_camera_x_2 */
void	mlx_rotate_camera_x_axis_set_cy_vec(t_data *data,
			double val_cos, double val_sin, int i);
void	mlx_rotate_camera_x_axis_set_cy(t_data *data,
			double val_cos, double val_sin);
void	mlx_rotate_camera_x_axis_set_l(t_data *data,
			double val_cos, double val_sin);

/* utils_mlx_key_rotate_camera_y_1 */
void	mlx_rotate_camera_y_axis_set_sp(t_data *data,
			double val_cos, double val_sin);
void	mlx_rotate_camera_y_axis_set_pl_vec(t_data *data,
			double val_cos, double val_sin, int i);
void	mlx_rotate_camera_y_axis_set_pl(t_data *data,
			double val_cos, double val_sin);

/* utils_mlx_key_rotate_camera_y_2 */
void	mlx_rotate_camera_y_axis_set_cy_vec(t_data *data,
			double val_cos, double val_sin, int i);
void	mlx_rotate_camera_y_axis_set_cy(t_data *data,
			double val_cos, double val_sin);
void	mlx_rotate_camera_y_axis_set_l(t_data *data,
			double val_cos, double val_sin);

/* utils_mlx_key_rotate_camera_z_1 */
void	mlx_rotate_camera_z_axis_set_sp(t_data *data,
			double val_cos, double val_sin);
void	mlx_rotate_camera_z_axis_set_pl_vec(t_data *data,
			double val_cos, double val_sin, int i);
void	mlx_rotate_camera_z_axis_set_pl(t_data *data,
			double val_cos, double val_sin);

/* utils_mlx_key_rotate_camera_z_2 */
void	mlx_rotate_camera_z_axis_set_cy_vec(t_data *data,
			double val_cos, double val_sin, int i);
void	mlx_rotate_camera_z_axis_set_cy(t_data *data,
			double val_cos, double val_sin);
void	mlx_rotate_camera_z_axis_set_l(t_data *data,
			double val_cos, double val_sin);

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

/* utils_mlx_key_rotate_plane_1 */
void	mlx_rotate_plane_x_axis(t_data *data, int flag, int i);
void	mlx_rotate_plane_y_axis(t_data *data, int flag, int i);
void	mlx_rotate_plane_z_axis(t_data *data, int flag, int i);
void	mlx_rotate_plane(int key, t_data *data, int i);

/* utils_mlx_key_rotate_plane_2 */
void	mlx_rotate_plane_x_axis_set_keep_scene(t_data *data, int i,
			double val_cos, double val_sin);
void	mlx_rotate_plane_y_axis_set_keep_scene(t_data *data, int i,
			double val_cos, double val_sin);
void	mlx_rotate_plane_z_axis_set_keep_scene(t_data *data, int i,
			double val_cos, double val_sin);

/* utils_mlx_key_move_cylinde */
void	mlx_move_cylinder_x(int key, t_data *data, int i);
void	mlx_move_cylinder_y(int key, t_data *data, int i);
void	mlx_move_cylinder_z(int key, t_data *data, int i);
void	mlx_move_cylinder(int key, t_data *data, int i);

/* utils_mlx_key_rotate_cylinder_1 */
void	mlx_rotate_cylinder_x_axis(t_data *data, int flag, int i);
void	mlx_rotate_cylinder_y_axis(t_data *data, int flag, int i);
void	mlx_rotate_cylinder_z_axis(t_data *data, int flag, int i);
void	mlx_rotate_cylinder(int key, t_data *data, int i);

/* utils_mlx_key_rotate_cylinder_2 */
void	mlx_rotate_cylinder_x_axis_set_keep_scene(t_data *data, int i,
			double val_cos, double val_sin);
void	mlx_rotate_cylinder_y_axis_set_keep_scene(t_data *data, int i,
			double val_cos, double val_sin);
void	mlx_rotate_cylinder_z_axis_set_keep_scene(t_data *data, int i,
			double val_cos, double val_sin);

#endif