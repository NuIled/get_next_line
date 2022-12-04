/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoutifra <aoutifra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 02:59:05 by aoutifra          #+#    #+#             */
/*   Updated: 2022/12/04 19:30:15 by aoutifra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>

#ifndef GET_NEXT_LINE_H
#define GET_NEXT_LINE_H
#ifndef BUFFER_SIZE
#define BUFFER_SIZE 1024
#endif

char	*ft_saver(char *s, int start);
char	*get_next_line(int fd);
int     ft_strchr(char *s, char c);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_getline(char *s, int i);
size_t	ft_strlcpy(char *dst, const char *src, size_t n);
char	*ft_strdup(const char *s1);
size_t ft_strlen(const char *s);

#endif