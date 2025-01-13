# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eberkowi <eberkowi@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/03 14:44:03 by eberkowi          #+#    #+#              #
#    Updated: 2025/01/13 16:49:42 by eberkowi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := cu3ed
CC := cc
FLAGS := -Wall -Wextra -Werror
CFILES := main.c \
			error_exit.c \
			validate_filetype.c \
			create_copy_of_file.c \
			parse_file.c \
			free_all.c \
			check_for_path.c

HEADER = includes/cu3ed.h
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
