/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniRT_bonus.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhwang <yhwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 16:15:19 by yhwang            #+#    #+#             */
/*   Updated: 2022/11/30 22:18:02 by yhwang           ###   ########.fr       */
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

/* main_bonus */
int		minirt_main(char **argv);
int		main(int argc, char **argv);

#endif