# Makefile for get_next_line

# 컴파일러 및 플래그
CC			= cc
CFLAGS		= -Wall -Wextra -Werror

# 소스 파일 및 오브젝트 파일
SRCS		= get_next_line.c get_next_line_utils.c
OBJS		= $(SRCS:.c=.o)

# 라이브러리 이름
NAME		= get_next_line.a

# Libft 디렉토리 및 라이브러리
LIBFT_DIR	= ../Libft
LIBFT		= $(LIBFT_DIR)/libft.a

# 모든 규칙
all: $(NAME)

# 라이브러리 빌드 (Libft에 의존하도록 설정)
$(NAME): $(OBJS) $(LIBFT)
	ar rcs $(NAME) $(OBJS)

# 오브젝트 파일 빌드
%.o: %.c
	$(CC) $(CFLAGS) -I$(LIBFT_DIR) -c $< -o $@

# Libft 빌드
$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

# 정리
clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re