#include "so_long.h"

void ft_error(char *str,t_conf *conf)
{
	int j;

	j = 0;
	while(j < conf->wsize.y)
	{
		free(conf->maps[j]);
		j++;
	}
	free(conf->maps);
	perror("error\n");
	perror(str);
	exit(0);
}


void ft_create_scoring(t_conf *conf)
{
	char	**new_maps;
	char *score_bar;
	int i;
	int j;

	i = 0;
	j = 0;
	score_bar = malloc(sizeof(char) * conf->wsize.x + 1);
	new_maps = malloc(sizeof(char *) * (conf->wsize.y + 2));
	conf->wsize.y++;
	while (conf->wsize.x > i)
	{
		score_bar[i] = 'M';
		i++;
	}
	score_bar[i] = '\0';
	new_maps[j] = score_bar;
	j++;
	while(conf->wsize.y > j)
	{
		new_maps[j] = conf->maps[j - 1];
		j++;
	}
	new_maps[j] = NULL;
	conf->maps = new_maps;
}
