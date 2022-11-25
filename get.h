#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#ifndef BUFFERSIE
#define BUFFERSIE 10


char	*get_next_line(int fd);
char *ft_strchr(char *s, char c);
char *ft_substr(char *s, int start ,int size);
char	*ft_strjoin(char const *s1, char const *s2);

#endif