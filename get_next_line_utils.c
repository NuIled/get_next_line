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
char	*ft_calloc(size_t count, size_t n)
{
	char 	*s;
	size_t	 i;
	i = 0;

	s = malloc(count * n);
	if (s == 0)
		return (NULL);
	while (s[i] && i < (n * count))
		s[i++] = 0;
	return (s);
}
char	*ft_strdup(const char *s1 )
{
	char	*s;
	size_t	i;

	i = ft_strlen(s1) + 1;
	s = malloc(i);
	if (s == 0)
		return (NULL);
	ft_strlcpy (s, s1, i);
	return (s);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*s;
	int		i;

	i = 0;
	if (!s1 || !s2)
		return (NULL);
	s = (char *)malloc((sizeof(char) * (strlen(s1) + strlen(s2) + 1)));
	if (!s)
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
	d = ft_calloc (size + 1 ,1);
	while(i < size)
	{
		d[i] = s[start];
		i++;
		start++;
	}
	d[i] = 0;
	return d;
}
