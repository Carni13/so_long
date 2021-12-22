#include "so_long.h"

void ft_move_hero(t_conf *conf)
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
				mlx_put_image_to_window(conf->mlx, conf->win, conf->hero.wait, i_size, j_size);
				conf->hero.i = i;
				conf->hero.j = j;
			}
			if (conf->maps[j][i] == 'i')
				mlx_put_image_to_window(conf->mlx, conf->win, conf->items1.sprites.img, i_size, j_size);
			if (conf->maps[j][i] == 'b')
				mlx_put_image_to_window(conf->mlx, conf->win, conf->badguy.sprite1.img, i_size, j_size);
			i_size += 32;
			i++;
		}
		i = 0;
		i_size = 0;
		j_size += 32;
		j++;
	}
	
}