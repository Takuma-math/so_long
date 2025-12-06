/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_keypress.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takhayas <hayatakucat@icloud.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 11:06:11 by takhayas          #+#    #+#             */
/*   Updated: 2025/12/06 02:24:59 by takhayas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static int	handle_esc(int keycode, t_game *data)
{
	if (keycode == KEYCODE_ESC)
	{
		free_assets(data);
		if (mlx_destroy_window(data->mlx_ptr, data->win_ptr))
			return (1);
		ft_free_map(data->map);
		exit(0);
	}
	return (0);
}

static void	update_x_y(int keycode, t_game *data, int *new_x, int *new_y)
{
	if (keycode == KEYCODE_W || keycode == KEYCODE_A
		|| keycode == KEYCODE_S || keycode == KEYCODE_D)
	{
		*new_x = data->player_x;
		*new_y = data->player_y;
		if (keycode == KEYCODE_W)
			(*new_y)--;
		else if (keycode == KEYCODE_A)
			(*new_x)--;
		else if (keycode == KEYCODE_S)
			(*new_y)++;
		else if (keycode == KEYCODE_D)
			(*new_x)++;
		if ((data->map)[(*new_y)][(*new_x)] == '1')
			return ;
		data->player_x = (*new_x);
		data->player_y = (*new_y);
		data->moves_count++;
		ft_printf("%d\n", data->moves_count);
	}
	return ;
}

static void	update_map_exit(t_game *data)
{
	if ((data->map)[data->player_y][data->player_x] == 'C')
	{
		data->collect_current++;
		(data->map)[data->player_y][data->player_x] = '0';
	}
	if (data->collect_current == data->collect_total
		&& (data->map)[data->player_y][data->player_x] == 'E')
	{
		free_assets(data);
		if (mlx_destroy_window(data->mlx_ptr, data->win_ptr))
			return ;
		ft_free_map(data->map);
		exit(0);
	}
	return ;
}

void	render_map(t_game *data)
{
	int	x;
	int	y;

	y = 0;
	while (y < data->height)
	{
		x = 0;
		while (x < data->width)
		{
			x++;
		}
		y++;
	}
}

int	handle_keypress(int keycode, t_game *data)
{
	int	new_x;
	int	new_y;

	if (handle_esc(keycode, data))
		return (1);
	update_x_y(keycode, data, &new_x, &new_y);
	update_map_exit(data);
	return (0);
}
