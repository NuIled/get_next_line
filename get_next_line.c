#include "get_next_line.h"


char *readline(int fd , char *s)
{
	char *d;
	if (s == NULL)
		s = ft_strdup("");
	int reads;
	reads = 1;
	d = ft_calloc(BUFFER_SIZE + 1, 1);
	
	while(ft_strchr(d,'\n') == 0 && reads > 0)
	{
		reads = read(fd,d,BUFFER_SIZE);
		if(reads < 0)
			break ;
		s = ft_strjoin(s,d);
	}
	free(d);
	return(s);
}


char *get_next_line(int fd)
{
	static char *s;
	char *d;
	char *c;
	int i;
 
	i = 0;
	if (fd < 0 || BUFFER_SIZE == 0)
		return (NULL);
	d = readline(fd,s);
	if (!s)
		ft_strdup("");
	while (d[i] != '\0' && d[i] != '\n')
		i++;
	c = ft_substr(d, 0, i);
	if (d[i] == '\n')
		i++;
	s = ft_substr (d,i, strlen(d) - i);
	if (d[0] == 0)
		return (NULL);
	 if (s)
	 	free (s);

	return c;
}
// int main ()
// {
// 	int fd;
	
// 	fd = open("42",O_RDONLY);
// 	printf("--->%s\n",get_next_line(fd));
// 	printf("--->%s\n",get_next_line(fd));
// 	printf("--->%s\n",get_next_line(fd));
// 	printf("--->%s\n",get_next_line(fd));
// 	printf("--->%s\n",get_next_line(fd));
// 	printf("--->%s\n",get_next_line(fd));
// 	printf("--->%s\n",get_next_line(fd));
// 	printf("--->%s\n",get_next_line(fd));
// 	printf("--->%s\n",get_next_line(fd));
// 	printf("--->%s\n",get_next_line(fd));
// 	printf("--->%s\n",get_next_line(fd));
// 	printf("--->%s\n",get_next_line(fd));
// 	printf("--->%s\n",get_next_line(fd));
// 	printf("--->%s\n",get_next_line(fd));
// 	printf("--->%s\n",get_next_line(fd));
// 	printf("--->%s\n",get_next_line(fd));
// 	printf("--->%s\n",get_next_line(fd));
// 	printf("--->%s\n",get_next_line(fd));
// 	printf("--->%s\n",get_next_line(fd));
// 	// printf("%s",get_next_line(fd));
// 	// printf("%s\n",get_next_line(fd));
// 	// printf("%s\n",get_next_line(fd));
	
// 	return 0;
// }