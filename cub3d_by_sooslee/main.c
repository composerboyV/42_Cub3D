#include "cub3d.h"

#include <stdio.h>
#include <string.h>

int find_height(t_map *map, char *argv)
{
    int fd;
    char *line;
	map->height = 0;

    fd = open(argv, O_RDONLY);
    if (fd < 0)
    {
        write(1, "Error!", 6);
        exit(1);
    }
    while((line = get_next_line(fd)))
    {
        map->height ++;
        free (line);
    }
    return (map->height);
}
void    finding_xy(t_map *map)
{
    printf("여기 들어 오긴 하니?\n");
    int y;
    int x;

    y = 0;
    
    while(map->map[y])
    {
        x = 0;
        while(map->map[y][x])
        {
            if (map->map[y][x] == 'N' || map->map[y][x] == 'S' || map->map[y][x] == 'W' || \
             map->map[y][x] == 'E')
            {
                map -> x = x;
                map -> y = y;
                break ;
            }
            x ++;
        }
        y ++;
    }
}
void    making_map(t_map *test, char *file_name)
{
        int i;
        int fd;
        char *line;
        fd = open(file_name, O_RDONLY);
        if (fd < 0)
        {
            write(1, "Error!", 6);
            exit(1);
        }
		i = 0;
		while((line = get_next_line(fd)))
        {
            test->map[i] = ft_strdup(line);
            i ++;
            free (line);
        }
        test->map[i] = NULL;
}

void init_map(t_map *map, char *argv)
{
    map->height = find_height(map, argv);
    map->map = (char **)malloc(sizeof(char *) * (map->height + 1));
	making_map(map, argv);
    map->width = 0;
	map->x = 0;
	map->y = 0;
    finding_xy(map);
    map->player_cnt = 0;
}


int main(int argc, char **argv)
{
	int i;
    if (argc == 2)
    {
        t_map test;
        init_map(&test, argv[1]);
		
        i = 0; 
        while(test.map[i])
        {
            printf("%s", test.map[i]);
            i ++;
        }
        printf("\nx 위치 : %d, y 위치 : %d\n", test.x, test.y);
        is_it_correct_map(&test, argv[1]);
        i = 0; 
        while(test.map[i])
        {
            printf("%s", test.map[i]);
            i ++;
        }
        double_free(test.map);
    }
}