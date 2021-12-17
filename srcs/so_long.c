/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jremy <jremy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 13:52:23 by jremy             #+#    #+#             */
/*   Updated: 2021/12/17 18:37:53 by jremy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <mlx.h>
#include "mega_struct.h"


int	main(int ac, char **av)
{
	t_conf	conf;
	(void)ac;

	conf.maps = ft_parsing_maps(av[1]);
	printf("%s",conf.maps[0]);
	printf("%s",conf.maps[1]);
	printf("%s",conf.maps[2]);
	printf("%s",conf.maps[3]);



	if (!conf.maps)
		exit(0);
	conf.mlx = mlx_init();
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