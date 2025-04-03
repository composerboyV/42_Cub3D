/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_height.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junkwak <junkwak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 20:00:10 by junkwak           #+#    #+#             */
/*   Updated: 2025/04/03 17:24:34 by junkwak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw.h"

int	find_height(t_map_info *map, char *argv)
{
	int		fd;
	char	*line;

	map->height = 0;
	fd = open(argv, O_RDONLY);
	if (fd < 0)
		show_error("Error opening file in find_height\n");
	while ((line = get_next_line(fd)))
	{
		map->height++;
		free(line);
		line = NULL;
	}
	close(fd);
	free(line);
	return (map->height);
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
			if (map->map[y][x] == 'N' || map->map[y][x] == 'S'
				|| map->map[y][x] == 'W' || map->map[y][x] == 'E')
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
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		map->map[i] = ft_strdup(line);
		free(line);
		line = NULL;
		i++;
	}
	free(line);
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
