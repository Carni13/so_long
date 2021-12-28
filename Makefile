SRC = srcs/so_long.c \
		srcs/ft_parsing_maps.c\
		srcs/window.c\
		srcs/ft_move.c\
		srcs/ft_collision.c\
		srcs/init_conf.c\
		srcs/ai_skull.c\
		srcs/ft_collision_skull.c\
		srcs/ft_move_skull.c\
		srcs/ft_check_maps_utils.c\
		srcs/ft_check_maps.c
MLX = ./mlx
IFLAGS = -I includes/
CFLAGS = -Wall -Wextra -Werror
CC = gcc
OBJ = $(SRC:.c=.o)
HEADER = includes/so_long.h
LIBMLX = libmlx.a
LIBFT = ./libft
NAME = so_long

all: $(NAME)

bonus: $(NAME)

$(NAME): $(OBJ) ${HEADER} ${MLX} ${LIBFT}
		@make -C ${MLX}
		@make -C ${LIBFT}
		@cp mlx/libmlx.a  ./${LIBMLX}
		@cp libft/libft.a  ./libft.a
		$(CC) ${OBJ} -Lmlx -lmlx -Llibft -lft -framework OpenGL -framework AppKit -o $(NAME)


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