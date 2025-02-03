# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jlehtone <jlehtone@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/03 14:44:03 by eberkowi          #+#    #+#              #
#    Updated: 2025/02/03 14:30:36 by jlehtone         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := cub3d
CC := cc
FLAGS := -Wall -Wextra -Werror -ggdb3 -g -O3 -ffast-math #-fsanitize=address,leak,undefined -fno-omit-frame-pointer
CFILES := main.c \
			check_for_path.c \
			check_for_rgb.c \
			check_for_wall.c \
			controls.c \
			copy_map.c \
			create_copy_of_file.c \
			create_images.c \
			create_textures.c \
			display_images.c \
			draw_line.c \
			error_exit.c \
			free_all.c \
			loop_through_file.c \
			parse_file.c \
			raycasting_utils.c \
			raycasting.c \
			rendering.c \
			resize_images.c \
			validate_filetype.c \
			validate_map.c \
			draw_walls.c \
			draw_walls_dark.c \
			draw_utils.c \
			torch_animation.c \
			torch_animation_utils.c \
			get_pixel_data.c \
			doors.c \
			mouse.c
HEADER = includes/cub3d.h
LIBFT := libft/libft.a
MLX42 := MLX42/build/libmlx42.a
LDFLAGS := -LMLX/build -lglfw
LMFLAG = -lm

SRC_PATH := sources/
OBJ_PATH := objects/

CFILES := $(addprefix $(SRC_PATH), $(CFILES))
OBJS := $(CFILES:$(SRC_PATH)%.c=$(OBJ_PATH)%.o)

all: $(OBJ_PATH) $(NAME)

$(OBJ_PATH):
	mkdir -p $(OBJ_PATH)

$(OBJ_PATH)%.o: $(SRC_PATH)%.c $(HEADER)
	$(CC) $(FLAGS) -c $< -o $@

$(NAME): $(LIBFT) $(OBJS)
	$(CC) $(FLAGS) $(OBJS) $(LIBFT) $(MLX42) -o $(NAME) $(LDFLAGS) $(LMFLAG)

$(LIBFT):
	make -C libft

clean:
	rm -rf $(OBJ_PATH)
	make clean -C libft

fclean: clean
	rm -f $(NAME)
	make fclean -C libft

re: fclean all
