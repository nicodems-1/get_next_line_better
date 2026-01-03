/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niverdie <niverdie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 16:52:58 by niverdie          #+#    #+#             */
/*   Updated: 2026/01/03 15:42:11 by niverdie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int	newline_finder(char *line, int *i)
{
	while (line[*i] != '\0')
	{
		if (line[*i] == '\n')
			return (*i);
		(*i)++;
	}
	return (-1);
}

void	nxt_buffer(char *buffer, int i)
{
	int	begin;
	int	len;

	begin = i + 1;
	len = ft_strlen(buffer) - begin;
	ft_memmove(buffer, &buffer[begin], len);
}

char	*ft_free(char *line)
{
	free(line);
	line = NULL;
	return (NULL);
}

char	*final_line(char *line, char *buffer, int i)
{
	line = ft_strjoin(line, buffer);
	nxt_buffer(buffer, i);
	return (line);
}

char	*get_next_line(int fd)
{
	static char	buffer[1024][BUFFER_SIZE + 1];
	char		*line;
	int			readbyte;
	int			i;

	line = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	readbyte = 1;
	while (readbyte > 0)
	{
		i = 0;
		if (newline_finder(buffer[fd], &i) != -1)
			return (final_line(line, buffer[fd], i));
		if (buffer[fd][0] != '\0')
			line = ft_strjoin(line, buffer[fd]);
		readbyte = read(fd, buffer[fd], BUFFER_SIZE);
		buffer[fd][readbyte] = '\0';
		if (readbyte < 0)
			return (ft_free(line));
		if (readbyte == 0)
			return (line);
	}
	return (NULL);
}

// #include <fcntl.h>
// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>
// #include <unistd.h>

// int	main(int ac, char **av)
// {
// 	int fd = open(av[1], 0, 0);
// 	int fd2 = open(av[2], 0, 0);
// 	int i = 0;
// 	char *line;
// 	char *line2;
// 	// line = get_next_line(fd);
// 	// printf("%s", line);
// 	do {
// 		line = get_next_line(fd);
// 		line2 = get_next_line(fd2);
// 		printf("%d : %s", i, line);
// 		printf("%d : %s", i, line);
// 		free(line);
// 		free(line2);
// 	} while (line && line2);
// 	close(fd);
// 	close(fd2);
// 	return (0);
// }