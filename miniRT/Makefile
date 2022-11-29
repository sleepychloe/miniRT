# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yhwang <yhwang@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/19 15:13:25 by yhwang            #+#    #+#              #
#    Updated: 2022/11/29 12:24:34 by yhwang           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = miniRT

CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f

LIBFT_DIR = ./libft
LIBFT_NAME = libft.a
LIBFT = $(addprefix $(LIBFT_DIR)/, $(LIBFT_NAME))

MLX_DIR = ./mlx_linux
MLX_FLAGS = -lX11 -lXext -lm
MLX = $(addprefix $(MLX_DIR)/, libmlx.a)

SRCS_DIR = ./srcs/
SRCS_PARSE_DIR = ./srcs/parse/
SRCS_RT_DIR = ./srcs/raytracing/
SRCS_UTILS_DIR = ./srcs/utils/
SRCS_UTILS_MLX_DIR = ./srcs/utils/utils_mlx/

FILES	= $(SRCS_DIR)main \
		$(SRCS_PARSE_DIR)parse_init_struct_1 \
		$(SRCS_PARSE_DIR)parse_init_struct_2 \
		$(SRCS_PARSE_DIR)parse_arg \
		$(SRCS_PARSE_DIR)parse_map \
		$(SRCS_PARSE_DIR)parse_ambient_1 \
		$(SRCS_PARSE_DIR)parse_ambient_2 \
		$(SRCS_PARSE_DIR)parse_camera_1 \
		$(SRCS_PARSE_DIR)parse_camera_2 \
		$(SRCS_PARSE_DIR)parse_light_1 \
		$(SRCS_PARSE_DIR)parse_light_2 \
		$(SRCS_PARSE_DIR)parse_sphere_1 \
		$(SRCS_PARSE_DIR)parse_sphere_2 \
		$(SRCS_PARSE_DIR)parse_plane_1 \
		$(SRCS_PARSE_DIR)parse_plane_2 \
		$(SRCS_PARSE_DIR)parse_cylinder_1 \
		$(SRCS_PARSE_DIR)parse_cylinder_2 \
		$(SRCS_PARSE_DIR)parse_cylinder_3 \
		$(SRCS_PARSE_DIR)parse_err_1 \
		$(SRCS_PARSE_DIR)parse_err_2 \
		$(SRCS_PARSE_DIR)parse_init_struct_keep_scene_1 \
		$(SRCS_PARSE_DIR)parse_init_struct_keep_scene_2 \
		$(SRCS_PARSE_DIR)parse_init_struct_keep_scene_3 \
		$(SRCS_PARSE_DIR)parse_utils \
		$(SRCS_RT_DIR)raytracing_main \
		$(SRCS_RT_DIR)raytracing_set_camera_1 \
		$(SRCS_RT_DIR)raytracing_set_camera_2 \
		$(SRCS_RT_DIR)raytracing_init_struct_obj \
		$(SRCS_RT_DIR)raytracing_init_struct_rt \
		$(SRCS_RT_DIR)raytracing_ray \
		$(SRCS_RT_DIR)raytracing_light \
		$(SRCS_RT_DIR)raytracing_sphere \
		$(SRCS_RT_DIR)raytracing_plane \
		$(SRCS_RT_DIR)raytracing_cylinder_1 \
		$(SRCS_RT_DIR)raytracing_cylinder_2 \
		$(SRCS_RT_DIR)raytracing_utils \
		$(SRCS_UTILS_MLX_DIR)utils_mlx \
		$(SRCS_UTILS_MLX_DIR)utils_mlx_key_move_camera \
		$(SRCS_UTILS_MLX_DIR)utils_mlx_key_rotate_camera_1 \
		$(SRCS_UTILS_MLX_DIR)utils_mlx_key_rotate_camera_2 \
		$(SRCS_UTILS_MLX_DIR)utils_mlx_key_rotate_camera_3 \
		$(SRCS_UTILS_MLX_DIR)utils_mlx_key_rotate_camera_x_1 \
		$(SRCS_UTILS_MLX_DIR)utils_mlx_key_rotate_camera_x_2 \
		$(SRCS_UTILS_MLX_DIR)utils_mlx_key_rotate_camera_y_1 \
		$(SRCS_UTILS_MLX_DIR)utils_mlx_key_rotate_camera_y_2 \
		$(SRCS_UTILS_MLX_DIR)utils_mlx_key_rotate_camera_z_1 \
		$(SRCS_UTILS_MLX_DIR)utils_mlx_key_rotate_camera_z_2 \
		$(SRCS_UTILS_MLX_DIR)utils_mlx_key_move_light \
		$(SRCS_UTILS_MLX_DIR)utils_mlx_key_move_sphere \
		$(SRCS_UTILS_MLX_DIR)utils_mlx_key_move_plane \
		$(SRCS_UTILS_MLX_DIR)utils_mlx_key_rotate_plane_1 \
		$(SRCS_UTILS_MLX_DIR)utils_mlx_key_rotate_plane_2 \
		$(SRCS_UTILS_MLX_DIR)utils_mlx_key_move_cylinder \
		$(SRCS_UTILS_MLX_DIR)utils_mlx_key_rotate_cylinder_1 \
		$(SRCS_UTILS_MLX_DIR)utils_mlx_key_rotate_cylinder_2 \
		$(SRCS_UTILS_DIR)utils_free \
		$(SRCS_UTILS_DIR)utils_vec3_1 \
		$(SRCS_UTILS_DIR)utils_vec3_2 \
		$(SRCS_UTILS_DIR)utils_color \
		$(SRCS_UTILS_DIR)utils_random \
		$(SRCS_UTILS_DIR)utils_msg_1 \
		$(SRCS_UTILS_DIR)utils_msg_2 \
		$(SRCS_UTILS_DIR)utils_msg_3

INCS_DIR	= ./incs

SRCS = $(addsuffix .c, $(FILES))
OBJS = $(addsuffix .o, $(FILES))

.c.o: $(SRCS) $(INCS_DIR)
	$(CC) $(CFLAGS) -c $< -o $@ -I$(INCS_DIR)

all: $(LIBFT_NAME) $(NAME)

$(LIBFT_NAME):
	make -C $(LIBFT_DIR)

$(NAME): $(MLX) $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $^ -o $@ -I$(INCS_DIR) -L$(MLX_DIR) -lmlx $(MLX_FLAGS)

$(MLX):
	make -C $(MLX_DIR)

clean:
	make clean -C $(LIBFT_DIR)
	make clean -C $(MLX_DIR)
	$(RM) $(OBJS)

fclean: clean
	make fclean -C $(LIBFT_DIR)
	$(RM) $(NAME)

re: fclean all

.PHONY: all, clean, fclean, re
