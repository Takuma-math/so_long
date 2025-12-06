/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takhayas <hayatakucat@icloud.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/23 18:33:21 by takhayas          #+#    #+#             */
/*   Updated: 2025/12/06 02:09:34 by takhayas         ###   ########.fr       */
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

# ifndef KEYCODE_ESC
#  define KEYCODE_ESC	53
# endif
# ifndef KEYCODE_W
#  define KEYCODE_W	13
# endif
# ifndef KEYCODE_A
#  define KEYCODE_A	0
# endif
# ifndef KEYCODE_S
#  define KEYCODE_S	1
# endif
# ifndef KEYCODE_D
#  define KEYCODE_D	2
# endif

typedef struct s_flood_data
{
	int	found_collect;
	int	found_exit;
	int	width;
	int	height;
}	t_flood_data;

typedef struct s_game
{
	void	*mlx_ptr;
	void	*win_ptr;
	char	**map;
	int		width;
	int		height;
	int		tile_size;
	int		player_x;
	int		player_y;
	int		moves_count;
	int		collect_total;
	int		collect_current;
	void	*img_wall;
	void	*img_floor;
	void	*img_player;
	void	*img_collect;
	void	*img_exit;
}	t_game;

//map_parser.c
char	**map_reader(char *file_name);
//map_validator.c
int		is_invalid_map(char **map);
int		ft_put_map_error(int i);
void	ft_free_map(char **map);
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
void	find_player_start(char **map, int *x, int *y);

//image_setup.c
int		ft_image_setup(t_game *data);
void	free_assets(t_game *data);

#endif
