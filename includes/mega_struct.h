#ifndef MEGA_STRUCT_H
# define MEGA_STRUCT_H

typedef struct s_coord
{
	int x;
	int y;
} t_coord;

typedef struct s_img
{
	void *img;
	int img_widht;
	int img_height;
} t_img;

typedef struct s_hero
{
	t_img sprite1;
	t_img sprite2;
	t_coord position;
	int items;
	int pv;
} t_hero;

typedef struct s_badbuy
{
	t_img sprite1;
	t_img sprite2;
	char *path;
	t_coord position;
} t_badguy;

typedef struct s_exit
{
	t_coord coord;
}t_exit;

typedef struct s_items
{
	t_coord coord;
} t_items;

typedef struct s_conf
{
	char **maps;
	t_coord wsize;
	t_hero hero;
	t_badguy badbuy;
	t_items items1;
	t_items items2;
	t_items items3;
	t_exit exit;
	char *wall;
	t_img iwall;
	char *grass;
	t_img igrass;
	void *mlx;
	void *win;
} t_conf;

#endif
