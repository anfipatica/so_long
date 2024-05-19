#include "../inc/so_long.h"

void	free_matrix_f_malloc(int **matrix, int i)
{
	while (i >= 0)
	{
		free(matrix[i]);
		i--;
	}
	free(matrix);
}

int		**create_ff_matrix(int width, int height)
{
	int		i;
	int		j;

	i = -1;
	j = -1;
	int		**matrix;
	matrix = ft_calloc(height, sizeof(int *));
	printf("with = %d, height = %d\n", width, height);
	if (!matrix)
		return (NULL);
	while (++i < height)
	{
		matrix[i] = ft_calloc(width, sizeof(int));
		if (!matrix[i])
			return (free_matrix_f_malloc(matrix, i), NULL);
	}
	return (matrix);
}

//Temporal function to see how the ff_map is doing
void	print_ff_matrix(t_map map)
{
	for (int y = 0; y < map.row_num; y++)
	{
		for (int x = 0; x < map.col_num; x++)
		{
			printf("%d|", map.ff_map[y][x]);
		}
		printf("\n");
	}
}

void	pre_flood_fill(t_map *map)
{
	int	tiles[5];
	map->ff_map = create_ff_matrix(map->col_num, map->row_num);
	if (map->ff_map == 0)
		malloc_failed(map);
	print_ff_matrix(*map);
	printf("%d, %d\n", map->p_pos[Y], map->p_pos[X]);
	map->ff_map[map->p_pos[Y]][map->p_pos[X]] = 1;
	flood_fill(map, map->p_pos[Y], map->p_pos[X], tiles);
}

int	check_tile(t_map *map, int y, int x)
{
	if (map->map[y][x] != '1' && map->ff_map[y][x] == 0)
	{
		return (1);
	}
	else
		return (0);
}

int	change_tile(t_map *map, int y, int x, int *tiles, int i)
{
	if (tiles[0] == 1)
		map->ff_map[y-1][x] = i;
	if (tiles[1] == 1)
		map->ff_map[y+1][x] = i;
	if (tiles[2] == 1)
		map->ff_map[y][x-1] = i;
	if (tiles[3] == 1)
		map->ff_map[y][x+1] = i;
}
void	flood_fill(t_map *map, int y, int x, int *tiles)
{
	static int i;

	if (!i)
		i = 2;
	
	tiles[0] = check_tile(map, y - 1, x);
	tiles[1] = check_tile(map, y + 1, x);
	tiles[2] = check_tile(map, y, x - 1);
	tiles[3] = check_tile(map, y, x + 1);

	change_tile(map, y, x, tiles, i);
	print_ff_matrix(*map);
}


/*void	flood_fill(t_map *map)
{
	int	y = map->p_pos[X];
	int x = map->p_pos[Y];
	int i = 0;

	map->ff_map = create_ff_matrix(map->col_num, map->row_num);
	if (map->ff_map == 0)
		malloc_failed(map);
	print_ff_matrix(*map);
	map->ff_map[x][y] = ++i;
	printf("i = %d\n", i);
	for (int j = 0; j < 120; j++)
	{
		i++;
		printf("%c, %c, %c, %c, %d\n", map->map[y - 1][x], map->map[y + 1][x], map->map[y][x - 1], map->map[y][x + 1], i);
		if (map->map[y - 1][x] != '1' && map->ff_map[y - 1][x] == 0)
		{
			printf("1\n");
			map->ff_map[y - 1][x] = i;
			y--;
		}
		else if (map->map[y + 1][x] != '1' && map->ff_map[y + 1][x] == 0)
		{
			map->ff_map[y + 1][x] = i;
			y++;
		}
		else if (map->map[y][x - 1] != '1' && map->ff_map[y][x - 1] == 0)
		{
			map->ff_map[y][x - 1] = i;
			x--;
		}
		else if (map->map[y][x + 1] != '1' && map->ff_map[y][x + 1] == 0)
		{
			map->ff_map[y][x + 1] = i;
			x++;
		}
		else
			break;
		print_ff_matrix(*map);
	}
	printf("\n\n");
	print_ff_matrix(*map);
}*/