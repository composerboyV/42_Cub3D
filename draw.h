/* ************************************************************************** */
/*		                                                                      */
/*                                                        :::      ::::::::   */
/*   draw.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junkwak <junkwak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 16:00:47 by junkwak           #+#    #+#             */
/*   Updated: 2025/04/05 16:09:19 by junkwak          ###   ########.fr       */
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
# include "./get_next_line/get_next_line.h"

# define KEY_ESC 65307
# define KEY_W 119
# define KEY_A 97
# define KEY_S 115
# define KEY_D 100
# define KEY_LEFT 65361
# define KEY_RIGHT 65363

typedef struct s_identifier_count
{
	int	no;
	int	so;
	int	we;
	int	ea;
	int	f;
	int	c;
}	t_identifier_count;

typedef struct s_map_flags
{
	int	no_found;
	int	so_found;
	int	we_found;
	int	ea_found;
	int	f_found;
	int	c_found;
}	t_map_flags;

typedef struct s_map_validator
{
	int	in_map;
	int	map_end;
	int	start_y;
	int	end_y;
	int	map_start;
}	t_map_validator;

typedef struct s_map_info
{
	double	player_x;
	double	player_y;
	char	**map;
	char	player_dir;
	char	*north_texture;
	char	*south_texture;
	char	*west_texture;
	char	*east_texture;
	int		width;
	int		height;
	int		floor_color;
	int		ceiling_color;
	int		*row_lengths;
	int		player_cnt;
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

void	init_player(t_game *game);
void	cast_rays(t_game *game);
void	perform_dda(t_game *game);
void	calculate_wall_distance(t_game *game);
void	draw_wall_line(t_game *game, int x);
void	update_screen(t_game *game);
void	render_frame(t_game *game);
void	move_player(t_game *game);
void	init_map_row_lengths(t_game *game);
void	process_map_spaces(t_game *game);
void	making_map(t_map_info *test, char *file_name);
void	double_free(char **map);
void	map_parsing(t_map_info *map, int x, int y);
void	is_it_correct_map(t_game *game, char *file_name);
void	move_backward(t_game *game);
void	show_error(char *str);
void	check_boundaries(t_map_info *map, int x, int y);
void	mark_visited(t_map_info *map, int x, int y);
void	check_invalid_char_in_line(t_map_info *map, int y);
void	check_map_characters(t_map_info *map);
void	check_map_line(t_map_info *map, int y, int *in_map, int *map_end);
void	check_for_non_map_content(t_map_info *map);
void	validate_identifiers(t_map_info *map);
void	count_player(t_map_info *map, int x, int y);
void	are_you_alone(t_map_info *map);
void	check_map_boundaries(t_map_info *map);
void	check_flood_fill_map(t_map_info *map);
void	init_map_flags(t_map_flags *flags);
void	check_line_ending(t_map_info *map, int y);
void	move_forward(t_game *game);
void	move_left(t_game *game);
void	move_right(t_game *game);
void	rotate_left(t_game *game);
void	rotate_right(t_game *game);
void	set_texture_direction(t_game *game);
void	set_wall_height(t_game *game);
void	set_texture_info(t_game *game);
void	check_cell(t_map_info *map, int i, int j);
void	check_boundary_line(char *line, char *error_msg);
void	init_map_validator(t_map_validator *validator, t_map_info *map);
void	count_player(t_map_info *map, int x, int y);
void	are_you_alone(t_map_info *map);
void	check_boundary_line(char *line, char *error_msg);
void	init_map_validator(t_map_validator *validator, t_map_info *map);
void	check_map_lines(t_map_info *map, int start_y);
void	check_map_boundaries(t_map_info *map);
void	check_identifier_in_map_start(t_map_info *map, int i, \
		t_map_flags *flags);
void	check_line_ending(t_map_info *map, int y);
void	check_cell(t_map_info *map, int i, int j);
void	check_flood_fill_map(t_map_info *map);
void	init_map_flags(t_map_flags *flags);
void	check_file_name(t_game *game, char *file);
void	check_boundaries(t_map_info *map, int x, int y);
void	mark_visited(t_map_info *map, int x, int y);
void	map_parsing(t_map_info *map, int x, int y);
void	check_invalid_char_in_line(t_map_info *map, int y);
void	count_identifiers(t_map_info *map, int *counts);
void	check_invalid_content(t_map_info *map);
void	init_counts(int *counts);
void	validate_identifiers(t_map_info *map);
void	check_map_characters(t_map_info *map);
void	check_map_line_status(t_map_info *map, int y, int *in_map,
			int *map_end);
void	check_map_line(t_map_info *map, int y, int *in_map, int *map_end);
void	check_for_non_map_content(t_map_info *map);
void	finding_xy(t_map_info *map);
void	making_map(t_map_info *map, char *file_name);
void	init_map(t_game *game, char *argv);
void	parse_and_validate_map(t_game *game, char **argv);
void	init_map_nswe(t_game *game, char *line);
void	set_texture_paths(t_game *game, char *file_name);
void	parse_color(t_game *game, char *line, int *color);
void	set_floor_ceiling(t_game *game, char *file_name);
void	setup_dda(t_game *game);
void	print_map_content(t_game *game);
void	print_validated_map(t_game *game);
void	set_texture_path(char *line, int i, char **texture);
void	set_texture_paths(t_game *game, char *file_name);
void	set_floor_ceiling(t_game *game, char *file_name);
void	clean_texture_path(char *path);
void	setup_dda(t_game *game);
void	free_split(char **split);
void	cleanup_game(t_game *game);
void	cleanup_and_exit(t_game *game, char *error_msg, int exit_code);

int		init_draw(t_game *game);
int		all_identifiers_found(t_map_flags flags);
int		load_textures(t_game *game);
int		key_press(int key, t_game *game);
int		key_release(int key, t_game *game);
int		game_loop(t_game *game);
int		exit_game(t_game *game);
int		start_draw(t_game *game);
int		is_valid_map_index(t_game *game, int x, int y);
int		find_map_start(t_map_info *map);
int		here_is_strange(char ch);
int		here_is_valid_map_char(char ch);
int		is_map_line(char *line);
int		is_only_spaces(char *line);
int		is_map_identifier(char *line);
int		has_wall_in_line(char *line);
int		find_max_width(t_map_info *map, int start_y);
int		is_valid_boundary_char(char ch);
int		is_at_edge(t_map_info *map, int i, int j);
int		is_player_or_zero(char ch);
int		is_near_space_or_out_of_bounds(t_map_info *map, int i, int j);
int		find_last_non_space(char *line);
int		is_at_edge(t_map_info *map, int i, int j);
int		is_near_space_or_out_of_bounds(t_map_info *map, int i, int j);
int		find_max_width(t_map_info *map, int start_y);
int		find_last_non_space(char *line);
int		is_valid_boundary_char(char ch);
int		is_map_start_char(char c);
int		find_map_start(t_map_info *map);
int		here_is_valid_map_char(char ch);
int		here_is_strange(char ch);
int		has_wall_in_line(char *line);
int		is_map_line(char *line);
int		is_only_spaces(char *line);
int		is_valid_line_before_map(char *line);
int		find_height(t_game *game, char *argv);
int		max_width(t_map_info *map);
int		check_its_nswe(char *str);
int		find_dir(char *temp);
int		file_exists(char *filename);
int		is_player_or_zero(char ch);
int		can_move_to(t_game *game, double new_x, double new_y);

#endif
