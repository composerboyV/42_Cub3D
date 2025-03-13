#include "cub3d.h"
int	here_is_strange(char ch)
{
	if (ch != 'N' || ch != 'W' || ch != 'S' || ch != 'E' || ch != ' ' || ch != '1' || ch != '0')
		return (1);
	else 
		return (-1);
}

void	check_file_name(char *file)
{
	int len;

	len = ft_strlen(file);

	if (ft_strncmp(file + len - 4, ".cub", 4) != 0)
		show_error("File name is wrong");
}

void	are_there_any_things(t_map *map, int x, int y)
{
    if (y < 0 || y >= map->height || x < 0 || x >= (int)ft_strlen(map->map[y]) || \
        map->map[y][x] == ' ' || here_is_strange(map->map[y][x]) == -1)
		show_error("MAP ERROR: Invalid character or boundary!\n");
    if (map->map[y][x] == '1' || map->map[y][x] == '0')
	{
        return;
	}
    if (map->map[y][x] != 'N' && map->map[y][x] != 'S' && \
        map->map[y][x] != 'E' && map->map[y][x] != 'W')
    {
        map->map[y][x] = '0';
    }
    are_there_any_things(map, x - 1, y);
    are_there_any_things(map, x + 1, y);
    are_there_any_things(map, x, y - 1); 
    are_there_any_things(map, x, y + 1); 
}

void map_parsing(t_map *map, int x, int y)
{
    if (y < 0 || y >= map->height || x < 0 || map->map[y][x] == ' ' || !(map->map[y][x]))
    {
        write(1, "MAP ERROR! : ", 10);
        exit(1);
    }
    if (map->map[y][x] == '1' || map->map[y][x] == 'X')
        return;

    if (map->map[y][x] != 'N' && map->map[y][x] != 'S' && 
        map->map[y][x] != 'E' && map->map[y][x] != 'W')
    {
        map->map[y][x] = 'X';
    }
    map_parsing(map, x - 1, y);
    map_parsing(map, x + 1, y);
    map_parsing(map, x, y - 1);
    map_parsing(map, x, y + 1);
}

void check_map_characters(t_map *map)
{
    int y = 0;
    int x;

    while (y < map->height)
    {
        x = 0;
        while (map->map[y][x] != '\0')
        {
            if (here_is_strange(map->map[y][x]))
            {
                printf("Invalid character '%c' at (%d, %d)\n", map->map[y][x], x, y);
                show_error("MAP ERROR: Invalid character in map!\n");
            }
            x++;
        }
        y++;
    }
}

void    are_you_alone(t_map *map)
{
    int y = 0;
    int x;

    map->player_cnt = 0;
    while (y < map->height)
    {
        x = 0;
        while (map->map[y][x] != '\0')
        {
            if (map->map[y][x] == 'N' || map->map[y][x] == 'S' || 
                map->map[y][x] == 'W' || map->map[y][x] == 'E')
            {
                map->player_cnt++;
                map->x = x;
                map->y = y;
            }
            x++;
        }
        y++;
    }
    if (map->player_cnt != 1)
    {
        printf("player_count : %d\n", map->player_cnt);
        show_error("Count of player is wrong\n");
    }
}
void	is_it_correct_map(t_map *map, char *file_name)
{
	check_file_name(file_name);
	map_parsing(map, map->x, map->y);
    are_you_alone(map);
	if (map->player_cnt != 1)
    {
        printf("player_count : %d\n", map->player_cnt);
        show_error("Count of player is wrong\n");
    }
	are_there_any_things(map, map -> x, map -> y);
}