NAME = libft.a

CC = cc
RM = rm -f
CFLAGS = -Wall -Wextra -Werror
AR = ar
ARFLAGS = crs

SRCS_MUST =   	  ft_strlen.c		\
		  ft_strlcpy.c		\
		  ft_strlcat.c		\
		  ft_strchr.c		\
		  ft_strnstr.c		\
		  ft_strncmp.c		\
		  ft_strdup.c		\
		  ft_strrchr.c		\
		  ft_memset.c		\
		  ft_memcpy.c		\
		  ft_memmove.c		\
		  ft_memchr.c		\
		  ft_memcmp.c		\
		  ft_bzero.c		\
		  ft_atoi.c		\
		  ft_calloc.c		\
		  ft_isalnum.c		\
		  ft_isalpha.c		\
		  ft_isascii.c		\
		  ft_isdigit.c		\
		  ft_isprint.c		\
		  ft_tolower.c		\
		  ft_toupper.c		\
		  ft_substr.c		\
		  ft_strjoin.c		\
		  ft_strtrim.c		\
		  ft_split.c		\
		  ft_strmapi.c		\
		  ft_itoa.c		\
		  ft_putchar_fd.c	\
		  ft_putstr_fd.c	\
		  ft_putendl_fd.c	\
		  ft_putnbr_fd.c	\

SRCS_BONUS = 	ft_lstnew.c		\
		  ft_lstsize.c		\
		  ft_lstadd_front.c	\
		  ft_lstadd_back.c	\
		  ft_lstclear.c		\
		  ft_lstlast.c		\
		  ft_lstiter.c		\
		  ft_lstmap.c		\
		  ft_lstdelone.c	\

SRCS = $(SRCS_MUST)
OBJS = $(SRCS:.c=.o)
OBJS_BNS = $(SRCS_BONUS:.c=.o)

ifdef WITH_BONUS
	OBJECTS = $(OBJS) $(OBJS_BNS)
else
	OBJECTS = $(OBJS)
endif

all : $(NAME)

$(NAME) : $(OBJECTS)
	$(AR) $(ARFLAGS) $@ $^

%.o : %.c 
	$(CC) $(CFLAGS) -c  $< -o  $@

clean:
	$(RM) $(OBJS) $(OBJS_BNS)

fclean : clean
	$(RM) $(NAME)

re : fclean all

bonus :
	@make WITH_BONUS=1 all

so:
	$(CC) -c -fPIC $(CFLAGS) $(SRCS)
	cc -shared -o libft.so $(OBJS) $(OBJS_BNS)

.PHONY : all clean fclean re
