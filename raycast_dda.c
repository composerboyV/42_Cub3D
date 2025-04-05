/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast_dda   4.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junkwak <junkwak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 18:40:30 by junkwak           #+#    #+#             */
/*   Updated: 2025/04/05 16:34:57 by junkwak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw.h"

static void	setup_dda_x(t_game *game)
{
	t_ray	*ray;

	ray = &game->draw.ray;
	ray->delta_dist_x = fabs(1 / ray->ray_dir_x);
	ray->delta_dist_y = fabs(1 / ray->ray_dir_y);
	if (ray->ray_dir_x < 0)
	{
		ray->step_x = -1;
		ray->side_dist_x = (game->player.x - ray->map_x)
			* ray->delta_dist_x;
	}
	else
	{
		ray->step_x = 1;
		ray->side_dist_x = (ray->map_x + 1.0 - game->player.x)
			* ray->delta_dist_x;
	}
}

static void	setup_dda_y(t_game *game)
{
	t_ray	*ray;

	ray = &game->draw.ray;
	if (ray->ray_dir_y < 0)
	{
		ray->step_y = -1;
		ray->side_dist_y = (game->player.y - ray->map_y)
			* ray->delta_dist_y;
	}
	else
	{
		ray->step_y = 1;
		ray->side_dist_y = (ray->map_y + 1.0 - game->player.y)
			* ray->delta_dist_y;
	}
}

void	setup_dda(t_game *game)
{
	setup_dda_x(game);
	setup_dda_y(game);
}

void	perform_dda(t_game *game)
{
	game->draw.ray.hit = 0;
	while (game->draw.ray.hit == 0)
	{
		if (game->draw.ray.side_dist_x < game->draw.ray.side_dist_y)
		{
			game->draw.ray.side_dist_x += game->draw.ray.delta_dist_x;
			game->draw.ray.map_x += game->draw.ray.step_x;
			game->draw.ray.side = 0;
		}
		else
		{
			game->draw.ray.side_dist_y += game->draw.ray.delta_dist_y;
			game->draw.ray.map_y += game->draw.ray.step_y;
			game->draw.ray.side = 1;
		}
		if (!is_valid_map_index(game, game->draw.ray.map_x, \
					game->draw.ray.map_y))
			game->draw.ray.hit = 1;
		else if (game->map_info->map[game->draw.ray.map_y] \
				[game->draw.ray.map_x] == '1')
			game->draw.ray.hit = 1;
	}
}
