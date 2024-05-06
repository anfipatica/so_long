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
# define MALLOC_ERROR 1
# define TILE_PIXEL 64
# define BUFFER_SIZE 30
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
	int		col_num;
	int		row_num;
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

#endif