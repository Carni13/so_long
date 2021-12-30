/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_skull_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jremy <jremy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/30 17:21:59 by jremy             #+#    #+#             */
/*   Updated: 2021/12/30 19:21:16 by jremy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/*
void ft_move_other_skull(t_conf *conf)
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
			if (conf->maps[j][i] == 'i')
				mlx_put_image_to_window(conf->mlx, conf->win, conf->items1.sprites.img, i_size, j_size);
			i_size += SIZE;
			i++;
		}
		i = 0;
		i_size = 0;
		j_size += SIZE;
		j++;
	}
}
*/

void	ft_walkright_skull(t_conf *conf)
{
	conf->skull.pi += SIZE / 6;
	conf->skull.p = RIGHT;
	mlx_put_image_to_window(conf->mlx, conf->win,
		conf->skull.right[conf->skull.cnt], conf->skull.pi, conf->skull.pj);
	conf->skull.cnt++;
	if (conf->skull.cnt == 6)
	{
		conf->maps[conf->skull.j][conf->skull.i + 1] = 'b';
		conf->maps[conf->skull.j][conf->skull.i] = '0';
		conf->skull.i += 1;
		conf->skull.pi = conf->skull.i * SIZE;
	}
}

void	ft_walkleft_skull(t_conf *conf)
{
	conf->skull.pi -= SIZE / 6;
	conf->skull.p = LEFT;
	mlx_put_image_to_window(conf->mlx, conf->win,
		conf->skull.left[conf->skull.cnt], conf->skull.pi, conf->skull.pj);
	conf->skull.cnt++;
	if (conf->skull.cnt == 6)
	{
		conf->maps[conf->skull.j][conf->skull.i - 1] = 'b';
		conf->maps[conf->skull.j][conf->skull.i] = '0';
		conf->skull.i -= 1;
		conf->skull.pi = conf->skull.i * SIZE;
	}
}

void	ft_walkup_skull(t_conf *conf)
{
	conf->skull.pj -= SIZE / 6;
	if (conf->skull.p == RIGHT)
		mlx_put_image_to_window(conf->mlx, conf->win,
			conf->skull.right[conf->skull.cnt], conf->skull.pi, conf->skull.pj);
	else
		mlx_put_image_to_window(conf->mlx, conf->win,
			conf->skull.left[conf->skull.cnt], conf->skull.pi, conf->skull.pj);
	conf->skull.cnt++;
	if (conf->skull.cnt == 6)
	{
		conf->maps[conf->skull.j - 1][conf->skull.i] = 'b';
		conf->maps[conf->skull.j][conf->skull.i] = '0';
		conf->skull.j -= 1;
		conf->skull.pj = conf->skull.j * SIZE;
	}
}

void	ft_walkdown_skull(t_conf *conf)
{
	conf->skull.pj += SIZE / 6;
	if (conf->skull.p == RIGHT)
		mlx_put_image_to_window(conf->mlx, conf->win,
			conf->skull.right[conf->skull.cnt], conf->skull.pi, conf->skull.pj);
	else
		mlx_put_image_to_window(conf->mlx, conf->win,
			conf->skull.left[conf->skull.cnt], conf->skull.pi, conf->skull.pj);
	conf->skull.cnt++;
	if (conf->skull.cnt == 6)
	{
		conf->maps[conf->skull.j + 1][conf->skull.i] = 'b';
		conf->maps[conf->skull.j][conf->skull.i] = '0';
		conf->skull.j += 1;
		conf->skull.pj = conf->skull.j * SIZE;
	}
}
