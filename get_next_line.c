/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niverdie <niverdie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 16:52:58 by niverdie          #+#    #+#             */
/*   Updated: 2025/12/17 09:16:44 by niverdie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <strings.h>

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
	static char	buffer[BUFFER_SIZE + 1];
	char		*line;
	int			readbyte;
	int			i;

	line = NULL;
	if (fd < 0)
		return (NULL);
	readbyte = 1;
	while (readbyte > 0)
	{
		i = 0;
		if (newline_finder(buffer, &i) != -1)
			return (final_line(line, buffer, i));
		if (buffer[0] != '\0')
			line = ft_strjoin(line, buffer);
		readbyte = read(fd, buffer, BUFFER_SIZE);
		buffer[readbyte] = '\0';
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

// int	main(void)
// {
// 	int fd = open("algo.txt", O_RDONLY);
// 	int i = 0;
// 	char *line;
// 	while ((line = get_next_line(fd)) != NULL)
// 	{
// 		i++;
// 		printf("%d : %s", i, line);
// 		free(line);
// 	}
// 	free(line);
// 	close(fd);
// 	return (0);
// }