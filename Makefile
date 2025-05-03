# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nando <nando@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/10 21:17:18 by nando             #+#    #+#              #
#    Updated: 2025/05/03 17:16:18 by nando            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

CC = cc -g3
CFLAGS = -Wall -Wextra -Werror

LIBFT = libft/libft.a

MLX_DIR = minilibx-Linux
MLX_FLAGS = -L$(MLX_DIR) -lmlx -lXext -lX11 -lm

SRCS =  \
		main/main.c \
		map/check_contents.c \
		map/load_map.c \
		map/path_exists.c \
		map/print_map.c \
		map/validate_map.c \
		game/running_game.c \
		game/init_game.c \
		game/draw_map.c \
		utils/free.c 

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(MLX_FLAGS) -o $(NAME)

$(LIBFT):
	$(MAKE) -C libft

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) 
	$(MAKE) -C libft clean

fclean: clean
	rm -f $(NAME) 
	$(MAKE) -C libft fclean

re: fclean all

.PHONY: all clean fclean re
