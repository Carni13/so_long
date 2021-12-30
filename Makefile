SRC = srcs/so_long.c \
		srcs/ft_parsing_maps.c\
		srcs/window.c\
		srcs/ft_move.c\
		srcs/ft_collision.c\
		srcs/init_conf.c\
		srcs/ft_check_maps_utils.c\
		srcs/ft_check_maps.c\
		srcs/ft_check_sprite.c\
		srcs/ft_destroy_image.c\
		srcs/ft_exit.c\
		srcs/ft_gengine_utils.c\
		srcs/ft_gengine.c\
		srcs/ft_init_sprite.c\
		srcs/ft_hooking.c
		
MLX = ./mlx
IFLAGS = -I includes/
CFLAGS = -Wall -Wextra -Werror -D BONUS=1
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
		$(CC) ${OBJ} -Lmlx -lmlx -Llibft -lft -framework OpenGL -framework AppKit  -o $(NAME)


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