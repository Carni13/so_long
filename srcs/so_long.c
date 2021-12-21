/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jremy <jremy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 13:52:23 by jremy             #+#    #+#             */
/*   Updated: 2021/12/21 19:04:49 by jremy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <mlx.h>
#include "mega_struct.h"

void ft_image(t_conf *conf, void *(*f)(void *, char *, int *,int *))
{
	printf("1");
	conf->hero.wait = f(conf->mlx, "./sprites/link_p1.xpm", &(conf->hero.w), &(conf->hero.h));
	conf->hero.front[0] = f(conf->mlx, "./sprites/face/sprite1.xpm", &(conf->hero.w), &(conf->hero.h));
	conf->hero.front[1] = f(conf->mlx, "./sprites/face/sprite2.xpm", &conf->hero.h, &conf->hero.w);
	conf->hero.front[2] = f(conf->mlx, "./sprites/face/sprite3.xpm", &conf->hero.h, &conf->hero.w);
	conf->hero.front[3] = f(conf->mlx, "./sprites/face/sprite4.xpm", &conf->hero.h, &conf->hero.w);
	//conf->hero.front[4] = f(conf->mlx, "./sprites/face/sprite5.xpm", &conf->hero.h, &conf->hero.w);
	conf->hero.front[5] = f(conf->mlx, "./sprites/face/sprite6.xpm", &conf->hero.h, &conf->hero.w);
	conf->hero.front[6] = f(conf->mlx, "./sprites/face/sprite7.xpm", &conf->hero.h, &conf->hero.w);
	conf->hero.front[7] = f(conf->mlx, "./sprites/face/sprite8.xpm", &conf->hero.h, &conf->hero.w);
	conf->hero.front[8] = f(conf->mlx, "./sprites/face/sprite9.xpm", &conf->hero.h, &conf->hero.w);
	conf->hero.front[9] = f(conf->mlx, "./sprites/face/sprite10.xpm", &conf->hero.h, &conf->hero.w);
	printf("2");

}

void ft_init_conf(t_conf *conf)
{
	conf->maps = NULL;
	ft_image(conf, &mlx_xpm_file_to_image);
	conf->badguy.path1 = "./sprites/moblin/front1.xpm";
	conf->badguy.path2 = "./sprites/link_p2.xpm";
	conf->badguy.move = NULL;
	conf->items1.path = "./sprites/item.xpm";
	conf->wall = "./sprites/wall.xpm";
	conf->grass = "./sprites/grass.xpm";
	conf->timer = 0;
	conf->second = 0;
}
void ft_move(t_conf *conf)
{
	int px;
	int py;
	int i;
	i = 0;
	px = conf->hero.i * 32;
	py = conf->hero.j * 32;	
	while(i < 9)
	{
		mlx_clear_window(conf->mlx, conf->win);
		ft_print_maps(conf);
		usleep(1000000/2);
		if (i == 4)
			i++;
		printf("coucou");
		mlx_put_image_to_window(conf->mlx, conf->win, conf->hero.front[i], px, py);
		printf("px et py = %d et %d",px,py);
		px += 3;
		py += 3;
		i++;
	}
//	mlx_put_image_to_window(conf->mlx, conf->win, conf->hero.wait, px + 5, py + 5);
}

void ft_animate(t_conf *conf)
{
	conf->maps[conf->hero.j][conf->hero.i] = '0';
	conf->maps[conf->hero.j + 1][conf->hero.i] = 'p';	
	ft_move(conf);
	ft_print_maps(conf);
	ft_print_game(conf);
}

int ft_game(t_conf *conf)
{
	usleep(1000000/24);
	conf->second++;
	if(conf->second == 24)
	{
		conf->timer++;
		conf->second = 0;
		ft_animate(conf);
		printf("d = %d\n",conf->timer);
	}
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

	/*
	vars.win = mlx_new_window(vars.mlx, 640, 480, "Hello world!");
	img1 = mlx_xpm_file_to_image(vars.mlx, relative_path1, &img_width, &img_height);
	img2 = mlx_xpm_file_to_image(vars.mlx, relative_path2, &img_width, &img_height);
	mlx_put_image_to_window(vars.mlx, vars.win, img1, 0, 0);
	mlx_put_image_to_window(vars.mlx, vars.win, img2, 10, 0);
	mlx_hook(vars.win, 2, 1L<<0, ft_close, &vars);
	mlx_loop(vars.mlx);
	*/
}