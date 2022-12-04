/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniRT_parse_bonus.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhwang <yhwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 22:04:42 by yhwang            #+#    #+#             */
/*   Updated: 2022/12/04 13:07:11 by yhwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_PARSE_BONUS_H
# define MINIRT_PARSE_BONUS_H

/* object surface */
# define SURFACE_L			1
# define SURFACE_C			2
# define SURFACE_T			3
# define SURFACE_I			4
# define SURFACE_D			5
# define SURFACE_M			6
# define SURFACE_G			7

/* parsing error code */
# define ERR_ATOI			-9999
# define ERR_ATOD			-9999.0
# define ERR_MALLOC			1
# define ERR_IDENTIFIER			2
# define ERR_LINE_TOKEN			3
# define ERR_LIGHTING_VALUE		4
# define ERR_FOV_VALUE			5
# define ERR_BRIGHTNESS_VALUE		6
# define ERR_XYZ_POS_TOKEN		7
# define ERR_XYZ_POS_VALUE		8
# define ERR_XYZ_VEC_TOKEN		9
# define ERR_XYZ_VEC_VALUE		10
# define ERR_DIAMETER_VALUE		11
# define ERR_HEIGHT_VALUE		12
# define ERR_SURFACE_FLAG		13
# define ERR_FUZZ_VALUE			14
# define ERR_RGB_TOKEN			15
# define ERR_RGB_VALUE			16
# define ERR_TEXTURE_PATH		17
# define ERR_IMAGE_PATH			18

# include "./miniRT_bonus.h"

/* parse_init_struct_1_bonus */
void	init_struct_scene_a(t_scene *scene);
void	init_struct_scene_c(t_scene *scene);
void	init_struct_scene_l(t_scene *scene, int i);
void	init_struct_scene(t_scene *scene);

/* parse_init_struct_2_bonus */
void	init_struct_scene_sp(t_scene *scene, int i);
void	init_struct_scene_pl(t_scene *scene, int i);
void	init_struct_scene_cy(t_scene *scene, int i);
void	init_struct_scene_co(t_scene *scene, int i);

/* parse_arg_bonus */
int		check_extention(char *str);
void	parse_arg(t_scene *scene, char *argv);

/* parse_map_bonus */
void	finish_gnl(t_scene *scene, char **line, int fd, int err);
char	**check_line(char **line);
int		check_id(t_scene *scene, char **line);
void	parse_map(t_scene *scene, char *argv);

/* parse_ambient_1_bonus */
int		parse_a_norminette(t_scene *scene, char ***s);
int		parse_a(t_scene *scene, char **line);

/* parse_ambient_2_bonus */
int		parse_a_token(t_scene *scene, char ***s);
int		parse_a_lighting(t_scene *scene, char ***s);
int		check_value_a_rgb(t_scene *scene, char **rgb);
int		parse_a_rgb(t_scene *scene, char ***s);

/* parse_camera_1_bonus */
int		parse_c_token(t_scene *scene, char ***s);
int		check_value_c_xyz_pos(t_scene *scene, char **xyz_pos);
int		parse_c_xyz_pos(t_scene *scene, char ***s);
int		parse_c_norminette(t_scene *scene, char ***s);
int		parse_c(t_scene *scene, char **line);

/* parse_camera_2_bonus */
int		check_value_c_xyz_vec(t_scene *scene, char **xyz_vec);
int		parse_c_xyz_vec(t_scene *scene, char ***s);
int		parse_c_fov(t_scene *scene, char ***s);

/* parse_light_1_bonus */
int		parse_l_token(t_scene *scene, int i, char ***s);
int		check_value_l_xyz_pos(t_scene *scene, int i, char **xyz_pos);
int		parse_l_xyz_pos(t_scene *scene, int i, char ***s);
int		parse_l_norminette(t_scene *scene, int i, char ***s);
int		parse_l(t_scene *scene, char **line);

/* parse_light_2_bonus */
int		parse_l_brightness(t_scene *scene, int i, char ***s);
int		check_value_l_rgb(t_scene *scene, int i, char **rgb);
int		parse_l_rgb(t_scene *scene, int i, char ***s);

/* parse_sphere_1_bonus */
int		check_sp_token(t_scene *scene, int i, char ***s);
int		parse_sp_token(t_scene *scene, int i, char ***s);
int		parse_sp_norminette(t_scene *scene, int i, char ***s);
int		parse_sp(t_scene *scene, char **line);

