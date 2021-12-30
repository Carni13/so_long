/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jremy <jremy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/30 13:11:08 by jremy             #+#    #+#             */
/*   Updated: 2021/12/30 13:12:25 by jremy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_exit(t_conf *conf)
{
	int	j;

	j = 0;
	if (conf->maps != NULL)
	{
		while (j < conf->wsize.y)
		{
			free(conf->maps[j]);
			j++;
		}
		free(conf->maps);
	}
	ft_destroy_image(conf);
	mlx_destroy_window(conf->mlx, conf->win);
	free(conf->mlx);
	exit(0);
}
