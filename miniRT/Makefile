# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yhwang <yhwang@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/19 15:13:25 by yhwang            #+#    #+#              #
#    Updated: 2022/10/23 08:19:48 by yhwang           ###   ########.fr        #
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
MLX_FLAGS = -lX11 -lXext -lm -lz
MLX = $(addprefix $(MLX_DIR)/, libmlx.a)

FILES = main \
		init_struct_1 \
		init_struct_2 \
		parse_arg \
		parse_map \
		parse_ambient_1 \
		parse_ambient_2 \
		parse_camera_1 \
		parse_camera_2 \
		parse_light_1 \
		parse_light_2 \
		parse_sphere_1 \
		parse_sphere_2 \
		parse_plane_1 \
		parse_plane_2 \
		parse_cylinder_1 \
		parse_cylinder_2 \
		parse_cylinder_3 \
		parse_err_1 \
		parse_err_2 \
		utils \
		utils_split \
		utils_free

INCS_DIR = ./incs
SRCS_DIR = ./srcs

SRCS = $(addprefix $(SRCS_DIR)/, $(addsuffix .c, $(FILES)))
OBJS = $(addprefix $(SRCS_DIR)/, $(addsuffix .o, $(FILES)))

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
