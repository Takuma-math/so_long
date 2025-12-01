/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_shape_validator.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takhayas <hayatakucat@icloud.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 00:13:08 by takhayas          #+#    #+#             */
/*   Updated: 2025/12/01 15:03:33 by takhayas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	is_not_rectangular(char **map)
{
	size_t	width;
	int		i;

	if (!map || !map[0])
		return (1);
	width = ft_strlen(map[0]);
	i = 0;
	while (map[i])
	{
		if (ft_strlen(map[i]) != width)
			return (1);
		i++;
	}
	return (0);
}

int	is_not_surrounded_by_walls(char **map)
{
	int	width;
	int	height;
	int	i;

	if (!map || !map[0])
		return (1);
	width = ft_strlen(map[0]);
	height = 0;
	while (map[height])
		height ++;
	i = 0;
	while (i < width)
	{
		if (map[0][i] != '1' || map[height - 1][i] != '1')
			return (1);
		i++;
	}
	i = 0;
	while (i < height)
	{
		if (map[i][0] != '1' || map[i][width - 1] != '1')
			return (1);
		i++;
	}
	return (0);
}
