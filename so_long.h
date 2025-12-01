/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takhayas <hayatakucat@icloud.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/23 18:33:21 by takhayas          #+#    #+#             */
/*   Updated: 2025/12/01 16:37:07 by takhayas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include "../mlx/mlx.h"
# include "libft/libft.h"
# include "libft/ft_printf.h"
# include "libft/get_next_line.h"

typedef struct s_flood_data
{
	int	found_collect;
	int	found_exit;
	int	width;
	int	height;
}	t_flood_data;

void	ft_free_map(char **map);
//map_parser.c
char	**map_reader(char *file_name);
//map_validator.c
int		is_invalid_map(char **map);
int		ft_put_map_error(int i);
//map_shape_validator.c
int		is_not_rectangular(char **map);
int		is_not_surrounded_by_walls(char **map);
//map_element_validator.c
int		ft_not_have_one_start(char **map);
int		ft_not_have_one_exit(char **map);
int		ft_collectibles_count(char **map);
//map_validator.c
int		ft_put_map_error(int i);
int		is_invalid_map(char **map);
//map_playable_validator.c
int		ft_is_not_playable(char **map, int total_collectibles);

#endif
