#include "so_long.h"

void ft_save_line(t_buff *buff)
{
	char *ret;
	int size;
	int i;
	if (buff->eof == 1 && ft_search_n(buff->memory) == 0)
		size = ft_strlen(buff->memory);
	else
		size = buff->position;
	ret = malloc(sizeof(char) * (size + 1));
	i = 0;
	while( i < size && buff->memory[i])
	{
		ret[i] = buff->memory[i];
		i++;
	}
	ret[i]='\0';
	buff->line = ret;
}

void ft_save_memory(t_buff *buff)
{
	char *ret;
	int size;

	if (buff->eof == 1 && ft_search_n(buff->memory) == 0)
	{
		free(buff->memory);
		buff->memory = NULL;
		return ;
	}
	size = ft_strlen(buff->memory) - buff->position;
	ret = malloc(sizeof(char) * (size + 1));
	ft_strcpy(ret, buff->memory + buff->position,size);
	ret[size]='\0';
	free(buff->memory);
	buff->memory = ft_strjoin(NULL,ret);
	free(ret);

}



char *ft_read(int fd, t_buff *buff)
{
	char buffer[BUFFER_SIZE + 1];
	int r;

	r = 1;
	buff->position = ft_search_n(buff->memory);
	while (buff->position == 0 && r > 0)
	{
		r = read(fd,buffer,BUFFER_SIZE);
		if (r <= 0)
		{
			buff->eof = 1;
			break;
		}
		buffer[r] = '\0';
		buff->memory = ft_strjoin(buff->memory, buffer);
		buff->position = ft_search_n(buff->memory);
	}
	ft_save_line(buff);
	ft_save_memory(buff);
	return (buff->memory);
}

char *get_next_line(int fd)
{
	static char save_memory[BUFFER_SIZE + 1];
	t_buff buff;

	if(fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	ft_init_struct(&buff);
	buff.memory = ft_strjoin(NULL,save_memory); // !!
	ft_strcpy(save_memory,ft_read(fd,&buff),ft_strlen(buff.memory));
	free(buff.memory);
	if (ft_strlen(save_memory) <= 0 && ft_strlen(buff.line) <= 0)
	{
		free(buff.line);
		return(NULL);
	}
	return (buff.line);
}
