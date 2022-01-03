/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_skull_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jremy <jremy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/30 17:21:59 by jremy             #+#    #+#             */
/*   Updated: 2022/01/03 10:44:36 by jremy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	ft_move_position(t_conf *conf)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (conf->wsize.y > j)
	{
		while (conf->wsize.x > i)
		{
			if (conf->maps[j][i] == 'b')
			{
				conf->skull.i = i;
				conf->skull.j = j;
			}
			i++;
		}
		i = 0;
		j++;
	}
	conf->skull.pi = conf->skull.i * SIZE;
	conf->skull.pj = conf->skull.j * SIZE;
}

void	ft_walkright_skull(t_conf *conf)
{
	conf->maps[conf->skull.j][conf->skull.i + 1] = 'b';
	conf->maps[conf->skull.j][conf->skull.i] = '0';
	conf->skull.pi += SIZE / 6;
	conf->skull.p = RIGHT;
	mlx_put_image_to_window(conf->mlx, conf->win,
		conf->skull.right[conf->skull.cnt], conf->skull.pi, conf->skull.pj);
	conf->skull.cnt++;
	if (conf->skull.cnt == 5)
	{
		conf->maps[conf->skull.j][conf->skull.i] = '0';
		ft_move_position(conf);
	}
}

void	ft_walkleft_skull(t_conf *conf)
{
	conf->maps[conf->skull.j][conf->skull.i - 1] = 'b';
	conf->maps[conf->skull.j][conf->skull.i] = '0';
	conf->skull.pi -= SIZE / 6;
	conf->skull.p = LEFT;
	mlx_put_image_to_window(conf->mlx, conf->win,
		conf->skull.left[conf->skull.cnt], conf->skull.pi, conf->skull.pj);
	conf->skull.cnt++;
	if (conf->skull.cnt == 5)
	{
		conf->maps[conf->skull.j][conf->skull.i] = '0';
		ft_move_position(conf);
	}
}

void	ft_walkup_skull(t_conf *conf)
{
	conf->maps[conf->skull.j - 1][conf->skull.i] = 'b';
	conf->maps[conf->skull.j][conf->skull.i] = '0';
	conf->skull.pj -= SIZE / 6;
	if (conf->skull.p == RIGHT)
		mlx_put_image_to_window(conf->mlx, conf->win,
			conf->skull.right[conf->skull.cnt], conf->skull.pi, conf->skull.pj);
	else
		mlx_put_image_to_window(conf->mlx, conf->win,
			conf->skull.left[conf->skull.cnt], conf->skull.pi, conf->skull.pj);
	conf->skull.cnt++;
	if (conf->skull.cnt == 5)
	{
		conf->maps[conf->skull.j][conf->skull.i] = '0';
		ft_move_position(conf);
	}
}

void	ft_walkdown_skull(t_conf *conf)
{
	conf->maps[conf->skull.j + 1][conf->skull.i] = 'b';
	conf->maps[conf->skull.j][conf->skull.i] = '0';
	conf->skull.pj += SIZE / 6;
	if (conf->skull.p == RIGHT)
		mlx_put_image_to_window(conf->mlx, conf->win,
			conf->skull.right[conf->skull.cnt], conf->skull.pi, conf->skull.pj);
	else
		mlx_put_image_to_window(conf->mlx, conf->win,
			conf->skull.left[conf->skull.cnt], conf->skull.pi, conf->skull.pj);
	conf->skull.cnt++;
	if (conf->skull.cnt == 5)
	{
		conf->maps[conf->skull.j][conf->skull.i] = '0';
		ft_move_position(conf);
	}
}
