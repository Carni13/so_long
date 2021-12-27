#include "so_long.h"



void ft_hero_sprites(t_conf *conf, void *(*f)(void *, char *, int *,int *))
{
	conf->hero.wait[0] = f(conf->mlx, "./sprites/wait1.xpm", &(conf->hero.w), &(conf->hero.h));
	conf->hero.wait[1] = f(conf->mlx, "./sprites/wait2.xpm", &(conf->hero.w), &(conf->hero.h));
	conf->hero.wait[2] = f(conf->mlx, "./sprites/wait3.xpm", &(conf->hero.w), &(conf->hero.h));
	conf->hero.wait[3] = f(conf->mlx, "./sprites/wait4.xpm", &(conf->hero.w), &(conf->hero.h));
	conf->hero.wait[4] = f(conf->mlx, "./sprites/wait5.xpm", &(conf->hero.w), &(conf->hero.h));
	conf->hero.wait[5] = f(conf->mlx, "./sprites/wait6.xpm", &(conf->hero.w), &(conf->hero.h));

	conf->hero.rwait[0] = f(conf->mlx, "./sprites/rwait1.xpm", &(conf->hero.w), &(conf->hero.h));
	conf->hero.rwait[1] = f(conf->mlx, "./sprites/rwait2.xpm", &(conf->hero.w), &(conf->hero.h));
	conf->hero.rwait[2] = f(conf->mlx, "./sprites/rwait3.xpm", &(conf->hero.w), &(conf->hero.h));
	conf->hero.rwait[3] = f(conf->mlx, "./sprites/rwait4.xpm", &(conf->hero.w), &(conf->hero.h));
	conf->hero.rwait[4] = f(conf->mlx, "./sprites/rwait5.xpm", &(conf->hero.w), &(conf->hero.h));
	conf->hero.rwait[5] = f(conf->mlx, "./sprites/rwait6.xpm", &(conf->hero.w), &(conf->hero.h));
	//
	conf->hero.right[0] = f(conf->mlx, "./sprites/walk1.xpm", &(conf->hero.w), &(conf->hero.h));
	conf->hero.right[1] = f(conf->mlx, "./sprites/walk2.xpm", &(conf->hero.w), &(conf->hero.h));
	conf->hero.right[2] = f(conf->mlx, "./sprites/walk3.xpm", &(conf->hero.w), &(conf->hero.h));
	conf->hero.right[3] = f(conf->mlx, "./sprites/walk4.xpm", &(conf->hero.w), &(conf->hero.h));
	conf->hero.right[4] = f(conf->mlx, "./sprites/walk5.xpm", &(conf->hero.w), &(conf->hero.h));
	conf->hero.right[5] = f(conf->mlx, "./sprites/walk6.xpm", &(conf->hero.w), &(conf->hero.h));
	
	conf->hero.left[0] = f(conf->mlx, "./sprites/rwalk1.xpm", &(conf->hero.w), &(conf->hero.h));
	conf->hero.left[1] = f(conf->mlx, "./sprites/rwalk2.xpm", &(conf->hero.w), &(conf->hero.h));
	conf->hero.left[2] = f(conf->mlx, "./sprites/rwalk3.xpm", &(conf->hero.w), &(conf->hero.h));
	conf->hero.left[3] = f(conf->mlx, "./sprites/rwalk4.xpm", &(conf->hero.w), &(conf->hero.h));
	conf->hero.left[4] = f(conf->mlx, "./sprites/rwalk5.xpm", &(conf->hero.w), &(conf->hero.h));
	conf->hero.left[5] = f(conf->mlx, "./sprites/rwalk6.xpm", &(conf->hero.w), &(conf->hero.h));
	printf("chargement des sprites heros ok \n");
}


