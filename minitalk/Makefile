# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: incshin <incshin@student.42seoul.kr>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/07 12:06:21 by incshin           #+#    #+#              #
#    Updated: 2022/10/07 13:46:09 by incshin          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SERVER = server
CLIENT = client
SERVER_BONUS = server_bonus
CLIENT_BONUS = client_bonus
LIBS	 = -L./libft -lft
LIBFT	 = libft.a
CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f
AR = ar
ARFLAG = crs
LIBFT_DIR = libft

SERVER_SRCS = server.c
CLIENT_SRCS = client.c

SERVER_SRCS_BONUS = server_bonus.c
CLIENT_SRCS_BONUS = client_bonus.c

SERVER_OBJS = $(SERVER_SRCS:.c=.o)
CLIENT_OBJS = $(CLIENT_SRCS:.c=.o)

SERVER_OBJS_BONUS = $(SERVER_SRCS_BONUS:.c=.o)
CLIENT_OBJS_BONUS = $(CLIENT_SRCS_BONUS:.c=.o)

all : $(LIBFT) $(SERVER) $(CLIENT)

$(LIBFT) :
	make -C $(LIBFT_DIR) all

$(SERVER) : $(SERVER_OBJS)
	$(CC) $(CFLAGS) $(LIBS) $< -o $@

$(CLIENT) : $(CLIENT_OBJS)
	$(CC) $(CFLAGS) $(LIBS) $< -o $@

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(SERVER_BONUS) : $(SERVER_OBJS_BONUS)
	$(CC) $(CFLAGS) $(LIBS) $< -o $@

$(CLIENT_BONUS) : $(CLIENT_OBJS_BONUS)
	$(CC) $(CFLAGS) $(LIBS) $< -o $@

bonus : $(LIBFT) $(SERVER_BONUS) $(CLIENT_BONUS)

clean :
	make -C $(LIBFT_DIR) clean
	$(RM) $(SERVER_OBJS) $(CLIENT_OBJS) $(SERVER_OBJS_BONUS) $(CLIENT_OBJS_BONUS)

fclean : clean
	make -C $(LIBFT_DIR) fclean
	$(RM) $(SERVER) $(SERVER_BONUS) $(CLIENT) $(CLIENT_BONUS)

re : fclean
	make all

.PHONY : all bonus clean fclean re