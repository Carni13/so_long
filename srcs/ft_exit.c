#include "so_long.h"

void ft_exit(t_conf *conf)
{
    int j;

	j = 0;
	while(j < conf->wsize.y)
	{
		free(conf->maps[j]);
		j++;
	}
	free(conf->maps);
    mlx_destroy_window(conf->mlx, conf->win);
    exit(0);
}
