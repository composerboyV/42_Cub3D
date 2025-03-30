/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dummy_texture.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sooslee <sooslee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 21:57:58 by junkwak           #+#    #+#             */
/*   Updated: 2025/03/30 20:11:06 by sooslee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw.h"

void clean_texture_path(char *path)
{
    int len;
    
    if (!path)
        return;
    
    len = ft_strlen(path);
    while (len > 0 && (path[len-1] == '\n' || path[len-1] == '\r' || 
                       path[len-1] == ' ' || path[len-1] == '\t'))
    {
        path[len-1] = '\0';
        len--;
    }
}


int file_exists(char *filename)
{
    int fd;
    
    if (!filename)
        return (0);
        
    fd = open(filename, O_RDONLY);
    if (fd < 0)
    {
        //printf("❌ 파일을 열 수 없음: %s (errno: %d)\n", filename, errno);
        exit(1);
        return (0);
    }
    close(fd);
    printf("✅ 파일 확인됨: %s\n", filename);
    return (1);
}

static void	create_dummy_texture(t_game *game, int i, int width, int height)
{
	int	color;
	int	x;
	int	y;

	game->draw.textures[i].img = mlx_new_image(game->draw.mlx, width, height);
	game->draw.textures[i].width = width;
	game->draw.textures[i].height = height;
	if (!game->draw.textures[i].img)
		return ;
	game->draw.textures[i].data = (int *)mlx_get_data_addr(
			game->draw.textures[i].img, 
			&game->draw.textures[i].bpp,
			&game->draw.textures[i].size_line,
			&game->draw.textures[i].endian);
	if (i == 0)
		color = 0x00FF0000;
	else if (i == 1)
		color = 0x0000FF00;
	else if (i == 2)
		color = 0x000000FF;
	else
		color = 0x00FFFF00;
	y = -1;
	while (++y < height)
	{
		x = -1;
		while (++x < width)
			game->draw.textures[i].data[y * width + x] = color;
	}
}

int load_textures(t_game *game)
{
    int     i;
    char    *texture_paths[4];
    
    // 경로에서 개행과 공백 제거
    if (game->map_info->north_texture)
        clean_texture_path(game->map_info->north_texture);
    if (game->map_info->south_texture)
        clean_texture_path(game->map_info->south_texture);
    if (game->map_info->west_texture)
        clean_texture_path(game->map_info->west_texture);
    if (game->map_info->east_texture)
        clean_texture_path(game->map_info->east_texture);
    
    texture_paths[0] = game->map_info->north_texture;
    texture_paths[1] = game->map_info->south_texture;
    texture_paths[2] = game->map_info->west_texture;
    texture_paths[3] = game->map_info->east_texture;
    
    printf("\n==== 텍스처 파일 확인 ====\n");
    for (i = 0; i < 4; i++)
    {
        printf("텍스처 %d: [%s] - ", i, texture_paths[i]);
        file_exists(texture_paths[i]);
    }
    printf("==========================\n\n");
    
    i = -1;
    while (++i < 4)
    {
        printf("Loading texture %d: [%s]\n", i, texture_paths[i]);
        
        if (!texture_paths[i] || ft_strlen(texture_paths[i]) == 0)
        {
            show_error(" 텍스처 경로가 비어있습니다.\n");
            create_dummy_texture(game, i, 64, 64);
            continue;
        }
        
        game->draw.textures[i].img = mlx_xpm_file_to_image(game->draw.mlx,
                texture_paths[i], &game->draw.textures[i].width,
                &game->draw.textures[i].height);
                
        if (!game->draw.textures[i].img)
        {
            printf("⚠️ 텍스처 로드 실패: %s\n", texture_paths[i]);
            printf("  - 경로가 정확한지 확인하세요\n");
            printf("  - XPM 파일 형식이 유효한지 확인하세요\n");
            printf("  - MLX 라이브러리가 이 XPM을 지원하는지 확인하세요\n");
            printf("  - 더미 텍스처 생성 중...\n");
            show_error("Error\n not image");
            create_dummy_texture(game, i, 64, 64);
            if (!game->draw.textures[i].img)
                return (0);
        }
        else
        {
            printf("✅ 텍스처 로드 성공: %s\n", texture_paths[i]);
            game->draw.textures[i].data = (int *)mlx_get_data_addr(
                    game->draw.textures[i].img, &game->draw.textures[i].bpp,
                    &game->draw.textures[i].size_line, &game->draw.textures[i].endian);
        }
    }
    return (1);
}

// int	load_textures(t_game *game)
// {
// 	int		i;
// 	char	*texture_paths[4];

// 	texture_paths[0] = game->map_info->north_texture;
// 	texture_paths[1] = game->map_info->south_texture;
// 	texture_paths[2] = game->map_info->west_texture;
// 	texture_paths[3] = game->map_info->east_texture;
// 	i = -1;
// 	while (++i < 4)
// 	{
// 		printf("Loading texture %d: %s\n", i, texture_paths[i]);
// 		game->draw.textures[i].img = mlx_xpm_file_to_image(game->draw.mlx,
// 				texture_paths[i], &game->draw.textures[i].width,
// 				&game->draw.textures[i].height);
// 		if (!game->draw.textures[i].img)
// 		{
// 			printf("Failed to load texture: %s, creating dummy texture\n",
// 					texture_paths[i]);
// 			create_dummy_texture(game, i, 64, 64);
// 			if (!game->draw.textures[i].img)
// 				return (0);
// 		}
// 		else
// 			game->draw.textures[i].data = (int *)mlx_get_data_addr(
// 					game->draw.textures[i].img, &game->draw.textures[i].bpp,
// 					&game->draw.textures[i].size_line, &game->draw.textures[i].endian);
// 	}
// 	return (1);
// }
