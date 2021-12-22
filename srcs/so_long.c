/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jremy <jremy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 13:52:23 by jremy             #+#    #+#             */
/*   Updated: 2021/12/22 12:59:58 by jremy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <mlx.h>
#include "mega_struct.h"


void ft_wait(t_conf *conf)
{
	int i;
	int j;
	int i_size;
	int j_size;

	i = 0;
	j = 0;
	i_size = 0;
	j_size = 0;
	while( conf->wsize.y > j)
	{
		while(conf->wsize.x > i)
		{
			if(conf->maps[j][i]== 'p')
				mlx_put_image_to_window(conf->mlx, conf->win, conf->hero.wait[conf->second], i_size, j_size);
			if (conf->maps[j][i] == 'i')
				mlx_put_image_to_window(conf->mlx, conf->win, conf->items1.sprites.img, i_size, j_size);
			if (conf->maps[j][i] == 'b')
				mlx_put_image_to_window(conf->mlx, conf->win, conf->hero.wait[conf->second], i_size, j_size);
			i_size += SIZE;
			i++;
		}
		i = 0;
		i_size = 0;
		j_size += SIZE;
		j++;
	}
}

void ft_walk(t_conf *conf)
{
	int count;

	count = 0;
	while (count != 6)
	{
		usleep(10000000/6);
		conf->hero.i = conf->hero.i + 22/6;
		mlx_clear_window(conf->mlx, conf->win);
		ft_print_maps(conf);
		mlx_put_image_to_window(conf->mlx, conf->win, conf->hero.right[count],conf->hero.i, conf->hero.j);
		printf("%d",count);		
		count++;
	}
	conf->hero.state = WAIT;
	conf->hero.i += 22;
	conf->hero.h += 22;
	conf->maps[conf->hero.j/22][conf->hero.i/22 + 1 ] = 'p';
	conf->maps[conf->hero.j/22][conf->hero.i/22] = '0';
	conf->timer++;
}
	
void ft_animate(t_conf *conf)
{
	mlx_clear_window(conf->mlx, conf->win);
	ft_print_maps(conf);
	if (conf->hero.state == WAIT)
		ft_wait(conf);
	if( conf->hero.state == MOVE)
		ft_walk(conf);
	//ft_move(conf);
	//ft_print_game(conf);
}

int	ft_hooking(int keycode, t_conf *conf)
{
	if(keycode == 0)
	{
		conf->hero.state = MOVE;
		conf->hero.state = LEFT;
	}
	if(keycode == 1)
	{
		conf->hero.state = MOVE;
		conf->hero.state = DOWN;
	}
	if(keycode == 2)
	{
		conf->hero.state = MOVE;
		conf->hero.state = RIGHT;
	}
	if(keycode == 13)
	{
		conf->hero.state = MOVE;
		conf->hero.state = UP;
	}
	if(keycode == 53)
	{
		mlx_destroy_window(conf->mlx, conf->win);
		exit(0);
	}
	return (0);
}

int ft_game(t_conf *conf)
{
	usleep(100000/6);
	conf->second++;
	if(conf->second == 6)
	{
		conf->timer++;
		conf->second = 0;	
		printf("d = %d\n",conf->timer);
	}
	mlx_hook(conf->win, 2, 1L<<0, &ft_hooking, conf);
	ft_animate(conf);
	return(0);
}
int	main(int ac, char **av)
{
	t_conf	conf;
	int (*game)(t_conf *conf);
	game = &ft_game;

	(void)ac;
	conf.mlx = mlx_init();
	ft_init_conf(&conf);
	conf.maps = ft_parsing_maps(av[1], &conf);
	if (!conf.maps)
		exit(0);
	
	ft_init_window(&conf);
	mlx_loop_hook(conf.mlx,game, &conf);
	mlx_loop(conf.mlx);
}