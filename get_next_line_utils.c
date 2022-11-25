#include "get.h"

char *ft_strchr(char *s, char c)
{
    while (*s)
    {
        if (*s == c)
            return *(&s);
        s++;
    }
    return 0;
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
	{
		s[i] = *s1;
		i++;
		s1++;
	}
	while (*s2 != '\0')
	{
		s[i] = *s2;
		i++;
		s2++;
	}
	s[i] = '\0';
	return (s);
}
char *ft_substr(char *s, int start ,int size)
{
    char *d;
    int   i;

    i = 0;

    d = calloc (size + 1,1);

    while (s[i] && i < size)
    {
        d[i] = s[i];
        i++;
    }
    return d;
}