/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_wall_line.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junkwak <junkwak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 21:59:20 by junkwak           #+#    #+#             */
/*   Updated: 2025/04/19 19:58:20 by junkwak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw.h"

static void	draw_walls(t_game *game, int x, double step, double tex_pos)
{
	int	y;
	int	tex_y;
	int	color;

	y = game->draw.ray.draw_start - 1;
	while (++y < game->draw.ray.draw_end)
	{
		tex_y = (int)tex_pos & (game->draw.textures[game->draw. \
			ray.tex_num].height - 1);
		tex_pos += step;
		color = game->draw.textures[game->draw.ray.tex_num].data[
			game->draw.textures[game->draw.ray.tex_num].height
			* tex_y + game->draw.ray.tex_x];
		game->draw.data[y * game->draw.win_width + x] = color;
	}
}

static void	draw_ceiling(t_game *game, int x)
{
	int	y;
	int	index;

	y = -1;
	while (++y < game->draw.ray.draw_start)
	{
		index = y * game->draw.win_width + x;
		if (index >= 0 && index < game->draw.win_width * game->draw.win_height)
			game->draw.data[index] = game->map_info->ceiling_color;
	}
}

static void	draw_floor(t_game *game, int x)
{
	int	y;

	y = game->draw.ray.draw_end - 1;
	while (++y < game->draw.win_height)
		game->draw.data[y * game->draw.win_width + x] \
			= game->map_info->floor_color;
}

void	draw_wall_line(t_game *game, int x)
{
	double	step;
	double	tex_pos;

	step = 1.0 * game->draw.textures[game->draw.ray.tex_num].height
		/ game->draw.ray.line_height;
	tex_pos = (game->draw.ray.draw_start - game->draw.win_height / 2
			+ game->draw.ray.line_height / 2) * step;
	draw_walls(game, x, step, tex_pos);
	draw_ceiling(game, x);
	draw_floor(game, x);
}

void	show_error(char *str)
{
	ssize_t	result;

	result = write(2, str, ft_strlen(str));
	(void)result;
	exit(1);
}
