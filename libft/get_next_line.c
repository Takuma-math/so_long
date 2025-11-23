/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takhayas <hayatakucat@icloud.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/29 15:04:56 by takhayas          #+#    #+#             */
/*   Updated: 2025/11/23 21:23:12 by takhayas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*ft_read_and_store(int fd, char *save, char *buf, int *read_bytes)
{
	char	*new_save;
	size_t	save_len;
	int		i;

	*read_bytes = read(fd, buf, BUFFER_SIZE);
	if (*read_bytes < 0)
	{
		free(save);
		return (NULL);
	}
	buf[*read_bytes] = '\0';
	save_len = ft_strlen_gnl(save);
	new_save = ft_realloc_gnl(save, save_len, save_len + *read_bytes + 1);
	if (!new_save)
		return (NULL);
	i = 0;
	while (buf[i])
	{
		new_save[save_len + i] = buf[i];
		i++;
	}
	new_save[save_len + i] = '\0';
	return (new_save);
}

static char	*ft_create_line(const char *save, int line_len)
{
	char	*line;
	int		i;

	if (save[line_len] == '\n')
		line = (char *)malloc(sizeof(char) * (line_len + 2));
	else
		line = (char *)malloc(sizeof(char) * (line_len + 1));
	if (!line)
		return (NULL);
	i = 0;
	while (i < line_len)
	{
		line[i] = save[i];
		i++;
	}
	if (save[line_len] == '\n')
		line[i++] = '\n';
	line[i] = '\0';
	return (line);
}

static void	ft_update_save(char **save, int line_len)
{
	char	*new_save;

	if ((*save)[line_len] == '\n')
	{
		new_save = ft_strdup_gnl(&(*save)[line_len + 1]);
	}
	else
	{
		new_save = NULL;
	}
	free(*save);
	*save = new_save;
}

static char	*ft_extract_line(char **save)
{
	char	*line;
	int		line_len;

	if (!*save)
		return (NULL);
	if (!(*save)[0])
	{
		free(*save);
		*save = NULL;
		return (NULL);
	}
	line_len = 0;
	while ((*save)[line_len] && (*save)[line_len] != '\n')
		line_len++;
	line = ft_create_line(*save, line_len);
	if (!line)
	{
		free(*save);
		*save = NULL;
		return (NULL);
	}
	ft_update_save(save, line_len);
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*save;
	char		*line;
	char		*buf;
	int			read_bytes;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (NULL);
	read_bytes = 1;
	while (!ft_strchr_gnl(save, '\n') && read_bytes > 0)
	{
		save = ft_read_and_store(fd, save, buf, &read_bytes);
		if (!save)
		{
			free(buf);
			return (NULL);
		}
	}
	line = ft_extract_line(&save);
	free(buf);
	return (line);
}
