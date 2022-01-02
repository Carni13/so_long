/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_skull_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jremy <jremy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/30 15:57:48 by jremy             #+#    #+#             */
/*   Updated: 2021/12/30 18:18:07 by jremy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	ft_skull_s3(t_conf *conf, void *(*f)(void *, char *, int *, int *))
{
	conf->skull.right[0] = f(conf->mlx, "./sprites/skull1.xpm",
			&(conf->skull.w), &(conf->skull.h));
	conf->skull.right[1] = f(conf->mlx, "./sprites/skull2.xpm",
			&(conf->skull.w), &(conf->skull.h));
	conf->skull.right[2] = f(conf->mlx, "./sprites/skull3.xpm",
			&(conf->skull.w), &(conf->skull.h));
	conf->skull.right[3] = f(conf->mlx, "./sprites/skull4.xpm",
			&(conf->skull.w), &(conf->skull.h));
	conf->skull.right[4] = f(conf->mlx, "./sprites/skull5.xpm",
			&(conf->skull.w), &(conf->skull.h));
	conf->skull.right[5] = f(conf->mlx, "./sprites/skull6.xpm",
			&(conf->skull.w), &(conf->skull.h));
	conf->skull.left[0] = f(conf->mlx, "./sprites/rskull1.xpm",
			&(conf->skull.w), &(conf->skull.h));
	conf->skull.left[1] = f(conf->mlx, "./sprites/rskull2.xpm",
			&(conf->skull.w), &(conf->skull.h));
	conf->skull.left[2] = f(conf->mlx, "./sprites/rskull3.xpm",
			&(conf->skull.w), &(conf->skull.h));
	conf->skull.left[3] = f(conf->mlx, "./sprites/rskull4.xpm",
			&(conf->skull.w), &(conf->skull.h));
	conf->skull.left[4] = f(conf->mlx, "./sprites/rskull5.xpm",
			&(conf->skull.w), &(conf->skull.h));
	conf->skull.left[5] = f(conf->mlx, "./sprites/rskull6.xpm",
			&(conf->skull.w), &(conf->skull.h));
}

void	ft_skull_s2(t_conf *conf, void *(*f)(void *, char *, int *, int *))
{
	conf->skull.death[0] = f(conf->mlx, "./sprites/death1.xpm",
			&(conf->skull.dw), &(conf->skull.dh));
	conf->skull.death[1] = f(conf->mlx, "./sprites/death2.xpm",
			&(conf->skull.dw), &(conf->skull.dh));
	conf->skull.death[2] = f(conf->mlx, "./sprites/death3.xpm",
			&(conf->skull.dw), &(conf->skull.dh));
	conf->skull.death[3] = f(conf->mlx, "./sprites/death4.xpm",
			&(conf->skull.dw), &(conf->skull.dh));
	conf->skull.death[4] = f(conf->mlx, "./sprites/death5.xpm",
			&(conf->skull.dw), &(conf->skull.dh));
	conf->skull.rdth[0] = f(conf->mlx, "./sprites/rdeath1.xpm",
			&(conf->skull.dw), &(conf->skull.dh));
	conf->skull.rdth[1] = f(conf->mlx, "./sprites/rdeath2.xpm",
			&(conf->skull.dw), &(conf->skull.dh));
	conf->skull.rdth[2] = f(conf->mlx, "./sprites/rdeath3.xpm",
			&(conf->skull.dw), &(conf->skull.dh));
	conf->skull.rdth[3] = f(conf->mlx, "./sprites/rdeath4.xpm",
			&(conf->skull.dw), &(conf->skull.dh));
	conf->skull.rdth[4] = f(conf->mlx, "./sprites/rdeath5.xpm",
			&(conf->skull.dw), &(conf->skull.dh));
	ft_skull_s3(conf, &mlx_xpm_file_to_image);
}

void	ft_skull_s(t_conf *conf, void *(*f)(void *, char *, int *, int *))
{
	conf->skull.wait[0] = f(conf->mlx, "./sprites/skullwait1.xpm",
			&(conf->skull.w), &(conf->skull.h));
	conf->skull.wait[1] = f(conf->mlx, "./sprites/skullwait2.xpm",
			&(conf->skull.w), &(conf->skull.h));
	conf->skull.wait[2] = f(conf->mlx, "./sprites/skullwait3.xpm",
			&(conf->skull.w), &(conf->skull.h));
	conf->skull.wait[3] = f(conf->mlx, "./sprites/skullwait4.xpm",
			&(conf->skull.w), &(conf->skull.h));
	conf->skull.wait[4] = f(conf->mlx, "./sprites/skullwait5.xpm",
			&(conf->skull.w), &(conf->skull.h));
	conf->skull.wait[5] = f(conf->mlx, "./sprites/skullwait6.xpm",
			&(conf->skull.w), &(conf->skull.h));
	conf->skull.rwait[0] = f(conf->mlx, "./sprites/rskullwait1.xpm",
			&(conf->skull.w), &(conf->skull.h));
	conf->skull.rwait[1] = f(conf->mlx, "./sprites/rskullwait2.xpm",
			&(conf->skull.w), &(conf->skull.h));
	conf->skull.rwait[2] = f(conf->mlx, "./sprites/rskullwait3.xpm",
			&(conf->skull.w), &(conf->skull.h));
	conf->skull.rwait[3] = f(conf->mlx, "./sprites/rskullwait4.xpm",
			&(conf->skull.w), &(conf->skull.h));
	conf->skull.rwait[4] = f(conf->mlx, "./sprites/rskullwait5.xpm",
			&(conf->skull.w), &(conf->skull.h));
	conf->skull.rwait[5] = f(conf->mlx, "./sprites/rskullwait6.xpm",
			&(conf->skull.w), &(conf->skull.h));
	ft_skull_s2(conf, &mlx_xpm_file_to_image);
}
