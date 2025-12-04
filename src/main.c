/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takhayas <hayatakucat@icloud.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 14:09:02 by takhayas          #+#    #+#             */
/*   Updated: 2025/12/05 00:50:47 by takhayas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	main(int argc, char **argv)
{
	char	**map;

	if (argc != 2)
		return (1);
	map = map_reader(argv[1]);
	if (map == NULL)
	{
		ft_printf("Error\nFailed to read map\n");
		return (1);
	}
	if (is_invalid_map(map))
		return (ft_put_map_error(is_invalid_map(map)));
	//

	//
	ft_free_map(map);
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
