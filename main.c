/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junkwak <junkwak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 21:50:45 by junkwak           #+#    #+#             */
/*   Updated: 2025/03/14 12:58:26 by junkwak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include "draw.h"
#include <unistd.h>

/* ------------------- 맵 파싱 관련 함수 ------------------- */

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
	}
	close(fd);
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
		show_error("Error opening file in making_map\n");
	i = 0;
	while ((line = get_next_line(fd)))
	{
		map->map[i] = ft_strdup(line);
		i++;
		free(line);
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

void	init_map(t_game *game, char *argv)
{
	if (!game->map_info)
	{
		game->map_info = (t_map_info *)malloc(sizeof(t_map_info));
		if (!game->map_info)
			show_error("Memory allocation failed for map_info\n");
		memset(game->map_info, 0, sizeof(t_map_info));
	}
	
	game->map_info->height = find_height(game->map_info, argv);
	printf("Map height: %d\n", game->map_info->height);
	
	game->map_info->map = (char **)malloc(sizeof(char *) * (game->map_info->height + 1));
	if (!game->map_info->map)
		show_error("Memory allocation failed for map\n");
	
	making_map(game->map_info, argv);
	game->map_info->width = max_width(game->map_info);
	printf("Map width: %d\n", game->map_info->width);
	
	finding_xy(game->map_info);
	
	printf("Player position: x=%f, y=%f, dir=%c\n", 
		game->map_info->player_x, game->map_info->player_y, game->map_info->player_dir);
}

void	set_texture_paths(t_game *game)
{
	// 텍스처 경로 설정
	game->map_info->north_texture = "textures/north.xpm";
	game->map_info->south_texture = "textures/south.xpm";
	game->map_info->west_texture = "textures/west.xpm";
	game->map_info->east_texture = "textures/east.xpm";
	
	// 바닥과 천장 색상 설정
	game->map_info->floor_color = 0x00AAAAAA;
	game->map_info->ceiling_color = 0x00BBDDFF;
}

void	parse_and_validate_map(t_game *game, char **argv)
{
	int	i;

	printf("Starting map parsing and validation...\n");
	init_map(game, argv[1]);
	
	i = 0;
	printf("Map content:\n");
	while (game->map_info->map[i])
	{
		printf("%s", game->map_info->map[i]);
		i++;
	}
	
	is_it_correct_map(game->map_info, argv[1]);
	
	i = 0;
	printf("\nValidated map:\n");
	while (game->map_info->map[i])
	{
		printf("%s", game->map_info->map[i]);
		i++;
	}
	
	// 텍스처 경로와 색상 설정
	set_texture_paths(game);
}

/* ------------------- 메인 함수 ------------------- */

int	main(int argc, char **argv)
{
	t_game	game;

	if (argc != 2)
		show_error("Error: Invalid number of arguments\n");
	
	// 모든 데이터 초기화
	memset(&game, 0, sizeof(t_game));
	
	// 맵 파싱 및 검증
	parse_and_validate_map(&game, argv);
	
	// 그래픽 시작
	if (!start_draw(&game))
	{
		printf("Error: Failed to initialize drawing engine\n");
		if (game.map_info && game.map_info->map)
			double_free(game.map_info->map);
		if (game.map_info)
			free(game.map_info);
		return (1);
	}
	if (game.draw.mlx)
		free(game.draw.mlx);
	return (0);
}
