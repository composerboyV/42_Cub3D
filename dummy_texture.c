/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dummy_texture.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junkwak <junkwak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 21:57:58 by junkwak           #+#    #+#             */
/*   Updated: 2025/03/13 21:18:11 by junkwak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw.h"

static void	create_dummy_texture(t_game *game, int i, int width, int height)
{
	int	color;
	int	x;
	int	y;

	game->draw.textures[i].img = mlx_new_image(game->draw.mlx, width, height);
	game->draw.textures[i].width = width;
	game->draw.textures[i].height = height;
	if (!game->draw.textures[i].img)
		return ;
	game->draw.textures[i].data = (int *)mlx_get_data_addr(
			game->draw.textures[i].img, 
			&game->draw.textures[i].bpp,
			&game->draw.textures[i].size_line,
			&game->draw.textures[i].endian);
	if (i == 0)
		color = 0x00FF0000;
	else if (i == 1)
		color = 0x0000FF00;
	else if (i == 2)
		color = 0x000000FF;
	else
		color = 0x00FFFF00;
	y = -1;
	while (++y < height)
	{
		x = -1;
		while (++x < width)
			game->draw.textures[i].data[y * width + x] = color;
	}
}

int	load_textures(t_game *game)
{
	int		i;
	char	*texture_paths[4];

	texture_paths[0] = game->map_info->north_texture;
	texture_paths[1] = game->map_info->south_texture;
	texture_paths[2] = game->map_info->west_texture;
	texture_paths[3] = game->map_info->east_texture;
	i = -1;
	while (++i < 4)
	{
		printf("Loading texture %d: %s\n", i, texture_paths[i]);
		game->draw.textures[i].img = mlx_xpm_file_to_image(game->draw.mlx,
				texture_paths[i], &game->draw.textures[i].width,
				&game->draw.textures[i].height);
		if (!game->draw.textures[i].img)
		{
			printf("Failed to load texture: %s, creating dummy texture\n",
					texture_paths[i]);
			create_dummy_texture(game, i, 64, 64);
			if (!game->draw.textures[i].img)
				return (0);
		}
		else
			game->draw.textures[i].data = (int *)mlx_get_data_addr(
					game->draw.textures[i].img, &game->draw.textures[i].bpp,
					&game->draw.textures[i].size_line, &game->draw.textures[i].endian);
	}
	return (1);
}
