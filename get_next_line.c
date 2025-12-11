/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niverdie <niverdie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 16:52:58 by niverdie          #+#    #+#             */
/*   Updated: 2025/12/11 19:57:34 by niverdie         ###   ########.fr       */
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

char	*final_string(char *line)
{
	int		len;
	char	*temp;

	len = newline_finder(line) + 1;
	temp = ft_substr(line, 0, len);
	free(line);
	return (temp);
}

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE + 1];
	char		*line;
	int			readbyte;

	buffer[BUFFER_SIZE] = '\0';
	line = ft_calloc(1, sizeof(char));
	readbyte = 1;
	while (readbyte > 0)
	{
		if (fd < 0)
		{
			free(line);
			return(NULL);
		}
		line = ft_strjoin(line, buffer);
		if (newline_finder(line) != -1)
		{
			nxt_buffer(buffer);
			return (line = final_string(line));
		}
		readbyte = read(fd, buffer, BUFFER_SIZE);
	}
	return (line);
}

// int	main(void)
// {
// 	int fd;

// 	fd = open("TEST.txt", O_RDONLY);
// 	char *line;
// 	int i;

// 	i = 0;
// 	while (i != 89)
// 	{
// 		line = get_next_line(fd);
// 		printf("%s", line);
// 		free(line);
// 		i++;
// 	}
// }