#include "so_long.h"

int ft_collleft(t_conf *conf)
{
	if(conf->maps[conf->hero.j][conf->hero.i - 1] == '1')
		return (-1);
	return (0);
}

int ft_collright(t_conf *conf)
{
	printf("collright\n");
	if(conf->maps[conf->hero.j][conf->hero.i + 1] == '1')
		return (-1);
	return (0);
}

int ft_colldown(t_conf *conf)
{
	if(conf->maps[conf->hero.j + 1][conf->hero.i] == '1')
		return (-1);
	return (0);
}

int ft_collup(t_conf *conf)
{
	if(conf->maps[conf->hero.j-1][conf->hero.i] == '1')
		return (-1);
	return (0);
}
int ft_hero_coll(t_conf *conf)
{
	int (*f_coll[4])(t_conf *conf);
	f_coll[UP] = ft_collup;
	f_coll[DOWN] = ft_colldown;
	f_coll[LEFT] = ft_collleft;
	f_coll[RIGHT] = ft_collright;
	return(f_coll[conf->hero.move](conf));
}