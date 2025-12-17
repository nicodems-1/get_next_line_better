/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niverdie <niverdie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 16:44:34 by niverdie          #+#    #+#             */
/*   Updated: 2025/12/17 08:58:52 by niverdie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s && s[i])
		i++;
	return (i);
}

char	*ft_strjoin(char *s1, char const *s2)
{
	int		i;
	int		j;
	char	*final_string;
	int		len;

	i = -1;
	j = -1;
	len = ft_strlen(s1) + ft_strlen(s2);
	final_string = malloc(len + 1 * sizeof(char));
	if (!final_string)
		return (ft_free(s1));
	while (s1 && s1[++i])
		final_string[i] = s1[i];
	if (i == -1)
		i = 0;
	free(s1);
	while (s2[++j] && s2[j] != '\n')
		final_string[i + j] = s2[j];
	if (s2[j] == '\n')
		final_string[i + j] = s2[j];
	if (s2[j] != '\n')
		final_string[i + j] = '\0';
	else
		final_string[i + j + 1] = '\0';
	return (final_string);
}

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char	*tmp_src;
	char	*tmp_dest;
	int		stock;
	size_t	i;

	stock = n;
	i = 0;
	if (!src && !dest)
		return (NULL);
	tmp_src = (char *)src;
	tmp_dest = (char *)dest;
	if (tmp_dest > tmp_src)
		while (n-- != 0)
			tmp_dest[n] = tmp_src[n];
	else
	{
		while (i < n)
		{
			tmp_dest[i] = tmp_src[i];
			i++;
		}
	}
	tmp_dest[stock] = '\0';
	return (dest);
}