/* parse_sphere_2_bonus */
int		check_value_sp_xyz_pos(t_scene *scene, int i, char **xyz_pos);
int		parse_sp_xyz_pos(t_scene *scene, int i, char ***s);
int		parse_sp_diameter(t_scene *scene, int i, char ***s);
int		parse_sp_surface_1(t_scene *scene, int i, char ***s);
int		parse_sp_surface_2(t_scene *scene, int i, char ***s);

/* parse_sphere_3_bonus */
int		parse_sp_surface_metal_fuzz(t_scene *scene, int i, char ***s);
int		check_value_sp_rgb(t_scene *scene, int i, char ***s, char **rgb);
void	put_value_sp_rgb1_rgb2(t_scene *scene, int i, char ***s, char **rgb);
int		parse_sp_rgb_1(t_scene *scene, int i, char ***s);
int		parse_sp_rgb_2(t_scene *scene, int i, char ***s);

/* parse_sphere_4_bonus */
int		parse_sp_texture_path(t_scene *scene, int i, char ***s);
int		parse_sp_img_path(t_scene *scene, int i, char ***s);

/* parse_plane_1_bonus */
int		check_pl_token(t_scene *scene, int i, char ***s);
int		parse_pl_token(t_scene *scene, int i, char ***s);
int		parse_pl_norminette(t_scene *scene, int i, char ***s);
int		parse_pl(t_scene *scene, char **line);

/* parse_plane_2_bonus */
int		check_value_pl_xyz_pos(t_scene *scene, int i, char **xyz_pos);
int		parse_pl_xyz_pos(t_scene *scene, int i, char ***s);
int		check_value_pl_xyz_vec(t_scene *scene, int i, char **xyz_vec);
int		parse_pl_xyz_vec(t_scene *scene, int i, char ***s);

/* parse_plane_3_bonus */
int		parse_pl_surface_metal_fuzz(t_scene *scene, int i, char ***s);
int		parse_pl_surface_1(t_scene *scene, int i, char ***s);
int		parse_pl_surface_2(t_scene *scene, int i, char ***s);
int		parse_pl_texture_path(t_scene *scene, int i, char ***s);
int		parse_pl_img_path(t_scene *scene, int i, char ***s);

/* parse_plane_4_bonus */
void	put_value_pl_rgb1_rgb2(t_scene *scene, int i, char ***s, char **rgb);
int		check_value_pl_rgb(t_scene *scene, int i, char ***s, char **rgb);
int		parse_pl_rgb_1(t_scene *scene, int i, char ***s);
int		parse_pl_rgb_2(t_scene *scene, int i, char ***s);

/* parse_cylinder_1_bonus */
int		check_cy_token(t_scene *scene, int i, char ***s);
int		parse_cy_token(t_scene *scene, int i, char ***s);
int		parse_cy_norminette(t_scene *scene, int i, char ***s);
int		parse_cy(t_scene *scene, char **line);

/* parse_cylinder_2_bonus */
int		check_value_cy_xyz_pos(t_scene *scene, int i, char **xyz_pos);
int		parse_cy_xyz_pos(t_scene *scene, int i, char ***s);
int		check_value_cy_xyz_vec(t_scene *scene, int i, char **xyz_vec);
int		parse_cy_xyz_vec(t_scene *scene, int i, char ***s);

/* parse_cylinder_3_bonus */
int		parse_cy_diameter(t_scene *scene, int i, char ***s);
int		parse_cy_height(t_scene *scene, int i, char ***s);
int		parse_cy_surface_metal_fuzz(t_scene *scene, int i, char ***s);
int		parse_cy_surface_1(t_scene *scene, int i, char ***s);
int		parse_cy_surface_2(t_scene *scene, int i, char ***s);

/* parse_cylinder_4_bonus */
void	put_value_cy_rgb1_rgb2(t_scene *scene, int i, char ***s, char **rgb);
int		check_value_cy_rgb(t_scene *scene, int i, char ***s, char **rgb);
int		parse_cy_rgb_1(t_scene *scene, int i, char ***s);
int		parse_cy_rgb_2(t_scene *scene, int i, char ***s);

