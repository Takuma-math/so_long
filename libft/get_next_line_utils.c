/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takhayas <hayatakucat@icloud.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/26 15:50:46 by takhayas          #+#    #+#             */
/*   Updated: 2025/11/23 21:23:49 by takhayas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen_gnl(const char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
		i++;
	return (i);
}

char	*ft_strchr_gnl(const char *s, int c)
{
	if (!s)
		return (NULL);
	while (*s)
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	if ((char)c == '\0')
		return ((char *)s);
	return (NULL);
}

char	*ft_strdup_gnl(const char *s1)
{
	char	*dst;
	size_t	i;

	if (!s1)
		return (NULL);
	i = 0;
	dst = (char *)malloc(sizeof(char) * (ft_strlen_gnl(s1) + 1));
	if (!dst)
		return (NULL);
	while (s1[i])
	{
		dst[i] = s1[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}

void	*ft_realloc_gnl(void *ptr, size_t old_size, size_t new_size)
{
	void	*new_ptr;
	size_t	i;

	if (!ptr)
		return (malloc(new_size));
	if (new_size == 0)
	{
		free(ptr);
		return (NULL);
	}
	if (new_size <= old_size)
		return (ptr);
	new_ptr = malloc(new_size);
	if (new_ptr)
	{
		i = 0;
		while (i < old_size)
		{
			((char *)new_ptr)[i] = ((char *)ptr)[i];
			i++;
		}
	}
	free(ptr);
	return (new_ptr);
}
