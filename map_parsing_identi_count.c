/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing_identi_count.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junkwak <junkwak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 17:14:00 by junkwak           #+#    #+#             */
/*   Updated: 2025/04/16 13:47:56 by junkwak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw.h"

void	count_identifiers(t_map_info *map, int *counts)
{
	int	i;

	i = 0;
	while (map->map[i] && i < find_map_start(map))
	{
		if (ft_strncmp(map->map[i], "NO ", 3) == 0)
			counts[0]++;
		else if (ft_strncmp(map->map[i], "SO ", 3) == 0)
			counts[1]++;
		else if (ft_strncmp(map->map[i], "WE ", 3) == 0)
			counts[2]++;
		else if (ft_strncmp(map->map[i], "EA ", 3) == 0)
			counts[3]++;
		else if (ft_strncmp(map->map[i], "F ", 2) == 0)
			counts[4]++;
		else if (ft_strncmp(map->map[i], "C ", 2) == 0)
			counts[5]++;
		i++;
	}
}

int	is_valid_line_before_map(char *line)
{
	return (is_only_spaces(line) || is_map_identifier(line));
}

void	check_invalid_content(t_map_info *map)
{
	int	i;

	i = 0;
	while (map->map[i] && i < find_map_start(map))
	{
		if (!is_valid_line_before_map(map->map[i]))
		{
			show_error("MAP ERROR: Invalid content before map!\n");
		}
		i++;
	}
}

void	init_counts(int *counts)
{
	int	i;

	i = 0;
	while (i < 6)
	{
		counts[i] = 0;
		i++;
	}
}

void	validate_identifiers(t_map_info *map)
{
	int	counts[6];

	init_counts(counts);
	count_identifiers(map, counts);
	check_invalid_content(map);
	if (counts[0] != 1 || counts[1] != 1 || counts[2] != 1 || \
		counts[3] != 1 || counts[4] != 1 || counts[5] != 1)
	{
		show_error("MAP ERROR: Missing or duplicate identifiers!\n");
	}
}
