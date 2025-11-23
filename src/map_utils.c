/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takhayas <hayatakucat@icloud.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/23 22:56:30 by takhayas          #+#    #+#             */
/*   Updated: 2025/11/23 22:57:59 by takhayas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	map_opener(char *file_name, int *fd)
{
	char	*full_path;

	full_path = ft_strjoin("./maps/", file_name);
	if (!full_path)
		return (1);
	*fd = open(full_path, O_RDONLY);
	free(full_path);
	if (*fd == -1)
		return (1);
	return (0);
}

void	ft_free_all(char **words, int i)
{
	while (--i >= 0)
		free(words[i]);
	free(words);
}