void ft_maps_sprites(t_conf *conf, void *(*f)(void *, char *, int *,int *))
{
	conf->igrass[0] = f(conf->mlx, "./sprites/grass4.xpm", &(conf->gw), &(conf->gh));
	conf->igrass[1] = f(conf->mlx, "./sprites/grass4.xpm", &(conf->gw), &(conf->gh));
	conf->igrass[2] = f(conf->mlx, "./sprites/grass3.xpm", &(conf->gw), &(conf->gh));
	conf->igrass[3] = f(conf->mlx, "./sprites/grass4.xpm", &(conf->gw), &(conf->gh));
	conf->iwall = f(conf->mlx, "./sprites/wall2.xpm", &(conf->ww), &(conf->wh));
	conf->items1.sprites.img = f(conf->mlx, "./sprites/key.xpm",
	 &(conf->items1.sprites.img_widht), &(conf->items1.sprites.img_height));
	conf->exit = f(conf->mlx, "./sprites/exit.xpm", &(conf->gw), &(conf->gh));

	conf->imenu = f(conf->mlx, "./sprites/menu.xpm", &(conf->mw), &(conf->mh));

	conf->hero.hdeath[0] = f(conf->mlx, "./sprites/hdeath1.xpm", &(conf->hero.w), &(conf->hero.h));
	conf->hero.hdeath[1] = f(conf->mlx, "./sprites/hdeath2.xpm", &(conf->hero.w), &(conf->hero.h));
	conf->hero.hdeath[2] = f(conf->mlx, "./sprites/hdeath2.xpm", &(conf->hero.w), &(conf->hero.h));
	conf->hero.hdeath[3] = f(conf->mlx, "./sprites/hdeath3.xpm", &(conf->hero.w), &(conf->hero.h));
	conf->hero.hdeath[4] = f(conf->mlx, "./sprites/hdeath3.xpm", &(conf->hero.w), &(conf->hero.h));
	conf->gaov = f(conf->mlx, "./sprites/game_over.xpm", &(conf->gow), &(conf->goh));

	printf("chargement des sprites maps ok \n");
}
void ft_skull_sprites(t_conf *conf, void *(*f)(void *, char *, int *,int *))
{
	conf->skull.wait[0] = f(conf->mlx, "./sprites/skullwait1.xpm", &(conf->skull.w), &(conf->skull.h));
	conf->skull.wait[1] = f(conf->mlx, "./sprites/skullwait2.xpm", &(conf->skull.w), &(conf->skull.h));
	conf->skull.wait[2] = f(conf->mlx, "./sprites/skullwait3.xpm", &(conf->skull.w), &(conf->skull.h));
	conf->skull.wait[3] = f(conf->mlx, "./sprites/skullwait4.xpm", &(conf->skull.w), &(conf->skull.h));
	conf->skull.wait[4] = f(conf->mlx, "./sprites/skullwait5.xpm", &(conf->skull.w), &(conf->skull.h));
	conf->skull.wait[5] = f(conf->mlx, "./sprites/skullwait6.xpm", &(conf->skull.w), &(conf->skull.h));

	conf->skull.rwait[0] = f(conf->mlx, "./sprites/rskullwait1.xpm", &(conf->skull.w), &(conf->skull.h));
	conf->skull.rwait[1] = f(conf->mlx, "./sprites/rskullwait2.xpm", &(conf->skull.w), &(conf->skull.h));
	conf->skull.rwait[2] = f(conf->mlx, "./sprites/rskullwait3.xpm", &(conf->skull.w), &(conf->skull.h));
	conf->skull.rwait[3] = f(conf->mlx, "./sprites/rskullwait4.xpm", &(conf->skull.w), &(conf->skull.h));
	conf->skull.rwait[4] = f(conf->mlx, "./sprites/rskullwait5.xpm", &(conf->skull.w), &(conf->skull.h));
	conf->skull.rwait[5] = f(conf->mlx, "./sprites/rskullwait6.xpm", &(conf->skull.w), &(conf->skull.h));

	conf->skull.death[0] = f(conf->mlx, "./sprites/death1.xpm", &(conf->skull.dw), &(conf->skull.dh));
	conf->skull.death[1] = f(conf->mlx, "./sprites/death2.xpm", &(conf->skull.dw), &(conf->skull.dh));
	conf->skull.death[2] = f(conf->mlx, "./sprites/death3.xpm", &(conf->skull.dw), &(conf->skull.dh));
	conf->skull.death[3] = f(conf->mlx, "./sprites/death4.xpm", &(conf->skull.dw), &(conf->skull.dh));
	conf->skull.death[4] = f(conf->mlx, "./sprites/death5.xpm", &(conf->skull.dw), &(conf->skull.dh));
	//
	conf->skull.rdeath[0] = f(conf->mlx, "./sprites/rdeath1.xpm", &(conf->skull.dw), &(conf->skull.dh));
	conf->skull.rdeath[1] = f(conf->mlx, "./sprites/rdeath2.xpm", &(conf->skull.dw), &(conf->skull.dh));
	conf->skull.rdeath[2] = f(conf->mlx, "./sprites/rdeath3.xpm", &(conf->skull.dw), &(conf->skull.dh));
	conf->skull.rdeath[3] = f(conf->mlx, "./sprites/rdeath4.xpm", &(conf->skull.dw), &(conf->skull.dh));
	conf->skull.rdeath[4] = f(conf->mlx, "./sprites/rdeath5.xpm", &(conf->skull.dw), &(conf->skull.dh));
	//
	conf->skull.right[0] = f(conf->mlx, "./sprites/skull1.xpm", &(conf->skull.w), &(conf->skull.h));
	conf->skull.right[1] = f(conf->mlx, "./sprites/skull2.xpm", &(conf->skull.w), &(conf->skull.h));
	conf->skull.right[2] = f(conf->mlx, "./sprites/skull3.xpm", &(conf->skull.w), &(conf->skull.h));
	conf->skull.right[3] = f(conf->mlx, "./sprites/skull4.xpm", &(conf->skull.w), &(conf->skull.h));
	conf->skull.right[4] = f(conf->mlx, "./sprites/skull5.xpm", &(conf->skull.w), &(conf->skull.h));
	conf->skull.right[5] = f(conf->mlx, "./sprites/skull6.xpm", &(conf->skull.w), &(conf->skull.h));
	
	conf->skull.left[0] = f(conf->mlx, "./sprites/rskull1.xpm", &(conf->skull.w), &(conf->skull.h));
	conf->skull.left[1] = f(conf->mlx, "./sprites/rskull2.xpm", &(conf->skull.w), &(conf->skull.h));
	conf->skull.left[2] = f(conf->mlx, "./sprites/rskull3.xpm", &(conf->skull.w), &(conf->skull.h));
	conf->skull.left[3] = f(conf->mlx, "./sprites/rskull4.xpm", &(conf->skull.w), &(conf->skull.h));
	conf->skull.left[4] = f(conf->mlx, "./sprites/rskull5.xpm", &(conf->skull.w), &(conf->skull.h));
	conf->skull.left[5] = f(conf->mlx, "./sprites/rskull6.xpm", &(conf->skull.w), &(conf->skull.h));
	printf("chargement des sprites skull ok \n");
}

void ft_init_conf(t_conf *conf)
{
	conf->maps = NULL;
	ft_hero_sprites(conf, &mlx_xpm_file_to_image);
	ft_maps_sprites(conf, &mlx_xpm_file_to_image);
	ft_skull_sprites(conf, &mlx_xpm_file_to_image);
	conf->timer = 0;
	conf->second = 0;
	conf->hero.items = 0;
	conf->skull.move = RIGHT;
	conf->skull.p = RIGHT;
	conf->skull.count = 0;
	conf->skull.state = WAIT;
	conf->rtimer = 0;
	conf->skull.acount = 0;
	conf->hero.pv = 3;

}