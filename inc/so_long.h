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

# define TILE_PIXEL 64
# define BUFFER_SIZE 30

//coordinates, for an easier readibility.
# define Y 0
# define X 1

//Map validations defines:
# define EMPTY_LINE 2
# define DIFFERENT_LENGTHS 3
# define INVALID_WALLS 4
# define INVALID_CHAR 5
# define NUMBER_EXITS 6
# define NUMBER_STARTS 7
# define NO_OBJECT 8
# define WRONG_SHAPE 9
# define NON_REACHABLE_EXIT 10
# define NON_REACHABLE_COLLECTIBLE 11

//Types of errors when creating a window.
# define DISPLAY 0
# define WINDOW 1
# define IMAGE 2

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
	void	*floor;
	void	*wall;
	void	*collectible;
	void	*character;
	void	*exit;
}				t_img;
typedef struct s_player
{
	int		pos[3];

}			player;

typedef struct s_data
{
	void	*mlx_ptr;
	void	*win_ptr;
	t_map	*map;
	t_img	*imgs;
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

void	read_map(t_data *data, char *map_name);
void	create_map(t_map *map);
void	trim_line(t_map *map);

//validate_map.c
//	Functions to check the validity of the map.

void	validate_map(t_map *map);
void	validate_row(t_map *map, int row);
void	check_char(t_map *map, int i, int row);
void	last_check(t_map *map);



// validation_utils.c
int		count_char(const char *str, const char c);
void	invalid_map(t_map *map, int error);


//flood_fill.c
int		check_tile(t_map *map, int y, int x);
int		change_tile(t_map *map, int y, int x, int *tiles);
void	pre_flood_fill(t_map *map);
void	flood_fill(t_map *map, int y, int x, int i);


//flood_fill_utils.c
void	free_matrix_f_malloc(int **matrix, int i);
void	print_ff_matrix(t_map map);
int		**create_ff_matrix(int width, int height);


//utils.c
void	malloc_failed(t_map *map);
t_map	init_map(void);
void	free_map(t_map *map);

//draw_map.c
void	draw_map(t_map *map);



#endif