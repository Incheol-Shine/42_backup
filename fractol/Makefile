# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: incshin <incshin@student.42seoul.kr>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/02 11:32:27 by incshin           #+#    #+#              #
#    Updated: 2022/11/02 13:57:16 by incshin          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= fractol
LIBFT = ./libft/libft.a
RM = rm -f

# directories
SRCDIR		= ./src
INCDIR		= ./includes
LIBFTDIR 	= libft
MLXDIR		= mlx

# src / obj files
SRC		=	main.c \
			util.c \
			event.c \
			fractal.c 

OBJ		= $(SRC:.c=.o)

# compiler
CC = cc
CFLAGS = -Wall -Wextra -Werror

all : $(NAME)

$(NAME): $(OBJ)
	@make -C $(LIBFTDIR) all
	@make -C $(MLXDIR) all
	$(CC) $(OBJ) $(LIBFT) -g -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -I. -Imlx -c $< -o $@

clean :
	@make -C $(LIBFTDIR) clean
	@make -C $(MLXDIR) clean
	$(RM) $(OBJ)

fclean : clean
	@make -C $(LIBFTDIR) fclean
	@$(RM) $(NAME)

re : fclean
	@make all

.PHONY : all clean fclean re