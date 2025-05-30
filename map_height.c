/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_height.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junkwak <junkwak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 20:00:10 by junkwak           #+#    #+#             */
/*   Updated: 2025/04/19 19:49:49 by junkwak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw.h"

int	find_height(t_game *game, char *argv)
{
	int		fd;
	char	*line;

	game->map_info->height = 0;
	fd = open(argv, O_RDONLY);
	if (fd < 0)
		cleanup_and_exit(game, "Error opening file in find_height\n", 1);
	line = get_next_line(fd);
	while (line)
	{
		game->map_info->height++;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (game->map_info->height);
}

static int	is_player_char(char c)
{
	return (c == 'N' || c == 'S' || c == 'W' || c == 'E');
}

void	finding_xy(t_map_info *map)
{
	int	y;
	int	x;

	y = 0;
	while (map->map[y])
	{
		x = 0;
		while (map->map[y][x])
		{
			if (is_player_char(map->map[y][x]))
			{
				map->player_x = x;
				map->player_y = y;
				map->player_dir = map->map[y][x];
				break ;
			}
			x++;
		}
		y++;
	}
}

void	making_map(t_map_info *map, char *file_name)
{
	int		i;
	int		fd;
	char	*line;

	fd = open(file_name, O_RDONLY);
	if (fd < 0)
		show_error("파일 열기 오류 (making_map)\n");
	i = 0;
	line = get_next_line(fd);
	while (line)
	{
		map->map[i] = ft_strdup(line);
		free(line);
		line = get_next_line(fd);
		i++;
	}
	map->map[i] = NULL;
	close(fd);
}

int	max_width(t_map_info *map)
{
	int		i;
	size_t	max;

	i = 0;
	if (!map->map[i])
		return (0);
	max = ft_strlen(map->map[i]);
	while (map->map[i])
	{
		if (max < ft_strlen(map->map[i]))
			max = ft_strlen(map->map[i]);
		i++;
	}
	return ((int)max);
}
