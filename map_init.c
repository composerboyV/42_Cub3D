/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_init3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junkwak <junkwak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 20:00:30 by junkwak           #+#    #+#             */
/*   Updated: 2025/04/05 16:45:25 by junkwak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw.h"

static void	alloc_map_info(t_game *game)
{
	if (!game->map_info)
	{
		game->map_info = (t_map_info *)malloc(sizeof(t_map_info));
		if (!game->map_info)
			show_error("Memory allocation failed for map_info\n");
		memset(game->map_info, 0, sizeof(t_map_info));
	}
}

static void	alloc_map(t_game *game)
{
	game->map_info->map = (char **)malloc(sizeof(char *) \
		* (game->map_info->height + 1));
	if (!game->map_info->map)
		show_error("Memory allocation failed for map\n");
}

void	init_map(t_game *game, char *argv)
{
	alloc_map_info(game);
	game->map_info->height = find_height(game->map_info, argv);
	printf("Map height: %d\n", game->map_info->height);
	alloc_map(game);
	making_map(game->map_info, argv);
	game->map_info->width = max_width(game->map_info);
	printf("Map width: %d\n", game->map_info->width);
	finding_xy(game->map_info);
	printf("Player position: x=%f, y=%f, dir=%c\n",
		game->map_info->player_x, game->map_info->player_y,
		game->map_info->player_dir);
}
static void	check_rgb_values(int r, int g, int b, char **colors)
{
	if (r < 0 || r > 255 || g < 0 || g > 255 || b < 0 || b > 255)
	{
		free_split(colors);
		show_error("Error: RGB 값은 0-255 사이여야 합니다\n");
	}
}

void	parse_color(char *line, int *color)
{
	char	**colors;
	int		r;
	int		g;
	int		b;
	int		i;

	colors = ft_split(line, ',');
	i = 0;
	while (colors[i])
		i++;
	if (i != 3)
	{
		free_split(colors);
		show_error("Error: 색상 형식이 잘못되었습니다 (RGB 3개 필요)\n");
	}
	r = ft_atoi(colors[0]);
	g = ft_atoi(colors[1]);
	b = ft_atoi(colors[2]);
	check_rgb_values(r, g, b, colors);
	*color = (r << 16) | (g << 8) | b;
	free_split(colors);
}