/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jremy <jremy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 13:52:23 by jremy             #+#    #+#             */
/*   Updated: 2022/01/05 09:50:24 by jremy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int ac, char **av)
{
	t_conf	conf;
	int		(*game)(t_conf *conf);

	game = &ft_game;
	if (ac < 2)
	{
		printf("Error\n");
		printf("need maps\n");
		exit(1);
	}
	conf.mlx = mlx_init();
	if (!conf.mlx)
		ft_error("Fail Mlx init", &conf);
	ft_init_conf(&conf);
	conf.maps = ft_parsing_maps(av[1], &conf);
	ft_check_maps(&conf);
	if (!conf.maps)
		ft_error("Maps Malloc Error", &conf);
	ft_init_window(&conf);
	conf.gow = ((conf.wsize.x * SIZE) / 2) - conf.gow / 2;
	conf.goh = ((conf.wsize.y * SIZE) / 2) - conf.goh / 2;
	mlx_hook(conf.win, 17, (0L), &ft_quite, &conf);
	mlx_loop_hook(conf.mlx, game, &conf);
	mlx_loop(conf.mlx);
}
