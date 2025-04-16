/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall_height.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junkwak <junkwak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 16:45:30 by junkwak           #+#    #+#             */
/*   Updated: 2025/04/16 13:52:29 by junkwak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw.h"

static void	set_line_height(t_game *game)
{
	t_ray	*ray;
	int		win_height;

	ray = &game->draw.ray;
	win_height = game->draw.win_height;
	ray->line_height = (int)(win_height / ray->perp_wall_dist);
	if (ray->line_height > win_height * 10)
		ray->line_height = win_height * 10;
}

static void	set_draw_start(t_game *game)
{
	t_ray	*ray;
	int		win_height;

	ray = &game->draw.ray;
	win_height = game->draw.win_height;
	ray->draw_start = -ray->line_height / 2 + win_height / 2;
	if (ray->draw_start < 0)
		ray->draw_start = 0;
	if (ray->draw_start >= win_height)
		ray->draw_start = win_height - 1;
}

static void	set_draw_end(t_game *game)
{
	t_ray	*ray;
	int		win_height;

	ray = &game->draw.ray;
	win_height = game->draw.win_height;
	ray->draw_end = ray->line_height / 2 + win_height / 2;
	if (ray->draw_end < ray->draw_start + 1)
		ray->draw_end = ray->draw_start + 1;
	if (ray->draw_end >= win_height)
		ray->draw_end = win_height - 1;
}

void	set_wall_height(t_game *game)
{
	set_line_height(game);
	set_draw_start(game);
	set_draw_end(game);
}