/* parse_cylinder_5_bonus */
int		parse_cy_texture_path(t_scene *scene, int i, char ***s);
int		parse_cy_img_path(t_scene *scene, int i, char ***s);

/* parse_cone_1_bonus */
int		check_co_token(t_scene *scene, int i, char ***s);
int		parse_co_token(t_scene *scene, int i, char ***s);
int		parse_co_norminette(t_scene *scene, int i, char ***s);
int		parse_co(t_scene *scene, char **line);

/* parse_cone_2_bonus */
int		check_value_co_xyz_pos(t_scene *scene, int i, char **xyz_pos);
int		parse_co_xyz_pos(t_scene *scene, int i, char ***s);
int		check_value_co_xyz_vec(t_scene *scene, int i, char **xyz_vec);
int		parse_co_xyz_vec(t_scene *scene, int i, char ***s);

/* parse_cone_3_bonus */
int		parse_co_diameter(t_scene *scene, int i, char ***s);
int		parse_co_height(t_scene *scene, int i, char ***s);
int		parse_co_surface_metal_fuzz(t_scene *scene, int i, char ***s);
int		parse_co_surface_1(t_scene *scene, int i, char ***s);
int		parse_co_surface_2(t_scene *scene, int i, char ***s);

/* parse_cone_4_bonus */
void	put_value_co_rgb1_rgb2(t_scene *scene, int i, char ***s, char **rgb);
int		check_value_co_rgb(t_scene *scene, int i, char ***s, char **rgb);
int		parse_co_rgb_1(t_scene *scene, int i, char ***s);
int		parse_co_rgb_2(t_scene *scene, int i, char ***s);

/* parse_cone_5_bonus */
int		parse_co_texture_path(t_scene *scene, int i, char ***s);
int		parse_co_img_path(t_scene *scene, int i, char ***s);

/* parse_err_1_bonus */
void	err_check_a(t_scene *scene);
void	err_check_c(t_scene *scene);
void	err_check_l(t_scene *scene, int i);
int		check_parse_error(t_scene *scene);

/* parse_err_2_bonus */
void	err_check_sp_1(t_scene *scene, int i);
void	err_check_sp_2(t_scene *scene, int i);
void	err_check_pl_1(t_scene *scene, int i);
void	err_check_pl_2(t_scene *scene, int i);

/* parse_err_3_bonus */
void	err_check_cy_1(t_scene *scene, int i);
void	err_check_cy_2(t_scene *scene, int i);
void	err_check_co_1(t_scene *scene, int i);
void	err_check_co_2(t_scene *scene, int i);

/* parse_init_struct_keep_scene_1_bonus */
void	init_struct_keep_scene_a(t_scene *keep_scene, t_scene *scene);
void	init_struct_keep_scene_c(t_scene *keep_scene, t_scene *scene);
void	put_value_keep_scene_l(t_scene *keep_scene, t_scene *scene);
void	init_struct_keep_scene_l(t_scene *keep_scene, t_scene *scene);
void	init_struct_keep_scene(t_scene *keep_scene, t_scene *scene);

/* parse_init_struct_keep_scene_2_bonus */
void	put_value_keep_scene_sp(t_scene *keep_scene, t_scene *scene);
void	init_struct_keep_scene_sp(t_scene *keep_scene, t_scene *scene);
void	put_value_keep_scene_pl(t_scene *keep_scene, t_scene *scene);
void	init_struct_keep_scene_pl(t_scene *keep_scene, t_scene *scene);

/* parse_init_struct_keep_scene_3_bonus */
void	put_value_keep_scene_cy(t_scene *keep_scene, t_scene *scene);
void	init_struct_keep_scene_cy_norminette(t_scene *keep_scene,
			t_scene *scene);
void	init_struct_keep_scene_cy(t_scene *keep_scene, t_scene *scene);

/* parse_init_struct_keep_scene_4_bonus */
void	put_value_keep_scene_co(t_scene *keep_scene, t_scene *scene);
void	init_struct_keep_scene_co_norminette(t_scene *keep_scene,
			t_scene *scene);
void	init_struct_keep_scene_co(t_scene *keep_scene, t_scene *scene);

/* parse_utils_bonus */
void	err_msg(char *str);
void	map_err_i(int i, char *id, char *str);
int		token_count(char **token, int cnt);
int		check_comma(char *str);
int		check_comma_surface_flag(char *str);

#endif