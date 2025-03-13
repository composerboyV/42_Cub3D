/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junkwak <junkwak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 21:58:15 by junkwak           #+#    #+#             */
/*   Updated: 2025/03/11 22:08:02 by junkwak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw.h"

void	init_map_row_lengths(t_game *game)
{
	int	y;

	if (!game->map_info.row_lengths)
	{
		game->map_info.row_lengths = (int *)malloc(sizeof(int)
				* game->map_info.height);
		if (!game->map_info.row_lengths)
		{
			printf("Failed to allocate memory for row_lengths\n");
			exit_game(game);
		}
	}
	y = -1;
	while (++y < game->map_info.height)
	{
		game->map_info.row_lengths[y] = strlen(game->map_info.map[y]);
		printf("Row %d length: %d\n", y, game->map_info.row_lengths[y]);
	}
}

void	process_map_spaces(t_game *game)
{
	int	y;
	int	x;
	int	row_len;

	y = -1;
	while (++y < game->map_info.height)
	{
		row_len = game->map_info.row_lengths[y];
		x = -1;
		while (++x < row_len)
		{
			if (game->map_info.map[y][x] == ' ')
				game->map_info.map[y][x] = '1';
		}
	}
}
