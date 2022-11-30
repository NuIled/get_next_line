/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.line                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoutifra <aoutifra@strtudent.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 15:04:49 by aoutifra          #+#    #+#             */
/*   Updated: 2022/11/29 15:26:20 by aoutifra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*readline(int fd,char *str)
{
	char	*dst;
	int		readed;
	readed = 1;
	dst = malloc(BUFFER_SIZE + 1);
	if (!dst || !str)
		return (NULL);
	while (ft_strchr(dst, '\n') == 0 && readed > 0)
	{
		readed = read(fd, dst, BUFFER_SIZE);
		if (readed < 0)
			break ;
		str = ft_strjoin(str, dst);
	}
	free(dst);
	return (str);
}

char	*get_next_line(int fd)
{
	static char	*stat;
	char		*line;
	int			i;

	i = 0;
	if (fd < 0 || BUFFER_SIZE == 0)
		return (NULL);
	stat = readline(fd, stat);
	if (!stat)
	{
		free (stat);
		return(NULL);
		}
	while (stat[i] != '\0' && stat[i] != '\n')
		i++;
	line = ft_substr(stat, 0, i + 1);
	if (stat[i] == '\n')
		i++;
	stat = ft_strtrim (stat, i);
	if (!stat)
		free (stat);
	return (line);
}
int main ()
{
	int fd;
	
	fd = open("file.txt",O_RDONLY);
	printf("%s",get_next_line(fd));
	printf("%s",get_next_line(fd));

	
	return 0;
}