/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sooslee <sooslee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 15:30:45 by junkwak           #+#    #+#             */
/*   Updated: 2025/03/21 20:11:05 by sooslee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DRAW_H
# define DRAW_H

# include <stdlib.h>
# include <math.h>
# include "./minilibx-linux/mlx.h"
# include <stdio.h>
# include <string.h>
# include <unistd.h>
# include "./Libft/libft.h"
#include "./get_next_line/get_next_line.h"

# define KEY_ESC 65307
# define KEY_W 119
# define KEY_A 97
# define KEY_S 115
# define KEY_D 100
# define KEY_LEFT 65361
# define KEY_RIGHT 65363


typedef struct s_map_info
{
	char	**map;
	int		width;
	int		height;
	double	player_x;
	double	player_y;
	char	player_dir;
	char	*north_texture;
	char	*south_texture;
	char	*west_texture;
	char	*east_texture;
	int		floor_color;
	int		ceiling_color;
	int		*row_lengths;
	int		player_cnt;//플레이어갯수(파싱)
	// char	*NO;
	// char	*SO;
	// char	*WE;
	// char	*EA;
	// char	*F;
	// char	*C;

}	t_map_info;

typedef struct s_player
{
	double	x;
	double	y;
	double	dir_x;
	double	dir_y;
	double	plane_x;
	double	plane_y;
	double	move_speed;
	double	rot_speed;
}	t_player;

typedef struct s_texture
{
	void	*img;
	int		*data;
	int		width;
	int		height;
	int		bpp;
	int		size_line;
	int		endian;
}	t_texture;

typedef struct s_ray
{
	double	camera_x;
	double	ray_dir_x;
	double	ray_dir_y;
	int		map_x;
	int		map_y;
	double	side_dist_x;
	double	side_dist_y;
	double	delta_dist_x;
	double	delta_dist_y;
	double	perp_wall_dist;
	int		step_x;
	int		step_y;
	int		hit;
	int		side;
	int		line_height;
	int		draw_start;
	int		draw_end;
	int		tex_num;
	double	wall_x;
	int		tex_x;
}	t_ray;

typedef struct s_draw
{
	void		*mlx;
	void		*win;
	void		*img;
	int			*data;
	int			bpp;
	int			size_line;
	int			endian;
	int			win_width;
	int			win_height;
	t_texture	textures[4];
	t_ray		ray;
}	t_draw;

typedef struct s_game
{
	t_map_info	*map_info;
	t_player	player;
	t_draw		draw;
	int			keys[6];
}	t_game;

int		init_draw(t_game *game);
int		load_textures(t_game *game);
void	init_player(t_game *game);
void	cast_rays(t_game *game);
void	perform_dda(t_game *game);
void	calculate_wall_distance(t_game *game);
void	draw_wall_line(t_game *game, int x);
void	update_screen(t_game *game);
void	render_frame(t_game *game);
int		key_press(int key, t_game *game);
int		key_release(int key, t_game *game);
void	move_player(t_game *game);
int		game_loop(t_game *game);
int		exit_game(t_game *game);
int		start_draw(t_game *game);
void	init_dummy_map(t_game *game);
int		is_valid_map_index(t_game *game, int x, int y);
void	init_map_row_lengths(t_game *game);
void	process_map_spaces(t_game *game);

/* parsing*/
void    making_map(t_map_info *test, char *file_name);
void    double_free(char **map);
void    map_parsing(t_map_info *map, int x, int y);
void	is_it_correct_map(t_map_info *map, char *file_name);
void    show_error(char *str);

#endif
