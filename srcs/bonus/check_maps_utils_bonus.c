/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_maps_utils_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jremy <jremy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/30 12:59:08 by jremy             #+#    #+#             */
/*   Updated: 2022/01/03 11:53:28 by jremy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	ft_check_items(t_conf *conf)
{
	int	i;
	int	j;
	int	check;

	check = 0;
	j = 0;
	i = 0;
	while (conf->wsize.y > j)
	{
		while (conf->wsize.x > i)
		{
			if (conf->maps[j][i] == 'C' )
				check++;
			i++;
		}
		i = 0;
		j++;
	}
	return (check);
}

void	ft_check_char(t_conf *conf)
{
	int	i;
	int	j;
	int	check;

	check = 0;
	j = 0;
	i = 0;
	while (conf->wsize.y > j)
	{
		while (conf->wsize.x > i)
		{
			if (conf->maps[j][i] != 'E' && conf->maps[j][i] != 'P'
			&& conf->maps[j][i] != 'C' && conf->maps[j][i] != '0'
			&& conf->maps[j][i] != '1'
			&& conf->maps[j][i] != 'b')
				ft_error("invalid input", conf);
			i++;
		}
		i = 0;
		j++;
	}
}

void	ft_create_scoring(t_conf *conf)
{
	char	**new_maps;
	char	*score_bar;
	int		i;
	int		j;

	i = 0;
	j = 1;
	score_bar = malloc(sizeof(char) * conf->wsize.x + 1);
	new_maps = malloc(sizeof(char *) * (conf->wsize.y + 2));
	if (!score_bar || !new_maps)
		ft_error("malloc error", conf);
	conf->wsize.y++;
	while (conf->wsize.x > i)
		score_bar[i++] = 'M';
	score_bar[i] = '\0';
	new_maps[0] = score_bar;
	while (conf->wsize.y > j)
	{
		new_maps[j] = conf->maps[j - 1];
		j++;
	}
	new_maps[j] = NULL;
	free(conf->maps);
	conf->maps = new_maps;
}

void	ft_ecrase_bad(t_conf *conf)
{
	int	i;
	int	j;
	int	check;

	check = 0;
	j = 0;
	i = 0;
	while (conf->wsize.y > j)
	{
		while (conf->wsize.x > i)
		{
			if (conf->maps[j][i] == 'b' && check >= 1)
				conf->maps[j][i] = '0';
			if (conf->maps[j][i] == 'b')
				check++;
			i++;
		}
		i = 0;
		j++;
	}
}

void	ft_ecrase_hero(t_conf *conf)
{
	int	i;
	int	j;
	int	check;

	check = 0;
	j = 0;
	i = 0;
	while (conf->wsize.y > j)
	{
		while (conf->wsize.x > i)
		{
			if (conf->maps[j][i] == 'P' && check >= 1)
				conf->maps[j][i] = '0';
			if (conf->maps[j][i] == 'P')
				check++;
			i++;
		}
		i = 0;
		j++;
	}
	ft_ecrase_bad(conf);
}	
