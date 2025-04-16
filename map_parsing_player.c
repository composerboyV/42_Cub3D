/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing_player.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junkwak <junkwak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 17:10:01 by junkwak           #+#    #+#             */
/*   Updated: 2025/04/03 17:10:05 by junkwak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw.h"

int	is_player_or_zero(char ch)
{
	if (ch == '0' || ch == 'N' || ch == 'S' || ch == 'E' || ch == 'W')
		return (1);
	return (0);
}

void	count_player(t_map_info *map, int x, int y)
{
	if (map->map[y][x] == 'N' || map->map[y][x] == 'S' || \
		map->map[y][x] == 'W' || map->map[y][x] == 'E')
	{
		map->player_cnt++;
		map->player_x = x;
		map->player_y = y;
		map->player_dir = map->map[y][x];
	}
}

void	are_you_alone(t_map_info *map)
{
	int	y;
	int	x;

	y = find_map_start(map);
	map->player_cnt = 0;
	while (y < map->height)
	{
		x = 0;
		while (map->map[y][x] != '\0')
		{
			count_player(map, x, y);
			x++;
		}
		y++;
	}
	if (map->player_cnt != 1)
	{
		show_error("Count of player is wrong\n");
	}
}

void	move_player(t_game *game)
{
	move_forward(game);
	move_backward(game);
	move_left(game);
	move_right(game);
	rotate_left(game);
	rotate_right(game);
}
