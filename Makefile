# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: iderighe <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/26 17:24:14 by iderighe          #+#    #+#              #
#    Updated: 2021/12/10 11:23:22 by iderighe         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	so_long

CC		=	clang
FLAGS	=	-Wall -Wextra -Werror
CFS		=	-fsanitize=address -g3
RM		=	/usr/bin/rm -f

LIB		=	-L./Libft -lft -L./minilibx-linux -lmlx -lXext -lX11

SRC		=	main_parse.c \
			create_lst_map.c \
			graphical.c \
			movement.c \
			error_free.c \
			all_display.c \

OBJ		=	$(SRC:.c=.o)


all		:	libft $(NAME)

$(NAME)	:	$(OBJ)
			$(MAKE) -C minilibx-linux
			$(CC) $(FLAGS) -o $(NAME) $(SRC) $(LIB)

libft	:
			$(MAKE) -C Libft

%.o		:	%.c
			$(CC) -o $@ -c $< $(FLAGS)

norm	:
			norminette $(SRC)
			norminette so_long.h
			$(MAKE) -C Libft norm

clean	:
			$(RM) $(OBJ)

fclean	:	clean
			$(RM) $(NAME)
			$(MAKE) -C Libft fclean
			$(MAKE) -C minilibx-linux clean

f		:	$(OBJ)
			$(MAKE) -C Libft
			$(MAKE) -C minilibx-linux
			$(CC) $(FLAGS) $(CFS) -o $(NAME) $(SRC) $(LIB)

fre		:	fclean f

re		:	fclean all

.PHONY	:	all libft norm clean fclean f fre re
