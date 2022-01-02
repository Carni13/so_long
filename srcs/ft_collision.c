/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_collision.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jremy <jremy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/30 13:03:50 by jremy             #+#    #+#             */
/*   Updated: 2021/12/30 17:35:44 by jremy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_collleft(t_conf *conf)
{
	if (conf->maps[conf->hero.j][conf->hero.i - 1] == '1'
	|| conf->maps[conf->hero.j][conf->hero.i - 1] == 'b')
		return (-1);
	if (conf->maps[conf->hero.j][conf->hero.i - 1] == 'C')
	{
		conf->hero.items++;
		return (0);
	}
	if (conf->maps[conf->hero.j][conf->hero.i - 1] == 'E')
	{
		if (conf->hero.items == (conf->items * 6))
		{
			conf->hero.items *= -1;
			return (0);
		}
		return (-1);
	}
	return (0);
}

int	ft_collright(t_conf *conf)
{
	if (conf->maps[conf->hero.j][conf->hero.i + 1] == '1'
	|| conf->maps[conf->hero.j][conf->hero.i + 1] == 'b')
		return (-1);
	if (conf->maps[conf->hero.j][conf->hero.i + 1] == 'C')
	{
		conf->hero.items++;
		return (0);
	}
	if (conf->maps[conf->hero.j][conf->hero.i + 1] == 'E')
	{
		if (conf->hero.items == (conf->items * 6))
		{
			conf->hero.items *= -1;
			return (0);
		}
		return (-1);
	}
	return (0);
}

int	ft_colldown(t_conf *conf)
{
	if (conf->maps[conf->hero.j + 1][conf->hero.i] == '1'
	|| conf->maps[conf->hero.j + 1][conf->hero.i] == 'b')
		return (-1);
	if (conf->maps[conf->hero.j + 1][conf->hero.i] == 'C')
	{
		conf->hero.items++;
		return (0);
	}
	if (conf->maps[conf->hero.j + 1][conf->hero.i] == 'E')
	{
		if (conf->hero.items == (conf->items * 6))
		{
			conf->hero.items *= -1;
			return (0);
		}
		return (-1);
	}
	return (0);
}

int	ft_collup(t_conf *conf)
{
	if (conf->maps[conf->hero.j - 1][conf->hero.i] == '1'
	|| conf->maps[conf->hero.j - 1][conf->hero.i] == 'b')
		return (-1);
	if (conf->maps[conf->hero.j - 1][conf->hero.i] == 'C')
	{
		conf->hero.items++;
		return (0);
	}
	if (conf->maps[conf->hero.j - 1][conf->hero.i] == 'E')
	{
		if (conf->hero.items == (conf->items * 6))
		{
			conf->hero.items *= -1;
			return (0);
		}
		return (-1);
	}
	return (0);
}

int	ft_hero_coll(t_conf *conf)
{
	int	(*f_coll[4])(t_conf *conf);

	f_coll[UP] = ft_collup;
	f_coll[DOWN] = ft_colldown;
	f_coll[LEFT] = ft_collleft;
	f_coll[RIGHT] = ft_collright;
	return (f_coll[conf->hero.move](conf));
}
