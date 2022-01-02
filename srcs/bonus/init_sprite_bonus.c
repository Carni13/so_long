/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_sprite_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jremy <jremy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/30 14:35:50 by jremy             #+#    #+#             */
/*   Updated: 2021/12/30 17:58:18 by jremy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	ft_hero_isprites(t_conf *conf)
{
	conf->hero.wait[0] = NULL;
	conf->hero.wait[1] = NULL;
	conf->hero.wait[2] = NULL;
	conf->hero.wait[3] = NULL;
	conf->hero.wait[4] = NULL;
	conf->hero.wait[5] = NULL;
	conf->hero.rwait[0] = NULL;
	conf->hero.rwait[1] = NULL;
	conf->hero.rwait[2] = NULL;
	conf->hero.rwait[3] = NULL;
	conf->hero.rwait[4] = NULL;
	conf->hero.rwait[5] = NULL;
	conf->hero.right[0] = NULL;
	conf->hero.right[1] = NULL;
	conf->hero.right[2] = NULL;
	conf->hero.right[3] = NULL;
	conf->hero.right[4] = NULL;
	conf->hero.right[5] = NULL;
	conf->hero.left[0] = NULL;
	conf->hero.left[1] = NULL;
	conf->hero.left[2] = NULL;
	conf->hero.left[3] = NULL;
	conf->hero.left[4] = NULL;
	conf->hero.left[5] = NULL;
}

void	ft_maps_isprites(t_conf *conf)
{
	conf->igrass[0] = NULL;
	conf->igrass[1] = NULL;
	conf->igrass[2] = NULL;
	conf->igrass[3] = NULL;
	conf->iwall = NULL;
	conf->items1.sprites.img = NULL;
	conf->exit = NULL;
	conf->imenu = NULL;
	conf->hero.hdeath[0] = NULL;
	conf->hero.hdeath[1] = NULL;
	conf->hero.hdeath[2] = NULL;
	conf->hero.hdeath[3] = NULL;
	conf->hero.hdeath[4] = NULL;
	conf->gaov = NULL;
}

void	ft_skull_isprites(t_conf *conf)
{
	conf->skull.right[0] = NULL;
	conf->skull.right[1] = NULL;
	conf->skull.right[2] = NULL;
	conf->skull.right[3] = NULL;
	conf->skull.right[4] = NULL;
	conf->skull.right[5] = NULL;
	conf->skull.left[0] = NULL;
	conf->skull.left[1] = NULL;
	conf->skull.left[2] = NULL;
	conf->skull.left[3] = NULL;
	conf->skull.left[4] = NULL;
	conf->skull.left[5] = NULL;
	conf->skull.death[0] = NULL;
	conf->skull.death[1] = NULL;
	conf->skull.death[2] = NULL;
	conf->skull.death[3] = NULL;
	conf->skull.death[4] = NULL;
	conf->skull.rdth[0] = NULL;
	conf->skull.rdth[1] = NULL;
	conf->skull.rdth[2] = NULL;
	conf->skull.rdth[3] = NULL;
	conf->skull.rdth[4] = NULL;
}

void	ft_skull_isprites2(t_conf *conf)
{
	conf->skull.wait[0] = NULL;
	conf->skull.wait[1] = NULL;
	conf->skull.wait[2] = NULL;
	conf->skull.wait[3] = NULL;
	conf->skull.wait[4] = NULL;
	conf->skull.wait[5] = NULL;
	conf->skull.rwait[0] = NULL;
	conf->skull.rwait[1] = NULL;
	conf->skull.rwait[2] = NULL;
	conf->skull.rwait[3] = NULL;
	conf->skull.rwait[4] = NULL;
	conf->skull.rwait[5] = NULL;
}

void	ft_init_sprite(t_conf *conf)
{
	ft_hero_isprites(conf);
	ft_maps_isprites(conf);
	ft_skull_isprites(conf);
	ft_skull_isprites2(conf);
}
