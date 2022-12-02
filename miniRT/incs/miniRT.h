/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniRT.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhwang <yhwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 16:15:19 by yhwang            #+#    #+#             */
/*   Updated: 2022/12/02 00:40:58 by yhwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# include "../libft/incs/libft.h"
# include "../libft/incs/get_next_line.h"
# include "../mlx_linux/mlx.h"

# include "./miniRT_linux_keycode.h"
# include "./miniRT_struct.h"
# include "./miniRT_parse.h"
# include "./miniRT_raytracing.h"
# include "./miniRT_utils_mlx.h"
# include "./miniRT_utils.h"

# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <math.h>

/* main */
void	minirt_main_norminette(t_scene *scene, t_scene *keep_scene);
int		minirt_main(char **argv);
int		main(int argc, char **argv);

#endif