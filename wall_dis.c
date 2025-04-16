/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall_dis.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junkwak <junkwak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 21:59:07 by junkwak           #+#    #+#             */
/*   Updated: 2025/04/16 13:54:01 by junkwak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw.h"

static void	set_perpendicular_distance(t_game *game)
{
	t_ray	*ray;

	ray = &game->draw.ray;
	if (ray->side == 0)
		ray->perp_wall_dist = (ray->map_x - game->player.x
				+ (1 - ray->step_x) / 2) / ray->ray_dir_x;
	else
		ray->perp_wall_dist = (ray->map_y - game->player.y
				+ (1 - ray->step_y) / 2) / ray->ray_dir_y;
	if (ray->perp_wall_dist < 0.1)
		ray->perp_wall_dist = 0.1;
	ray->perp_wall_dist = fabs(ray->perp_wall_dist);
}

void	calculate_wall_distance(t_game *game)
{
	set_perpendicular_distance(game);
	set_wall_height(game);
	set_texture_info(game);
}
