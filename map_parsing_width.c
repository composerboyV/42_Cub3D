/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing_width.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junkwak <junkwak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 17:11:00 by junkwak           #+#    #+#             */
/*   Updated: 2025/04/16 13:45:48 by junkwak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw.h"

int	find_max_width(t_map_info *map, int start_y)
{
	int	y;
	int	len;
	int	max_width;

	max_width = 0;
	y = start_y;
	while (y < map->height)
	{
		len = ft_strlen(map->map[y]);
		if (len > max_width)
			max_width = len;
		y++;
	}
	return (max_width);
}

int	find_last_non_space(char *line)
{
	int	x;

	x = ft_strlen(line) - 1;
	while (x >= 0 && (line[x] == ' ' || line[x] == '\n' || \
		line[x] == '\t' || line[x] == '\r'))
		x--;
	return (x);
}

void	check_line_ending(t_map_info *map, int y)
{
	int	x;

	x = find_last_non_space(map->map[y]);
	if (x >= 0 && map->map[y][x] != '1' && map->map[y][x] != ' ')
	{
		show_error("MAP ERROR: Map must be closed by walls!\n");
	}
}
