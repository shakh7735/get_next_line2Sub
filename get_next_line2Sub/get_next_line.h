#ifndef GET_NEXT_LINE_H

# define GET_NEXT_LINE_H

# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <stddef.h>
# include <stdio.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/stat.h>

#ifndef BUFFER_SIZE

# define BUFFER_SIZE 10

#endif

#ifndef MAX_OPEN_F

# define MAX_OPEN_F 20

#endif

char	*get_next_line(int fd);
char    *get_read(int fd, char **str_st);
char	*ft_strdup(const char *s);
size_t	ft_strlen(char const *str);
char	*ft_strjoin(char *s1, char const *s2);
int     ft_strchr_n(const char *s, int c);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char    *get_new_static(char *old_str, int index);
char	*ft_strjoin_up_free(char *temp, char *str);

#endif