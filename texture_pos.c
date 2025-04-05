/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_pos    4.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junkwak <junkwak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 17:00:00 by junkwak           #+#    #+#             */
/*   Updated: 2025/04/05 16:39:03 by junkwak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw.h"

void	set_texture_direction(t_game *game)
{
	t_ray	*ray;

	ray = &game->draw.ray;
	if (ray->side == 0)
	{
		if (ray->ray_dir_x > 0)
			ray->tex_num = 0;
		else
			ray->tex_num = 1;
	}
	else
	{
		if (ray->ray_dir_y > 0)
			ray->tex_num = 2;
		else
			ray->tex_num = 3;
	}
}

static void	set_wall_x(t_game *game)
{
	t_ray	*ray;

	ray = &game->draw.ray;
	if (ray->side == 0)
		ray->wall_x = game->player.y + ray->perp_wall_dist * ray->ray_dir_y;
	else
		ray->wall_x = game->player.x + ray->perp_wall_dist * ray->ray_dir_x;
	ray->wall_x -= floor(ray->wall_x);
}

static void	set_texture_x(t_game *game)
{
	t_ray	*ray;
	int		tex_width;

	ray = &game->draw.ray;
	tex_width = game->draw.textures[ray->tex_num].width;
	ray->tex_x = (int)(ray->wall_x * (double)tex_width);
	if (ray->side == 0 && ray->ray_dir_x > 0)
		ray->tex_x = tex_width - ray->tex_x - 1;
	if (ray->side == 1 && ray->ray_dir_y < 0)
		ray->tex_x = tex_width - ray->tex_x - 1;
}

void	set_texture_info(t_game *game)
{
	set_texture_direction(game);
	set_wall_x(game);
	set_texture_x(game);
}
