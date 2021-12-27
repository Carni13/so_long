#include "so_long.h"

int ft_collleft(t_conf *conf)
{
	//printf("maps items = %c\n",conf->maps[conf->hero.j][conf->hero.i - 1]);
	if(conf->maps[conf->hero.j][conf->hero.i - 1] == '1'
	|| conf->maps[conf->hero.j][conf->hero.i - 1] == 'b')
		return (-1);
	if(conf->maps[conf->hero.j][conf->hero.i - 1] == 'i')
	{
		conf->hero.items++;
		//printf("items = %d\n",conf->hero.items);
		return (0);
	}
	if(conf->maps[conf->hero.j][conf->hero.i - 1] == 'E')
	{
		if (conf->hero.items == 18)
		{
			conf->hero.items = 100;
			return (0);
		}
		return (-1);		
	}
	return (0);
}

int ft_collright(t_conf *conf)
{
	//printf("maps items = %c\n",conf->maps[conf->hero.j][conf->hero.i + 1]);
	if(conf->maps[conf->hero.j][conf->hero.i + 1] == '1'
	|| conf->maps[conf->hero.j][conf->hero.i + 1] == 'b')
		return (-1);
	if(conf->maps[conf->hero.j][conf->hero.i + 1] == 'i')
	{
		conf->hero.items++;
		//printf("items = %d\n",conf->hero.items);
		return (0);
	}
	if(conf->maps[conf->hero.j][conf->hero.i + 1] == 'E')
	{
		if (conf->hero.items == 18)
		{
			conf->hero.items = 100;
			return (0);
		}
		return (-1);		
	}
	return (0);
}

int ft_colldown(t_conf *conf)
{
	//printf("maps items = %c\n",conf->maps[conf->hero.j+1][conf->hero.i]);
	if(conf->maps[conf->hero.j + 1][conf->hero.i] == '1'
	|| conf->maps[conf->hero.j + 1][conf->hero.i] == 'b')
		return (-1);
	if(conf->maps[conf->hero.j + 1][conf->hero.i] == 'i')
	{
		conf->hero.items++;
		//printf("items = %d\n",conf->hero.items);
		return (0);
	}
	if(conf->maps[conf->hero.j + 1][conf->hero.i] == 'E')
	{
		if (conf->hero.items == 18)
		{
			conf->hero.items = 100;
			return (0);
		}
		return (-1);		
	}
	return (0);
}

int ft_collup(t_conf *conf)
{
	//printf("maps items = %c\n",conf->maps[conf->hero.j-1][conf->hero.i]);
	if(conf->maps[conf->hero.j-1][conf->hero.i] == '1'
	|| conf->maps[conf->hero.j - 1][conf->hero.i] == 'b')
		return (-1);
	if(conf->maps[conf->hero.j-1][conf->hero.i] == 'i')
	{
		conf->hero.items++;
		//printf("items = %d\n",conf->hero.items);
		return (0);
	}
	if(conf->maps[conf->hero.j-1][conf->hero.i] == 'E')
	{
		if (conf->hero.items == 18)
		{
			conf->hero.items = 100;
			return (0);
		}
		return (-1);		
	}
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