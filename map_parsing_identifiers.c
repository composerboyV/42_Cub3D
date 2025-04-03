/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing_identifiers.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junkwak <junkwak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 17:12:00 by junkwak           #+#    #+#             */
/*   Updated: 2025/04/03 17:09:39 by junkwak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw.h"

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

void	check_identifier_in_map_start(t_map_info *map, int i, \
		t_map_flags *flags)
{
	if (ft_strncmp(map->map[i], "NO ", 3) == 0)
		flags->no_found = 1;
	else if (ft_strncmp(map->map[i], "SO ", 3) == 0)
		flags->so_found = 1;
	else if (ft_strncmp(map->map[i], "WE ", 3) == 0)
		flags->we_found = 1;
	else if (ft_strncmp(map->map[i], "EA ", 3) == 0)
		flags->ea_found = 1;
	else if (ft_strncmp(map->map[i], "F ", 2) == 0)
		flags->f_found = 1;
	else if (ft_strncmp(map->map[i], "C ", 2) == 0)
		flags->c_found = 1;
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
