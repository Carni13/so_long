/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_destroy_image.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jremy <jremy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/30 13:09:56 by jremy             #+#    #+#             */
/*   Updated: 2022/01/03 16:40:27 by jremy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_mlx_destroy_image(void *mlx, void *img)
{
	if (img && mlx)
		mlx_destroy_image(mlx, img);
	return (0);
}

void	ft_dhero_sprites(t_conf *conf, int (*f)(void *, void *))
{
	f(conf->mlx, conf->hero.wait[0]);
	f(conf->mlx, conf->hero.wait[1]);
	f(conf->mlx, conf->hero.wait[2]);
	f(conf->mlx, conf->hero.wait[3]);
	f(conf->mlx, conf->hero.wait[4]);
	f(conf->mlx, conf->hero.wait[5]);
	f(conf->mlx, conf->hero.rwait[0]);
	f(conf->mlx, conf->hero.rwait[1]);
	f(conf->mlx, conf->hero.rwait[2]);
	f(conf->mlx, conf->hero.rwait[3]);
	f(conf->mlx, conf->hero.rwait[4]);
	f(conf->mlx, conf->hero.rwait[5]);
	f(conf->mlx, conf->hero.right[0]);
	f(conf->mlx, conf->hero.right[1]);
	f(conf->mlx, conf->hero.right[2]);
	f(conf->mlx, conf->hero.right[3]);
	f(conf->mlx, conf->hero.right[4]);
	f(conf->mlx, conf->hero.right[5]);
	f(conf->mlx, conf->hero.left[0]);
	f(conf->mlx, conf->hero.left[1]);
	f(conf->mlx, conf->hero.left[2]);
	f(conf->mlx, conf->hero.left[3]);
	f(conf->mlx, conf->hero.left[4]);
	f(conf->mlx, conf->hero.left[5]);
}

void	ft_dmaps_sprites(t_conf *conf, int (*f)(void *, void *))
{
	f(conf->mlx, conf->exit);
	f(conf->mlx, conf->imenu);
	f(conf->mlx, conf->hero.hdeath[0]);
	f(conf->mlx, conf->hero.hdeath[1]);
	f(conf->mlx, conf->hero.hdeath[2]);
	f(conf->mlx, conf->hero.hdeath[3]);
	f(conf->mlx, conf->hero.hdeath[4]);
	f(conf->mlx, conf->gaov);
	f(conf->mlx, conf->igrass[0]);
	f(conf->mlx, conf->igrass[1]);
	f(conf->mlx, conf->igrass[2]);
	f(conf->mlx, conf->igrass[3]);
	f(conf->mlx, conf->iwall);
	f(conf->mlx, conf->items1.sprites.img);
}

void	ft_destroy_image(t_conf *conf)
{
	ft_dhero_sprites(conf, &check_mlx_destroy_image);
	ft_dmaps_sprites(conf, &check_mlx_destroy_image);
}
