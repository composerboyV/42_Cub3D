/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_right.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junkwak <junkwak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 16:47:30 by junkwak           #+#    #+#             */
/*   Updated: 2025/04/03 16:35:49 by junkwak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw.h"

static void	rotate_dir_right(t_game *game, double rot_speed)
{
	double	old_dir_x;

	old_dir_x = game->player.dir_x;
	game->player.dir_x = game->player.dir_x * cos(rot_speed)
		- game->player.dir_y * sin(rot_speed);
	game->player.dir_y = old_dir_x * sin(rot_speed)
		+ game->player.dir_y * cos(rot_speed);
}

static void	rotate_plane_right(t_game *game, double rot_speed)
{
	double	old_plane_x;

	old_plane_x = game->player.plane_x;
	game->player.plane_x = game->player.plane_x * cos(rot_speed)
		- game->player.plane_y * sin(rot_speed);
	game->player.plane_y = old_plane_x * sin(rot_speed)
		+ game->player.plane_y * cos(rot_speed);
}

void	rotate_right(t_game *game)
{
	if (!game->keys[5])
		return ;
	rotate_dir_right(game, game->player.rot_speed);
	rotate_plane_right(game, game->player.rot_speed);
}
