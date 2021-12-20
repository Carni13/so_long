#include "so_long.h"
#include "mega_struct.h"
#include <fcntl.h>

char **ft_parsing_maps(char *files,t_conf *conf)
{
	int fd;
	int r;
	char buffer[BUFFER_SIZE];
	fd = open(files, 0);
	r = read(fd,buffer,BUFFER_SIZE);
	buffer[r] = '\0';
	conf->maps = ft_split(buffer, '\n');
	conf->wsize.y = 0;
	conf->wsize.x = 0;
	conf->wsize.x = ft_strlen(conf->maps[conf->wsize.y]);
	while(conf->maps[conf->wsize.y])
		conf->wsize.y++;
	close(fd);
	return(conf->maps);
}



