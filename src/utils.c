#include "../inc/so_long.h"

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