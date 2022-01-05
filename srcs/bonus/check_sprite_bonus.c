/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_sprite_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jremy <jremy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/30 13:02:34 by jremy             #+#    #+#             */
/*   Updated: 2022/01/05 09:44:13 by jremy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	ft_check(void *img, t_conf *conf)
{
	if (img == NULL)
		ft_error("Sprite Error", conf);
	return ;
}

void	ft_chero_sprites(t_conf *conf)
{
	ft_check(conf->hero.wait[0], conf);
	ft_check(conf->hero.wait[1], conf);
	ft_check(conf->hero.wait[2], conf);
	ft_check(conf->hero.wait[3], conf);
	ft_check(conf->hero.wait[4], conf);
	ft_check(conf->hero.wait[5], conf);
	ft_check(conf->hero.rwait[0], conf);
	ft_check(conf->hero.rwait[1], conf);
	ft_check(conf->hero.rwait[2], conf);
	ft_check(conf->hero.rwait[3], conf);
	ft_check(conf->hero.rwait[4], conf);
	ft_check(conf->hero.rwait[5], conf);
	ft_check(conf->hero.right[0], conf);
	ft_check(conf->hero.right[1], conf);
	ft_check(conf->hero.right[2], conf);
	ft_check(conf->hero.right[3], conf);
	ft_check(conf->hero.right[4], conf);
	ft_check(conf->hero.right[5], conf);
	ft_check(conf->hero.left[0], conf);
	ft_check(conf->hero.left[1], conf);
	ft_check(conf->hero.left[2], conf);
	ft_check(conf->hero.left[3], conf);
	ft_check(conf->hero.left[4], conf);
	ft_check(conf->hero.left[5], conf);
}

void	ft_cmaps_sprites(t_conf *conf)
{
	ft_check(conf->igrass[0], conf);
	ft_check(conf->igrass[1], conf);
	ft_check(conf->igrass[2], conf);
	ft_check(conf->igrass[3], conf);
	ft_check(conf->iwall, conf);
	ft_check(conf->items1.sprites.img, conf);
	ft_check(conf->exit, conf);
	ft_check(conf->imenu, conf);
	ft_check(conf->hero.hdeath[0], conf);
	ft_check(conf->hero.hdeath[1], conf);
	ft_check(conf->hero.hdeath[2], conf);
	ft_check(conf->hero.hdeath[3], conf);
	ft_check(conf->hero.hdeath[4], conf);
	ft_check(conf->gaov, conf);
	ft_check(conf->skull.wait[0], conf);
	ft_check(conf->skull.wait[1], conf);
	ft_check(conf->skull.wait[2], conf);
	ft_check(conf->skull.wait[3], conf);
	ft_check(conf->skull.wait[4], conf);
	ft_check(conf->skull.wait[5], conf);
	ft_check(conf->skull.rwait[0], conf);
	ft_check(conf->skull.rwait[1], conf);
	ft_check(conf->skull.rwait[2], conf);
}

void	ft_cskull_sprites(t_conf *conf)
{
	ft_check(conf->skull.right[0], conf);
	ft_check(conf->skull.right[1], conf);
	ft_check(conf->skull.right[2], conf);
	ft_check(conf->skull.right[3], conf);
	ft_check(conf->skull.right[4], conf);
	ft_check(conf->skull.right[5], conf);
	ft_check(conf->skull.left[0], conf);
	ft_check(conf->skull.left[1], conf);
	ft_check(conf->skull.left[2], conf);
	ft_check(conf->skull.left[3], conf);
	ft_check(conf->skull.left[4], conf);
	ft_check(conf->skull.left[5], conf);
	ft_check(conf->skull.death[0], conf);
	ft_check(conf->skull.death[1], conf);
	ft_check(conf->skull.death[2], conf);
	ft_check(conf->skull.death[3], conf);
	ft_check(conf->skull.death[4], conf);
	ft_check(conf->skull.rdth[0], conf);
	ft_check(conf->skull.rdth[1], conf);
	ft_check(conf->skull.rdth[2], conf);
	ft_check(conf->skull.rdth[3], conf);
	ft_check(conf->skull.rdth[4], conf);
	ft_check(conf->skull.rwait[3], conf);
	ft_check(conf->skull.rwait[4], conf);
	ft_check(conf->skull.rwait[5], conf);
}

void	ft_check_sprite(t_conf *conf)
{
	ft_chero_sprites(conf);
	ft_cmaps_sprites(conf);
	ft_cskull_sprites(conf);
}
