# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: incshin <incshin@student.42seoul.kr>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/02 11:32:27 by incshin           #+#    #+#              #
#    Updated: 2022/11/10 12:33:08 by incshin          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= push_swap
LIBFT = ./libft/libft.a
RM = rm -f

# directories
SRCDIR		= ./src/
INCDIR		= ./includes/
LIBFTDIR 	= libft

# src / obj files
SRC		=	$(SRCDIR)main.c \
			

OBJ		= $(SRC:.c=.o)

# compiler
CC = cc
CFLAGS = -Wall -Wextra -Werror

all : $(NAME)

$(NAME): $(OBJ)
	@make -C $(LIBFTDIR) all
	$(CC) $(OBJ) $(LIBFT) -g -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -I$(INCDIR) -c $< -o $@

clean :
	@make -C $(LIBFTDIR) clean
	$(RM) $(OBJ)

fclean : clean
	@make -C $(LIBFTDIR) fclean
	@$(RM) $(NAME)

re : fclean
	@make all

.PHONY : all clean fclean re