#include "draw.h"

int is_player_or_zero(char ch)
{
    if (ch == '0' || ch == 'N' || ch == 'S' || ch == 'E' || ch == 'W')
        return 1;
    return 0;
}

int is_at_edge(t_map_info *map, int i, int j)
{
    int map_start;
    
    map_start = find_map_start(map);
    if (i == map_start || i == map->height - 1 || j == 0 || 
        j == (int)ft_strlen(map->map[i]) - 1)
        return 1;
    return 0;
}

int is_near_space_or_out_of_bounds(t_map_info *map, int i, int j)
{
    if (j >= (int)ft_strlen(map->map[i-1]) || j >= (int)ft_strlen(map->map[i+1]))
        return 1;
    
    if (map->map[i-1][j] == ' ' || map->map[i+1][j] == ' ' ||
        map->map[i][j-1] == ' ' || map->map[i][j+1] == ' ')
        return 1;
        
    return 0;
}

void check_cell(t_map_info *map, int i, int j)
{
    if (is_player_or_zero(map->map[i][j]) && 
        (is_at_edge(map, i, j) || 
         is_near_space_or_out_of_bounds(map, i, j)))
    {
        printf("Map error: Space/zero at edge or not surrounded by walls at (%d, %d)\n", j, i);
        show_error("MAP ERROR: Map must be closed/surrounded by walls!\n");
    }
}

void check_flood_fill_map(t_map_info *map)
{
    int i;
    int j;
    int map_start;
    
    map_start = find_map_start(map);
    i = map_start;
    
    while (i < map->height)
    {
        j = 0;
        while (j < (int)ft_strlen(map->map[i]))
        {
            check_cell(map, i, j);
            j++;
        }
        i++;
    }
}

int find_max_width(t_map_info *map, int start_y)
{
    int y;
    int len;
    int max_width;
    
    max_width = 0;
    y = start_y;
    
    while (y < map->height)
    {
        len = ft_strlen(map->map[y]);
        if (len > max_width)
            max_width = len;
        y++;
    }
    
    return max_width;
}

int find_last_non_space(char *line)
{
    int x;
    
    x = ft_strlen(line) - 1;
    while (x >= 0 && (line[x] == ' ' || line[x] == '\n' || 
                     line[x] == '\t' || line[x] == '\r'))
        x--;
    
    return x;
}

void check_line_ending(t_map_info *map, int y)
{
    int x;
    
    x = find_last_non_space(map->map[y]);
            
    if (x >= 0 && map->map[y][x] != '1' && map->map[y][x] != ' ')
    {
        printf("Map error: Line %d is not properly closed with wall\n", y);
        show_error("MAP ERROR: Map must be closed/surrounded by walls!\n");
    }
}

int is_valid_boundary_char(char ch)
{
    return (ch == '1' || ch == ' ' || ch == '\n' || ch == '\t' || ch == '\r');
}

void check_boundary_line(char *line, char *error_msg)
{
    int x;
    
    x = 0;
    while (x < (int)ft_strlen(line))
    {
        if (!is_valid_boundary_char(line[x]))
        {
            printf("%s\n", error_msg);
            show_error("MAP ERROR: First/last line of map must be walls!\n");
        }
        x++;
    }
}

void init_map_validator(t_map_validator *validator, t_map_info *map)
{
    validator->start_y = find_map_start(map);
    validator->end_y = map->height - 1;
    validator->map_start = validator->start_y;
    validator->in_map = 0;
    validator->map_end = 0;
}

void check_map_lines(t_map_info *map, int start_y)
{
    int y;
    
    y = start_y;
    while (y < map->height)
    {
        check_line_ending(map, y);
        y++;
    }
}

void check_map_boundaries(t_map_info *map)
{
    t_map_validator validator;
    
    init_map_validator(&validator, map);
    
    // 결과값 무시 (사용하지 않음)
    find_max_width(map, validator.start_y);
    
    // 각 라인을 확인하여 맵 바깥쪽 콘텐츠 감지
    check_map_lines(map, validator.start_y);
    
    // 첫 줄과 마지막 줄이 모두 벽으로만 구성되었는지 확인
    check_boundary_line(map->map[validator.start_y], 
                      "Map error: First line must contain only walls or spaces");
    check_boundary_line(map->map[validator.end_y], 
                      "Map error: Last line must contain only walls or spaces");
}

