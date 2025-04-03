/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junkwak <junkwak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 20:01:30 by junkwak           #+#    #+#             */
/*   Updated: 2025/04/04 15:00:35 by junkwak          ###   ########.fr       */
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
