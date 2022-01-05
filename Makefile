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

SRC_BONUS = srcs/bonus/ai_skull_bonus.c\
			srcs/bonus/ai_skull_utils_bonus.c\
			srcs/bonus/check_maps_bonus.c\
			srcs/bonus/check_maps_utils_bonus.c\
			srcs/bonus/check_sprite_bonus.c\
			srcs/bonus/collision_bonus.c\
			srcs/bonus/collision_skull_bonus.c\
			srcs/bonus/destroy_image_bonus.c\
			srcs/bonus/exit_bonus.c\
			srcs/bonus/gengine_bonus.c\
			srcs/bonus/gengine_utils_bonus.c\
			srcs/bonus/hooking_bonus.c\
			srcs/bonus/init_conf_bonus.c\
			srcs/bonus/init_skull_bonus.c\
			srcs/bonus/init_sprite_bonus.c\
			srcs/bonus/move_bonus.c\
			srcs/bonus/move_skull_bonus.c\
			srcs/bonus/parsing_maps_bonus.c\
			srcs/bonus/so_long_bonus.c\
			srcs/bonus/window_bonus.c
		
MLX = ./mlx
IFLAGS = -I includes/
CFLAGS = -Wall -Wextra -Werror
CC = gcc
OBJ = $(SRC:.c=.o)
OBJ_BONUS = $(SRC_BONUS:.c=.o)
HEADER = includes/so_long.h
LIBMLX = libmlx.a
LIBFT = ./libft
NAME = so_long
NAME_BONUS = so_long_bonus

all: $(NAME)

bonus: $(NAME_BONUS)

$(NAME_BONUS): $(OBJ_BONUS) ${HEADER} ${MLX} ${LIBFT}
		@make -C ${MLX}
		@make -C ${LIBFT}
		@cp mlx/libmlx.a  ./${LIBMLX}
		@cp libft/libft.a  ./libft.a
		$(CC) $(CFLAGS) ${OBJ_BONUS} -Lmlx -lmlx -Llibft -lft -framework OpenGL -framework AppKit -o $(NAME_BONUS) 

$(NAME): $(OBJ) ${HEADER} ${MLX} ${LIBFT}
		@make -C ${MLX}
		@make -C ${LIBFT}
		@cp mlx/libmlx.a  ./${LIBMLX}
		@cp libft/libft.a  ./libft.a
		$(CC) $(CFLAGS) ${OBJ} -Lmlx -lmlx -Llibft -lft -framework OpenGL -framework AppKit  -o $(NAME)

%.o:%.c
	$(CC) $(CFLAGS) $(IFLAGS) -Imlx -c $< -o $@

clean:
	rm -f $(OBJ)
	rm -f $(OBJ_BONUS)	
	@make clean -C $(MLX)
	@make clean -C $(LIBFT)

fclean: clean
	rm -f $(NAME)
	rm -f $(NAME_BONUS)
	rm -f $(LIBMLX)
	rm -f libft.a
	@make fclean -C $(LIBFT)


re: fclean all

rbonus: fclean bonus

.PHONY: all clean fclean rbonus bonus