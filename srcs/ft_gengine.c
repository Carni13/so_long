#include  "so_long.h"


void ft_wait(t_conf *conf)
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
			if(conf->maps[j][i]== 'P')
			{
				if (conf->hero.p == LEFT)
					mlx_put_image_to_window(conf->mlx, conf->win, conf->hero.rwait[conf->second], i_size, j_size);
				else
					mlx_put_image_to_window(conf->mlx, conf->win, conf->hero.wait[conf->second], i_size, j_size);
			}
			if (conf->maps[j][i] == 'I')
				mlx_put_image_to_window(conf->mlx, conf->win, conf->items1.sprites.img, i_size, j_size);
			//if (conf->maps[j][i] == 'b')
				//mlx_put_image_to_window(conf->mlx, conf->win, conf->skull.wait[conf->second], i_size, j_size);
			i_size += SIZE;
			i++;
		}
		i = 0;
		i_size = 0;
		j_size += SIZE;
		j++;
	}
}

void ft_print_score(t_conf *conf)
{
	if (conf->wsize.x < (SIZE * 15))
	{
		mlx_string_put(conf->mlx, conf->win, (SIZE * 1), (SIZE/2), 0xFFFFFFFF, ft_itoa(conf->score));
		return;
	}
	mlx_string_put(conf->mlx, conf->win, (SIZE), (SIZE/2), 0xFFFFFFFF, "items =");
	mlx_string_put(conf->mlx, conf->win, (SIZE * 4), (SIZE/2), 0xFFFFFFFF, ft_itoa(conf->hero.items/6));
	mlx_string_put(conf->mlx, conf->win, (SIZE * 5), (SIZE/2), 0xFFFFFFFF, "timers =");
	mlx_string_put(conf->mlx, conf->win, (SIZE * 8), (SIZE/2), 0xFFFFFFFF, ft_itoa(conf->rtimer));
	mlx_string_put(conf->mlx, conf->win, (SIZE * 9), (SIZE/2), 0xFFFFFFFF, "pv =");
	mlx_string_put(conf->mlx, conf->win, (SIZE * 11), (SIZE/2), 0xFFFFFFFF, ft_itoa(conf->hero.pv));
	mlx_string_put(conf->mlx, conf->win, (SIZE * 12), (SIZE/2), 0xFFFFFFFF, "score =");
	mlx_string_put(conf->mlx, conf->win, (SIZE * 15), (SIZE/2), 0xFFFFFFFF, ft_itoa(conf->score));
}

	
void ft_animate(t_conf *conf)
{
    void (*f_walk[4])(t_conf *conf);

	f_walk[UP] = ft_walkup;
	f_walk[DOWN] = ft_walkdown;
	f_walk[LEFT] = ft_walkleft;
	f_walk[RIGHT] = ft_walkright;
    ft_print_maps(conf);
	ft_print_score(conf);
	//ft_ai_skull(conf);
	//if(conf->hero.move == DEATH)
		//return (0);
	if (conf->hero.state == MOVE)
	{
		if(ft_hero_coll(conf) == -1)
		{
			conf->hero.state = WAIT;
			return (0);
		}
		f_walk[conf->hero.move](conf);
		return(0);
	}
	if(conf->hero.items == -100)
        ft_exit(conf);
	ft_wait(conf);
}

int ft_game(t_conf *conf)
{
	
	//if(conf->hero.move == DEATH)
	//{
	//	ft_death(conf);
		//return (0);
	//}
	mlx_hook(conf->win, 2, 1L<<0, &ft_hooking, conf);
    ft_time(conf);
	mlx_clear_window(conf->mlx, conf->win);
	ft_animate(conf);
	return(0);
}