#include "../inc/so_long.h"

void	free_data(t_data *data)
{
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	mlx_destroy_display(data->mlx_ptr);
	free(data->mlx_ptr);
	exit (0);
}
void	init_window(t_data *data)
{
	data->mlx_ptr = mlx_init();
	if (!(data->mlx_ptr))
		exit;
	data->win_ptr = mlx_new_window(data->mlx_ptr, WIDTH, HEIGHT, "so_long");
	if (!(data->win_ptr))
		free_data(data);
	mlx_loop(data->mlx_ptr);
}

t_map	init_map(void)
{
	t_map	map;

	//map = ft_calloc(1, sizeof(t_map));
	//if (!map)
	//	exit(1);
	map.c_count = 0;
	map.e_count = 0;
	map.i_count = 0;
	map.o_count = 0;
	map.p_count = 0;
	map.map_fd = 0;
	map.map_line = NULL;
	map.map_line_buf = "";
	map.row_num = 0;
	map.col_num = 0;
	return (map);
}
void	invalid_map(t_map *map, int error)
{
	if (error == EMPTY_LINE)
		printf("Found an empty line inside the .ber\n");
	else if (error == DIFFERENT_LENGTHS)
		printf("row length discrepancy found. Invalid .ber\n");
	else if (error == INVALID_WALLS)
		printf("Walls do not enclose the map. Invalid .ber\n");
	else if (error == INVALID_CHAR)
		printf("Found invalid char inside the .ber.\n");
	else if (error == NUMBER_EXITS)
		printf("The map needs one exit. Only one.\n");
	else if (error == NUMBER_STARTS)
		printf("The map needs one starting point. Only one.\n");
	else if (error == NO_OBJECT)
		printf("There is no collectible. There needs to be at least one.\n");
	else if (error == WRONG_SHAPE)
		printf("Map needs to be an horizontal rectangle. Wrong shape, invalid .ber\n");
}


void	draw_map(t_data *data, char *map_name)
{
	t_map	map;

	map = init_map();
	map.map_fd = open(map_name, O_RDONLY);
	while (map.map_line_buf)
	{
		map.map_line_buf = get_next_line(map.map_fd);
		if (!(map.map_line_buf))
		{
			trim_line(&map);
			map.row_num = count_char(map.map_line, '\n');
			create_map(&map);
		}
		else
		{
			map.map_line = gnl_strnjoin(map.map_line, map.map_line_buf, ft_strlen(map.map_line) + ft_strlen(map.map_line_buf));
			map.row_num++;
			free(map.map_line_buf);
			map.map_line_buf = "";
		}
	}
	free_map(&map);
}
int	main(int argc, char **argv)
{
	t_data	data;

	if (argc != 2)
		return (1);
	//init_window(&data);
	draw_map(&data, argv[1]);
}


