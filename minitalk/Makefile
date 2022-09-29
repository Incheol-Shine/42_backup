NAME = libftprintf.a
LIBFT = ./libft/libft.a
CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f
AR = ar
ARFLAG = crs
LIBFT_DIR = libft

PRINTF_SRCS = \
	ft_printf.c \
	ft_printf_functions_1.c \
	ft_printf_functions_2.c

PRINTF_OBJS = $(PRINTF_SRCS:.c=.o)

all : $(NAME)

$(NAME) : $(PRINTF_OBJS)
	make -C $(LIBFT_DIR) all
	cp $(LIBFT) ./$@
	$(AR) $(ARFLAG) $@ $^

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean :
	make -C $(LIBFT_DIR) clean
	$(RM) $(PRINTF_OBJS)
	$(RM) $(PRINTF_OBJS_BONUS)

fclean : clean
	make -C $(LIBFT_DIR) fclean
	$(RM) $(NAME)

re : fclean
	make all

.PHONY : all clean fclean re