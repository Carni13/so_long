/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_gengine.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jremy <jremy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/30 13:14:10 by jremy             #+#    #+#             */
/*   Updated: 2022/01/05 09:17:37 by jremy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include  "so_long.h"

void	ft_wait2(t_conf *conf, int i, int j)
{
	if (conf->maps[j][i] == 'P')
	{
		if (conf->hero.p == LEFT)
			mlx_put_image_to_window(conf->mlx, conf->win,
				conf->hero.rwait[conf->second], i * SIZE, j * SIZE);
		else
			mlx_put_image_to_window(conf->mlx, conf->win,
				conf->hero.wait[conf->second], i * SIZE, j * SIZE);
	}
	if (conf->maps[j][i] == 'C')
		mlx_put_image_to_window(conf->mlx, conf->win,
			conf->items1.sprites.img, i * SIZE, j * SIZE);
}

void	ft_wait(t_conf *conf)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (conf->wsize.y > j)
	{
		while (conf->wsize.x > i)
		{
			ft_wait2(conf, i, j);
			i++;
		}
		i = 0;
		j++;
	}
}

void	ft_print_score(t_conf *conf)
{
	char			*tmp;
	unsigned int	c;

	c = 0xFFFFFFFF;
	tmp = ft_itoa(conf->score);
	if (conf->wsize.x < 16)
	{
		mlx_string_put(conf->mlx, conf->win, (SIZE * 1),
			(SIZE / 2), c, tmp);
		free(tmp);
		return ;
	}
	mlx_string_put(conf->mlx, conf->win, (SIZE * 8), (SIZE / 2), c, "score =");
	mlx_string_put(conf->mlx, conf->win, (SIZE * 11), (SIZE / 2), c, tmp);
	free(tmp);
	tmp = ft_itoa(conf->hero.items / 6);
	mlx_string_put(conf->mlx, conf->win, (SIZE), (SIZE / 2), c, "items:");
	mlx_string_put(conf->mlx, conf->win,
		(SIZE * 4), (SIZE / 2), 0xFFFFFFFF, tmp);
	free(tmp);
	mlx_string_put(conf->mlx, conf->win, (SIZE * 5), (SIZE / 2), c, "pv:");
	tmp = ft_itoa(conf->hero.pv);
	mlx_string_put(conf->mlx, conf->win, (SIZE * 7), (SIZE / 2), c, tmp);
	free(tmp);
}

void	ft_animate(t_conf *conf)
{
	void	(*f_walk[4])(t_conf *conf);

	f_walk[UP] = ft_walkup;
	f_walk[DOWN] = ft_walkdown;
	f_walk[LEFT] = ft_walkleft;
	f_walk[RIGHT] = ft_walkright;
	ft_print_maps(conf);
	if (BONUS == 1)
		ft_print_score(conf);
	if (conf->hero.state == MOVE)
	{
		if (ft_hero_coll(conf) == -1)
		{
			conf->hero.state = WAIT;
			conf->hero.count = 0;
			return ;
		}
		f_walk[conf->hero.move](conf);
		return ;
	}
	if (conf->hero.items < 0)
		ft_exit(conf, 0);
	ft_wait(conf);
}

int	ft_game(t_conf *conf)
{
	mlx_hook(conf->win, 2, 1L << 0, &ft_hooking, conf);
	ft_time(conf);
	mlx_clear_window(conf->mlx, conf->win);
	ft_animate(conf);
	return (0);
}
