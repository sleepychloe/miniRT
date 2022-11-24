# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yhwang <yhwang@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/19 15:13:25 by yhwang            #+#    #+#              #
#    Updated: 2022/11/24 16:28:57 by yhwang           ###   ########.fr        #
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

FILES	= ./srcs/main \
		./srcs/parse/parse_init_struct_1 \
		./srcs/parse/parse_init_struct_2 \
		./srcs/parse/parse_arg \
		./srcs/parse/parse_map \
		./srcs/parse/parse_ambient_1 \
		./srcs/parse/parse_ambient_2 \
		./srcs/parse/parse_camera_1 \
		./srcs/parse/parse_camera_2 \
		./srcs/parse/parse_light_1 \
		./srcs/parse/parse_light_2 \
		./srcs/parse/parse_sphere_1 \
		./srcs/parse/parse_sphere_2 \
		./srcs/parse/parse_plane_1 \
		./srcs/parse/parse_plane_2 \
		./srcs/parse/parse_cylinder_1 \
		./srcs/parse/parse_cylinder_2 \
		./srcs/parse/parse_cylinder_3 \
		./srcs/parse/parse_err_1 \
		./srcs/parse/parse_err_2 \
		./srcs/parse/parse_utils \
		./srcs/raytracing/raytracing_main \
		./srcs/raytracing/raytracing_init_struct \
		./srcs/raytracing/raytracing_ray \
		./srcs/raytracing/raytracing_light \
		./srcs/raytracing/raytracing_sphere \
		./srcs/raytracing/raytracing_plane \
		./srcs/raytracing/raytracing_cylinder_1 \
		./srcs/raytracing/raytracing_cylinder_2 \
		./srcs/raytracing/raytracing_utils \
		./srcs/utils/utils_split \
		./srcs/utils/utils_free \
		./srcs/utils/utils_vec3_1 \
		./srcs/utils/utils_vec3_2 \
		./srcs/utils/utils_color \
		./srcs/utils/utils_random \
		./srcs/utils/utils_mlx \
		./srcs/utils/utils_mlx_key_move_camera \
		./srcs/utils/utils_mlx_key_rotate_camera \
		./srcs/utils/utils_mlx_key_move_light \
		./srcs/utils/utils_mlx_key_move_sphere \
		./srcs/utils/utils_mlx_key_move_plane \
		./srcs/utils/utils_mlx_key_rotate_plane \
		./srcs/utils/utils_mlx_key_move_cylinder \
		./srcs/utils/utils_mlx_key_rotate_cylinder \
		./srcs/utils/utils_msg_1 \
		./srcs/utils/utils_msg_2 \
		./srcs/utils/utils_msg_3

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
