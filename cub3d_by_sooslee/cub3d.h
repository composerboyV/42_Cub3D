#ifndef CUB3D_H
#define CUB3D_H

#include <unistd.h>
#include <stdio.h>
#include "./get_next_line/get_next_line.h"
typedef struct s_map
{
    char **map;
    int width;
    int height;
    int x;
    int y;
    int player_cnt;
} t_map;

void    making_map(t_map *test, char *file_name);
void    double_free(char **map);
void    map_parsing(t_map *map, int x, int y);
void	is_it_correct_map(t_map *map, char *file_name);
void    show_error(char *str);



#endif