# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jlehtone <jlehtone@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/03 14:44:03 by eberkowi          #+#    #+#              #
#    Updated: 2025/02/04 17:03:36 by jlehtone         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := cub3d
NAME_BONUS := cub3d_bonus
CC := cc
FLAGS := -Wall -Wextra -Werror -ggdb3 -g -O3 -ffast-math #-fsanitize=address,leak,undefined -fno-omit-frame-pointer
CFILES := 	main.c \
			check_for_path.c \
			check_for_rgb.c \
			check_for_wall.c \
			controls.c \
			copy_map.c \
			create_copy_of_file.c \
			create_images.c \
			create_textures.c \
			display_images.c \
			error_exit.c \
			free_all.c \
			free_images.c \
			loop_through_file.c \
			parse_file.c \
			raycasting_utils.c \
			raycasting.c \
			rendering.c \
			validate_filetype.c \
			validate_map.c \
			draw_walls.c \
			draw_utils.c \
			get_pixel_data.c
CFILES_BONUS := main_bonus.c \
				check_for_path_bonus.c \
				check_for_rgb_bonus.c \
				check_for_wall_bonus.c \
				controls_bonus.c \
				copy_map_bonus.c \
				create_copy_of_file_bonus.c \
				create_images_bonus.c \
				create_textures_bonus.c \
				display_images_bonus.c \
				draw_line_bonus.c \
				error_exit_bonus.c \
				free_all_bonus.c \
				free_images_bonus.c \
				loop_through_file_bonus.c \
				parse_file_bonus.c \
				raycasting_utils_bonus.c \
				raycasting_bonus.c \
				rendering_bonus.c \
				resize_images_bonus.c \
				validate_filetype_bonus.c \
				validate_map_bonus.c \
				draw_walls_bonus.c \
				draw_walls_dark_bonus.c \
				draw_utils_bonus.c \
				torch_animation_bonus.c \
				torch_animation_utils_bonus.c \
				get_pixel_data_bonus.c \
				resize_minimap_bonus.c \
				doors_bonus.c \
				mouse_bonus.c
HEADER = includes/cub3d.h
LIBFT := libft/libft.a
MLX42 := MLX42/build/libmlx42.a
LDFLAGS := -LMLX/build -lglfw
LMFLAG = -lm

SRC_BONUS_PATH := sources_bonus/
SRC_PATH := sources/
OBJ_PATH := objects/

CFILES := $(addprefix $(SRC_PATH), $(CFILES))
CFILES_BONUS := $(addprefix $(SRC_BONUS_PATH), $(CFILES_BONUS))
OBJS := $(CFILES:$(SRC_PATH)%.c=$(OBJ_PATH)%.o)
OBJS_BONUS := $(CFILES_BONUS:$(SRC_BONUS_PATH)%.c=$(OBJ_PATH)%.o)

all: $(OBJ_PATH) $(NAME)

$(OBJ_PATH):
	mkdir -p $(OBJ_PATH)

$(OBJ_PATH)%.o: $(SRC_PATH)%.c $(HEADER)
	$(CC) $(FLAGS) -c $< -o $@
	
$(OBJ_PATH)%.o: $(SRC_BONUS_PATH)%.c $(HEADER)
	$(CC) $(FLAGS) -c $< -o $@

$(NAME): $(LIBFT) $(OBJS)
	$(CC) $(FLAGS) $(OBJS) $(LIBFT) $(MLX42) -o $(NAME) $(LDFLAGS) $(LMFLAG)

$(NAME_BONUS): $(LIBFT) $(OBJS_BONUS)
	$(CC) $(FLAGS) $(OBJS_BONUS) $(LIBFT) $(MLX42) -o $(NAME_BONUS) $(LDFLAGS) $(LMFLAG)

$(LIBFT):
	make -C libft

clean:
	rm -rf $(OBJ_PATH)
	make clean -C libft

fclean: clean
	rm -f $(NAME)
	rm -f $(NAME_BONUS)
	make fclean -C libft

bonus: $(OBJ_PATH) $(NAME_BONUS)

re: fclean all

.PHONY: all bonus clean fclean re
