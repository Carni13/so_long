SRC = srcs/so_long.c 
MLX = ./mlx
IFLAGS = -I includes/
CFLAGS = -Wall -Wextra -Werror
CC = gcc
OBJ = $(SRC:.c=.o)
HEADER = includes/so_long.h
LIBMLX = libmlx.a
NAME = so_long

all: $(NAME)

bonus: $(NAME)

$(NAME): $(OBJ) ${HEADER} ${MLX}
		@make -C ${MLX}
		@cp mlx/libmlx.a  ./${LIBMLX}
		$(CC) ${OBJ} -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME)


%.o:%.c
	$(CC) $(CFLAGS) $(IFLAGS) -Imlx -c $< -o $@

clean:
	rm -f $(OBJ)
	@make clean -C $(MLX)

fclean: clean
	rm -f $(NAME)
	@make fclean -C $(MLX)

re: fclean all

.PHONY: all clean fclean res