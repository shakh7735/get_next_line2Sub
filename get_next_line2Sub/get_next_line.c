#include "get_next_line.h"

char *get_next_line(int fd)
{
	static char	*str_st[MAX_OPEN_F];
	char	*line;
	int 	index;
    
	if (fd < 0 || fd > MAX_OPEN_F || BUFFER_SIZE <= 0)
		return (NULL);
    str_st[fd] = get_read(fd, str_st);
    if (!str_st[fd])
        return (NULL);
if (!str_st[fd])
        return (NULL);	
index = ft_strchr_n(str_st[fd],'\n');
	if (index < 0)
	{
	    line = ft_substr(str_st[fd], 0,ft_strlen(str_st[fd]));
		free (str_st[fd]);
	}
	else
	{
	    line = ft_substr(str_st[fd], 0,index + 1);
		str_st[fd] = get_new_static(str_st[fd], index);
	}
	return (line);
}

char    *get_new_static(char *old_str, int index)
{
    char *new_str;
    
    if (!old_str)
        return (NULL);
    if (index < 0)
    {
    	free(old_str);
    	return (NULL);
    }
    new_str = ft_substr(old_str, index + 1, ft_strlen(old_str) - index) ;
    free(old_str);
    return (new_str);
}

char *get_read(int fd, char **str_st)
{
    char    *temp;
	int 	byte_read;
	
  	temp = malloc(BUFFER_SIZE + 1);
	if (!temp)
		return (NULL);
	byte_read = 1;
	while (ft_strchr_n(str_st[fd],'\n') == -1 && byte_read != 0)
	{
		byte_read = read (fd, temp, BUFFER_SIZE);
		if (byte_read == -1)
		{
			free(temp);
			return (NULL);
		}
		temp[byte_read] = 0;
	    str_st[fd] = ft_strjoin_up_free(str_st[fd], temp);
	}
	free (temp);
	return (str_st[fd]);
}

char	*ft_strjoin_up_free(char *temp, char *str)
{
	char	*line;

	if (!str)
		return (NULL);
	line = ft_strjoin_up(temp, str);
	free(temp);
	return (line);
}


