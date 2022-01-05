/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hooking.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jremy <jremy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/30 14:31:42 by jremy             #+#    #+#             */
/*   Updated: 2022/01/05 09:17:42 by jremy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_hookleft(t_conf *conf)
{
	conf->hero.state = MOVE;
	conf->hero.move = LEFT;
	conf->hero.count = 0;
	conf->hero.p = LEFT;
}

void	ft_hookright(t_conf *conf)
{
	conf->hero.state = MOVE;
	conf->hero.move = RIGHT;
	conf->hero.count = 0;
	conf->hero.p = RIGHT;
}

void	ft_hookdown(t_conf *conf)
{
	conf->hero.state = MOVE;
	conf->hero.move = DOWN;
	conf->hero.count = 0;
}

void	ft_hookup(t_conf *conf)
{
	conf->hero.state = MOVE;
	conf->hero.move = UP;
	conf->hero.count = 0;
}

int	ft_hooking(int keycode, t_conf *conf)
{
	void	(*f_hook[4])(t_conf *conf);

	f_hook[UP] = ft_hookup;
	f_hook[DOWN] = ft_hookdown;
	f_hook[LEFT] = ft_hookleft;
	f_hook[RIGHT] = ft_hookright;
	if (conf->hero.state == MOVE)
		return (0);
	if (keycode == 0 || keycode == 123)
		f_hook[LEFT](conf);
	if (keycode == 1 || keycode == 125)
		f_hook[DOWN](conf);
	if (keycode == 2 || keycode == 124)
		f_hook[RIGHT](conf);
	if (keycode == 13 || keycode == 126)
		f_hook[UP](conf);
	if (keycode == 53)
		ft_exit(conf, 0);
	return (0);
}
