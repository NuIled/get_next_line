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
	size_t	i;

	i = 0;
	while (s[start] != '\0')
	{
		s[i] = s[start];
		i++;
		start++;
	}
	s[i] = 0;
	return (s);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*s;
	int		i;

	i = 0;
	if (!s1)
		s1 = malloc(1);
	if (!s2)
		return (NULL);
	s = (char *)malloc((sizeof(char) * (strlen(s1) + strlen(s2) + 1)));
	if (!s1)
		return (NULL);
	while (*s1 != '\0')
		s[i++] = *s1++;
	while (*s2 != '\0')
		s[i++] = *s2++;
	s[i] = 0;
	return (s);
}
char *ft_substr(char *s, int start, int size)
{
	int i;
	i = 0;
	char *d;
	d = malloc (size + 1);
	if (!d)
		return(NULL);
	while(i < size)
	{
		d[i] = s[start];
		i++;
		start++;
	}
	d[i] = 0;
	return d;
}
