/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jremy <jremy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 13:52:45 by jremy             #+#    #+#             */
/*   Updated: 2021/12/17 18:35:29 by jremy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

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
char *ft_strjoin(char *str1, char *str2);
void ft_strcpy(char *dst, char *src, int size);
int ft_search_n(char *str);
int ft_strlen(char *str);
char *get_next_line(int fd);
char **ft_parsing_maps(char *files);
#endif 
