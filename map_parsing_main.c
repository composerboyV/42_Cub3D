/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing_main.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junkwak <junkwak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 17:15:00 by junkwak           #+#    #+#             */
/*   Updated: 2025/04/03 17:08:07 by junkwak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw.h"

void	is_it_correct_map(t_map_info *map, char *file_name)
{
	check_file_name(file_name);
	check_map_characters(map);
	check_for_non_map_content(map);
	check_map_boundaries(map);
	are_you_alone(map);
	check_flood_fill_map(map);
	map_parsing(map, map->player_x, map->player_y);
}
