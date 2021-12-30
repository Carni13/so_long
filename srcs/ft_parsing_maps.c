#include "so_long.h"

void ft_check_name(char *files)
{
	int i;

	i = 0;
	while(files[i])
		i++;
	while(i >= 0)
	{
		if(files[i] == '.')
			break;
		i--;
	}
	if(ft_strncmp(files + i, ".ber", 4) != 0)
	{
		perror("Incorrect maps name\n");
		exit(1);
	}
}
char	**ft_parsing_maps(char *files,t_conf *conf)
{
	int		fd;
	int		r;
	char	buffer[BUFFER_SIZE];
	
	ft_check_name(files);
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



