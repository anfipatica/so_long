#include "../inc/so_long.h"

int	check_tile(t_map *map, int y, int x)
{
	if (map->map[y][x] != '1' && map->ff_map[y][x] == 0)
	{
		return (1);
	}
	else
		return (0);
}

int	change_tile(t_map *map, int y, int x, int *tiles)
{
	int	changed;

	changed = 0;
	if (tiles[0] == 1)
	{
		map->ff_map[y-1][x] = map->ff_map[y][x] + 1;
		changed++;
	}
	if (tiles[1] == 1)
	{
		map->ff_map[y+1][x] = map->ff_map[y][x] + 1;
		changed++;
	}
	if (tiles[2] == 1)
	{
		map->ff_map[y][x-1] = map->ff_map[y][x] + 1;
		changed++;
	}
	if (tiles[3] == 1)
	{
		map->ff_map[y][x+1] = map->ff_map[y][x] + 1;
		changed++;
	}
	return (changed);
}

void	flood_fill(t_map *map, int y, int x, int i)
{
	int	tiles[5];

	if (map->map[y][x] == 'C')
		map->accesible_c++;
	if (map->map[y][x] == 'E')
		map->accesible_e++;
	tiles[0] = check_tile(map, y - 1, x);
	tiles[1] = check_tile(map, y + 1, x);
	tiles[2] = check_tile(map, y, x - 1);
	tiles[3] = check_tile(map, y, x + 1);
	if (change_tile(map, y, x, tiles) != 0)
		i++;
	if (tiles[0] == 1)
		flood_fill(map, y - 1, x, i);
	if (tiles[1] == 1)
		flood_fill(map, y + 1, x, i);
	if (tiles[2] == 1)
		flood_fill(map, y, x - 1, i);
	if (tiles[3] == 1)
		flood_fill(map, y, x + 1, i);
}

void	pre_flood_fill(t_map *map)
{
	printf("antes de nada: col = %d, row = %d\n", map->col_num, map->row_num);
	map->ff_map = create_ff_matrix(map->col_num, map->row_num);
	if (map->ff_map == 0)
		malloc_failed(map);
	print_ff_matrix(*map);
	printf("%d, %d\n", map->p_pos[Y], map->p_pos[X]);
	map->ff_map[map->p_pos[Y]][map->p_pos[X]] = 1;
	flood_fill(map, map->p_pos[Y], map->p_pos[X], 2);
	print_ff_matrix(*map);
	validate_path(map);
}