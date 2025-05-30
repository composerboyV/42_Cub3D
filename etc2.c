/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   etc2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junkwak <junkwak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 22:00:06 by junkwak           #+#    #+#             */
/*   Updated: 2025/04/19 20:05:25 by junkwak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw.h"

static void	free_texture_paths(t_map_info *map_info)
{
	if (map_info->north_texture)
		free(map_info->north_texture);
	if (map_info->south_texture)
		free(map_info->south_texture);
	if (map_info->west_texture)
		free(map_info->west_texture);
	if (map_info->east_texture)
		free(map_info->east_texture);
	if (map_info->row_lengths)
		free(map_info->row_lengths);
}

static void	free_map_array(t_map_info *map_info)
{
	int	i;

	if (map_info->map)
	{
		i = 0;
		while (map_info->map[i])
		{
			free(map_info->map[i]);
			i++;
		}
		free(map_info->map);
	}
}

static void	free_mlx_resources(t_game *game)
{
	int	i;

	i = -1;
	if (game->draw.img)
		mlx_destroy_image(game->draw.mlx, game->draw.img);
	while (++i < 4)
	{
		if (game->draw.textures[i].img)
			mlx_destroy_image(game->draw.mlx, game->draw.textures[i].img);
	}
	if (game->draw.win)
		mlx_destroy_window(game->draw.mlx, game->draw.win);
	if (game->draw.mlx)
		mlx_destroy_display(game->draw.mlx);
	if (game->draw.mlx)
		free(game->draw.mlx);
}

int	exit_game(t_game *game)
{
	if (game->map_info)
	{
		free_texture_paths(game->map_info);
		free_map_array(game->map_info);
		free(game->map_info);
	}
	free_mlx_resources(game);
	exit(0);
	return (0);
}

int	game_loop(t_game *game)
{
	move_player(game);
	render_frame(game);
	return (0);
}
