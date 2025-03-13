/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junkwak <junkwak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 21:59:42 by junkwak           #+#    #+#             */
/*   Updated: 2025/03/13 21:20:37 by junkwak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw.h"

static void	move_forward_backward(t_game *game)
{
	double	new_x;
	double	new_y;
	int		map_x;
	int		map_y;

	if (game->keys[0])
	{
		new_x = game->player.x + game->player.dir_x * game->player.move_speed;
		new_y = game->player.y + game->player.dir_y * game->player.move_speed;
		map_x = (int)new_x;
		map_y = (int)new_y;
		if (is_valid_map_index(game, map_x, map_y)
			&& game->map_info->map[map_y][map_x] != '1')
		{
			game->player.x = new_x;
			game->player.y = new_y;
		}
	}
	if (game->keys[2])
	{
		new_x = game->player.x - game->player.dir_x * game->player.move_speed;
		new_y = game->player.y - game->player.dir_y * game->player.move_speed;
		if (game->map_info->map[(int)new_y][(int)new_x] != '1')
		{
			game->player.x = new_x;
			game->player.y = new_y;
		}
	}
}

static void	move_left_right(t_game *game)
{
	double	new_x;
	double	new_y;

	if (game->keys[1])
	{
		new_x = game->player.x - game->player.plane_x * game->player.move_speed;
		new_y = game->player.y - game->player.plane_y * game->player.move_speed;
		if (game->map_info->map[(int)new_y][(int)new_x] != '1')
		{
			game->player.x = new_x;
			game->player.y = new_y;
		}
	}
	if (game->keys[3])
	{
		new_x = game->player.x + game->player.plane_x * game->player.move_speed;
		new_y = game->player.y + game->player.plane_y * game->player.move_speed;
		if (game->map_info->map[(int)new_y][(int)new_x] != '1')
		{
			game->player.x = new_x;
			game->player.y = new_y;
		}
	}
}

static void	rotate_left(t_game *game)
{
	double	old_dir_x;
	double	old_plane_x;

	if (game->keys[4])
	{
		old_dir_x = game->player.dir_x;
		game->player.dir_x = game->player.dir_x * cos(-game->player.rot_speed)
			- game->player.dir_y * sin(-game->player.rot_speed);
		game->player.dir_y = old_dir_x * sin(-game->player.rot_speed)
			+ game->player.dir_y * cos(-game->player.rot_speed);
		old_plane_x = game->player.plane_x;
		game->player.plane_x = game->player.plane_x * cos(-game->player.rot_speed)
			- game->player.plane_y * sin(-game->player.rot_speed);
		game->player.plane_y = old_plane_x * sin(-game->player.rot_speed)
			+ game->player.plane_y * cos(-game->player.rot_speed);
	}
}

static void	rotate_right(t_game *game)
{
	double	old_dir_x;
	double	old_plane_x;

	if (game->keys[5])
	{
		old_dir_x = game->player.dir_x;
		game->player.dir_x = game->player.dir_x * cos(game->player.rot_speed)
			- game->player.dir_y * sin(game->player.rot_speed);
		game->player.dir_y = old_dir_x * sin(game->player.rot_speed)
			+ game->player.dir_y * cos(game->player.rot_speed);
		old_plane_x = game->player.plane_x;
		game->player.plane_x = game->player.plane_x * cos(game->player.rot_speed)
			- game->player.plane_y * sin(game->player.rot_speed);
		game->player.plane_y = old_plane_x * sin(game->player.rot_speed)
			+ game->player.plane_y * cos(game->player.rot_speed);
	}
}

void	move_player(t_game *game)
{
	move_forward_backward(game);
	move_left_right(game);
	rotate_left(game);
	rotate_right(game);
}
