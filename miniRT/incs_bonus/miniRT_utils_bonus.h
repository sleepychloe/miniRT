/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniRT_utils_bonus.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhwang <yhwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 22:09:04 by yhwang            #+#    #+#             */
/*   Updated: 2022/11/30 22:17:08 by yhwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_UTILS_BONUS_H
# define MINIRT_UTILS_BONUS_H

/* color */
# define B				"\x1b[0m"
# define R				"\x1b[31m"
# define BLUE				"\x1b[34m"
# define WHITE				"\x1b[7m"

# include "./miniRT_bonus.h"

/* utils_free_bonus */
void	*ft_realloc(void *old_ptr, size_t old_len, size_t new_len);
void	ft_free_2d(char **str);
void	ft_free_3d(char ***str);
void	free_scene(t_scene *scene);
void	free_obj(t_obj **obj);

/* utils_vec3_1_bonus */
t_vec3	vec3(double x, double y, double z);
t_vec3	vec3_add_vec3(t_vec3 v1, t_vec3 v2);
t_vec3	vec3_sub_vec3(t_vec3 v1, t_vec3 v2);
t_vec3	vec3_mul_rn(t_vec3 v, double rn);
double	vec3_dot_vec3(t_vec3 v1, t_vec3 v2);

/* utils_vec3_2_bonus */
double	vec3_length(t_vec3 v);
t_vec3	vec3_unit(t_vec3 v);

/* utils_color_bonus */
t_rgb3	rgb3(double r, double g, double b);
t_rgb3	color_add(t_rgb3 c1, t_rgb3 c2);
double	color_clamp(double c);
t_rgb3	color_average(t_rgb3 c);
int		color_convert_to_int(t_rgb3 rgb);

/* utils_random_bonus */
double	random_double(void);
t_vec3	random_double_xyz(void);

/* utils_msg_1_bonus */
void	show_guide_1(void);
void	show_guide_2(void);
void	show_guide_3(void);
void	show_guide_3(void);
void	show_guide(void);

/* utils_msg_2_bonus */
void	print_info_1(t_data *data, t_scene *scene, int flag);
void	print_info_2(t_data *data, t_scene *scene, int flag);
void	print_info_3(t_data *data, t_scene *scene, int flag);
void	print_info_4(t_data *data, t_scene *scene, int flag);
void	print_scene_info(t_data *data, t_scene *scene, int flag);

/* utils_msg_3_bonus */
void	print_info_5(t_data *data, t_scene *scene, int flag);
void	print_info_6(t_data *data, t_scene *scene, int flag);
void	print_info_7(t_data *data, t_scene *scene, int flag);
void	print_info_8(t_data *data, t_scene *scene, int flag);

#endif