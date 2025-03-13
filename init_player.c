/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junkwak <junkwak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 21:58:30 by junkwak           #+#    #+#             */
/*   Updated: 2025/03/13 21:20:13 by junkwak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw.h"

static void	set_player_direction(t_game *game)
{
	if (game->map_info->player_dir == 'N')
	{
		game->player.dir_x = 0;
		game->player.dir_y = -1;
		game->player.plane_x = 0.66;
		game->player.plane_y = 0;
	}
	else if (game->map_info->player_dir == 'S')
	{
		game->player.dir_x = 0;
		game->player.dir_y = 1;
		game->player.plane_x = -0.66;
		game->player.plane_y = 0;
	}
	else if (game->map_info->player_dir == 'E')
	{
		game->player.dir_x = 1;
		game->player.dir_y = 0;
		game->player.plane_x = 0;
		game->player.plane_y = 0.66;
	}
	else if (game->map_info->player_dir == 'W')
	{
		game->player.dir_x = -1;
		game->player.dir_y = 0;
		game->player.plane_x = 0;
		game->player.plane_y = -0.66;
	}
}

void	init_player(t_game *game)
{
	game->player.x = game->map_info->player_x + 0.5;
	game->player.y = game->map_info->player_y + 0.5;
	set_player_direction(game);
	game->player.move_speed = 0.01;
	game->player.rot_speed = 0.01;
}
