/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_draw.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junkwak <junkwak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 21:57:27 by junkwak           #+#    #+#             */
/*   Updated: 2025/04/16 13:57:08 by junkwak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*ptr;

	ptr = (unsigned char *)b;
	while (len--)
		*ptr++ = (unsigned char)c;
	return (b);
}

int	init_draw(t_game *game)
{
	game->draw.mlx = mlx_init();
	if (!game->draw.mlx)
		return (0);
	game->draw.win_width = 1980;
	game->draw.win_height = 1080;
	game->draw.win = mlx_new_window(game->draw.mlx, game->draw.win_width,
			game->draw.win_height, "cub3D");
	if (!game->draw.win)
		return (0);
	game->draw.img = mlx_new_image(game->draw.mlx, game->draw.win_width,
			game->draw.win_height);
	if (!game->draw.img)
		return (0);
	game->draw.data = (int *)mlx_get_data_addr(game->draw.img, &game->draw.bpp,
			&game->draw.size_line, &game->draw.endian);
	return (1);
}

void	init_map_row_lengths(t_game *game)
{
	int	y;

	if (!game->map_info->row_lengths)
	{
		game->map_info->row_lengths = (int *)malloc(sizeof(int)
				* game->map_info->height);
		if (!game->map_info->row_lengths)
		{
			show_error("Failed to allocate memory for row_lengths\n");
			exit_game(game);
		}
	}
	y = -1;
	while (++y < game->map_info->height)
	{
		game->map_info->row_lengths[y] = strlen(game->map_info->map[y]);
	}
}

void	process_map_spaces(t_game *game)
{
	int	y;
	int	x;
	int	row_len;

	y = -1;
	while (++y < game->map_info->height)
	{
		row_len = game->map_info->row_lengths[y];
		x = -1;
		while (++x < row_len)
		{
			if (game->map_info->map[y][x] == ' ')
				game->map_info->map[y][x] = '1';
		}
	}
}
