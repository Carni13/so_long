#include "so_long.h"

void ft_move_other(t_conf *conf)
{
	int i;
	int j;
	int i_size;
	int j_size;

	i = 0;
	j = 0;
	i_size = 0;
	j_size = 0;
	while( conf->wsize.y > j)
	{
		while(conf->wsize.x > i)
		{
			if (conf->maps[j][i] == 'I')
				mlx_put_image_to_window(conf->mlx, conf->win,
					conf->items1.sprites.img, i_size, j_size);
			i_size += SIZE;
			i++;
		}
		i = 0;
		i_size = 0;
		j_size += SIZE;
		j++;
	}
}

void ft_walkright(t_conf *conf)
{
	conf->hero.pi += SIZE/6;
	mlx_put_image_to_window(conf->mlx, conf->win,
			conf->hero.right[conf->hero.count],conf->hero.pi, conf->hero.pj);
	conf->hero.count++;
	if (conf->hero.count == 6)
	{
		conf->score++;
		if(BONUS == 0)
			printf("%d\n",conf->score);
		conf->hero.state = WAIT;
		conf->maps[conf->hero.j][conf->hero.i + 1 ] = 'P';
		conf->maps[conf->hero.j][conf->hero.i] = '0';
		conf->hero.i += 1;
		conf->hero.pi = conf->hero.i * SIZE;

	}
}

void ft_walkleft(t_conf *conf)
{
	conf->hero.pi -= SIZE/6;	
	mlx_put_image_to_window(conf->mlx, conf->win,
		conf->hero.left[conf->hero.count],conf->hero.pi, conf->hero.pj);
	conf->hero.count++;
	if (conf->hero.count == 6)
	{
		conf->score++;
		if(BONUS == 0)
			printf("%d\n",conf->score);
		conf->hero.state = WAIT;
		conf->maps[conf->hero.j][conf->hero.i - 1 ] = 'P';
		conf->maps[conf->hero.j][conf->hero.i] = '0';
		conf->hero.i -= 1;
		conf->hero.pi = conf->hero.i * SIZE;
	}
}
void ft_walkup(t_conf *conf)
{
	conf->hero.pj -= SIZE/6;
	if (conf->hero.p == RIGHT)
		mlx_put_image_to_window(conf->mlx, conf->win,
				conf->hero.right[conf->hero.count],conf->hero.pi, conf->hero.pj);
	else
		mlx_put_image_to_window(conf->mlx, conf->win,
				conf->hero.left[conf->hero.count],conf->hero.pi, conf->hero.pj);
	conf->hero.count++;
	if (conf->hero.count == 6)
	{
		conf->score++;
		if(BONUS == 0)
			printf("%d\n",conf->score);
		conf->hero.state = WAIT;
		conf->maps[conf->hero.j - 1][conf->hero.i] = 'P';
		conf->maps[conf->hero.j][conf->hero.i] = '0';
		conf->hero.j -= 1;
		conf->hero.pj = conf->hero.j * SIZE;
	}
}

void ft_walkdown(t_conf *conf)
{
	conf->hero.pj += SIZE/6;
	if (conf->hero.p == RIGHT)
		mlx_put_image_to_window(conf->mlx, conf->win,
			conf->hero.right[conf->hero.count],conf->hero.pi, conf->hero.pj);
	else
		mlx_put_image_to_window(conf->mlx, conf->win,
			conf->hero.left[conf->hero.count],conf->hero.pi, conf->hero.pj);
	conf->hero.count++;
	if (conf->hero.count == 6)
	{
		conf->score++;
		if(BONUS == 0)
			printf("%d\n",conf->score);
		conf->hero.state = WAIT;
		conf->maps[conf->hero.j + 1][conf->hero.i] = 'P';
		conf->maps[conf->hero.j][conf->hero.i] = '0';
		conf->hero.j += 1;
		conf->hero.pj = conf->hero.j * SIZE;
	}
}

