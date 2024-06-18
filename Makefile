NAME = so_long
NAME_BONUS = so_long_bonus

INC_DIR = ./inc
OBJS_DIR = ./obj
BONUS_OBJS_DIR = ./obj/bonus
SRC_DIR = ./src
BONUS_DIR = ./bonus
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

OBJS_BONUS = $(BONUS_OBJS_DIR)/main.o \
			$(BONUS_OBJS_DIR)/get_next_line.o \
			$(BONUS_OBJS_DIR)/get_next_line_utils.o \
			$(BONUS_OBJS_DIR)/read_map.o \
			$(BONUS_OBJS_DIR)/validation_utils.o \
			$(BONUS_OBJS_DIR)/validate_map.o \
			$(BONUS_OBJS_DIR)/flood_fill.o \
			$(BONUS_OBJS_DIR)/flood_fill_utils.o \
			$(BONUS_OBJS_DIR)/draw_map.o \
			$(BONUS_OBJS_DIR)/draw_map_utils.o \
			$(BONUS_OBJS_DIR)/move_character.o \
			$(BONUS_OBJS_DIR)/drawing_functions.o \
			$(BONUS_OBJS_DIR)/foe_movement.o \
			$(BONUS_OBJS_DIR)/free_functions.o \
			$(BONUS_OBJS_DIR)/utils.o \
			$(BONUS_OBJS_DIR)/initialize_draw.o \
			$(BONUS_OBJS_DIR)/refresh_sprites.o \
			$(BONUS_OBJS_DIR)/add_imgs.o \
			$(BONUS_OBJS_DIR)/initialize_elements.o \
			$(BONUS_OBJS_DIR)/handle_input.o \
			$(BONUS_OBJS_DIR)/foe_movement_utils.o

.PHONY = clean all fclean re

all : $(NAME)

$(NAME) : $(OBJS)
	make re -C src/utils/libft
	$(CC) $^ $(LIBFT) -o $@ $(CFLAGS)

$(OBJS_DIR)/%.o : $(SRC_DIR)/%.c
	mkdir -p $(OBJS_DIR)
	$(CC) -c $^ -o $@ $(CFLAGS)

bonus : $(NAME_BONUS)

$(NAME_BONUS) : $(OBJS_BONUS)
	make re -C src/utils/libft
	$(CC) $^ $(LIBFT) -o $@ $(CFLAGS)

$(BONUS_OBJS_DIR)/%.o : $(BONUS_DIR)/%.c
	mkdir -p $(BONUS_OBJS_DIR)
	$(CC) -c $^ -o $@ $(CFLAGS)

clean:
	$(RM) $(OBJS_DIR)
	$(RM) $(BONUS_OBJS_DIR)

fclean: clean
	rm $(NAME) $(NAME_BONUS)

re: fclean all