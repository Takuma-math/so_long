/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takhayas <hayatakucat@icloud.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/23 18:32:33 by takhayas          #+#    #+#             */
/*   Updated: 2025/11/24 00:02:21 by takhayas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static t_list	*read_map_to_list(int fd)
{
	char	*line;
	t_list	*head;
	t_list	*new_node;

	head = NULL;
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		new_node = ft_lstnew(line);
		if (!new_node)
		{
			free(line);
			ft_lstclear(&head, free);
			return (NULL);
		}
		ft_lstadd_back(&head, new_node);
	}
	return (head);
}

static char	**list_to_2d_array(t_list *head, int size)
{
	char	**map;
	t_list	*tmp;
	int		i;
	size_t	len;

	map = (char **)malloc(sizeof(char *) * (size + 1));
	if (!map)
		return (NULL);
	tmp = head;
	i = 0;
	while (tmp)
	{
		map[i] = tmp->content;
		len = ft_strlen(map[i]);
		if (len > 0 && map[i][len - 1] == '\n')
			map[i][len - 1] = '\0';
		tmp = tmp->next;
		i++;
	}
	map[i] = NULL;
	return (map);
}

void	free_list_nodes(t_list *head)
{
	t_list	*tmp;

	while (head)
	{
		tmp = head->next;
		free(head);
		head = tmp;
	}
}

char	**map_reader(char *file_name)
{
	t_list	*head;
	int		fd;
	char	**map;
	int		size;

	if (map_opener(file_name, &fd))
		return (NULL);
	head = read_map_to_list(fd);
	close(fd);
	if (!head)
		return (NULL);
	size = ft_lstsize(head);
	map = list_to_2d_array(head, size);
	if (!map)
	{
		ft_lstclear(&head, free);
		return (NULL);
	}
	free_list_nodes(head);
	return (map);
}
