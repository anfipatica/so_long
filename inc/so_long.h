/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymunoz-m <ymunoz-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 21:16:39 by anfi              #+#    #+#             */
/*   Updated: 2024/06/19 15:15:09 by ymunoz-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "./minilibx-linux/mlx.h"
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <X11/X.h>
# include <X11/keysym.h>
# include <fcntl.h> //macros for open.
# include "../src/utils/libft/libft.h"

//TILE_PIXEL = How many pixels is a tile.
// Recomended REFRESH_RATE: 20000;
# define TILE_PIXEL 64
# define BUFFER_SIZE 30

//coordinates, for an easier readibility.
# define Y 0
# define X 1

// Map validations defines for invalid_map() inside validation_utils.c
// Check out the error message each define has inside the function
// for more info about them.
# define WRONG_MAP_NAME -1
# define WRONG_MAP_EXTENSION 0
# define UNABLE_TO_OPEN 1
# define EMPTY_LINE 2
# define DIFFERENT_LENGTHS 3
# define INVALID_WALLS 4
# define INVALID_CHAR 5
# define NO_EXIT 6
# define TOO_MANY_EXITS 7
# define NO_STARTING_POINT 8
# define TOO_MANY_STARTING_POINTS 9
# define NO_OBJECT 10
# define WRONG_SHAPE 11
# define NON_REACHABLE_EXIT 12
# define NON_REACHABLE_COLLECTIBLE 13
# define NON_REACHABLE_FOE 14

//Types of errors when creating a window.
# define DISPLAY 0
# define WINDOW 1
# define IMAGE 2

//Directions for the character and foes.
# define PERMANENT_STILL -1
# define NONE 0
# define UP 1
# define DOWN 2
# define LEFT 3
# define RIGHT 4

typedef enum s_boolean
{
	false = 0,
	true = 1
}		t_bool;

/**  t_map is a struct that contains all the needed map information.
 * - *_count: counters used for the map validation.
 * - map_fd: here we save the map fd that open() returns.
 * - map_line: We first read the map as an unique line.
 * - map_line_buf: a buffer for the line, used in gnl.
 * - map: Once the map is saved in a line, we split it into a matrix in map.
 * - ff_map: an int matrix used to validate if the map is solvable 
 		and to keep track of the foes movement.
 * - p_pos[3]: An int array that will hold the Y and X position of P.
 * - col_num: Will hold the number of columns of the map matrix.
 * - row_num: Will hold the number of rows of the map matrix. */
typedef struct s_map
{
	int		c_count;
	int		e_count;
	int		p_count;
	int		accesible_c;
	int		accesible_e;
	int		map_fd;
	char	*map_line;
	char	*map_line_buf;
	char	**map;
	int		**ff_map;
	int		p_pos[3];
	int		col_num;
	int		row_num;
}				t_map;

/** t_img is a struct that contains the needed variables for minilibx and X11
 * to create an image. Every sprite is t_img since we need its address to
 * manipulate pixels.
 * - imt_ptr: el puntero a la imagen.
 * - addr: la dirección en memoria del primer píxel.
 * - height: The image height.
 * - width: The image width.
 * - bpp: how many bits form a pixel.
 * - endian: endian refers to the way the computer saves the data on the memory.
 * - line_len: The actual image length, which may differ from width because of
 * 	data alignment, memory stuff.
 * - mov:
 * */
typedef struct s_img
{
	void	*img_ptr;
	char	*addr;
	int		height;
	int		width;
	int		bpp;
	int		endian;
	int		line_len;
}				t_img;

/** A struct to hold the sprites each item needs.*/
typedef struct s_item
{
	t_img	*floor;
	t_img	*wall;
	t_img	*collectible;
	t_img	*character;
	t_img	*exit;
}				t_item;

/** t_data is the struct that holds everything together.
 * - mlx_ptr: the pointer that holds the mlx instance. Let's say it's the key to
 * 	connect with the X11 server.
 * - win_ptr: The pointer of the window we create.
 * - map: a t_map struct.
 * - items: a t_item struct.
 * - layer: a t_img sprite to hold the pointer and address of the image we put
 * 	on the window.
 * - movements: an int to keep track of how many movements the character makes.
 * - sprite_state: some elements change after certain refresh time and alternate
 * 	between two sprites.
 * - message: to hold the message it is printed with the movements made.
 * - char_state: to hold which direction the character is looking at.
 * - foe_info: an array of t_foe. Each foe has a possition inside the array.*/
typedef struct s_data
{
	void	*mlx_ptr;
	void	*win_ptr;
	t_map	*map;
	t_item	*items;
	t_img	*layer;
	int		movements;
	char	*message;
	int		char_state;
}				t_data;

//get_next_line.c

char			*get_next_line(int fd);
char			*ft_read(int fd, char *remain);
char			*clean_remain(char *remain);
int				ft_find_end_line(char *line);
char			*gnl_strnjoin(char *s1, char *s2, int n);

