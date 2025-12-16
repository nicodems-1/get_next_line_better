/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niverdie <niverdie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 16:52:58 by niverdie          #+#    #+#             */
/*   Updated: 2025/12/16 22:23:42 by niverdie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	newline_finder(char *line)
{
	int	i;

	i = 0;
	while (line[i] != '\0')
	{
		if (line[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

void	nxt_buffer(char buffer[])
{
	int	begin;
	int	len;

	begin = newline_finder(buffer) + 1;
	len = ft_strlen(buffer) - begin;
	ft_memmove(buffer, &buffer[begin], len);
}

char	*final_string(int readbyte, char *line)
{
	int		len;
	char	*temp;

	if (readbyte == 0 && line[0] == '\0')
		return (NULL);
	len = newline_finder(line) + 1;
	temp = ft_substr(line, 0, len);
	free(line);
	return (temp);
}

char	*ft_free(char *line, char buffer[])
{
	int	i;

	i = -1;
	free(line);
	while (++i < BUFFER_SIZE)
		buffer[i] = '\0';
	return (NULL);
}

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE + 1];
	char		*line;
	int			readbyte;

	if (fd < 0)
		return (NULL);
	line = ft_calloc(1, sizeof(char));
	readbyte = 1;
	while (readbyte > 0)
	{
		line = ft_strjoin(line, buffer);
		if (newline_finder(line) != -1)
		{
			nxt_buffer(buffer);
			return (line = final_string(readbyte, line));
		}
		readbyte = read(fd, buffer, BUFFER_SIZE);
		if (readbyte < 0)
			return (ft_free(line, buffer));
		buffer[readbyte] = '\0';
	}
	if (readbyte == 0 && line[0] != '\0')
		return (line);
	free(line);
	return (NULL);
}

// char	*get_next_line(int fd)
// {
// 	static char	buffer[BUFFER_SIZE + 1];
// 	char		*line;
// 	int			readbyte;

// 	buffer[BUFFER_SIZE] = '\0';
// 	readbyte = 1;
// 	line = ft_calloc(1, sizeof(char));
// 	if (fd < 0)
// 		return(ft_free(line));
// 	int init = 0;
// 	while (newline_finder(line) == -1 && readbyte > 0)
// 	{
// 		if (init++ == 0)
// 			readbyte = read(fd, buffer, BUFFER_SIZE);
// 		else if (newline_finder(line) != -1)
// 		nxt_buffer(readbyte, buffer);

// 		line = ft_strjoin(line, buffer);
// 		buffer[readbyte] = '\0';
// 		if (readbyte < 0)
// 			return(ft_free(line));
// 	}
// 	return (final_string(readbyte, line));
// }

// int	main(int argc, char **argv)
// {
// 	int fd;

// 	fd = open(argv[1], O_RDONLY);
// 	char *line = "";
// 	int i;

// 	i = 0;
// 	while (line)
// 	{
// 		line = get_next_line(fd);
// 		printf("%s", line);
// 		free(line);
// 		close(fd);
// 	}
// }

// int	main(void)
// {
// 	char *line = "";

// 	int fd = open("algo.txt", O_RDONLY);
// 	while (line)
// 	{
// 		line = get_next_line(fd);

// 		printf("%s", line);
// 		free(line);
// 	}
// 	close(fd);
// }

// #include <fcntl.h>
// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>
// #include <unistd.h>

// char	*get_next_line(int fd);

// int	main(void)
// {
// 	int fd = open("algo.txt", O_RDONLY);
// 	if (fd == -1)
// 	{
// 		perror("Erreur lors de l'ouverture du fichier");
// 		return (1);
// 	}
// 	int i = 0;
// 	char *line;
// 	while ((line = get_next_line(fd)) != NULL)
// 	{
// 		i++;
// 		printf("%d : %s", i, line);
// 		if (i == 10000)
// 		{
// 			close(fd);
// 		}
// 		free(line);
// 	}
// 	free(line);
// 	close(fd);
// 	return (0);
// }