/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validator.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takhayas <hayatakucat@icloud.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 14:53:59 by takhayas          #+#    #+#             */
/*   Updated: 2025/12/02 13:38:58 by takhayas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	ft_free_map(char **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
	return ;
}

int	ft_put_map_error(int i)
{
	if (i == 0)
		return (0);
	if (i == 1)
		ft_printf("Error\nmap not exist\n");
	if (i == 2)
		ft_printf("Error\nmap is not rectangular\n");
	if (i == 3)
		ft_printf("Error\nmap is not surrounded by walls\n");
	if (i == 4)
		ft_printf("Error\nmap_must_have_one_start_point\n");
	if (i == 5)
		ft_printf("Error\nmap_must_have_one_exit\n");
	if (i == 6)
		ft_printf("Error\nmap_must_have_collectibles\n");
	if (i == 7)
		ft_printf("Error\nYou cannot reach exit on the map\n");
	return (1);
}

int	is_invalid_map(char **map)
{
	if (!map || !map[0] || map[0][0] == '\0')
		return (1);
	if (is_not_rectangular(map))
		return (2);
	if (is_not_surrounded_by_walls(map))
		return (3);
	if (ft_not_have_one_start(map))
		return (4);
	if (ft_not_have_one_exit(map))
		return (5);
	if (!ft_collectibles_count(map))
		return (6);
	if (ft_is_not_playable(map, ft_collectibles_count(map)))
		return (7);
	return (0);
}
