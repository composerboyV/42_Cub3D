/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   etc2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junkwak <junkwak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 22:00:06 by junkwak           #+#    #+#             */
/*   Updated: 2025/04/05 16:41:53 by junkwak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw.h"

int	exit_game(t_game *game)
{
	int	i;

	free(game->map_info->north_texture);
	free(game->map_info->south_texture);
	free(game->map_info->west_texture);
	free(game->map_info->east_texture);
	free(game->map_info->row_lengths);
	if (game->draw.img)
		mlx_destroy_image(game->draw.mlx, game->draw.img);
	i = -1;
	while (++i < 4)
	{
		if (game->draw.textures[i].img)
			mlx_destroy_image(game->draw.mlx, game->draw.textures[i].img);
	}
	if (game->draw.win)
		mlx_destroy_window(game->draw.mlx, game->draw.win);
	if (game->map_info && game->map_info->map)
		double_free(game->map_info->map);
	if (game->map_info)
		free(game->map_info);
	exit(0);
	return (0);
}

int	game_loop(t_game *game)
{
	move_player(game);
	render_frame(game);
	return (0);
}

int	start_draw(t_game *game)
{
	printf("Initializing draw engine...\n");
	init_map_row_lengths(game);
	if (!init_draw(game))
	{
		printf("Failed to initialize MLX\n");
		return (0);
	}
	printf("Loading textures...\n");
	if (!load_textures(game))
	{
		printf("Failed to load textures\n");
		return (0);
	}
	init_player(game);
	mlx_hook(game->draw.win, 2, 1L << 0, key_press, game);
	mlx_hook(game->draw.win, 3, 1L << 1, key_release, game);
	mlx_hook(game->draw.win, 17, 0, exit_game, game);
	printf("Starting game loop...\n");
	mlx_loop_hook(game->draw.mlx, game_loop, game);
	mlx_loop(game->draw.mlx);
	free(game->draw.mlx);
	free(game->draw.win);
	free(game->draw.img);
	free(game->draw.data);
	return (1);
}

void	clean_texture_path(char *path)
{
	int	len;

	if (!path)
		return ;
	len = ft_strlen(path);
	while (len > 0 && (path[len - 1] == '\n' || path[len - 1] == '\r' || \
				path[len - 1] == ' ' || path[len - 1] == '\t'))
	{
		path[len - 1] = '\0';
		len--;
	}
}

int	file_exists(char *filename)
{
	int	fd;

	if (!filename)
		return (0);
	fd = open(filename, O_RDONLY);
	if (fd < 0)
	{
		exit(1);
		return (0);
	}
	close(fd);
	return (1);
}
