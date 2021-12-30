/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_sprite.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jremy <jremy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/30 14:35:50 by jremy             #+#    #+#             */
/*   Updated: 2021/12/30 17:35:09 by jremy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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

void	ft_init_sprite(t_conf *conf)
{
	ft_hero_isprites(conf);
	ft_maps_isprites(conf);
}
