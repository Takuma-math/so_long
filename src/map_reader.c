/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_reader.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takhayas <hayatakucat@icloud.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/23 18:46:56 by takhayas          #+#    #+#             */
/*   Updated: 2025/11/23 23:23:35 by takhayas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static int	*get_map_len_height_process(int fd)
{
	int		*len_height;
	char	*line;

	len_height = (int *)ft_calloc(2, sizeof(int));
	if (!len_height)
		return (NULL);
	line = get_next_line(fd);
	if (!line)
	{
		free(len_height);
		return (NULL);
	}
	while (line[len_height[0]] && line[len_height[0]] != '\n')
		len_height[0]++;
	free(line);
	len_height[1]++;
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		free(line);
		len_height[1]++;
	}
	return (len_height);
}

int	*get_map_len_height(char *file_name)
{
	int		fd;
	int		*map_len_height;

	if (map_opener(file_name, &fd))
		return (NULL);
	map_len_height = get_map_len_height_process(fd);
	close(fd);
	return (map_len_height);
}

static char	**fill_map_lines(int fd, char **map, int height)
{
	int		i;
	size_t	len;

	i = 0;
	while (i < height)
	{
		map[i] = get_next_line(fd);
		if (!map[i])
		{
			ft_free_all(map, i);
			return (NULL);
		}
		len = ft_strlen(map[i]);
		if (len > 0 && map[i][len - 1] == '\n')
			map[i][len - 1] = '\0';
		i++;
	}
	map[i] = NULL;
	return (map);
}

char	**map_reader(char *file_name)
{
	int		fd;
	char	**map;
	int		*map_len_height;

	map_len_height = get_map_len_height(file_name);
	if (!map_len_height)
		return (NULL);
	if (map_opener(file_name, &fd))
	{
		free(map_len_height);
		return (NULL);
	}
	map = (char **)malloc(sizeof(char *) * (map_len_height[1] + 1));
	if (!map)
	{
		free(map_len_height);
		close(fd);
		return (NULL);
	}
	map = fill_map_lines(fd, map, map_len_height[1]);
	close(fd);
	free(map_len_height);
	return (map);
}
