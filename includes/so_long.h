/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jremy <jremy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 13:52:45 by jremy             #+#    #+#             */
/*   Updated: 2021/12/22 18:50:47 by jremy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
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
# define SPEED 10000

int so_long(int i);
void ft_init_struct(t_conf *conf);
char **ft_parsing_maps(char *files, t_conf *conf);
void ft_init_window(t_conf *conf);
void ft_print_maps(t_conf *conf);
void ft_print_game(t_conf *conf);
void ft_init_conf(t_conf *conf);
void ft_walkright(t_conf *conf);
void ft_walkup(t_conf *conf);
void ft_walkdown(t_conf *conf);
void ft_walkleft(t_conf *conf);
int ft_hero_coll(t_conf *conf);
int ft_skull_coll(t_conf *conf);
void ft_walkright_skull(t_conf *conf);
void ft_walkup_skull(t_conf *conf);
void ft_walkdown_skull(t_conf *conf);
void ft_walkleft_skull(t_conf *conf);
void ft_ai_skull(t_conf *conf);
#endif 
