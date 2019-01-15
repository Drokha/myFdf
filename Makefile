# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: trabut <trabut@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/01/08 17:53:12 by trabut            #+#    #+#              #
#    Updated: 2019/01/14 15:29:05 by trabut           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

FLAGS = -Wall -Wextra -Werror

SRC = main.c parsing.c

OBJ =

LIB = libft/libft.a

INC = fdf.h

all: $(NAME)

$(NAME):
	gcc -I /usr/local/include  $(SRC) -L /usr/local/lib/ -l mlx -framework OpenGL -framework AppKit libft/libft.a

p: all clean

clean:
	/bin/rm -f $(OBJ)
	echo "Objects Destroyed"

fclean:		clean
	/bin/rm -f $(NAME)
	echo "Project Destroyed"

re:		fclean all

norm:
	norminette $(SRC) $(INC)

.PHONY:    all clean fclean re norm

.SILENT: