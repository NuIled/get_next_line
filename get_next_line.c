/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoutifra <aoutifra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 21:41:25 by aoutifra          #+#    #+#             */
/*   Updated: 2022/11/25 18:41:23 by aoutifra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get.h"
char *readline (int fd, char *s)
{
	char *d;
	int j;
	int i;
	i = 0;
	s = calloc(1,1);
	d = calloc(BUFFERSIE,1);
	j = read(fd ,s ,BUFFERSIE);
	// d = calloc(j,1);
	while (i < j)
	{
		d[i] = s[i];
		i++; 
	}
	free(s);
	return d;
}

char	*get_next_line(int fd)
{
	int BUFSIZz;
	BUFSIZz = 10;
	int			i;
	i = 0;
	int			l;
	static char	*c;
	char 		*s;
	char 		*v;
	s = readline (fd,c);
	while (1)
	{
	while (s[i] && s[i] != '\n')
		i++;
	if(s[i]!='\n')
		v = readline(fd ,c);
	if (s[i]== '\n')
	{
		s = ft_substr(s,0,i);
		break;
	}
	s =ft_strjoin(s,v);
	}
	return s;
}

int main ()
{
	int fd = open("file.txt", O_RDONLY);
	printf("%s\n",get_next_line(fd));
	printf("%s\n",get_next_line(fd));
	return 0;
}