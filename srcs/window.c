#include "so_long.h"
#include "mega_struct.h"
#include <mlx.h>



void ft_print_maps(t_conf *conf)
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
			if(conf->maps[j][i]== '1')
				mlx_put_image_to_window(conf->mlx, conf->win, conf->iwall, i_size, j_size);
			else if(conf->maps[j][i]== 'E')
				mlx_put_image_to_window(conf->mlx, conf->win, conf->exit, i_size, j_size);
			else
				mlx_put_image_to_window(conf->mlx, conf->win, conf->igrass[3], i_size, j_size);
			if (conf->maps[j][i]== 'i')
				mlx_put_image_to_window(conf->mlx, conf->win, conf->items1.sprites.img, i_size, j_size);
			if (conf->maps[j][i]== 'M')
				mlx_put_image_to_window(conf->mlx, conf->win, conf->imenu, i_size, j_size);
			i_size += SIZE;
			i++;
		}
		i = 0;
		i_size = 0;
		j_size += SIZE;
		j++;
	}
}
void ft_print_game(t_conf *conf)
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
			if(conf->maps[j][i]== 'p')
			{
				mlx_put_image_to_window(conf->mlx, conf->win, conf->hero.wait[0], i_size, j_size);
				conf->hero.pi = i * SIZE;
				conf->hero.pj = j * SIZE;
				conf->hero.i = i;
				conf->hero.j = j;
				conf->hero.li = i;
				conf->hero.lj = j;
			}	
			if (conf->maps[j][i] == 'b')
			{
				mlx_put_image_to_window(conf->mlx, conf->win, conf->skull.wait[0], i_size, j_size);
				conf->skull.pi = i * SIZE;
				conf->skull.pj = j * SIZE;
				conf->skull.i = i;
				conf->skull.j = j;
			}
			i_size += SIZE;
			i++;
		}
		i = 0;
		i_size = 0;
		j_size += SIZE;
		j++;
	}
	
}

void ft_init_window(t_conf *conf)
{
	int lwin;
	int hwin;
	lwin = SIZE * conf->wsize.x;
	hwin = SIZE * conf->wsize.y;
	printf("hwin = %d et lwin = %d\n",hwin,lwin);
	conf->hero.p = RIGHT;
	conf->win = mlx_new_window(conf->mlx, lwin, hwin, "so_long");
	ft_print_maps(conf);
	ft_print_game(conf);
	conf->hero.state = WAIT;
}