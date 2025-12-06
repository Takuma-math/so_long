/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takhayas <hayatakucat@icloud.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 14:09:02 by takhayas          #+#    #+#             */
/*   Updated: 2025/12/06 02:16:08 by takhayas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static int	ft_map_open_perse_validation(t_game *data, char *file_name)
{
	int	is_invalid;

	data->map = map_reader(file_name);
	if (data->map == NULL)
	{
		ft_printf("Error\nFailed to read map\n");
		return (1);
	}
	is_invalid = is_invalid_map(data->map);
	if (is_invalid)
	{
		ft_free_map(data->map);
		return (ft_put_map_error(is_invalid));
	}
	return (0);
}

static int	ft_mlx_setup(t_game *data)
{
	data->mlx_ptr = mlx_init();
	if (!data->mlx_ptr)
		return (1);
	data->width = ft_strlen((data->map)[0]);
	data->height = 0;
	while ((data->map)[data->height])
		data->height++;
	data->tile_size = 32;
	data->win_ptr = mlx_new_window(data->mlx_ptr, data->width * data->tile_size,
			data->height * data->tile_size, "so_long");
	if (!data->win_ptr)
		return (1);
	return (0);
}

static void	ft_player_setup(t_game *data)
{
	find_player_start(data->map, &(data->player_x), &(data->player_y));
	data->moves_count = 0;
	data->collect_current = 0;
	data->collect_total = ft_collectibles_count(data->map);
}

int	main(int argc, char **argv)
{
	t_game	data;

	if (argc != 2)
		return (1);
	if (ft_map_open_perse_validation(&data, argv[1]))
		return (1);
	if (ft_mlx_setup(&data))
		return (1);
	if (ft_image_setup(&data))
		return (1);
	ft_player_setup(&data);
	ft_free_map(data.map);
	return (0);
}

	// //for test
	// int	i;
	// i = 0;
	// while (map[i])
	// {
	// 	ft_printf("%s\n", map[i]);
	// 	free(map[i]);
	// 	i++;
	// }
	////
