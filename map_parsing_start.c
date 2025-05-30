/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing_start.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junkwak <junkwak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 17:12:30 by junkwak           #+#    #+#             */
/*   Updated: 2025/04/19 19:53:45 by junkwak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw.h"

void	init_map_flags(t_map_flags *flags)
{
	flags->no_found = 0;
	flags->so_found = 0;
	flags->we_found = 0;
	flags->ea_found = 0;
	flags->f_found = 0;
	flags->c_found = 0;
}

int	find_map_start(t_map_info *map)
{
	int			i;
	t_map_flags	flags;
	int			found_all_identifiers;

	i = 0;
	init_map_flags(&flags);
	while (map->map[i])
	{
		check_identifier_in_map_start(map, i, &flags);
		found_all_identifiers = all_identifiers_found(flags);
		if (found_all_identifiers && is_map_start_char(map->map[i][0]))
			break ;
		i++;
	}
	return (i);
}

int	here_is_valid_map_char(char ch)
{
	if (ch == 'N' || ch == 'W' || ch == 'S' || ch == 'E' || \
		ch == ' ' || ch == '1' || ch == '0' || \
		ch == '\n' || ch == '\t' || ch == '\r')
		return (1);
	return (0);
}

int	here_is_strange(char ch)
{
	if (!here_is_valid_map_char(ch) && ch != 'X')
		return (1);
	return (0);
}

void	check_file_name(t_game *game, char *file)
{
	int	len;

	len = ft_strlen(file);
	if (ft_strncmp(file + len - 4, ".cub", 4) != 0)
		cleanup_and_exit(game, "File name is wrong\n", 1);
}
