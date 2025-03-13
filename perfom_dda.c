/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   perfom_dda.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junkwak <junkwak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 21:58:53 by junkwak           #+#    #+#             */
/*   Updated: 2025/03/11 22:10:20 by junkwak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw.h"

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
		if (!is_valid_map_index(game, game->draw.ray.map_x, game->draw.ray.map_y))
			game->draw.ray.hit = 1;
		else if (game->map_info.map[game->draw.ray.map_y][game->draw.ray.map_x]
				== '1')
			game->draw.ray.hit = 1;
	}
}
