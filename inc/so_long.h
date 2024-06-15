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
// Recomended REFRESH_RATE: 30000;
# define TILE_PIXEL 64
# define BUFFER_SIZE 30
# define REFRESH_RATE 20000

//coordinates, for an easier readibility.
# define Y 0
# define X 1

//Map validations defines:
# define EMPTY_LINE 0
# define DIFFERENT_LENGTHS 1
# define INVALID_WALLS 2
# define INVALID_CHAR 3
# define NUMBER_EXITS 4
# define NUMBER_STARTS 5
# define NO_OBJECT 6
# define WRONG_SHAPE 7
# define NON_REACHABLE_EXIT 8
# define NON_REACHABLE_COLLECTIBLE 9
# define NON_REACHABLE_FOE 10

//Types of errors when creating a window.
# define DISPLAY 0
# define WINDOW 1
# define IMAGE 2

//Directions of the character and foes.
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

/**
 * *_count = counters used for the map validation.
 * map_fd = here we save the map fd that open() returns.
 * map_line = We first read the map as an unique line.
 * map_line_buf = a buffer for the line, used in gnl.
 * map = Once the map is saved in a line, we split it into a matrix in map.
 * ff_map = an int matrix used by the flood_fill algorithm to check if the exit is reachable.
	It has the same dimensions as map and will act as an "underlayer" that will save the info of the possible paths.
	For more information, read the info related to the flood_fill() function inside flood_fill.c.
 * p_pos[3] = An int array that will hold the Y and X position of P.
 * col_num = Will hold the number of columns of the map matrix.
 * row_num = Will hold the number of rows of the map matrix.
 * 
*/
typedef struct s_map
{
	int		c_count;
	int		e_count;
	int		p_count;
	int		f_count;
	int		accesible_c;
	int		accesible_e;
	int		accesible_f;
	int		map_fd;
	char	*map_line;
	char	*map_line_buf;
	char	**map;
	int		**ff_map;
	int		p_pos[3];
	int		col_num;
	int		row_num;
}				t_map;


typedef struct s_img
{
	void	*img_ptr;
	char	*addr;
	int		height;
	int		width;
	int		bpp;
	int		endian;
	int		line_len;
	int		mov;

}				t_img;

typedef struct s_foe
{
	int	dir;
	int	x;
	int y;
}				t_foe;
typedef struct s_item
{
	t_img	*floor;
	t_img	*wall[17];
	t_img	*collectible[2];
	t_img	*character[10];
	t_img	*foe[2];
	t_img	*exit;
}				t_item;


typedef struct s_data
{
	void	*mlx_ptr;
	void	*win_ptr;
	t_map	*map;
	t_item	*items;
	t_img	*layer;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		movements;
	int		sprite_state;
	char	*message;
	int		char_state;
	t_foe	*foe_info;
}				t_data;


//get_next_line.c

char	*get_next_line(int fd);
char	*ft_read(int fd, char *remain);
char	*clean_remain(char *remain);
int		ft_find_end_line(char *line);
char	*gnl_strnjoin(char *s1, char *s2, int n);

//get_next_line_utils.c

void	ft_free(char **str);
char	*gnl_strdup(char *s1, int n);

//main.c

void	init_window(t_data *data);

//read_map.c
//	We read the map as one line, then we split it into a matrix and do map validations.

t_map	read_map(char *map_name);
void	create_map(t_map *map);
void	trim_line(t_map *map);

//validate_map.c
//	Functions to check the validity of the map.

void	validate_map(t_map *map);
void	validate_row(t_map *map, int row);
void	check_char(t_map *map, int i, int row);
void	validate_path(t_map *map);



// validation_utils.c

int		count_char(const char *str, const char c);
void	invalid_map(t_map *map, int error);


//flood_fill.c

int		check_enemy_path(char **map, int y, int x, int dir);
int		check_tile(t_map *map, int y, int x);
int		change_tile(t_map *map, int y, int x, int *tiles);
void	pre_flood_fill(t_map *map);
void	flood_fill(t_map *map, int y, int x, int i);


//flood_fill_utils.c

void	free_matrix_f_malloc(int **matrix, int i);
void	print_ff_matrix(t_map map);
int		**create_ff_matrix(int width, int height);
void	print_matrix(t_map map);



//utils.c

void	malloc_failed(t_map *map);
t_map	init_map(void);
void	free_map(t_map *map);

//draw_map.c

void	draw_map(t_map *map);
void	initializa_draw(t_data *data);
int		handle_input(int keysym, t_data *data);
void	move_character(t_data *data, int x, int y, int key);


//draw_map_utils.c

void	init_items(t_data *data);
void	init_window(t_data *data);
void	add_imgs_util(t_data *data, t_img *img, char *path);
void	add_imgs(t_data *data);
void	destroy_element(int type, t_data *data, void *element);
int		free_data(t_data *data);

//drawing_functions.c

void		put_pixel_img(t_img *img, int x, int y, unsigned int color);
unsigned int	get_pixel_img(t_img img, int x, int y);
void		draw_tile(t_data *data, t_img *img, int row, int col);
void		merge_tile(t_data *data, t_img *overlap, int row, int col);

//movements.c

t_bool	move_up(t_data *data, int x, int y);
t_bool	move_down(t_data *data, int x, int y);
t_bool	move_left(t_data *data, int x, int y);
t_bool	move_right(t_data *data, int x, int y);
void	check_changes(t_data *data, t_map *map, int p_x, int p_y);

//foe_movement.c

void	register_foes(t_data *data, int y, int x);
int		move_foe(t_data *data, int y, int x, int n);
void	update_map(t_data *data);
int		move_foe_right(t_data *data, int y, int x, int n);
int		move_foe_left(t_data *data, int y, int x, int n);



//free_functions.c

void	free_map(t_map *map);
void	destroy_element(int type, t_data *data, void *element);
void	free_items(t_data *data, int i);


#endif