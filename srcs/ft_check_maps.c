/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_maps.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jremy <jremy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/30 12:56:26 by jremy             #+#    #+#             */
/*   Updated: 2022/01/03 16:45:36 by jremy            ###   ########.fr       */
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

void	ft_check_input(t_conf *conf)
{
	int	i;
	int	j;
	int	check;
	int	check2;

	j = 0;
	i = 0;
	check = 0;
	check2 = 0;
	while (conf->wsize.y > j)
	{
		while (conf->wsize.x > i)
		{
			if (conf->maps[j][i] == 'E')
				check += 1;
			if (conf->maps[j][i] == 'P')
				check2 += 1;
			i++;
		}
		i = 0;
		j++;
	}
	if (check < 1 || check2 < 1)
		ft_error("invalid conf", conf);
}

void	ft_check_maps(t_conf *conf)
{
	int	j;

	j = 0;
	ft_check_size(conf);
	ft_check_wall(conf);
	ft_ecrase_hero(conf);
	ft_check_input(conf);
	conf->items = ft_check_items(conf);
	ft_check_char(conf);
	ft_create_scoring(conf);
}
