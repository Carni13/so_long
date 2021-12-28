#include "so_long.h"
/*
void ft_move_other_skull(t_conf *conf)
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
			if (conf->maps[j][i] == 'i')
				mlx_put_image_to_window(conf->mlx, conf->win, conf->items1.sprites.img, i_size, j_size);
			i_size += SIZE;
			i++;
		}
		i = 0;
		i_size = 0;
		j_size += SIZE;
		j++;
	}
}
*/
void ft_walkright_skull(t_conf *conf)
{
	//printf("right\n");
	conf->skull.pi += SIZE/6;
	//mlx_clear_window(conf->mlx, conf->win);
	//ft_print_maps(conf);
//	ft_move_other_skull(conf);
	conf->skull.p = RIGHT;
	mlx_put_image_to_window(conf->mlx, conf->win, conf->skull.right[conf->skull.count],conf->skull.pi, conf->skull.pj);
	conf->skull.count++;

	if (conf->skull.count == 6)
	{
		conf->maps[conf->skull.j][conf->skull.i + 1 ] = 'b';
		conf->maps[conf->skull.j][conf->skull.i] = '0';
		conf->skull.i += 1;
		conf->skull.pi = conf->skull.i * SIZE;

	}
}

void ft_walkleft_skull(t_conf *conf)
{
	//printf("left\n");
	conf->skull.pi -= SIZE/6;
	//mlx_clear_window(conf->mlx, conf->win);
	//ft_print_maps(conf);
	//ft_move_other_skull(conf);
	conf->skull.p = LEFT;
	mlx_put_image_to_window(conf->mlx, conf->win, conf->skull.left[conf->skull.count],conf->skull.pi, conf->skull.pj);
	conf->skull.count++;
	if (conf->skull.count == 6)
	{
		conf->maps[conf->skull.j][conf->skull.i - 1 ] = 'b';
		conf->maps[conf->skull.j][conf->skull.i] = '0';
		conf->skull.i -= 1;
		conf->skull.pi = conf->skull.i * SIZE;
	}
}
void ft_walkup_skull(t_conf *conf)
{
	//printf("left\n");
	conf->skull.pj -= SIZE/6;
	//mlx_clear_window(conf->mlx, conf->win);
	//ft_print_maps(conf);
	//ft_move_other_skull(conf);
	if (conf->skull.p == RIGHT)
		mlx_put_image_to_window(conf->mlx, conf->win, conf->skull.right[conf->skull.count],conf->skull.pi, conf->skull.pj);
	else
		mlx_put_image_to_window(conf->mlx, conf->win, conf->skull.left[conf->skull.count],conf->skull.pi, conf->skull.pj);
	conf->skull.count++;

	if (conf->skull.count == 6)
	{
		conf->maps[conf->skull.j - 1][conf->skull.i] = 'b';
		conf->maps[conf->skull.j][conf->skull.i] = '0';
		conf->skull.j -= 1;
		conf->skull.pj = conf->skull.j * SIZE;
	}
}

void ft_walkdown_skull(t_conf *conf)
{
	//printf("left\n");
	conf->skull.pj += SIZE/6;
	//mlx_clear_window(conf->mlx, conf->win);
	//ft_print_maps(conf);
	//ft_move_other(conf);
	if (conf->skull.p == RIGHT)
		mlx_put_image_to_window(conf->mlx, conf->win, conf->skull.right[conf->skull.count],conf->skull.pi, conf->skull.pj);
	else
		mlx_put_image_to_window(conf->mlx, conf->win, conf->skull.left[conf->skull.count],conf->skull.pi, conf->skull.pj);
	conf->skull.count++;
	if (conf->skull.count == 6)
	{
		conf->maps[conf->skull.j + 1][conf->skull.i] = 'b';
		conf->maps[conf->skull.j][conf->skull.i] = '0';
		conf->skull.j += 1;
		conf->skull.pj = conf->skull.j * SIZE;
	}
}

