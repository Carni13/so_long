/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ai_skull_utils_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jremy <jremy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/30 15:25:21 by jremy             #+#    #+#             */
/*   Updated: 2022/01/03 11:49:54 by jremy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	ft_new_direction(t_conf *conf)
{
	if (conf->skull.state == WAIT)
	{
		conf->skull.move = clock() % 4;
		conf->skull.state = MOVE;
		conf->skull.cnt = 0;
		ft_move_position(conf);
	}
	else
		conf->skull.state = WAIT;
	conf->skull.acount = 0;
}

void	ft_reinit_game(t_conf *conf)
{
	conf->hero.pv--;
	conf->hero.move = WAIT;
	conf->hero.state = WAIT;
	conf->maps[conf->hero.j][conf->hero.i] = '0';
	conf->hero.i = conf->hero.li;
	conf->hero.j = conf->hero.lj;
	conf->maps[conf->hero.j][conf->hero.i] = 'P';
	conf->hero.pj = conf->hero.j * SIZE;
	conf->hero.pi = conf->hero.i * SIZE;
	conf->skull.cnt = 0;
	conf->skull.state = WAIT;
	conf->skull.acount = 0;
}

void	ft_check_move(t_conf *conf)
{
	if (conf->skull.cnt == 6)
	{
		conf->skull.acount++;
		conf->skull.cnt = 0;
	}
	if (check_hero(conf) == -1)
	{
		conf->hero.move = DEATH;
		conf->skull.cnt = 0;
		conf->skull.acount = 0;
		return ;
	}
}
