NAME = libft.a

RM = rm -f

CC = gcc 

CFLAGS = -Wall -Werror -Wextra

OBJS_DIR = ./obj

SRCS = ft_isalnum.c \
		ft_isalpha.c \
		ft_isascii.c \
		ft_isdigit.c \
		ft_isprint.c \
		ft_strlen.c \
		ft_memset.c \
		ft_bzero.c \
		ft_memcpy.c \
		ft_memmove.c \
		ft_strlcpy.c \
		ft_strlcat.c \
		ft_toupper.c \
		ft_tolower.c \
		ft_strchr.c \
		ft_strrchr.c \
		ft_strncmp.c \
		ft_memchr.c \
		ft_memcmp.c \
		ft_strnstr.c \
		ft_atoi.c \
		ft_calloc.c \
		ft_strdup.c \
		ft_substr.c \
		ft_strjoin.c \
		ft_strtrim.c \
		ft_split.c \
		ft_itoa.c \
		ft_strmapi.c \
		ft_striteri.c \
		ft_putchar_fd.c \
		ft_putstr_fd.c \
		ft_putendl_fd.c \
		ft_putnbr_fd.c \

OBJS = $(SRCS:%.c=obj/%.o)

.PHONY: clean all fclean re

all: $(NAME)

$(NAME): objs $(OBJS)
	@ar -rcs $(NAME) $(OBJS)

objs:
	@mkdir -p $(OBJS_DIR)

$(OBJS_DIR)/%.o: %.c
	$(CC) -c $< -o $@

clean:
	$(RM) $(OBJS) $(OBJS_BONUS)
	rm -rf $(OBJS_DIR)

fclean: clean
	$(RM) $(NAME)

re: fclean all