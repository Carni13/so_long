/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jremy <jremy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/30 13:11:08 by jremy             #+#    #+#             */
/*   Updated: 2022/01/05 09:40:30 by jremy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_error(char *str, t_conf *conf)
{
	printf("Error\n");
	printf("%s\n", str);
	ft_exit(conf, 1);
}

int	ft_quite(t_conf *conf)
{
	ft_exit(conf, 1);
	return (0);
}

void	ft_exit(t_conf *conf, int output)
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
	if (conf->win)
		mlx_destroy_window(conf->mlx, conf->win);
	exit(output);
}
