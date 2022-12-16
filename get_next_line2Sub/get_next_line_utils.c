#include "get_next_line.h"

size_t	ft_strlen(char const *str)
{
	size_t	i;

	i = 0;
	if (!str)
	    return (0);
	while (*str++ != '\0')
		i++;
	return (i);
}

int ft_strchr_n(const char *s, int c)
{
	int	i;

    if (!s)
     return(-1);
	i = -1;
	while (s[++i])
		if (s[i] == (unsigned char)c)
			return (i);
	if (c == 0)
		return (i);
	return (-1);
}


char	*ft_strjoin(char *s1, char const *s2)
{
	char	*d;
	size_t	i1;
	size_t	i2;
	int	j;

	if (!s1 && !s2)
		return (NULL);
	i1 = ft_strlen(s1);
	i2 = ft_strlen(s2);
	d = malloc(sizeof(char) * (i1 + i2 + 1));
	if (!d)
		return (NULL);
	j = 0;
	if (s1)
	{
	    while (*s1)
		    d[j++] = *s1++;
	}
	while (*s2)
		d[j++] = *s2++;
	d[i1 + i2] = 0;
	return (d);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*d;
	unsigned int	m;
	size_t			len_s;

	len_s = ft_strlen(s);
	if (len_s < start || len == 0)
		m = 0;
	else if (len_s - start + 1 > len)
		m = len;
	else
		m = len_s - start;
	d = (char *) malloc(m + 1);
	if (!d)
		return (NULL);
	len_s = 0;
	while (s[start] && len_s < m)
		d[len_s++] = s[start++];
	d[len_s] = '\0';
	return (d);
}