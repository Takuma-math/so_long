/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_element_validator.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takhayas <hayatakucat@icloud.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 14:39:11 by takhayas          #+#    #+#             */
/*   Updated: 2025/12/01 16:34:19 by takhayas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	ft_not_have_one_start(char **map)
{
	int	start_count;
	int	i;
	int	j;

	if (!map || !map[0])
		return (1);
	i = 0;
	start_count = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'P')
				start_count++;
			j++;
		}
		i++;
	}
	if (start_count != 1)
		return (1);
	else
		return (0);
}

int	ft_not_have_one_exit(char **map)
{
	int	exit_count;
	int	i;
	int	j;

	if (!map || !map[0])
		return (1);
	i = 0;
	exit_count = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'E')
				exit_count++;
			j++;
		}
		i++;
	}
	if (exit_count != 1)
		return (1);
	else
		return (0);
}

int	ft_collectibles_count(char **map)
{
	int	collectibles_count;
	int	i;
	int	j;

	if (!map || !map[0])
		return (1);
	i = 0;
	collectibles_count = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'C')
				collectibles_count++;
			j++;
		}
		i++;
	}
	return (collectibles_count);
}
