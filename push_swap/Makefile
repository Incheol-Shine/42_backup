# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: incshin <incshin@student.42seoul.kr>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/17 19:23:20 by incshin           #+#    #+#              #
#    Updated: 2022/11/17 20:37:10 by incshin          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= push_swap
LIBFT = ./libft/libft.a
RM = rm -f

# directories
SRCDIR		= ./src
INCDIR		= ./includes
LIBFTDIR 	= libft
MLXDIR		= mlx

# src / obj files
SRC		=	main.c \
			preprocess.c \
			util.c \
			stack.c \
			command_1.c \
			command_2.c \
			command_3.c \
			sort_1.c \
			sort_2.c

OBJ		= $(SRC:.c=.o)

# compiler
CC = cc
CFLAGS = -Wall -Wextra -Werror

all : $(NAME)

$(NAME): $(OBJ)
	@make -C $(LIBFTDIR) all
	@$(CC) $(OBJ) $(LIBFT) -g -o $(NAME)

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

clean :
	@make -C $(LIBFTDIR) clean
	@$(RM) $(OBJ)

fclean : clean
	@make -C $(LIBFTDIR) fclean
	@$(RM) $(NAME)

re : fclean
	@make all

.PHONY : all clean fclean re