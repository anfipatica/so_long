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

t_map	init_map(t_map *map)
{
	map = ft_calloc(1, sizeof(t_map));
	if (!map)
		exit(1);
	map->c_count = 0;
	map->e_count = 0;
	map->i_count = 0;
	map->o_count = 0;
	map->p_count = 0;
	map->map_fd = 0;
	map->map_line = NULL;
	map->map_line_buf = "";
	map->row_num = 0;
	map->col_num = 0;
	return (*map);
}
void	validate_map(t_map *map)
{
	int	i;
	int	j;

	i = -1;
	printf("rows: %d\n", map->row_num);
	while ((map->map)[++i])
	{
		printf("i = %d\n", i);
		j = -1;
		printf("+%d\n", map->col_num);
		printf("-%d\n", ft_strlen(map->map[i]));
		if (i == 0)
			map->col_num = ft_strlen(map->map[i]);
		else if (map->col_num != ft_strlen(map->map[i]))
			invalid_map(1);

	}
}

void	invalid_map(int x)
{
	if (x == 1)
		printf("Found invalid row length\n");
	exit(1);
}
void	create_map(t_map *map)
{
	map->c_count = 1;
	map->map = ft_split(map->map_line, '\n');
	validate_map(map);

}
void	draw_map(t_data *data, char *map_name)
{
	t_map	map;
	int		i;

	map = init_map(&map);
	i = -1;
	map.map_fd = open(map_name, O_RDONLY);
	while (map.map_line_buf)
	{
		map.map_line_buf = get_next_line(map.map_fd);
		if (!(map.map_line_buf))
		{
			printf("We finished reading the map\n");
			create_map(&map);
		}
		else
		{
			map.map_line = gnl_strnjoin(map.map_line, map.map_line_buf, ft_strlen(map.map_line) + ft_strlen(map.map_line_buf));
			map.row_num++;
		}
	}

}
int	main(int argc, char **argv)
{
	t_data	data;

	if (argc != 2)
		return (1);
	//init_window(&data);
	draw_map(&data, argv[1]);
}


