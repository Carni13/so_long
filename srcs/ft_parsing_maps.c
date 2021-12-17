#include "so_long.h"
#include "mega_struct.h"
#include <fcntl.h>

char **ft_parsing_maps(char *files)
{
	int fd;
	int i;
	i = 0;
	char **ret_maps;
	fd = open(files, 0);
	ret_maps = malloc(sizeof(char *) * (4));

	while(ret_maps != NULL && i < 4)
	{
		ret_maps[i] = get_next_line(fd);
		i++;
	}
	return(ret_maps);
}



