/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing_validate.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junkwak <junkwak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 17:13:00 by junkwak           #+#    #+#             */
/*   Updated: 2025/04/19 19:55:27 by junkwak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw.h"

void	check_boundaries(t_map_info *map, int x, int y)
{
	if (y < 0 || y >= map->height || x < 0 || \
		x >= (int)ft_strlen(map->map[y]) || \
		map->map[y][x] == ' ')
		show_error("Map error: Map is not enclosed by walls!\n");
	if (here_is_strange(map->map[y][x]) == 1)
		show_error("Invalid character or boundary!\n");
}

void	mark_visited(t_map_info *map, int x, int y)
{
	if (map->map[y][x] == 'N' || map->map[y][x] == 'S' || \
		map->map[y][x] == 'E' || map->map[y][x] == 'W' ||
		map->map[y][x] == '0')
	{
		map->map[y][x] = 'X';
	}
}

void	map_parsing(t_map_info *map, int x, int y)
{
	check_boundaries(map, x, y);
	if (map->map[y][x] == '1' || map->map[y][x] == 'X')
		return ;
	mark_visited(map, x, y);
	map_parsing(map, x - 1, y);
	map_parsing(map, x + 1, y);
	map_parsing(map, x, y - 1);
	map_parsing(map, x, y + 1);
}

int	has_wall_in_line(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] == '1')
			return (1);
		i++;
	}
	return (0);
}

void	is_it_correct_map(t_game *game, char *file_name)
{
	check_file_name(game, file_name);
	check_map_characters(game->map_info);
	check_for_non_map_content(game->map_info);
	check_map_boundaries(game->map_info);
	are_you_alone(game->map_info);
	check_flood_fill_map(game->map_info);
	map_parsing(game->map_info, game->map_info->player_x, \
		game->map_info->player_y);
}
