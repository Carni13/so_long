#include "so_long.h"
#include "mega_struct.h"
#include <mlx.h>

int ft_open_sprites(t_conf *conf)
{
	conf->iwall.img= mlx_xpm_file_to_image(conf->mlx, conf->wall, &(conf->iwall.img_widht), &(conf->iwall.img_height));
	conf->igrass.img= mlx_xpm_file_to_image(conf->mlx, conf->grass, &(conf->igrass.img_widht), &(conf->igrass.img_height));
	if (conf->igrass.img_height != conf->iwall.img_height)
		return (-1);
	if (conf->igrass.img_widht != conf->igrass.img_widht)
		return(-1);
	return (0);
}

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
			if(conf->maps[j][i]== '0')
				mlx_put_image_to_window(conf->mlx, conf->win, conf->igrass.img, i_size, j_size);
			else
				mlx_put_image_to_window(conf->mlx, conf->win, conf->iwall.img, i_size, j_size);
			i_size += 16;
			i++;
		}
		i = 0;
		i_size = 0;
		j_size += 16;
		j++;
	}
}

void ft_init_window(t_conf *conf)
{
	int lwin;
	int hwin;
	conf->wall = "./sprites/wall2.xpm";
	conf->grass = "./sprites/grass.xpm";

	ft_open_sprites(conf);

	lwin = conf->igrass.img_widht * conf->wsize.x;
	hwin = conf->igrass.img_height * conf->wsize.y;
	printf("hwin = %d et lwin = %d\n",hwin,lwin);
	conf->win = mlx_new_window(conf->mlx, lwin, hwin, "so_long");
	ft_print_maps(conf);
}

//i = ((b = 2) ,5)