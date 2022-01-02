/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jremy <jremy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/30 14:42:47 by jremy             #+#    #+#             */
/*   Updated: 2021/12/30 17:39:41 by jremy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_print_image_maps(t_conf *conf, char c, int i_size, int j_size)
{
	if (c == '1')
		mlx_put_image_to_window(conf->mlx,
			conf->win, conf->iwall, i_size, j_size);
	else if (c == 'E')
		mlx_put_image_to_window(conf->mlx,
			conf->win, conf->exit, i_size, j_size);
	else
		mlx_put_image_to_window(conf->mlx,
			conf->win, conf->igrass[3], i_size, j_size);
	if (c == 'C')
		mlx_put_image_to_window(conf->mlx, conf->win,
			conf->items1.sprites.img, i_size, j_size);
	if (c == 'M')
		mlx_put_image_to_window(conf->mlx, conf->win,
			conf->imenu, i_size, j_size);
}

void	ft_print_maps(t_conf *conf)
{
	int	i;
	int	j;
	int	i_size;
	int	j_size;

	i = 0;
	j = 0;
	i_size = 0;
	j_size = 0;
	while (conf->wsize.y > j)
	{
		while (conf->wsize.x > i)
		{
			ft_print_image_maps(conf, conf->maps[j][i], i_size, j_size);
			i_size += SIZE;
			i++;
		}
		i = 0;
		i_size = 0;
		j_size += SIZE;
		j++;
	}
}

void	ft_print_hero(t_conf *conf)
{
	int	i;
	int	j;	

	i = 0;
	j = 0;
	while (conf->wsize.y > j)
	{
		while (conf->wsize.x > i)
		{
			if (conf->maps[j][i] == 'P')
			{
				mlx_put_image_to_window(conf->mlx, conf->win,
					conf->hero.wait[0], i * SIZE, j * SIZE);
				conf->hero.pi = i * SIZE;
				conf->hero.pj = j * SIZE;
				conf->hero.i = i;
				conf->hero.j = j;
				conf->hero.li = i;
				conf->hero.lj = j;
			}
			i++;
		}
		i = 0;
		j++;
	}	
}

void	ft_init_window(t_conf *conf)
{
	int	lwin;
	int	hwin;

	lwin = SIZE * conf->wsize.x;
	hwin = SIZE * conf->wsize.y;
	conf->hero.p = RIGHT;
	conf->win = mlx_new_window(conf->mlx, lwin, hwin, "so_long");
	ft_print_maps(conf);
	ft_print_hero(conf);
	conf->hero.state = WAIT;
}
