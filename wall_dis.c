/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall_dis.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junkwak <junkwak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 21:59:07 by junkwak           #+#    #+#             */
/*   Updated: 2025/03/14 10:34:15 by junkwak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw.h"

static void	set_perpendicular_distance(t_game *game)
{
	if (game->draw.ray.side == 0)
		game->draw.ray.perp_wall_dist = (game->draw.ray.map_x - game->player.x
				+ (1 - game->draw.ray.step_x) / 2) / game->draw.ray.ray_dir_x;
	else
		game->draw.ray.perp_wall_dist = (game->draw.ray.map_y - game->player.y
				+ (1 - game->draw.ray.step_y) / 2) / game->draw.ray.ray_dir_y;
	if (game->draw.ray.perp_wall_dist < 0.1)
		game->draw.ray.perp_wall_dist = 0.1;
	game->draw.ray.perp_wall_dist = fabs(game->draw.ray.perp_wall_dist);
}

static void	set_wall_height(t_game *game)
{
	game->draw.ray.line_height = (int)(game->draw.win_height
			/ game->draw.ray.perp_wall_dist);
	if (game->draw.ray.line_height > game->draw.win_height * 2)
		game->draw.ray.line_height = game->draw.win_height * 2;
	game->draw.ray.draw_start = -game->draw.ray.line_height / 2
		+ game->draw.win_height / 2;
	if (game->draw.ray.draw_start < 0)
		game->draw.ray.draw_start = 0;
	if (game->draw.ray.draw_start >= game->draw.win_height)
		game->draw.ray.draw_start = game->draw.win_height - 1;
	game->draw.ray.draw_end = game->draw.ray.line_height / 2
		+ game->draw.win_height / 2;
	if (game->draw.ray.draw_end < game->draw.ray.draw_start + 1)
		game->draw.ray.draw_end = game->draw.ray.draw_start + 1;
	if (game->draw.ray.draw_end >= game->draw.win_height)
		game->draw.ray.draw_end = game->draw.win_height - 1;
}

static void	set_texture_info(t_game *game)
{
	if (game->draw.ray.side == 0)
	{
		if (game->draw.ray.ray_dir_x > 0)
			game->draw.ray.tex_num = 0;
		else
			game->draw.ray.tex_num = 1;
	}
	else
	{
		if (game->draw.ray.ray_dir_y > 0)
			game->draw.ray.tex_num = 2;
		else
			game->draw.ray.tex_num = 3;
	}
	if (game->draw.ray.side == 0)
		game->draw.ray.wall_x = game->player.y + game->draw.ray.perp_wall_dist
			* game->draw.ray.ray_dir_y;
	else
		game->draw.ray.wall_x = game->player.x + game->draw.ray.perp_wall_dist
			* game->draw.ray.ray_dir_x;
	game->draw.ray.wall_x -= floor(game->draw.ray.wall_x);
	game->draw.ray.tex_x = (int)(game->draw.ray.wall_x
			* (double)game->draw.textures[game->draw.ray.tex_num].width);
	if (game->draw.ray.side == 0 && game->draw.ray.ray_dir_x > 0)
		game->draw.ray.tex_x = game->draw.textures[game->draw.ray.tex_num].width
			- game->draw.ray.tex_x - 1;
	if (game->draw.ray.side == 1 && game->draw.ray.ray_dir_y < 0)
		game->draw.ray.tex_x = game->draw.textures[game->draw.ray.tex_num].width
			- game->draw.ray.tex_x - 1;
}

void	calculate_wall_distance(t_game *game)
{
	set_perpendicular_distance(game);
	set_wall_height(game);
	set_texture_info(game);
}
