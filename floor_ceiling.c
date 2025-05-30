/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floor_ceiling.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junkwak <junkwak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 18:10:00 by junkwak           #+#    #+#             */
/*   Updated: 2025/04/19 20:03:42 by junkwak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw.h"

static void	process_floor_color(t_game *game, char *line)
{
	char	*color_str;

	if (ft_strncmp(line, "F ", 2) == 0)
	{
		color_str = line + 2;
		while (*color_str == ' ')
			color_str++;
		parse_color(game, color_str, &game->map_info->floor_color);
	}
}

static void	process_ceiling_color(t_game *game, char *line)
{
	char	*color_str;

	if (ft_strncmp(line, "C ", 2) == 0)
	{
		color_str = line + 2;
		while (*color_str == ' ')
			color_str++;
		parse_color(game, color_str, &game->map_info->ceiling_color);
	}
}

void	set_floor_ceiling(t_game *game, char *file_name)
{
	int		fd;
	char	*line;

	fd = open(file_name, O_RDONLY);
	if (fd < 0)
		cleanup_and_exit(game, "Error: 파일 열기 실패\n", 1);
	line = NULL;
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		process_floor_color(game, line);
		process_ceiling_color(game, line);
		free(line);
	}
	close(fd);
}
