/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jremy <jremy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 13:52:23 by jremy             #+#    #+#             */
/*   Updated: 2021/12/30 18:28:38 by jremy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int ac, char **av)
{
	t_conf	conf;
	int		(*game)(t_conf *conf);

	game = &ft_game;
	(void)ac;
	conf.mlx = mlx_init();
	ft_init_conf(&conf);
	conf.maps = ft_parsing_maps(av[1], &conf);
	ft_check_maps(&conf);
	if (!conf.maps)
		exit(0);
	ft_init_window(&conf);
	conf.gow = ((conf.wsize.x * SIZE) / 2) - conf.gow / 2;
	conf.goh = ((conf.wsize.y * SIZE) / 2) - conf.goh / 2;
	mlx_loop_hook(conf.mlx, game, &conf);
	mlx_loop(conf.mlx);
}
