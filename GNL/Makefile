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

NAME = get_next_line.a
CC = gcc
CFLAGS = -Wall -Wextra -Werror
SRCS = get_next_line.c get_next_line_utils.c
SRCS_B = get_next_line_bonus.c get_next_line_utils_bonus.c
OBJS = $(SRCS:.c=.o)
OBJS_B = $(SRCS_B:.c=.o)
AR = ar
ARFLAGS = -rcs
RM = rm
RMFLAGS = -f

ifdef BONUS
	TOTAL_OBJS = $(OBJS_B)
else
	TOTAL_OBJS = $(OBJS)
endif

all: $(NAME)

clean:
	$(RM) $(RMFLAGS) -f $(OBJS) $(OBJS_B)

fclean: clean
	$(RM) $(RMFLAGS) $(NAME)

re: fclean all

bonus :
	make BONUS=1

$(NAME): $(TOTAL_OBJS)
	$(AR) $(ARFLAGS) $@ $^

%.o : %.c
	$(CC) $(CFLAGS) -c $<

.PHONY: all clean fclean re bonus
