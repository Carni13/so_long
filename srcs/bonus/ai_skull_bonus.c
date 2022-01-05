/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ai_skull_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jremy <jremy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/30 15:16:42 by jremy             #+#    #+#             */
/*   Updated: 2022/01/05 09:21:27 by jremy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	ft_break(t_conf *conf)
{
	int	i;
	int	j;
	int	check;

	j = 0;
	i = 0;
	check = 0;
	while (conf->wsize.y > j)
	{
		while (conf->wsize.x > i)
		{
			if (conf->maps[j][i] == 'b')
				check += 1;
			i++;
		}
		i = 0;
		j++;
	}
	if (check > 1)
		exit(0);
}

void	ft_skull_wait(t_conf *conf)
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
				if (conf->skull.p == LEFT)
					mlx_put_image_to_window(conf->mlx, conf->win,
						conf->skull.rwait[conf->skull.cnt], i * SIZE, j * SIZE);
				else
					mlx_put_image_to_window(conf->mlx, conf->win,
						conf->skull.wait[conf->skull.cnt], i * SIZE, j * SIZE);
			}
			i++;
		}
		i = 0;
		j++;
	}
	conf->skull.cnt++;
}

void	ft_death(t_conf *conf)
{
	mlx_clear_window(conf->mlx, conf->win);
	ft_print_maps(conf);
	conf->skull.cnt ++;
	usleep(100000 / 6);
	if (conf->skull.p == LEFT)
		mlx_put_image_to_window(conf->mlx, conf->win,
			conf->skull.rdth[conf->skull.cnt], conf->skull.pi, conf->skull.pj);
	else
		mlx_put_image_to_window(conf->mlx, conf->win,
			conf->skull.death[conf->skull.cnt], conf->skull.pi, conf->skull.pj);
	mlx_put_image_to_window(conf->mlx, conf->win,
		conf->hero.hdeath[conf->skull.cnt], conf->hero.pi, conf->hero.pj);
	if (conf->hero.pv <= 0)
		mlx_put_image_to_window(conf->mlx, conf->win,
			conf->gaov, conf->gow, conf->goh);
	if (conf->skull.cnt == 4 && conf->hero.pv <= 0)
	{
		sleep(3);
		ft_exit(conf, 0);
	}
	if (conf->skull.cnt >= 4)
		ft_reinit_game(conf);
}

int	check_hero(t_conf *conf)
{
	int	i;
	int	j;

	i = conf->skull.i;
	j = conf->skull.j;
	if (conf->skull.p == LEFT)
	{
		if (conf->maps[j - 1][i - 1] == 'P'
			|| conf->maps[j][i - 1] == 'P'
			|| conf->maps[j + 1][i] == 'P'
			|| conf->maps[j - 1][i] == 'P'
			|| conf->maps[j][i] == 'P')
			return (-1);
	}
	if (conf->skull.p == RIGHT)
	{
		if (conf->maps[j - 1][i + 1] == 'P'
			|| conf->maps[j][i + 1] == 'P'
			|| conf->maps[j + 1][i] == 'P'
			|| conf->maps[j - 1][i] == 'P'
			|| conf->maps[j][i] == 'P')
			return (-1);
	}
	return (0);
}

void	ft_ai_skull(t_conf *conf)
{
	void	(*f_walk[4])(t_conf *conf);
	int		i;

	i = 0;
	f_walk[UP] = ft_walkup_skull;
	f_walk[DOWN] = ft_walkdown_skull;
	f_walk[LEFT] = ft_walkleft_skull;
	f_walk[RIGHT] = ft_walkright_skull;
	if (conf->skull.acount == 8)
		ft_new_direction(conf);
	ft_check_move(conf);
	if (ft_skull_coll(conf) == -1)
		return ;
	if (conf->skull.state == WAIT)
		ft_skull_wait(conf);
	else
		f_walk[conf->skull.move](conf);
	return ;
}
