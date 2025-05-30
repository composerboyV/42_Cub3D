/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junkwak <junkwak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 20:01:00 by junkwak           #+#    #+#             */
/*   Updated: 2025/04/19 19:52:58 by junkwak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw.h"

void	print_map_content(t_game *game)
{
	int	i;

	i = 0;
	printf("Map content:\n");
	while (game->map_info->map[i])
	{
		printf("%s", game->map_info->map[i]);
		i++;
	}
}

int	check_its_nswe(char *str)
{
	if (ft_strncmp(str, "NO ", 3) == 0)
		return (1);
	else if (ft_strncmp(str, "SO ", 3) == 0)
		return (1);
	else if (ft_strncmp(str, "WE ", 3) == 0)
		return (1);
	else if (ft_strncmp(str, "EA ", 3) == 0)
		return (1);
	else
		return (0);
}

void	parse_and_validate_map(t_game *game, char **argv)
{
	printf("Starting map parsing and validation...\n");
	init_map(game, argv[1]);
	print_map_content(game);
	set_texture_paths(game, argv[1]);
	set_floor_ceiling(game, argv[1]);
	printf("바닥 색상: 0x%08X\n", game->map_info->floor_color);
	printf("천장 색상: 0x%08X\n", game->map_info->ceiling_color);
	is_it_correct_map(game, argv[1]);
}