//get_next_line_utils.c

void			ft_free(char **str);
char			*gnl_strdup(char *s1, int n);

/** main.c
 * The alpha and the omega.
 * Oh and also where we validate the map has a valid extension.*/

void			validate_name(char *name);
int				main(int argc, char **argv);

/** read_map.c
 * We read the map as one line,
 * then we split it into a matrix and do map validations.*/

void			trim_line(t_map *map);
void			create_map(t_map *map);
t_map			read_map(char *map_name);

/** validate_map.c
 * Functions to check the validity of the map. */

void			validate_path(t_map *map);
void			check_char(t_map *map, int i, int row);
void			validate_row(t_map *map, int row);
void			validate_map(t_map *map);

/** validation_utils.c
 * needed complementary functions for map validation.*/

int				count_char(const char *str, const char c);
void			invalid_map(t_map *map, int error);
void			invalid_map_continuation(int error);

/** flood_fill.c
 * Functions to execute the flood_fill algorithms and therefore check if
 * the exit is reachable, being a solvable and valid map. */

int				check_tile(t_map *map, int y, int x);
int				change_tile(t_map *map, int y, int x, int *tiles);
void			pre_flood_fill(t_map *map);
void			flood_fill(t_map *map, int y, int x, int i);

/** flood_fill_utils.c
 * Functions needed for the flood_fill, regarding creation, freeing and cleaning
 * of the int matrix ff_map.*/

void			free_matrix_f_malloc(int **matrix, int i);
int				**create_ff_matrix(int width, int height);
void			clean_ff_matrix(t_map *map);
//void			print_matrix(t_map map);
//void			print_ff_matrix(t_map map);

//utils.c
t_map			init_map(void);
void			*calloc_or_free(t_data *data, int n, int size);

//draw_map.c
void			draw_map(t_map *map);

/** initialize_draw.c
 * Funtions to initialize the image, drawing element tile by tile
 * when the game is first launched.*/

void			draw_wall_continuation(t_data *data, int y, int x, char **map);
void			draw_wall(t_data *data, int y, int x);
void			initialize_draw(t_data *data);

/** refresh_sprites.c
 * Functions to refresh the sprites when the refresh time is reached.*/

void			refresh_collectibles_and_foes(t_data *data);
void			refresh_character(t_data *data);
int				refresh_sprites(t_data *data);
void			update_map(t_data *data);

/** draw_map_utils.c
 * Some useful auxiliar functions to draw the map. */

void			check_screen_size(t_data *data, int width, int height);
void			put_centered_image(t_data *data, t_img *img);
int				loop_hook(t_data *data);

/** initialize_elements.c
 * Functions to initialize every inside the t_data struct. */

void			init_window(t_data *data);
void			init_items(t_data *data);

/** add_imgs.c
 * We have a lot of images so there's a whole file just with
 * this purpose.*/

void			add_imgs_util(t_data *data, t_img *img, char *path);
void			add_wall_imgs(t_data *data, t_item *items);
void			add_imgs(t_data *data, t_item *items);

/** handle_input.c
 * Functions that are activated when a movement key is pressed.
 * */
void			update_character_movement(t_data *data, int y, int x,
					char *movements);
void			update_character(t_data *data, int x, int y, int key);
int				handle_input(int keysym, t_data *data);
void			check_changes(t_data *data, t_map *map, int p_y, int p_x);

/** drawing_functions.c
 * The root drawing functions, this is where the image actually
 * gets each pixel painted*/

void			put_pixel_img(t_img *img, int x, int y, unsigned int color);
unsigned int	get_pixel_img(t_img img, int x, int y);
void			draw_tile(t_data *data, t_img *img, int row, int col);
void			merge_tile(t_data *data, t_img *overlap, int row, int col);

/** move_character.c
 * The functions to move the character in the four possible directions.*/

t_bool			move_up(t_data *data, int x, int y);
t_bool			move_down(t_data *data, int x, int y);
t_bool			move_left(t_data *data, int x, int y);
t_bool			move_right(t_data *data, int x, int y);

/** foe_movement.c
 * Functions no decide where the foe must move. */

void			change_foe_direction(t_data *data, int y, int x, int movement);
void			move_foe(t_data *data, int y, int x, int n);
void			move_foe_right(t_data *data, int y, int x, int n);
void			move_foe_left(t_data *data, int y, int x, int n);

/** foe_movement_utils.c
 * Some auxiliar functions for the foe movement*/

void			register_foes(t_data *data, int y, int x);
int				check_if_foe_can_move(t_data *data, int y, int x);

/** free_functions.c
 * Where every function related to freeing memory is*/

void			free_map(t_map *map);
void			destroy_element(int type, t_data *data, void *element);
void			free_items(t_data *data);
int				free_data(t_data *data);

#endif