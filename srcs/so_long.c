/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jremy <jremy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 13:52:23 by jremy             #+#    #+#             */
/*   Updated: 2021/12/22 19:18:17 by jremy            ###   ########.fr       */
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
			{
				if (conf->hero.p == LEFT)
					mlx_put_image_to_window(conf->mlx, conf->win, conf->hero.rwait[conf->second], i_size, j_size);
				else
					mlx_put_image_to_window(conf->mlx, conf->win, conf->hero.wait[conf->second], i_size, j_size);
			}
			if (conf->maps[j][i] == 'i')
				mlx_put_image_to_window(conf->mlx, conf->win, conf->items1.sprites.img, i_size, j_size);
			if (conf->maps[j][i] == 'b')
				mlx_put_image_to_window(conf->mlx, conf->win, conf->skull.wait[conf->second], i_size, j_size);
			i_size += SIZE;
			i++;
		}
		i = 0;
		i_size = 0;
		j_size += SIZE;
		j++;
	}
}

	
void ft_animate(t_conf *conf)
{
	mlx_clear_window(conf->mlx, conf->win);
	if (conf->hero.state == WAIT)
		ft_print_maps(conf);
	ft_wait(conf);
}

int	ft_hooking(int keycode, t_conf *conf)
{
	printf("keycode = %d\n",keycode);
	if(conf->hero.state == MOVE)
		return (0);
	if(keycode == 0)
	{
		conf->hero.state = MOVE;
		conf->hero.move = LEFT;
		conf->hero.count = 0;
		conf->hero.p = LEFT;
	}
	if(keycode == 1)
	{
		conf->hero.state = MOVE;
		conf->hero.move = DOWN;
		conf->hero.count = 0;
	}
	if(keycode == 2)
	{
		conf->hero.state = MOVE;
		conf->hero.move = RIGHT;
		conf->hero.count = 0;
		conf->hero.p = RIGHT;
	}
	if(keycode == 13)
	{
		conf->hero.state = MOVE;
		conf->hero.move = UP;
		conf->hero.count = 0;
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
	void (*f_walk[4])(t_conf *conf);
	f_walk[UP] = ft_walkup;
	f_walk[DOWN] = ft_walkdown;
	f_walk[LEFT] = ft_walkleft;
	f_walk[RIGHT] = ft_walkright;
	mlx_hook(conf->win, 2, 1L<<0, &ft_hooking, conf);
	usleep(SPEED/6);
	conf->second++;
	if(conf->second == 6)
	{
		conf->timer++;
		conf->second = 0;
	}
	ft_ai_skull(conf);
	if (conf->hero.state == MOVE)
	{
		if(ft_hero_coll(conf) == -1)
		{
			conf->hero.state = WAIT;
			return (0);
		}
		f_walk[conf->hero.move](conf);
		return(0);
	}
	if(conf->hero.items == 100)
	{
		mlx_destroy_window(conf->mlx, conf->win);
		exit(0);
	}
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