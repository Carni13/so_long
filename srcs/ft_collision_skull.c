#include "so_long.h"

int ft_collleft_skull(t_conf *conf)
{
	if(conf->maps[conf->skull.j][conf->skull.i - 1] == '1'
	||conf->maps[conf->skull.j][conf->skull.i - 1] == 'E')
	{
		//conf->skull.state = WAIT;
		conf->skull.move = UP;
		return (-1);
	}
	if(conf->maps[conf->skull.j][conf->skull.i - 1] == 'i')
	{
		//conf->skull.state = WAIT;
		conf->skull.move = UP;
		return (-1);
	}
	return (0);
}

int ft_collright_skull(t_conf *conf)
{
	if(conf->maps[conf->skull.j][conf->skull.i + 1] == '1'
	||conf->maps[conf->skull.j][conf->skull.i + 1] == 'E')
	{
		//conf->skull.state = WAIT;
		conf->skull.move = DOWN;
		return (-1);
	}
	if(conf->maps[conf->skull.j][conf->skull.i + 1] == 'i')
	{
		//conf->skull.state = WAIT;
		conf->skull.move = DOWN;
		return (-1);
	}		
	return (0);
}

int ft_colldown_skull(t_conf *conf)
{
	if(conf->maps[conf->skull.j + 1][conf->skull.i] == '1'
		|| conf->maps[conf->skull.j + 1][conf->skull.i] == 'E'
		|| conf->maps[conf->skull.j + 1][conf->skull.i] == 'p')
	{
		//conf->skull.state = WAIT;
		conf->skull.move = LEFT;
		return (-1);
	}
	if(conf->maps[conf->skull.j + 1][conf->skull.i] == 'i')
	{
		//conf->skull.state = WAIT;
		conf->skull.move = LEFT;
		return (-1);
	}
	return (0);
}

int ft_collup_skull(t_conf *conf)
{
	if(conf->maps[conf->skull.j-1][conf->skull.i] == '1'
	|| conf->maps[conf->skull.j -1][conf->skull.i] == 'E'
	|| conf->maps[conf->skull.j + 1][conf->skull.i] == 'p')
	{
		//conf->skull.state = WAIT;
		conf->skull.move = RIGHT;
		return (-1);
	}
	if(conf->maps[conf->skull.j-1][conf->skull.i] == 'i')
	{
		//conf->skull.state = WAIT;
		conf->skull.move = RIGHT;
		return (-1);
	}
	return (0);
}
int ft_skull_coll(t_conf *conf)
{
	int (*f_coll[4])(t_conf *conf);
	f_coll[UP] = ft_collup_skull;
	f_coll[DOWN] = ft_colldown_skull;
	f_coll[LEFT] = ft_collleft_skull;
	f_coll[RIGHT] = ft_collright_skull;
	return(f_coll[conf->skull.move](conf));
}