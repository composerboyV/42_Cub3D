# 프로젝트 이름
NAME		= cub3D

# 컴파일러 및 플래그
CC			= cc
CFLAGS		= -Wall -Wextra -Werror -g -fsanitize=address

# 디렉토리
SRCS_DIR	= srcs
OBJS_DIR	= objs
INCLUDES	= includes
LIBFT_DIR	= Libft
GNL_DIR		= get_next_line

# 소스 파일 및 오브젝트 파일
SRCS		= main.c\
		  cub3d_utils.c\
		  map_parsing.c \
		  error.c
OBJS		= $(patsubst $(SRCS_DIR)/%.c, $(OBJS_DIR)/%.o, $(SRCS))

# Libft 및 get_next_line
LIBFT		= $(LIBFT_DIR)/libft.a
GNL			= $(GNL_DIR)/get_next_line.a

# 모든 규칙
all: $(NAME)

# 실행 파일 빌드
$(NAME): $(OBJS) $(LIBFT) $(GNL)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(GNL) -o $(NAME)

# 오브젝트 파일 빌드
$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.c
	@mkdir -p $(OBJS_DIR)
	$(CC) $(CFLAGS) -I$(INCLUDES) -I$(LIBFT_DIR) -I$(GNL_DIR) -c $< -o $@

# Libft 빌드
$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

# get_next_line 빌드 (Libft에 의존하도록 설정)
$(GNL): $(LIBFT)
	$(MAKE) -C $(GNL_DIR)

# 정리
clean:
	$(MAKE) -C $(LIBFT_DIR) clean
	$(MAKE) -C $(GNL_DIR) clean
	rm -rf $(OBJS_DIR)

fclean: clean
	$(MAKE) -C $(LIBFT_DIR) fclean
	$(MAKE) -C $(GNL_DIR) fclean
	rm -f $(NAME)

re: fclean all

# 보너스 (필요한 경우)
bonus: all

.PHONY: all clean fclean re bonus
