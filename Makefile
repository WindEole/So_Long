# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: iderighe <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/26 17:24:14 by iderighe          #+#    #+#              #
#    Updated: 2021/12/01 18:04:13 by iderighe         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	so_long

LFT		=	Libft/libft.a
LIB		=	-L ./Libft -lft

#OS		=	$(shell uname)

#ifeq ($(info $(OS)), linux)
#	$(info $(OS))
#else
#	echo "MacOS"
#endif

MLX_L	=	minilibx-linux/Makefile.gen
LIB_L	=	-L ./minilibx-mlx-linux -lmlx -lXext -lX11 -lm -lbsd

SRC		=	main_parse.c \
			all_display.c \
			create_lst_map.c \
			get_next_line.c \
			get_next_line_utils.c \
			error_free.c \

OBJ		=	$(SRC:.c=.o)

CC		=	clang
FLAGS	=	-Wall -Wextra -Werror
CFS		=	-fsanitize=address -g3
RM		=	rm -f

#ifeq ($(OS), Linux)
#	FLAGS += -LMLX_TEST/mlx-linux -lmlx -lXext -lX11 -IMLX_TEST/mlx-linux/.
#else
#	FLAGS += MLX_TEST/mlx-linux/Makefile.gen
#endif

all		:	$(NAME)

$(NAME)	:	$(MLX) $(LFT) $(OBJ)
			$(CC) $(FLAGS) -o $(NAME) $(SRC) $(LIB) $(LIB_L)

$(LFT)	:	
			make -C Libft

$(MLX)	:	
			make -C minilibx-linux

%.o		:	%.c
			$(CC) -o $@ -c $< $(FLAGS)

clean	:
			$(RM) $(OBJ)


fclean	:	clean
			$(RM) $(NAME)
			make -C Libft fclean
			make -C minilibx-linux clean

f		:	$(MLX) $(LFT) $(OBJ)
			$(CC) $(FLAGS) $(CFS) -o $(NAME) $(SRC) $(LIB) $(LIB_L)

fre		:	fclean f

re		:	fclean lclean mclean all

.PHONY	:	all clean fclean f fre re
