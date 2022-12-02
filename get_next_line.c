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
        // int k =BUFFER_SIZE +1;
	char	*dst;
	int		readed;

	dst = malloc(BUFFER_SIZE + 1);
	readed = 1;
	while (ft_strchr(str, '\n') == 0 && readed >= 0)
	{
		readed = read(fd, dst, BUFFER_SIZE);
        dst[readed] = '\0';
		if(readed == -1)
			return (free(dst), NULL);
		if (readed == 0)
			break;
		str = ft_strjoin(str, dst);
		if (!str)
				return (free(str),NULL);
	}
	free(dst);
	return (str);
}

char	*get_next_line(int fd)
{
	static char	*stat;
	char		*line;
	int			i;

    // stat = NULL;
	i = 0;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	stat = readline(fd, stat);
	if(!stat)
		return(free(stat),NULL);
	while (stat[i] != '\0' && stat[i] != '\n')
		i++;
	if (stat[i] == '\n')
		i++;
	line = ft_strtri(stat, i);
	if (!line)
		return (free(line), NULL);
	stat = ft_strtrim (stat, i);
	// printf("%p\n", stat);
	if(!stat)
		return(free(stat),NULL);
	return (line);
}

// int main ()
// {
// 	int fd = open("file.txt",O_RDONLY);
// 	printf("+%s+",get_next_line(fd));
// 	// close(stdin);
// 	// printf("%d",fd);÷
// 	// printf("+%s+",get_next_line(fd));
// }

// int main(int argc, char const *argv[])
// {
//     int fd = open("get_next_line.h",O_RDONLY);
// 	char *s;
// 	s = get_next_line(fd);
// 	printf("%s", s);
// // 	while((s = get_next_line(fd)))
// // {
// // 	 printf("%s",s);
// // }
// 	 free(s);
// 	s = get_next_line(fd);
// 	printf("%s", s);
// // 	while((s = get_next_line(fd)))
// // {
// // 	 printf("%s",s);
// // }
// 	 free(s);
// 	system("leaks a.out");
//     return 0;
// }
