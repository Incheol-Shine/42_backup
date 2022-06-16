# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: incshin <incshin@student.42seoul.kr>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/02 17:10:46 by incshin           #+#    #+#              #
#    Updated: 2022/06/02 17:10:48 by incshin          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = a.out
CC = cc
CFLAGS = -Wall -Wextra -Werror
SRCS = get_next_line.c get_next_line_utils.c main.c
SRCS_B = get_next_line_bonus.c get_next_line_utils_bonus.c main.c
OBJS = $(SRCS:.c=.o)
OBJS_B = $(SRCS_B:.c=.o)
RM = rm
RMFLAGS = -f
buff = 42
ifdef BONUS
	TOTAL_OBJS = $(OBJS_B)
else
	TOTAL_OBJS = $(OBJS)
endif

all: $(NAME)

clean:
	$(RM) $(RMFLAGS) $(OBJS) $(OBJS_B)

fclean: clean
	$(RM) $(RMFLAGS) $(NAME)

re: fclean all

bonus :
	make BONUS=0

$(NAME): $(TOTAL_OBJS)
	$(CC) -g $(CFLAGS) -D BUFFER_SIZE=$(buff) -o $@ $^

%.o : %.c
	$(CC) $(CFLAGS) -D BUFFER_SIZE=$(buff) -c $<

.PHONY: all clean fclean re bonus
