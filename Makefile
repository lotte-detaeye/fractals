# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lde-taey <lde-taey@student.42berlin.de>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/03 12:16:32 by lde-taey          #+#    #+#              #
#    Updated: 2024/05/15 16:35:30 by lde-taey         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractal

CFLAGS = -Werror -Wall -Wextra -g

CC = gcc

MLX = minilibx-linux/libmlx.a

SRCS = main.c init.c str_utils.c cleanup.c math_utils.c render.c events.c

OBJS = $(SRCS:.c=.o)

$(NAME) : $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME) $(MLX) -lX11 -lXext -lm

all : $(NAME)

.PHONY : clean fclean re

clean :
	rm -f $(OBJS)

fclean : clean
	rm -f $(NAME)

re : fclean all