int is_map_identifier(char *line)
{
    if (ft_strncmp(line, "NO ", 3) == 0 ||
        ft_strncmp(line, "SO ", 3) == 0 ||
        ft_strncmp(line, "WE ", 3) == 0 ||
        ft_strncmp(line, "EA ", 3) == 0 ||
        ft_strncmp(line, "F ", 2) == 0 ||
        ft_strncmp(line, "C ", 2) == 0)
        return 1;
    return 0;
}

void check_identifier_in_map_start(t_map_info *map, int i, 
                                  t_map_flags *flags)
{
    if (ft_strncmp(map->map[i], "NO ", 3) == 0) 
        flags->no_found = 1;
    else if (ft_strncmp(map->map[i], "SO ", 3) == 0) 
        flags->so_found = 1;
    else if (ft_strncmp(map->map[i], "WE ", 3) == 0) 
        flags->we_found = 1;
    else if (ft_strncmp(map->map[i], "EA ", 3) == 0) 
        flags->ea_found = 1;
    else if (ft_strncmp(map->map[i], "F ", 2) == 0) 
        flags->f_found = 1;
    else if (ft_strncmp(map->map[i], "C ", 2) == 0) 
        flags->c_found = 1;
}

int all_identifiers_found(t_map_flags flags)
{
    return (flags.no_found && flags.so_found && flags.we_found && 
            flags.ea_found && flags.f_found && flags.c_found);
}

int is_map_start_char(char c)
{
    return (c == ' ' || c == '1' || c == '0');
}

int find_map_start(t_map_info *map)
{
    int i;
    t_map_flags flags;
    int found_all_identifiers;
    
    i = 0;
    flags.no_found = 0;
    flags.so_found = 0;
    flags.we_found = 0;
    flags.ea_found = 0;
    flags.f_found = 0;
    flags.c_found = 0;
    
    while (map->map[i])
    {
        check_identifier_in_map_start(map, i, &flags);
        
        found_all_identifiers = all_identifiers_found(flags);
                               
        if (found_all_identifiers && is_map_start_char(map->map[i][0]))
            break;
        i++;
    }
    return i;
}

int here_is_valid_map_char(char ch)
{
    if (ch == 'N' || ch == 'W' || ch == 'S' || ch == 'E' || 
        ch == ' ' || ch == '1' || ch == '0' || 
        ch == '\n' || ch == '\t' || ch == '\r')
        return 1;
    return 0;
}

int here_is_strange(char ch)
{
    if (!here_is_valid_map_char(ch) && ch != 'X')
        return (1);
    return (0);
}

void check_file_name(char *file)
{
    int len;

    len = ft_strlen(file);
    if (ft_strncmp(file + len - 4, ".cub", 4) != 0)
        show_error("File name is wrong");
}

void check_boundaries(t_map_info *map, int x, int y)
{
    if (y < 0 || y >= map->height || x < 0 || 
        x >= (int)ft_strlen(map->map[y]) || 
        map->map[y][x] == ' ')
        show_error("Map error: Map is not enclosed by walls!\n");
    
    if (here_is_strange(map->map[y][x]) == 1)
        show_error("Invalid character or boundary!\n");
}

void mark_visited(t_map_info *map, int x, int y)
{
    if (map->map[y][x] == 'N' || map->map[y][x] == 'S' || 
        map->map[y][x] == 'E' || map->map[y][x] == 'W' ||
        map->map[y][x] == '0')
    {
        map->map[y][x] = 'X';
    }
}

void map_parsing(t_map_info *map, int x, int y)
{
    check_boundaries(map, x, y);
    
    if (map->map[y][x] == '1' || map->map[y][x] == 'X')
        return;
        
    mark_visited(map, x, y);
    
    // 상하좌우 이동하며 검사
    map_parsing(map, x - 1, y);
    map_parsing(map, x + 1, y);
    map_parsing(map, x, y - 1);
    map_parsing(map, x, y + 1);
}

int has_wall_in_line(char *line)
{
    int i;
    
    i = 0;
    while (line[i])
    {
        if (line[i] == '1')
            return 1;
        i++;
    }
    return 0;
}

int is_map_line(char *line)
{
    int i;
    int has_wall;
    
    i = 0;
    has_wall = 0;
    
    while (line[i])
    {
        if (line[i] == '1')
            has_wall = 1;
        
        if (!here_is_valid_map_char(line[i]))
            return 0;
        i++;
    }
    
    return has_wall;
}

int is_only_spaces(char *line)
{
    int i;
    
    i = 0;
    while (line[i])
    {
        if (line[i] != ' ' && line[i] != '\n' && 
            line[i] != '\t' && line[i] != '\r')
            return 0;
        i++;
    }
    return 1;
}

