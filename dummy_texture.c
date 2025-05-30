/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dummy_texture.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junkwak <junkwak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 15:18:19 by junkwak           #+#    #+#             */
/*   Updated: 2025/04/19 20:05:57 by junkwak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw.h"

static void	create_dummy_texture(t_game *game, int i, int w, int h)
{
	int	color[4];
	int	x;
	int	y;

	color[0] = 0x00FF0000;
	color[1] = 0x0000FF00;
	color[2] = 0x000000FF;
	color[3] = 0x00FFFF00;
	game->draw.textures[i].img = mlx_new_image(game->draw.mlx, w, h);
	game->draw.textures[i].width = w;
	game->draw.textures[i].height = h;
	if (!game->draw.textures[i].img)
		return ;
	game->draw.textures[i].data = (int *)mlx_get_data_addr \
		(game->draw.textures[i].img, \
		&game->draw.textures[i].bpp, \
		&game->draw.textures[i].size_line, \
		&game->draw.textures[i].endian);
	y = -1;
	while (++y < h)
	{
		x = -1;
		while (++x < w)
			game->draw.textures[i].data[y * w + x] = color[i];
	}
}

static void	clean_all_texture_paths(t_map_info *map_info)
{
	if (map_info->north_texture)
		clean_texture_path(map_info->north_texture);
	if (map_info->south_texture)
		clean_texture_path(map_info->south_texture);
	if (map_info->west_texture)
		clean_texture_path(map_info->west_texture);
	if (map_info->east_texture)
		clean_texture_path(map_info->east_texture);
}

static char	**prepare_texture_paths(t_game *game)
{
	static char	*texture_paths[4];

	texture_paths[0] = game->map_info->north_texture;
	texture_paths[1] = game->map_info->south_texture;
	texture_paths[2] = game->map_info->west_texture;
	texture_paths[3] = game->map_info->east_texture;
	return (texture_paths);
}

static int	load_single_texture(t_game *game, char *path, int index)
{
	if (!path || ft_strlen(path) == 0)
	{
		create_dummy_texture(game, index, 64, 64);
		return (1);
	}
	game->draw.textures[index].img = mlx_xpm_file_to_image(
			game->draw.mlx, path,
			&game->draw.textures[index].width,
			&game->draw.textures[index].height);
	if (!game->draw.textures[index].img)
	{
		create_dummy_texture(game, index, 64, 64);
		if (!game->draw.textures[index].img)
			return (0);
		return (1);
	}
	game->draw.textures[index].data = (int *)mlx_get_data_addr(
			game->draw.textures[index].img,
			&game->draw.textures[index].bpp,
			&game->draw.textures[index].size_line,
			&game->draw.textures[index].endian);
	return (1);
}

int	load_textures(t_game *game)
{
	char	**texture_paths;
	int		i;

	clean_all_texture_paths(game->map_info);
	texture_paths = prepare_texture_paths(game);
	i = -1;
	while (++i < 4)
	{
		if (!file_exists(texture_paths[i]))
		{
			cleanup_and_exit(game, "Error: Texture file not found\n", 1);
		}
	}
	i = -1;
	while (++i < 4)
	{
		if (!load_single_texture(game, texture_paths[i], i))
			return (0);
	}
	return (1);
}
