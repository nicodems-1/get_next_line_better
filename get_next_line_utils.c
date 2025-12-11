/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niverdie <niverdie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 16:44:34 by niverdie          #+#    #+#             */
/*   Updated: 2025/12/11 19:36:06 by niverdie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strjoin(char *s1, char const *s2)
{
	int		i;
	int		j;
	char	*final_string;

	i = 0;
	j = 0;
	final_string = NULL;
	final_string = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!final_string)
		return (NULL);
	while (s1[i])
	{
		final_string[i] = s1[i];
		i++;
	}
	free(s1);
	while (s2[j])
	{
		final_string[i + j] = s2[j];
		j++;
	}
	final_string[i + j] = '\0';
	return (final_string);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*sub;
	unsigned int	i;

	sub = NULL;
	i = 0;
	if (!s || start >= ft_strlen(s))
	{
		sub = ft_calloc(1, sizeof(char));
		return (sub);
	}
	if (len > ft_strlen(s) - start)
		sub = malloc(sizeof(char) * (ft_strlen(s) - start + 1));
	else
		sub = malloc(sizeof(char) * (len + 1));
	if (!sub)
		return (NULL);
	while (len != i && s[start])
	{
		sub[i] = s[start];
		start++;
		i++;
	}
	sub[i] = '\0';
	return (sub);
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	unsigned char	*ptr;
	size_t			i;

	i = 0;
	if (size != 0 && nmemb > SIZE_MAX / size)
		return (NULL);
	ptr = malloc(nmemb * size);
	if (ptr == NULL)
	{
		return (NULL);
	}
	while (i < nmemb * size)
		ptr[i++] = 0;
	return (ptr);
}

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char	*tmp_src;
	char	*tmp_dest;
	size_t	i;

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
	tmp_dest[i] = '\0';
	return (dest);
}
