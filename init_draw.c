/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_draw.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junkwak <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 21:57:27 by junkwak           #+#    #+#             */
/*   Updated: 2025/03/11 21:57:38 by junkwak          ###   ########.fr       */
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
	game->draw.win_width = 800;
	game->draw.win_height = 600;
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
