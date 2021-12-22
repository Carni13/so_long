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
	int i;
	int j;
	int h;
	int w;
	void *wait[6];
	void *left[6];
	void *right[6];
	int items;
	int pv;
} t_hero;

typedef struct s_badguy
{
	t_img sprite1;
	t_img sprite2;
	char *path1;
	char *path2;
	char *move;
	t_coord position;
} t_badguy;

typedef struct s_exit
{
	t_coord coord;
}t_exit;

typedef struct s_items
{
	t_img sprites;
	t_coord coord;
} t_items;

typedef struct s_conf
{
	char **maps;
	t_coord wsize;
	t_hero hero;
	t_badguy badguy;
	t_items items1;
	t_items items2;
	t_items items3;
	t_exit exit;
	void *igrass[4];
	int gh;
	int gw;
	void *iwall;
	int wh;
	int ww;
	void *mlx;
	void *win;
	int timer;
	int second;	
} t_conf;

#endif
