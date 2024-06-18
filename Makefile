NAME = so_long

INC_DIR = ./inc
OBJS_DIR = ./obj
SRC_DIR = ./src
LIBFT = $(SRC_DIR)/utils/libft/libft.a
CC = gcc
CFLAGS = -Wall -Werror -Wextra -L$(INC_DIR)/minilibx-linux -lmlx -lXext -lX11 -I$(INC_DIR)

RM = rm -rf

OBJS = $(OBJS_DIR)/main.o \
		$(OBJS_DIR)/get_next_line.o \
		$(OBJS_DIR)/get_next_line_utils.o \
		$(OBJS_DIR)/read_map.o \
		$(OBJS_DIR)/validation_utils.o \
		$(OBJS_DIR)/validate_map.o \
		$(OBJS_DIR)/flood_fill.o \
		$(OBJS_DIR)/flood_fill_utils.o \
		$(OBJS_DIR)/draw_map.o \
		$(OBJS_DIR)/draw_map_utils.o \
		$(OBJS_DIR)/move_character.o \
		$(OBJS_DIR)/drawing_functions.o \
		$(OBJS_DIR)/foe_movement.o \
		$(OBJS_DIR)/free_functions.o \
		$(OBJS_DIR)/utils.o \
		$(OBJS_DIR)/initialize_draw.o \
		$(OBJS_DIR)/refresh_sprites.o \
		$(OBJS_DIR)/add_imgs.o \
		$(OBJS_DIR)/initialize_elements.o \
		$(OBJS_DIR)/handle_input.o \
		$(OBJS_DIR)/foe_movement_utils.o

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