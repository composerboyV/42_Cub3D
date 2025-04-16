/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junkwak <junkwak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 20:01:30 by junkwak           #+#    #+#             */
/*   Updated: 2025/04/15 10:24:29 by junkwak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw.h"

int	find_dir(char *temp)
{
	int	i;

	i = 0;
	while (temp[i] && temp[i] == ' ')
		i++;
	while (temp[i] && temp[i] != ' ')
		i++;
	while (temp[i] && temp[i] == ' ')
		i++;
	return (i);
}

void	set_texture_path(char *line, int i, char **texture)
{
	char	*path;

	path = (char *)malloc(sizeof(char) * (ft_strlen(line) + 1));
	if (!path)
		show_error("Memory allocation failed for texture path\n");
	ft_strlcpy(path, line + i, ft_strlen(line + i) + 1);
	*texture = path;
}

void	init_map_nswe(t_game *game, char *line)
{
	int		i;

	if (!line)
		return ;
	i = find_dir(line);
	if (ft_strncmp(line, "NO ", 3) == 0)
		set_texture_path(line, i, &game->map_info->north_texture);
	else if (ft_strncmp(line, "SO ", 3) == 0)
		set_texture_path(line, i, &game->map_info->south_texture);
	else if (ft_strncmp(line, "WE ", 3) == 0)
		set_texture_path(line, i, &game->map_info->west_texture);
	else if (ft_strncmp(line, "EA ", 3) == 0)
		set_texture_path(line, i, &game->map_info->east_texture);
}

static void	print_texture_paths(t_game *game)
{
	printf("North texture: %s\n", game->map_info->north_texture);
	printf("South texture: %s\n", game->map_info->south_texture);
	printf("West texture: %s\n", game->map_info->west_texture);
	printf("East texture: %s\n", game->map_info->east_texture);
}

void	set_texture_paths(t_game *game, char *file_name)
{
	int		fd;
	char	*line;

	fd = open(file_name, O_RDONLY);
	if (fd < 0)
		show_error("Error opening file in set_texture_paths\n");
	line = get_next_line(fd);
	while (line)
	{
		if (check_its_nswe(line) == 1)
			init_map_nswe(game, line);
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	print_texture_paths(game);
}
