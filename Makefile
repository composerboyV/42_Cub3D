CC = cc
CFLAGS = -Wall -Wextra -Werror -g -I./minilibx-linux -Imlx_linux -I./include -O3
RM = rm -rf
SRC = draw_wall_line.c ./dummy_texture.c ./etc.c ./etc2.c ./init_draw.c ./init_map.c ./init_player.c \
	./main.c ./move_player.c ./perfom_dda.c ./raycast.c ./test.c ./wall_dis.c
MLX = ./minilibx-linux
OBJS = $(SRC:.c=.o)
NAME = cub3D

all : $(NAME)

$(NAME): $(OBJS)
	make -C minilibx-linux/
	make -C libft/
	$(CC) $(OBJS) -no-pie -Lmlx_linux -lmlx_Linux -L$(MLX) -lXext -lX11 -lm -lz -L libft/ -lft -o $(NAME)
	@echo "$(GREEN)$(NAME) created!$(DEFAULT)"

%.o : %.c
	$(CC) $(CFLAGS) -I$(MLX) -Imlx_linux -O3 -c $< -o $@

clean :
	make clean -C libft/
	$(RM) $(OBJS)
	@echo "$(YELLOW)object files deleted!$(DEFAULT)"

fclean :
	make fclean -C libft/
	$(RM) $(OBJS) $(NAME)
	@echo "$(RED)all deleted!$(DEFAULT)"

re :
	make fclean
	make all

.PHONY: all clean fclean re

RED			=	\033[1;31m
GREEN		=	\033[1;32m
YELLOW		=	\033[1;33m
DEFAULT		=	\033[0m
