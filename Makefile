# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eberkowi <eberkowi@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/03 14:44:03 by eberkowi          #+#    #+#              #
#    Updated: 2025/01/10 17:38:46 by eberkowi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := cu3ed
CC := cc
FLAGS := -Wall -Wextra -Werror
CFILES := main.c \
			error_exit.c \
			validate_filetype.c \
			create_map.c

HEADER = cu3ed.h
LIBFT := libft/libft.a
MLX42 := MLX42/build/libmlx42.a
LDFLAGS := -LMLX/build -lglfw

OBJECTS := $(CFILES:.c=.o)

.PHONY: all
all: $(NAME)

$(NAME): $(LIBFT) $(OBJECTS) $(HEADER)
	$(CC) $(FLAGS) $(OBJECTS) $(LIBFT) $(MLX42) -o $(NAME) $(LDFLAGS)

$(LIBFT):
	make -C libft

%.o: %.c
	$(CC) $(FLAGS) -c $< -o $@

.PHONY: clean
clean:
	rm -f $(OBJECTS)
	make clean -C libft

.PHONY: fclean
fclean: clean
	rm -f $(NAME)
	make fclean -C libft

.PHONY: re
re: fclean all
