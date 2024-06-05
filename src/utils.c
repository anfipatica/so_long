#include "../inc/so_long.h"

t_map	init_map(void)
{
	t_map	map;

	map.c_count = 0;
	map.e_count = 0;
	map.f_count = 0;
	map.accesible_c = 0;
	map.accesible_e = 0;
	map.accesible_f = 0;
	map.p_count = 0;
	map.map_fd = 0;
	map.map_line = NULL;
	map.map_line_buf = "";
	map.row_num = 0;
	map.col_num = 0;
	return (map);
}

void	free_map(t_map *map)
{
	int	i;

	i = -1;
	while (map->map[++i])
		free(map->map[i]);
	free(map->map);
	free(map->map_line);
	i = -1;
	if (map->ff_map)
	{
		while (++i < map->row_num)
			free(map->ff_map[i]);
		free (map->ff_map);
	}
}

void	malloc_failed(t_map *map)
{
	printf("malloc failed. Exiting...\n");
	free_map(map);
	exit(1);
}