/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_setup.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takhayas <hayatakucat@icloud.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 10:44:38 by takhayas          #+#    #+#             */
/*   Updated: 2025/12/05 11:45:00 by takhayas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	free_assets(t_game *data)
{
	if (data->img_collect)
		mlx_destroy_image(data->mlx_ptr, data->img_collect);
	if (data->img_exit)
		mlx_destroy_image(data->mlx_ptr, data->img_exit);
	if (data->img_floor)
		mlx_destroy_image(data->mlx_ptr, data->img_floor);
	if (data->img_player)
		mlx_destroy_image(data->mlx_ptr, data->img_player);
	if (data->img_wall)
		mlx_destroy_image(data->mlx_ptr, data->img_wall);
}

static int	setup_wall_collect(t_game *data, int *img_width, int *img_height)
{
	data->img_wall = mlx_xpm_file_to_image(data->mlx_ptr, "/image/wall.xpm",
			img_width, img_height);
	if (!(data->img_wall) || *img_width != data->tile_size
		|| *img_height != data->tile_size)
		return (1);
	data->img_collect = mlx_xpm_file_to_image(data->mlx_ptr,
			"/image/collectible.xpm", img_width, img_height);
	if (!(data->img_collect) || *img_width != data->tile_size
		|| *img_height != data->tile_size)
	{
		free_assets(data);
		return (1);
	}
	return (0);
}

static int	setup_exit_floor_player(t_game *data, int *width, int *height)
{
	data->img_exit = mlx_xpm_file_to_image(data->mlx_ptr,
			"/image/exit.xpm", width, height);
	if (!(data->img_exit) || *width != data->tile_size
		|| *height != data->tile_size)
	{
		free_assets(data);
		return (1);
	}
	data->img_floor = mlx_xpm_file_to_image(data->mlx_ptr,
			"/image/floor.xpm", width, height);
	if (!(data->img_floor) || *width != data->tile_size
		|| *height != data->tile_size)
	{
		free_assets(data);
		return (1);
	}
	data->img_player = mlx_xpm_file_to_image(data->mlx_ptr,
			"/image/player.xpm", width, height);
	if (!(data->img_player) || *width != data->tile_size
		|| *height != data->tile_size)
	{
		free_assets(data);
		return (1);
	}
	return (0);
}

int	ft_image_setup(t_game *data)
{
	int	img_width;
	int	img_height;

	if (setup_wall_collect(data, &img_width, &img_height))
		return (1);
	if (setup_exit_floor_player(data, &img_width, &img_height))
		return (1);
	return (0);
}
