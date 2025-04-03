/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_strafe.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junkwak <junkwak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 16:46:50 by junkwak           #+#    #+#             */
/*   Updated: 2025/04/03 16:35:31 by junkwak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw.h"

static int	can_move_to(t_game *game, double new_x, double new_y)
{
	int	map_x;
	int	map_y;

	map_x = (int)new_x;
	map_y = (int)new_y;
	return (is_valid_map_index(game, map_x, map_y)
		&& game->map_info->map[map_y][map_x] != '1');
}

void	move_left(t_game *game)
{
	double	new_x;
	double	new_y;

	if (!game->keys[1])
		return ;
	new_x = game->player.x - game->player.plane_x * game->player.move_speed;
	new_y = game->player.y - game->player.plane_y * game->player.move_speed;
	if (can_move_to(game, new_x, new_y))
	{
		game->player.x = new_x;
		game->player.y = new_y;
	}
}

void	move_right(t_game *game)
{
	double	new_x;
	double	new_y;

	if (!game->keys[3])
		return ;
	new_x = game->player.x + game->player.plane_x * game->player.move_speed;
	new_y = game->player.y + game->player.plane_y * game->player.move_speed;
	if (can_move_to(game, new_x, new_y))
	{
		game->player.x = new_x;
		game->player.y = new_y;
	}
}
