/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniRT_bonus.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhwang <yhwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 16:15:19 by yhwang            #+#    #+#             */
/*   Updated: 2022/12/20 09:42:07 by yhwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_BONUS_H
# define MINIRT_BONUS_H

# include "../libft/incs/libft.h"
# include "../libft/incs/get_next_line.h"
# include "../mlx_linux/mlx.h"

# include "./miniRT_linux_keycode_bonus.h"
# include "./miniRT_struct_bonus.h"
# include "./miniRT_parse_bonus.h"
# include "./miniRT_raytracing_bonus.h"
# include "./miniRT_utils_mlx_bonus.h"
# include "./miniRT_utils_bonus.h"

# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <math.h>

/* epsilon, delta */
# define EPSILON			1e-4
# define DELTA				1e-10

/* main_bonus */
void	minirt_main_norminette(t_scene *scene, t_scene *keep_scene);
int		minirt_main(char **argv);
int		main(int argc, char **argv);

#endif