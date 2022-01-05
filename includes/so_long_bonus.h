/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jremy <jremy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 13:52:45 by jremy             #+#    #+#             */
/*   Updated: 2022/01/05 09:10:49 by jremy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <time.h>
# include "mega_struct.h"
# include "../libft/libft.h"
# include <mlx.h>
# define BUFFER_SIZE 100000
# define WAIT 0
# define MOVE 1
# define UP 0
# define DOWN 1
# define LEFT 2
# define RIGHT 3
# define SIZE 22
# define SPEED 2500000
# define DEATH 666
# define AFTERDEATH -666
# define BONUS 1

int		so_long(int i);
void	ft_init_sprite(t_conf *conf);
void	ft_init_struct(t_conf *conf);
char	**ft_parsing_maps(char *files, t_conf *conf);
void	ft_init_window(t_conf *conf);
void	ft_print_maps(t_conf *conf);
void	ft_print_game(t_conf *conf);
void	ft_init_conf(t_conf *conf);
void	ft_walkright(t_conf *conf);
void	ft_walkup(t_conf *conf);
void	ft_walkdown(t_conf *conf);
void	ft_walkleft(t_conf *conf);
int		ft_hero_coll(t_conf *conf);
int		ft_skull_coll(t_conf *conf);
void	ft_walkright_skull(t_conf *conf);
void	ft_walkup_skull(t_conf *conf);
void	ft_walkdown_skull(t_conf *conf);
void	ft_walkleft_skull(t_conf *conf);
void	ft_ai_skull(t_conf *conf);
void	ft_death(t_conf *conf);
void	ft_error(char *str, t_conf *conf);
void	ft_check_maps(t_conf *conf);
void	ft_create_scoring(t_conf *conf);
void	ft_check_maps(t_conf *conf);
void	ft_create_scoring(t_conf *conf);
void	ft_check_char(t_conf *conf);
void	ft_check_sprite(t_conf *conf);
void	ft_destroy_image(t_conf *conf);
void	ft_exit(t_conf *conf, int output);
void	ft_time(t_conf *conf);
int		ft_game(t_conf *conf);
int		ft_hooking(int keycode, t_conf *conf);
void	ft_new_direction(t_conf *conf);
void	ft_reinit_game(t_conf *conf);
void	ft_check_move(t_conf *conf);
void	ft_skull_s(t_conf *conf, void *(*f)(void *, char *, int *, int *));
int		check_hero(t_conf *conf);
void	ft_move_position(t_conf *conf);
int		check_mlx_destroy_image(void *mlx, void *img);
void	ft_ecrase_hero(t_conf *conf);
int		ft_check_items(t_conf *conf);
int		ft_quite(t_conf *conf);

#endif 
