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

# define WIDTH 1000
# define HEIGHT 700
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


typedef struct s_data
{
	void	*mlx_ptr;
	void	*win_ptr;
}				t_data;

typedef struct s_map
{
	int		o_count;
	int		i_count;
	int		c_count;
	int		e_count;
	int		p_count;
	int		map_fd;
	char	*map_line;
	char	*map_line_buf;
	char	**map;
	int		**ff_map;
	int		p_pos[3];
	int		e_pos[3];
	int		col_num;
	int		row_num;
	int		tiles[5];
}				t_map;

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
void	invalid_map(t_map *map, int error);
void	free_map(t_map *map);

// validation_utils.c
int		count_char(const char *str, const char c);


//string_to_matrix.c
void	trim_line(t_map *map);
void	create_map(t_map *map);

//validate_map.c
void	validate_map(t_map *map);

//flood_fill.c
void	pre_flood_fill(t_map *map);
void	flood_fill(t_map *map, int y, int x, int *tiles);
//utils.c
void	malloc_failed(t_map *map);



#endif