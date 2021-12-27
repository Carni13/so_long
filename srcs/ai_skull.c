#include "so_long.h"

void ft_skull_wait(t_conf *conf)
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
			if(conf->maps[j][i]== 'b')
			{
				if (conf->skull.p == LEFT)
					mlx_put_image_to_window(conf->mlx, conf->win, conf->skull.rwait[conf->skull.count], i_size, j_size);
				else
					mlx_put_image_to_window(conf->mlx, conf->win, conf->skull.wait[conf->skull.count], i_size, j_size);
			}
			i_size += SIZE;
			i++;
		}
		i = 0;
		i_size = 0;
		j_size += SIZE;
		j++;
	}
	conf->skull.count++;
}

void ft_death(t_conf *conf)
{
	mlx_clear_window(conf->mlx, conf->win);
	ft_print_maps(conf);
	conf->skull.count ++;
	usleep(100000/6);
	if(conf->skull.p == LEFT)
		mlx_put_image_to_window(conf->mlx, conf->win, conf->skull.rdeath[conf->skull.count],conf->skull.pi, conf->skull.pj);
	else
		mlx_put_image_to_window(conf->mlx, conf->win, conf->skull.death[conf->skull.count],conf->skull.pi, conf->skull.pj);
	mlx_put_image_to_window(conf->mlx, conf->win, conf->hero.hdeath[conf->skull.count], conf->hero.pi, conf->hero.pj);
	if(conf->hero.pv == 0)
		mlx_put_image_to_window(conf->mlx, conf->win, conf->gaov, conf->gow, conf->goh);
	if(conf->skull.count == 4 && conf->hero.pv == 0)
	{
		sleep(3);
		mlx_clear_window(conf->mlx,conf->win);
		mlx_destroy_window(conf->mlx, conf->win);
		exit(0);
	}
	if(conf->skull.count == 4)
	{
		conf->skull.count = 0;
		conf->hero.move = WAIT;
		conf->maps[conf->hero.j][conf->hero.i] = '0';
		conf->hero.i = conf->hero.li;
		conf->hero.j = conf->hero.lj;
		conf->maps[conf->hero.j][conf->hero.i] = 'p';
		conf->hero.pj = conf->hero.j * SIZE;
		conf->hero.pi = conf->hero.i * SIZE;
	}
}
int check_hero(t_conf *conf)
{
	int i;
	int j;
	i = conf->skull.i;
	j = conf->skull.j;
	if(conf->skull.p == LEFT)
	{
		if(conf->maps[j - 1][i - 1] == 'p'
			|| conf->maps[j][i - 1] == 'p'
			|| conf->maps[j][i] == 'p')
				return(-1);
	}
	if(conf->skull.p == RIGHT)
	{
		if( conf->maps[j - 1][i + 1] == 'p'
			|| conf->maps[j][i + 1] == 'p'
			|| conf->maps[j][i] == 'p')
			return(-1);
	}
	return (0);
}
void ft_ai_skull(t_conf *conf)
{
	void (*f_walk[4])(t_conf *conf);
	f_walk[UP] = ft_walkup_skull;
	f_walk[DOWN] = ft_walkdown_skull;
	f_walk[LEFT] = ft_walkleft_skull;
	f_walk[RIGHT] = ft_walkright_skull;
	printf("skull acount = %d\n",conf->skull.acount);
	if(conf->skull.acount == 8)
	{
		if(conf->skull.state == WAIT)
		{
			conf->skull.move = clock()%4;
			conf->skull.state = MOVE;
		}
		else
			conf->skull.state = WAIT;
		conf->skull.acount = 0;
	}
	if(ft_skull_coll(conf) == -1)
		return ;
	if(conf->skull.count == 6)
	{
		conf->skull.acount++;
		conf->skull.count = 0;
	}
	if(check_hero(conf)== -1)
	{
		conf->hero.move = DEATH;
		conf->hero.pv--;
			return;
	}
	if (conf->skull.state == WAIT)
		ft_skull_wait(conf);
	else
		f_walk[conf->skull.move](conf);
	return ;
}

