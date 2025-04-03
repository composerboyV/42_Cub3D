/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing_edges.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junkwak <junkwak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 17:10:30 by junkwak           #+#    #+#             */
/*   Updated: 2025/04/03 17:13:33 by junkwak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw.h"

int	is_at_edge(t_map_info *map, int i, int j)
{
	int	map_start;

	map_start = find_map_start(map);
	if (i == map_start || i == map->height - 1 || j == 0 || \
		j == (int)ft_strlen(map->map[i]) - 1)
		return (1);
	return (0);
}

int	is_near_space_or_out_of_bounds(t_map_info *map, int i, int j)
{
	if (j >= (int)ft_strlen(map->map[i - 1]) || \
		j >= (int)ft_strlen(map->map[i + 1]))
		return (1);
	if (map->map[i - 1][j] == ' ' || map->map[i + 1][j] == ' ' ||
		map->map[i][j - 1] == ' ' || map->map[i][j + 1] == ' ')
		return (1);
	return (0);
}

void	check_cell(t_map_info *map, int i, int j)
{
	if (is_player_or_zero(map->map[i][j]) && \
		(is_at_edge(map, i, j) || is_near_space_or_out_of_bounds(map, i, j)))
	{
		printf("Map error: Space/zero at (%d, %d)\n", j, i);
		show_error("MAP ERROR: Map must be closed by walls!\n");
	}
}

void	check_flood_fill_map(t_map_info *map)
{
	int	i;
	int	j;
	int	map_start;

	map_start = find_map_start(map);
	i = map_start;
	while (i < map->height)
	{
		j = 0;
		while (j < (int)ft_strlen(map->map[i]))
		{
			check_cell(map, i, j);
			j++;
		}
		i++;
	}
}
