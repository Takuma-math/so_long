/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_playable_validator.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takhayas <hayatakucat@icloud.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 15:14:45 by takhayas          #+#    #+#             */
/*   Updated: 2025/12/01 16:31:27 by takhayas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static void	find_player_start(char **map, int *x, int *y)
{
	int	player_x;
	int	player_y;

	player_y = 0;
	while (map[player_y])
	{
		player_x = 0;
		while (map[player_y][player_x])
		{
			if (map[player_y][player_x] == 'P')
			{
				*x = player_x;
				*y = player_y;
				return ;
			}
			player_x++;
		}
		player_y++;
	}
	return ;
}

static void	flood_fill_map(char **map, int x, int y, t_flood_data *data)
{
	if (x < 0 || y < 0 || x >= data->width || y >= data->height
		|| map[y][x] == '1' || map[y][x] == 'V')
		return ;
	if (map[y][x] == 'C')
		data->found_collect++;
	if (map[y][x] == 'E')
		data->found_exit++;
	map[y][x] = 'V';
	flood_fill_map(map, x + 1, y, data);
	flood_fill_map(map, x - 1, y, data);
	flood_fill_map(map, x, y + 1, data);
	flood_fill_map(map, x, y - 1, data);
	return ;
}

static char	**ft_map_copy(char **map)
{
	int		height;
	int		i;
	char	**map_copy;

	height = 0;
	while (map[height])
		height++;
	map_copy = (char **)malloc(sizeof(char *) * (height + 1));
	if (!map_copy)
		return (NULL);
	i = 0;
	while (i < height)
	{
		map_copy[i] = ft_strdup(map[i]);
		if (!map_copy[i])
		{
			while (i--)
				free(map_copy[i]);
			free(map_copy);
			return (NULL);
		}
		i++;
	}
	map_copy[i] = NULL;
	return (map_copy);
}

int	ft_is_not_playable(char **map, int total_collectibles)
{
	char			**map_copy;
	int				start_x;
	int				start_y;
	t_flood_data	data;

	data.found_collect = 0;
	data.found_exit = 0;
	data.width = ft_strlen(map[0]);
	data.height = 0;
	while (map[data.height])
		data.height++;
	map_copy = ft_map_copy(map);
	if (!map_copy)
		return (1);
	find_player_start(map_copy, &start_x, &start_y);
	flood_fill_map(map_copy, start_x, start_y, &data);
	if (data.found_collect != total_collectibles || data.found_exit != 1)
	{
		ft_free_map(map_copy);
		return (1);
	}
	ft_free_map(map_copy);
	return (0);
}
