#include "draw.h"

int find_map_start(t_map_info *map)
{
    int i = 0;
    
    // 맵 시작을 찾기 - 공백이나 1로 시작하는 첫 번째 행
    while (map->map[i])
    {
        if (map->map[i][0] == ' ' || map->map[i][0] == '1' || map->map[i][0] == '0')
            break;
        i++;
    }
    
    return i;
}


int	here_is_strange(char ch)
{
	// 올바른 문자가 아니면 1 반환 (문제 있음)
	if (ch != 'N' && ch != 'W' && ch != 'S' && ch != 'E' && 
        ch != ' ' && ch != '1' && ch != '0' && ch != 'X')
		return (1); // 잘못된 문자
	
	return (0); // 올바른 문자
}


void	check_file_name(char *file)
{
	int len;

	len = ft_strlen(file);

	if (ft_strncmp(file + len - 4, ".cub", 4) != 0)
		show_error("File name is wrong");
}

void	are_there_any_things(t_map_info *map, int x, int y)
{
    if (y < 0 || y >= map->height || x < 0 || x >= (int)ft_strlen(map->map[y]) || \
        map->map[y][x] == ' ' || here_is_strange(map->map[y][x]) != 0)
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

void map_parsing(t_map_info *map, int x, int y)
{
    // 맵 경계 또는 공백 체크
    if (y < 0 || y >= map->height || x < 0 || 
        x >= (int)ft_strlen(map->map[y]) || 
        map->map[y][x] == ' ' )
        show_error("Map error: Map is not enclosed by walls!\n");
    
    if (here_is_strange(map->map[y][x]) == 1)
        show_error("Invalid character or boundary!\n");
    
    // 이미 방문했거나 벽인 경우 리턴
    if (map->map[y][x] == '1' || map->map[y][x] == 'X')
        return;
    
    // 플레이어 위치 저장 후 'X'로 표시
    if (map->map[y][x] == 'N' || map->map[y][x] == 'S' || 
        map->map[y][x] == 'E' || map->map[y][x] == 'W')
    {
        // 위치와 방향은 이미 are_you_alone에서 저장했으므로
        // 여기서는 그냥 'X'로 변경만 함
        map->map[y][x] = 'X';
    }
    else if (map->map[y][x] == '0')
    {
        map->map[y][x] = 'X';
    }
    
    // 상하좌우 이동하며 검사
    map_parsing(map, x - 1, y); // 왼쪽
    map_parsing(map, x + 1, y); // 오른쪽
    map_parsing(map, x, y - 1); // 위
    map_parsing(map, x, y + 1); // 아래
}

void check_map_characters(t_map_info *map)
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

void are_you_alone(t_map_info *map)
{
    int y;
    int x;
    int map_start;

    map->player_cnt = 0;
    map_start = find_map_start(map);
    
    // 실제 맵 부분만 검사
    y = map_start;
    while (y < map->height)
    {
        x = 0;
        while (map->map[y][x] != '\0')
        {
            if (map->map[y][x] == 'N' || map->map[y][x] == 'S' || 
                map->map[y][x] == 'W' || map->map[y][x] == 'E')
            {
                map->player_cnt++;
                map->player_x = x;
                map->player_y = y;
                map->player_dir = map->map[y][x];
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
void	is_it_correct_map(t_map_info *map, char *file_name)
{
	// 파일 이름 체크
	check_file_name(file_name);
	
	// 플레이어 수 체크 - 먼저 실행
	are_you_alone(map);
	
	// 플레이어 위치에서 맵 파싱 수행
	map_parsing(map, map->player_x, map->player_y);

    //are_there_any_things(map, map->player_x, map->player_y);
	
	// 플레이어 위치 기반 맵 유효성 검사
	printf("맵 파싱 완료: 플레이어 위치 x=%f, y=%f, 방향=%c\n", 
		map->player_x, map->player_y, map->player_dir);
}