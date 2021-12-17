#include "so_long.h"

int ft_strlen(char *str)
{
	int i;

	if(!str)
		return(0);
	i = 0;
	while (str[i])
		i++;
	return (i);
}

int ft_search_n(char *str)
{
	int i;

	if(!str)
		return(0);
	i = 0;
	while(str[i])
	{
		if (str[i] == '\n')
			return (i + 1);
		i++;
	}
	return (0);
}

void ft_strcpy(char *dst, char *src, int size)
{
	dst[size] = '\0';
	while(size > 0)
	{
		*dst = *src;
		dst++;
		src++;
		size--;
	}
}

char *ft_strjoin(char *str1, char *str2)
{
	char *ret;
	int lstr1;
	int lstr2;

	if (!str1)
		lstr1 = 0;
	else 
		lstr1 = ft_strlen(str1);
	if(!str2)
		return(NULL);
	lstr2 = ft_strlen(str2);
	ret = malloc(sizeof(char) * (lstr1 + lstr2 + 1));
	ft_strcpy(ret, str1, lstr1);
	ft_strcpy(ret + lstr1, str2, lstr2);
	ret[lstr1 + lstr2] = '\0';
	free(str1);
	return (ret);
}

void ft_init_struct(t_buff *buff)
{
	buff->position = 0;
	buff->eof = 0;
	buff->line = NULL;
	buff->memory = NULL;
}