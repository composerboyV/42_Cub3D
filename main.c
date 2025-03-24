/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sooslee <sooslee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 21:50:45 by junkwak           #+#    #+#             */
/*   Updated: 2025/03/24 15:17:04 by sooslee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include "draw.h"
#include <unistd.h>

void	free_split(char **split)
{
	int	i;

	i = 0;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
}

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
int	check_its_nswe(char *str)
{
	if(ft_strncmp(str, "NO ", 3) == 0)
		return 1;
	else if(ft_strncmp(str, "SO ", 3) == 0)
		return 1;
	else if(ft_strncmp(str, "WE ", 3) == 0)
		return 1;
	else if(ft_strncmp(str, "EA ", 3) == 0)
		return 1;
	else
		return 0;
}

int find_dir(char *temp)
{
    int i = 0;
    
    // 공백 건너뛰기
    while (temp[i] && temp[i] == ' ')
        i++;
    
    // 식별자 건너뛰기 (NO, SO, WE, EA)
    while (temp[i] && temp[i] != ' ')
        i++;
    
    // 다시 공백 건너뛰기
    while (temp[i] && temp[i] == ' ')
        i++;
    
    return (i);
}

void init_map_nswe(t_game *game, char *line)
{
    char *path;
    int i;
    
    if (!line)
        return;
    
    // 메모리 할당
    path = (char *)malloc(sizeof(char) * (ft_strlen(line) + 1));
    if (!path)
        show_error("Memory allocation failed for texture path\n");
    
    i = find_dir(line);
    
    if (ft_strncmp(line, "NO ", 3) == 0)
    {
        ft_strlcpy(path, line + i, ft_strlen(line + i) + 1);
        game->map_info->north_texture = path;
    }
    else if (ft_strncmp(line, "SO ", 3) == 0)
    {
        ft_strlcpy(path, line + i, ft_strlen(line + i) + 1);
        game->map_info->south_texture = path;
    }
    else if (ft_strncmp(line, "WE ", 3) == 0)
    {
        ft_strlcpy(path, line + i, ft_strlen(line + i) + 1);
        game->map_info->west_texture = path;
    }
    else if (ft_strncmp(line, "EA ", 3) == 0)
    {
        ft_strlcpy(path, line + i, ft_strlen(line + i) + 1);
        game->map_info->east_texture = path;
    }
    else
    {
        free(path); // 해당하는 텍스처가 없으면 메모리 해제
    }
}


void set_texture_paths(t_game *game, char *file_name)
{
    int fd;
    char *line;
    
    fd = open(file_name, O_RDONLY);
    if (fd < 0)
        show_error("Error opening file in set_texture_paths\n");
    
    while ((line = get_next_line(fd)))
    {
        if (check_its_nswe(line) == 1)
            init_map_nswe(game, line);
        free(line);
    }
    close(fd);
    // 텍스처 경로가 제대로 설정되었는지 확인
    printf("North texture: %s\n", game->map_info->north_texture);
    printf("South texture: %s\n", game->map_info->south_texture);
    printf("West texture: %s\n", game->map_info->west_texture);
    printf("East texture: %s\n", game->map_info->east_texture);

    // 바닥과 천장 색상 설정 (기존과 동일)
    // game->map_info->floor_color = 0x00AAAAAA;
    // game->map_info->ceiling_color = 0x00BBDDFF;
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
	if (r < 0 || r > 255 || g < 0 || g > 255 || b < 0 || b > 255)
	{
		free_split(colors);
		show_error("Error: RGB 값은 0-255 사이여야 합니다\n");
	}
	*color = (r << 16) | (g << 8) | b;
	free_split(colors);
}
void	set_floor_ceiling(t_game *game, char *file_name)
{
	int		fd;
	char	*line;
	char	*color_str;

	fd = open(file_name, O_RDONLY);
	if (fd < 0)
		show_error("Error: 파일 열기 실패\n");
	
	while ((line = get_next_line(fd)))
	{
		if (ft_strncmp(line, "F ", 2) == 0)
		{
			color_str = line + 2;
			while (*color_str == ' ')
				color_str++;
			parse_color(color_str, &game->map_info->floor_color);
		}
		else if (ft_strncmp(line, "C ", 2) == 0)
		{
			color_str = line + 2;
			while (*color_str == ' ')
				color_str++;
			parse_color(color_str, &game->map_info->ceiling_color);
		}
		free(line);
	}
	close(fd);
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
	// 텍스처 경로와 색상 설정
	set_texture_paths(game, argv[1]);
	set_floor_ceiling(game, argv[1]);
	printf("바닥 색상: 0x%08X\n", game->map_info->floor_color);
	printf("천장 색상: 0x%08X\n", game->map_info->ceiling_color);
	is_it_correct_map(game->map_info, argv[1]);
	
	i = 0;
	printf("\nValidated map:\n");
	while (game->map_info->map[i])
	{
		printf("%s", game->map_info->map[i]);
		i++;
	}

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
