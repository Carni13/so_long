/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_maps_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jremy <jremy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/30 12:56:26 by jremy             #+#    #+#             */
/*   Updated: 2021/12/30 17:25:52 by jremy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_check_size(t_conf *conf)
{
	int	i;
	int	j;
	int	size;

	i = 0;
	j = 0;
	size = 0;
	while (conf->wsize.y > j)
	{
		size = ft_strlen(conf->maps[j]);
		if (size != conf->wsize.x)
			ft_error("no valide maps it's not a rectangle", conf);
		j++;
	}
}

void	ft_check_wall2(t_conf *conf)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (conf->wsize.y > j)
	{
		if (conf->maps[j][conf->wsize.x - 1] != '1')
			ft_error("invalid Wall!", conf);
		j++;
	}
	while (i < conf->wsize.x)
	{
		if (conf->maps[conf->wsize.y - 1][i] != '1')
			ft_error("invalid Wall!", conf);
		i++;
	}
}

void	ft_check_wall(t_conf *conf)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < conf->wsize.x)
	{
		if (conf->maps[j][i] != '1')
			ft_error("invalid Wall!", conf);
		i++;
	}
	i = 0;
	while (conf->wsize.y > j)
	{
		if (conf->maps[j][i] != '1')
			ft_error("invalid Wall!", conf);
		j++;
	}
	ft_check_wall2(conf);
}

int	ft_check_input(t_conf *conf)
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
			if (conf->maps[j][i] == 'E')
				check += 100000;
			if (conf->maps[j][i] == 'P')
				check += 1000000;
			if (conf->maps[j][i] == 'I')
				check += 1;
			i++;
		}
		i = 0;
		j++;
	}
	if (check > 1110000 || check < 1100001)
		ft_error("invalid conf", conf);
	return (check);
}

void	ft_check_maps(t_conf *conf)
{
	int	j;

	j = 0;
	ft_check_size(conf);
	ft_check_wall(conf);
	conf->items = ft_check_input(conf) - 1100000;
	ft_check_char(conf);
	ft_create_scoring(conf);
}
