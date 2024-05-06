NAME = so_long

INC_DIR = ./inc
OBJS_DIR = ./obj
SRC_DIR = ./src
LIBFT = $(SRC_DIR)/utils/libft/libft.a
CC = gcc
CFLAGS = -L$(INC_DIR)/minilibx-linux -lmlx -lXext -lX11 -I$(INC_DIR)
# Faltan: -Wall -Werror -Wextra 

RM = rm -rf

OBJS = $(OBJS_DIR)/main.o \
		$(OBJS_DIR)/get_next_line.o \
		$(OBJS_DIR)/get_next_line_utils.o

.PHONY = clean all fclean re

all : $(NAME)

$(NAME) : $(OBJS)
	make re -C src/utils/libft
	$(CC) $^ $(LIBFT) -o $@ $(CFLAGS)

$(OBJS_DIR)/%.o : $(SRC_DIR)/%.c
	mkdir -p $(OBJS_DIR)
	$(CC) -c $^ -o $@ $(CFLAGS)

clean:
	$(RM) $(OBJS_DIR)

fclean: clean
	rm $(NAME)

re: fclean all