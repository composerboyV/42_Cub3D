# 프로젝트 이름
NAME		= cub3D

# 컴파일러 및 플래그
CC			= cc
 CFLAGS		= -Wall -Wextra -Werror -g
#CFLAGS		= -Wall -Wextra -Werror -g

# 라이브러리 디렉토리
LIBFT_DIR	= Libft
GNL_DIR		= get_next_line
MLX_DIR		= minilibx-linux

# 소스 파일
SRCS		= main.c \
		      map_height.c \
     			map_init.c \
      		map_validate.c \
			floor_ceiling.c \
			dummy_texture.c \
			  etc.c \
			  etc2.c \
			  etc3.c \
			  texture_init.c \
			  init_draw.c \
			  draw_wall_line.c \
			  init_player.c \
			  raycast.c \
			  wall_dis.c \
			  rotate_right.c \
			  move_forward.c \
			  move_strafe.c \
			  rotate_left.c \
			  wall_height.c \
			  texture_pos.c \
			  map_parsing_player.c \
			  map_parsing_edges.c \
			  map_parsing_width.c \
			  map_parsing_boundaries.c \
			  map_parsing_start.c \
			  map_parsing_validate.c \
			  map_parsing_line_check.c \
			  map_parsing_identi_count.c \
			  map_parsing_characters.c \
			  raycast_dda.c

# 오브젝트 파일
OBJS		= $(SRCS:.c=.o)

# 라이브러리
LIBFT		= $(LIBFT_DIR)/libft.a
GNL			= $(GNL_DIR)/get_next_line.a

# 컬러 코드
RED			= \033[1;31m
GREEN		= \033[1;32m
YELLOW		= \033[1;33m
DEFAULT		= \033[0m

# 모든 규칙
all: $(NAME)

# 실행 파일 빌드
$(NAME): $(OBJS) $(LIBFT) $(GNL)
	@$(MAKE) -C $(MLX_DIR) 2>/dev/null || true
	@$(CC) $(CFLAGS) $(OBJS) -no-pie -Wl,-rpath,./$(LIBFT_DIR) -I$(MLX_DIR) -L$(MLX_DIR) -lmlx_Linux -lXext -lX11 -lm -lz -L$(LIBFT_DIR) -lft $(GNL) -o $(NAME)
	@echo "$(GREEN)$(NAME) created!$(DEFAULT)"

# 오브젝트 파일 빌드
%.o: %.c
	@$(CC) $(CFLAGS) -I. -I$(LIBFT_DIR) -I$(GNL_DIR) -I$(MLX_DIR) -c $< -o $@

# Libft 빌드
$(LIBFT):
	@$(MAKE) -C $(LIBFT_DIR)

# get_next_line 빌드
$(GNL): $(LIBFT)
	@$(MAKE) -C $(GNL_DIR)

# 정리
clean:
	@$(MAKE) -C $(LIBFT_DIR) clean
	@$(MAKE) -C $(GNL_DIR) clean
	@$(MAKE) -C $(MLX_DIR) clean 2>/dev/null || true
	@$(RM) $(OBJS)
	@echo "$(YELLOW)object files deleted!$(DEFAULT)"

fclean: clean
	@$(MAKE) -C $(LIBFT_DIR) fclean
	@$(MAKE) -C $(GNL_DIR) fclean
	@$(RM) $(NAME)
	@echo "$(RED)all deleted!$(DEFAULT)"

re: fclean all

.PHONY: all clean fclean re
