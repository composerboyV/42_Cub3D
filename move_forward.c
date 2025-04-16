/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_forward.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junkwak <junkwak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 16:46:30 by junkwak           #+#    #+#             */
/*   Updated: 2025/04/16 13:54:51 by junkwak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw.h"

static int	check_wall_collision(t_game *game, int map_x, int map_y)
{
	if (!is_valid_map_index(game, map_x, map_y)
		|| game->map_info->map[map_y][map_x] == '1')
		return (1);
	return (0);
}

static int	check_adjacent_walls(t_game *game, double x, double y,
		double margin)
{
	int	map_x;
	int	map_y;

	map_x = (int)x;
	map_y = (int)y;
	if ((x - map_x < margin && check_wall_collision(game, map_x - 1, map_y))
		|| (map_x + 1 - x < margin
			&& check_wall_collision(game, map_x + 1, map_y))
		|| (y - map_y < margin && check_wall_collision(game, map_x, map_y - 1))
		|| (map_y + 1 - y < margin
			&& check_wall_collision(game, map_x, map_y + 1)))
		return (1);
	return (0);
}

static int	check_diagonal_walls(t_game *game, double x, double y,
		double margin)
{
	int	map_x;
	int	map_y;

	map_x = (int)x;
	map_y = (int)y;
	if ((x - map_x < margin && y - map_y < margin
			&& check_wall_collision(game, map_x - 1, map_y - 1))
		|| (map_x + 1 - x < margin && y - map_y < margin
			&& check_wall_collision(game, map_x + 1, map_y - 1))
		|| (x - map_x < margin && map_y + 1 - y < margin
			&& check_wall_collision(game, map_x - 1, map_y + 1))
		|| (map_x + 1 - x < margin && map_y + 1 - y < margin
			&& check_wall_collision(game, map_x + 1, map_y + 1)))
		return (1);
	return (0);
}

int	can_move_to(t_game *game, double new_x, double new_y)
{
	double	margin;
	int		map_x;
	int		map_y;

	margin = 0.2;
	map_x = (int)new_x;
	map_y = (int)new_y;
	if (check_wall_collision(game, map_x, map_y))
		return (0);
	if (check_adjacent_walls(game, new_x, new_y, margin))
		return (0);
	if (check_diagonal_walls(game, new_x, new_y, margin))
		return (0);
	return (1);
}
