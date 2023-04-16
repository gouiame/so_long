# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cgouiame <cgouiame@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/15 01:42:04 by cgouiame          #+#    #+#              #
#    Updated: 2023/04/16 01:09:07 by cgouiame         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
FLAGS = -Wall -Werror -Wextra
MLXFLAGS = $(FLAGS) -lmlx -framework OpenGL -framework AppKit
FILES = ft_split.c so_long.c utils.c utils2.c \
		valid_path.c mlx.c mlx_utils.c mlx_utils2.c

OBJ= $(FILES:.c=.o)
NAME = so_long

all : $(NAME)

$(NAME): $(OBJ) 
		 		$(CC) $(MLXFLAGS) $(OBJ) -o $(NAME)
						
%.o : %.c so_long.h 
		$(CC) $(FLAGS) -c $< 											

clean :
		 rm -f $(OBJ)

fclean : clean
		 rm -f $(NAME)

re : fclean all