void check_invalid_char_in_line(t_map_info *map, int y)
{
    int x;
    
    x = 0;
    while (map->map[y][x] != '\0')
    {
        if (!here_is_valid_map_char(map->map[y][x]))
        {
            printf("Invalid character '%c' at (%d, %d)\n", 
                   map->map[y][x], x, y);
            show_error("MAP ERROR: Invalid character in map!\n");
        }
        x++;
    }
}

void count_identifiers(t_map_info *map, int *counts)
{
    int i;
    
    i = 0;
    while (map->map[i] && i < find_map_start(map))
    {
        if (ft_strncmp(map->map[i], "NO ", 3) == 0) 
            counts[0]++;
        else if (ft_strncmp(map->map[i], "SO ", 3) == 0) 
            counts[1]++;
        else if (ft_strncmp(map->map[i], "WE ", 3) == 0) 
            counts[2]++;
        else if (ft_strncmp(map->map[i], "EA ", 3) == 0) 
            counts[3]++;
        else if (ft_strncmp(map->map[i], "F ", 2) == 0) 
            counts[4]++;
        else if (ft_strncmp(map->map[i], "C ", 2) == 0) 
            counts[5]++;
        i++;
    }
}

int is_valid_line_before_map(char *line)
{
    return (is_only_spaces(line) || is_map_identifier(line));
}

void check_invalid_content(t_map_info *map)
{
    int i;
    
    i = 0;
    while (map->map[i] && i < find_map_start(map))
    {
        if (!is_valid_line_before_map(map->map[i]))
        {
            printf("Invalid line before map: '%s'\n", map->map[i]);
            show_error("MAP ERROR: Invalid content before map!\n");
        }
        i++;
    }
}

void validate_identifiers(t_map_info *map)
{
    int counts[6];
    int i;
    
    i = 0;
    while (i < 6)
    {
        counts[i] = 0;
        i++;
    }
    
    count_identifiers(map, counts);
    check_invalid_content(map);
    
    if (counts[0] != 1 || counts[1] != 1 || counts[2] != 1 || 
        counts[3] != 1 || counts[4] != 1 || counts[5] != 1)
    {
        show_error("MAP ERROR: Missing or duplicate identifiers!\n");
    }
}

void check_map_characters(t_map_info *map)
{
    int y;
    
    validate_identifiers(map);
    
    y = find_map_start(map);
    while (y < map->height)
    {
        check_invalid_char_in_line(map, y);
        y++;
    }
}

void check_map_line_status(t_map_info *map, int y, int *in_map, int *map_end)
{
    int only_spaces;
    
    only_spaces = is_only_spaces(map->map[y]);
    
    if (!*in_map && !only_spaces && is_map_line(map->map[y]))
        *in_map = 1;
    
    if (*in_map && only_spaces && !*map_end)
        *map_end = 1;
}

void check_map_line(t_map_info *map, int y, int *in_map, int *map_end)
{
    int only_spaces;
    
    only_spaces = is_only_spaces(map->map[y]);
    check_map_line_status(map, y, in_map, map_end);
    
    if (*map_end && !only_spaces)
    {
        printf("Invalid content after map ended at line %d\n", y);
        show_error("MAP ERROR: Content found after map ended!\n");
    }
}

void check_for_non_map_content(t_map_info *map)
{
    int y;
    int in_map;
    int map_end;
    
    y = find_map_start(map);
    in_map = 0;
    map_end = 0;
    
    while (y < map->height)
    {
        check_map_line(map, y, &in_map, &map_end);
        y++;
    }
}

void count_player(t_map_info *map, int x, int y)
{
    if (map->map[y][x] == 'N' || map->map[y][x] == 'S' || 
        map->map[y][x] == 'W' || map->map[y][x] == 'E')
    {
        map->player_cnt++;
        map->player_x = x;
        map->player_y = y;
        map->player_dir = map->map[y][x];
    }
}

void are_you_alone(t_map_info *map)
{
    int y;
    int x;

    y = find_map_start(map);
    map->player_cnt = 0;
    
    while (y < map->height)
    {
        x = 0;
        while (map->map[y][x] != '\0')
        {
            count_player(map, x, y);
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

void is_it_correct_map(t_map_info *map, char *file_name)
{
    check_file_name(file_name);
    check_map_characters(map);
    check_for_non_map_content(map);
    check_map_boundaries(map);
    are_you_alone(map);
    check_flood_fill_map(map);
    map_parsing(map, map->player_x, map->player_y);
    
    printf("맵 파싱 완료: 플레이어 위치 x=%f, y=%f, 방향=%c\n", 
        map->player_x, map->player_y, map->player_dir);
}