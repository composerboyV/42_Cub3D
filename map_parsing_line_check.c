/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing_line_check.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junkwak <junkwak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 17:13:30 by junkwak           #+#    #+#             */
/*   Updated: 2025/04/16 13:58:33 by junkwak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw.h"

int	is_map_line(char *line)
{
	int	i;
	int	has_wall;

	i = 0;
	has_wall = 0;
	while (line[i])
	{
		if (line[i] == '1')
			has_wall = 1;
		if (!here_is_valid_map_char(line[i]))
			return (0);
		i++;
	}
	return (has_wall);
}

int	is_only_spaces(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] != ' ' && line[i] != '\n' && \
			line[i] != '\t' && line[i] != '\r')
			return (0);
		i++;
	}
	return (1);
}

void	check_invalid_char_in_line(t_map_info *map, int y)
{
	int	x;

	x = 0;
	while (map->map[y][x] != '\0')
	{
		if (!here_is_valid_map_char(map->map[y][x]))
		{
			printf("Invalid character '%c' at (%d, %d)\n", \
				map->map[y][x], x, y);
			show_error("MAP ERROR: Invalid character in map!\n");
		}
		x++;
	}
}

int	all_identifiers_found(t_map_flags flags)
{
	return (flags.no_found && flags.so_found && flags.we_found && \
		flags.ea_found && flags.f_found && flags.c_found);
}

int	is_map_start_char(char c)
{
	return (c == ' ' || c == '1' || c == '0');
}
