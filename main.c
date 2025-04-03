/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sooslee <sooslee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 21:50:45 by junkwak           #+#    #+#             */
/*   Updated: 2025/04/03 20:00:00 by junkwak          ###   ########.fr       */
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

static void	free_map_array(t_map_info *map_info)
{
	int	i;

	if (map_info->map)
	{
		i = 0;
		while (map_info->map[i])
		{
			free(map_info->map[i]);
			i++;
		}
		free(map_info->map);
	}
}

static void	free_textures(t_map_info *map_info)
{
	free(map_info->north_texture);
	free(map_info->south_texture);
	free(map_info->west_texture);
	free(map_info->east_texture);
}

void	cleanup_game(t_game *game)
{
	if (game->map_info)
	{
		free_map_array(game->map_info);
		free_textures(game->map_info);
		free(game->map_info);
	}
}

int	main(int argc, char **argv)
{
	t_game	game;

	if (argc != 2)
		show_error("오류: 인자 개수가 잘못되었습니다\n");
	memset(&game, 0, sizeof(t_game));
	parse_and_validate_map(&game, argv);
	if (!start_draw(&game))
	{
		printf("오류: 그래픽 엔진 초기화 실패\n");
		cleanup_game(&game);
		return (1);
	}
	cleanup_game(&game);
	return (0);
}
