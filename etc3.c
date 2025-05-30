/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   etc3.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junkwak <junkwak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/19 20:02:50 by junkwak           #+#    #+#             */
/*   Updated: 2025/04/19 20:04:37 by junkwak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw.h"

int	start_draw(t_game *game)
{
	init_map_row_lengths(game);
	if (!init_draw(game))
	{
		cleanup_and_exit(game, "Failed to initialize MLX\n", 1);
		return (0);
	}
	if (!load_textures(game))
	{
		cleanup_and_exit(game, "Failed to load textures\n", 1);
		return (0);
	}
	init_player(game);
	mlx_hook(game->draw.win, 2, 1L << 0, key_press, game);
	mlx_hook(game->draw.win, 3, 1L << 1, key_release, game);
	mlx_hook(game->draw.win, 17, 0, exit_game, game);
	mlx_loop_hook(game->draw.mlx, game_loop, game);
	mlx_loop(game->draw.mlx);
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
	int	len;

	if (!filename)
		return (0);
	len = ft_strlen(filename);
	if (len < 4 || ft_strncmp(filename + len - 4, ".xpm", 4) != 0)
		return (0);
	fd = open(filename, O_RDONLY);
	if (fd < 0)
	{
		return (0);
	}
	close(fd);
	return (1);
}

void	cleanup_and_exit(t_game *game, char *error_msg, int exit_code)
{
	int	i;

	if (error_msg)
		write(2, error_msg, ft_strlen(error_msg));
	if (game)
	{	
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
		cleanup_game(game);
	}
	exit(exit_code);
}
