/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_strafe.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junkwak <junkwak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 16:46:50 by junkwak           #+#    #+#             */
/*   Updated: 2025/04/05 18:46:58 by junkwak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw.h"

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
