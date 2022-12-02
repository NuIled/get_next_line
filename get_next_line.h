#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#ifndef GET_NEXT_LINE_H
#define GET_NEXT_LINE_H
#ifndef BUFFER_SIZE
#define BUFFER_SIZE 1
#endif

char	*ft_strtrim(char *s, int start);
char	*get_next_line(int fd);
int     ft_strchr(char *s, char c);
char *ft_substr(char *s, int start ,int size);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_calloc(size_t count, size_t n);
char	*ft_strtri(char *s, int i);

#endif