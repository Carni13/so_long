/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jremy <jremy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 13:52:45 by jremy             #+#    #+#             */
/*   Updated: 2021/12/20 16:46:52 by jremy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include "mega_struct.h"
# include "../libft/libft.h"

#define BUFFER_SIZE 100000

typedef struct s_buff
{
	int position;
	int eof;
	char *line;
	char *memory;
} t_buff;

int so_long(int i);
void ft_init_struct(t_buff *buff);
char **ft_parsing_maps(char *files, t_conf *conf);
void ft_init_window(t_conf *conf);
#endif 
