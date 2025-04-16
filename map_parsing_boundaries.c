/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing_boundaries.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junkwak <junkwak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 17:11:30 by junkwak           #+#    #+#             */
/*   Updated: 2025/04/16 13:59:25 by junkwak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw.h"

int	is_valid_boundary_char(char ch)
{
	return (ch == '1' || ch == ' ' || ch == '\n' || \
		ch == '\t' || ch == '\r');
}

void	check_boundary_line(char *line, char *error_msg)
{
	int	x;

	x = 0;
	while (x < (int)ft_strlen(line))
	{
		if (!is_valid_boundary_char(line[x]))
		{
			printf("%s\n", error_msg);
			show_error("MAP ERROR: Map boundaries must be walls!\n");
		}
		x++;
	}
}

void	init_map_validator(t_map_validator *validator, t_map_info *map)
{
	validator->start_y = find_map_start(map);
	validator->end_y = map->height - 1;
	validator->map_start = validator->start_y;
	validator->in_map = 0;
	validator->map_end = 0;
}

void	check_map_lines(t_map_info *map, int start_y)
{
	int	y;

	y = start_y;
	while (y < map->height)
	{
		check_line_ending(map, y);
		y++;
	}
}

void	check_map_boundaries(t_map_info *map)
{
	t_map_validator	validator;

	init_map_validator(&validator, map);
	find_max_width(map, validator.start_y);
	check_map_lines(map, validator.start_y);
	check_boundary_line(map->map[validator.start_y], \
		"Map error: First line must have only walls or spaces");
	check_boundary_line(map->map[validator.end_y], \
		"Map error: Last line must have only walls or spaces");
}
