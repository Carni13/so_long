/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mega_struct.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jremy <jremy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 11:56:05 by jremy             #+#    #+#             */
/*   Updated: 2022/01/03 11:59:10 by jremy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MEGA_STRUCT_H
# define MEGA_STRUCT_H

typedef struct s_coord
{
	int	x;
	int	y;
}	t_coord;

typedef struct s_img
{
	void	*img;
	int		img_widht;
	int		img_height;
}	t_img;

typedef struct s_hero
{
	int		i;
	int		j;
	int		li;
	int		lj;
	int		h;
	int		w;
	int		pi;
	int		pj;
	void	*wait[6];
	void	*left[6];
	void	*right[6];
	void	*rwait[6];
	void	*hdeath[5];
	int		p;
	int		count;
	int		items;
	int		pv;
	int		state;
	int		move;
}	t_hero;

typedef struct s_skull
{
	int		i;
	int		j;
	int		h;
	int		w;
	int		pi;
	int		pj;
	int		li;
	int		lj;
	void	*wait[6];
	void	*left[6];
	void	*right[6];
	void	*rwait[6];
	void	*death[5];
	void	*rdth[5];
	int		dh;
	int		dw;
	int		p;
	int		cnt;
	int		acount;
	int		state;
	int		move;
}	t_skull;

typedef struct s_exit
{
	t_coord		coord;
}t_exit;

typedef struct s_items
{
	t_img		sprites;
	t_coord		coord;
}	t_items;

typedef struct s_conf
{
	char	**maps;
	t_coord	wsize;
	t_hero	hero;
	t_skull	skull;
	t_items	items1;
	void	*gaov;
	int		goh;
	int		gow;
	void	*exit;
	void	*igrass[4];
	int		gh;
	int		gw;
	void	*iwall;
	int		wh;
	int		ww;
	void	*imenu;
	int		mh;
	int		mw;
	void	*mlx;
	void	*win;
	int		timer;
	int		second;
	int		rtimer;
	int		items;
	int		score;
}	t_conf;

#endif
