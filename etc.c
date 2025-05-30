/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   etc.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junkwak <junkwak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 21:59:33 by junkwak           #+#    #+#             */
/*   Updated: 2025/04/19 20:03:17 by junkwak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw.h"

void	update_screen(t_game *game)
{
	mlx_put_image_to_window(game->draw.mlx, game->draw.win,
		game->draw.img, 0, 0);
}

void	render_frame(t_game *game)
{
	ft_memset(game->draw.data, 0, game->draw.win_width
		* game->draw.win_height * sizeof(int));
	cast_rays(game);
	update_screen(game);
}

int	key_press(int key, t_game *game)
{
	if (key == KEY_ESC)
		exit_game(game);
	else if (key == KEY_W)
		game->keys[0] = 1;
	else if (key == KEY_A)
		game->keys[1] = 1;
	else if (key == KEY_S)
		game->keys[2] = 1;
	else if (key == KEY_D)
		game->keys[3] = 1;
	else if (key == KEY_LEFT)
		game->keys[4] = 1;
	else if (key == KEY_RIGHT)
		game->keys[5] = 1;
	return (0);
}

int	key_release(int key, t_game *game)
{
	if (key == KEY_W)
		game->keys[0] = 0;
	else if (key == KEY_A)
		game->keys[1] = 0;
	else if (key == KEY_S)
		game->keys[2] = 0;
	else if (key == KEY_D)
		game->keys[3] = 0;
	else if (key == KEY_LEFT)
		game->keys[4] = 0;
	else if (key == KEY_RIGHT)
		game->keys[5] = 0;
	return (0);
}

void	double_free(char **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
}
