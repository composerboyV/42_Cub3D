/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing_characters.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junkwak <junkwak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 17:14:30 by junkwak           #+#    #+#             */
/*   Updated: 2025/04/16 13:48:18 by junkwak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw.h"

void	check_map_characters(t_map_info *map)
{
	int	y;

	validate_identifiers(map);
	y = find_map_start(map);
	while (y < map->height)
	{
		check_invalid_char_in_line(map, y);
		y++;
	}
}

void	check_map_line_status(t_map_info *map, int y, int *in_map, int *map_end)
{
	int	only_spaces;

	only_spaces = is_only_spaces(map->map[y]);
	if (!*in_map && !only_spaces && is_map_line(map->map[y]))
		*in_map = 1;
	if (*in_map && only_spaces && !*map_end)
		*map_end = 1;
}

void	check_map_line(t_map_info *map, int y, int *in_map, int *map_end)
{
	int	only_spaces;

	only_spaces = is_only_spaces(map->map[y]);
	check_map_line_status(map, y, in_map, map_end);
	if (*map_end && !only_spaces)
	{
		show_error("MAP ERROR: Content found after map ended!\n");
	}
}

void	check_for_non_map_content(t_map_info *map)
{
	int	y;
	int	in_map;
	int	map_end;

	y = find_map_start(map);
	in_map = 0;
	map_end = 0;
	while (y < map->height)
	{
		check_map_line(map, y, &in_map, &map_end);
		y++;
	}
}

int	is_map_identifier(char *line)
{
	if (ft_strncmp(line, "NO ", 3) == 0 || \
		ft_strncmp(line, "SO ", 3) == 0 || \
		ft_strncmp(line, "WE ", 3) == 0 || \
		ft_strncmp(line, "EA ", 3) == 0 || \
		ft_strncmp(line, "F ", 2) == 0 || \
		ft_strncmp(line, "C ", 2) == 0)
		return (1);
	return (0);
}
