/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jremy <jremy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 13:52:23 by jremy             #+#    #+#             */
/*   Updated: 2021/12/20 18:22:00 by jremy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <mlx.h>
#include "mega_struct.h"

void ft_init_conf(t_conf *conf)
{
	conf->maps = NULL;
	conf->hero.path1 = "./sprites/link_p1.xpm";
	conf->hero.path2 = "./sprites/link_p2.xpm";
	conf->badguy.path1 = "./sprites/link_p1.xpm";
	conf->badguy.path2 = "./sprites/link_p2.xpm";
	conf->badguy.move = NULL;
	conf->items1.path = "./sprites/items.xpm";
	conf->wall = "./sprites/wall2.xpm";
	conf->grass = "./sprites/grass.xpm";
}
int	main(int ac, char **av)
{
	t_conf	conf;
	(void)ac;
	ft_init_conf(&conf);
	conf.maps = ft_parsing_maps(av[1], &conf);
	if (!conf.maps)
		exit(0);
	conf.mlx = mlx_init();
	ft_init_window(&conf);
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