# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eberkowi <eberkowi@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/03 14:44:03 by eberkowi          #+#    #+#              #
#    Updated: 2025/01/20 14:37:32 by eberkowi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := cub3d
CC := cc
FLAGS := -Wall -Wextra -Werror
CFILES := main.c \
			error_exit.c \
			validate_filetype.c \
			create_copy_of_file.c \
			parse_file.c \
			free_all.c \
			check_for_path.c \
			check_for_rgb.c \
			create_textures.c \
			create_images.c \
			resize_images.c \
			display_map.c \
			controls.c \
			copy_map.c \
			validate_map.c

HEADER = includes/cub3d.h
LIBFT := libft/libft.a
MLX42 := MLX42/build/libmlx42.a
LDFLAGS := -LMLX/build -lglfw

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
	$(CC) $(FLAGS) $(OBJS) $(LIBFT) $(MLX42) -o $(NAME) $(LDFLAGS) 

$(LIBFT):
	make -C libft

clean:
	rm -rf $(OBJ_PATH)
	make clean -C libft

fclean: clean
	rm -f $(NAME)
	make fclean -C libft

re: fclean all
