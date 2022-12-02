# include "unistd.h"
# include "stdlib.h"
# include "stdio.h"
# include "fcntl.h"
#include "get_next_line.h"

size_t ft_strlen(const char *s)
{
	size_t i = 0;
	while (s[i++] != 0);
	return (i);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t n)
{
	size_t	i;
	size_t	lensrc;

	i = 0;
	lensrc = ft_strlen (src);
	if (n)
	{
		while (src[i] && i < n - 1)
		{
			dst[i] = src[i];
			i++;
		}
	}
	dst[i] = '\0';
	return (lensrc);
}


int ft_strchr(char *s, char c)
{
	if (!s)
		return (0);
    while (*s)
    {
        if (*s == c)
            return (1);
        s++;
    }
    return 0;
}

char	*ft_strtrim(char *s, int start)
{
	char *remain;
	size_t	i;
	i = 0;
	remain = malloc(strlen(s)-start +1);
	while (i < strlen(s)-start)
	{
		remain[i] = s[start];
		i++;
		start++;
	}
	remain[i] = 0;
	return (free(s),remain);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*res;
	int		i;
	int		j;

	if(!s1)
		s1 = strdup("");
	if (s1 && s2)
	{
		res = (char *)malloc(((ft_strlen(s1) + ft_strlen(s2)) + 1));
		if (!res)
			return (NULL);
		i = -1;
		j = -1;
		while (s1[++i])
			res[i] = s1[i];
		while (s2[++j])
			res[i + j] = s2[j];
		res[i + j] = '\0';
			// printf("--->%s<----",res);
		free(s1);
		return ( res);
	}
	return (NULL);
}

char	*ft_strtri(char *s, int i)
{
	int	j;

	j = 0;
	char *d;
	d = malloc (i + 1);
	if(!d)
		return(NULL);
	while (s[j] && j < i)
	{
		d[j] = s[j];
		j++;
	}
	d[j] = 0;
	return (d);
}
