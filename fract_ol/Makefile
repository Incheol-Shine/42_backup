NAME	= fractol
LIBFT = ./libft/libft.a
RM = rm -f

# directories
SRCDIR		= ./src
INCDIR		= ./includes
LIBFTDIR 	= libft
MLXDIR		= mlx_linux

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
	$(CC) $(OBJ) $(LIBFT) -Lmlx_linux -lmlx_Linux -L. -Imlx_linux -lXext -lX11 -lm -lz -o $@

# $(CC) $(CFLAGS) -L. -lmlx -framework OpenGL -framework AppKit -c $< -o $@
# cc main.c -Lmlx_linux -lmlx_Linux -L. -Imlx_linux -lXext -lX11 -lm -lz
%.o: %.c
	$(CC) $(CFLAGS) -I. -Imlx_linux -O3 -c $< -o $@

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