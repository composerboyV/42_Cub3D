/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast   3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junkwak <junkwak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 21:58:42 by junkwak           #+#    #+#             */
/*   Updated: 2025/04/05 16:36:33 by junkwak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw.h"

int	is_valid_map_index(t_game *game, int x, int y)
{
	return (y >= 0 && y < game->map_info->height && \
			x >= 0 && x < game->map_info->row_lengths[y]);
}

static void	init_ray_dir(t_game *game, int x)
{
	game->draw.ray.camera_x = 2 * x / (double)game->draw.win_width - 1;
	game->draw.ray.ray_dir_x = game->player.dir_x + game->player.plane_x
		* game->draw.ray.camera_x;
	game->draw.ray.ray_dir_y = game->player.dir_y + game->player.plane_y
		* game->draw.ray.camera_x;
	game->draw.ray.map_x = (int)game->player.x;
	game->draw.ray.map_y = (int)game->player.y;
}

void	cast_rays(t_game *game)
{
	int	x;

	x = -1;
	while (++x < game->draw.win_width)
	{
		init_ray_dir(game, x);
		setup_dda(game);
		perform_dda(game);
		calculate_wall_distance(game);
		draw_wall_line(game, x);
	}
}
