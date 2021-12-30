/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_maps_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jremy <jremy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/30 12:59:08 by jremy             #+#    #+#             */
/*   Updated: 2021/12/30 17:35:59 by jremy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_error(char *str, t_conf *conf)
{
	perror("error\n");
	perror(str);
	ft_exit(conf);
}

void	ft_check_char(t_conf *conf)
{
	int	i;
	int	j;

	j = 0;
	i = 0;
	while (conf->wsize.y > j)
	{
		while (conf->wsize.x > i)
		{
			if (conf->maps[j][i] != 'E'
			&& conf->maps[j][i] != 'P'
			&& conf->maps[j][i] != 'I'
			&& conf->maps[j][i] != '0'
			&& conf->maps[j][i] != '1')
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
	conf->wsize.y++;
	while (conf->wsize.x > i)
	{
		score_bar[i] = 'M';
		i++;
	}
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
