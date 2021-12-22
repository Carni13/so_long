#include "so_long.h"

void ft_ai_skull(t_conf *conf)
{
	void (*f_walk[4])(t_conf *conf);
	f_walk[UP] = ft_walkup_skull;
	f_walk[DOWN] = ft_walkdown_skull;
	f_walk[LEFT] = ft_walkleft_skull;
	f_walk[RIGHT] = ft_walkright_skull;
	if(conf->timer%3 == 0 && conf->second == 0)
		conf->skull.move = clock()%4;
	if(ft_skull_coll(conf) == -1)
		return ;
	if(conf->skull.count == 6)
		conf->skull.count = 0;
	f_walk[conf->skull.move](conf);
		return ;
}

