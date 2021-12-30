#include "so_long.h"

void ft_time(t_conf *conf)
{
    int i;

    i = 0;
    while(i < 20000)
        i++;
    conf->second++;
	if(conf->second == 6)
	{
		conf->timer++;
		conf->second = 0;
	}
	if(conf->timer == 6)
	{
		conf->rtimer++;
		conf->timer = 0;	
	}
}
