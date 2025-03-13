/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junkwak <junkwak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 13:56:06 by junkwak           #+#    #+#             */
/*   Updated: 2025/03/13 21:34:46 by junkwak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw.h"
#include <stdlib.h>
#include <string.h>

static void	allocate_map_memory(t_game *game)
{
	int	i;

	game->map_info->map = (char **)malloc(sizeof(char *)
			* game->map_info->height);
	if (!game->map_info->map)
		return ;
	i = -1;
	while (++i < game->map_info->height)
	{
		game->map_info->map[i] = (char *)malloc(sizeof(char)
				* (game->map_info->width + 1));
		if (!game->map_info->map[i])
			return ;
	}
}

static void	copy_map_data(t_game *game)
{
	const char	*map_data[10] = {
		"11111111111111111111",
		"10000000000000000001",
		"10000000000000000001",
		"10000000000000000001",
		"10000000001111111111",
		"1000N000001",
		"1000000001",
		"1000111101",
		"1000110001",
		"1111111111"
	};
	int			i;

	i = -1;
	while (++i < game->map_info->height)
		strcpy(game->map_info->map[i], map_data[i]);
}

void	init_dummy_map(t_game *game)
{
	// printf("map_info->width 의 값은 : %d\n\n", game->map_info->width);
	// printf("map_info->height 의 값은 : %d\n\n", game->map_info->height);
	// game->map_info.width = 10;
	// game->map_info.height = 10;
	allocate_map_memory(game);
	copy_map_data(game);
	game->map_info->player_x = 4;
	game->map_info->player_y = 4;
	game->map_info->player_dir = 'N';
	game->map_info->north_texture = "textures/north.xpm";
	game->map_info->south_texture = "textures/south.xpm";
	game->map_info->west_texture = "textures/west.xpm";
	game->map_info->east_texture = "textures/east.xpm";
	game->map_info->floor_color = 0x00AAAAAA;
	game->map_info->ceiling_color = 0x00BBDDFF;
}
