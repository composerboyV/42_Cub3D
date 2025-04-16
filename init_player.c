/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junkwak <junkwak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 21:58:30 by junkwak           #+#    #+#             */
/*   Updated: 2025/04/11 12:56:53 by junkwak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw.h"

static void	set_direction_ns(t_game *game, char dir)
{
	if (dir == 'N')
	{
		game->player.dir_x = 0;
		game->player.dir_y = -1;
		game->player.plane_x = 0.66;
		game->player.plane_y = 1;
	}
	else if (dir == 'S')
	{
		game->player.dir_x = 0;
		game->player.dir_y = 1;
		game->player.plane_x = -0.66;
		game->player.plane_y = 0;
	}
}

static void	set_direction_ew(t_game *game, char dir)
{
	if (dir == 'E')
	{
		game->player.dir_x = 1;
		game->player.dir_y = 0;
		game->player.plane_x = 0;
		game->player.plane_y = 0.66;
	}
	else if (dir == 'W')
	{
		game->player.dir_x = -1;
		game->player.dir_y = 0;
		game->player.plane_x = 0;
		game->player.plane_y = -0.66;
	}
}

static void	set_player_direction(t_game *game)
{
	char	dir;

	dir = game->map_info->player_dir;
	if (dir == 'N' || dir == 'S')
		set_direction_ns(game, dir);
	else if (dir == 'E' || dir == 'W')
		set_direction_ew(game, dir);
}

void	init_player(t_game *game)
{
	game->player.x = game->map_info->player_x + 0.5;
	game->player.y = game->map_info->player_y + 0.5;
	set_player_direction(game);
	game->player.move_speed = 0.01;
	game->player.rot_speed = 0.01;
}
