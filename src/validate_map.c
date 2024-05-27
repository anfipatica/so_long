#include "../inc/so_long.h"

/**
 * This is the last validation. After the flood_fill algorithm has been applied, we check
 * that the cell on the ff_map corresponding to the E position on the map, has any number aside
 * from 0 asigned to it. If so, the exit is reachable and the map is valid.
*/
void	validate_path(t_map *map)
{
	if (map->e_count != map->accesible_e)
		invalid_map(map, NON_REACHABLE_EXIT);
	if (map->c_count != map->accesible_c)
		invalid_map(map, NON_REACHABLE_COLLECTIBLE);
}

/**
 * In this function we will keep track of each P, E and C chars found
 * to check that the subject needs are fulfilled.
 * We will also call invalid_map() if we find any non allowed char.
*/

void	check_char(t_map *map, int i, int row)
{
	if ((i == 0 || i == (map->col_num - 1)) && map->map[row][i] != '1')
		invalid_map(map, INVALID_WALLS);
	else if (map->map[row][i] == 'C')
		map->c_count++;
	else if (map->map[row][i] == 'E')
		map->e_count++;
	else if (map->map[row][i] == 'P')
	{
		map->p_count++;
		map->p_pos[Y] = row;
		map->p_pos[X] = i;
	}
	else if (map->map[row][i] != '0' && map->map[row][i] != '1')
		invalid_map(map, INVALID_CHAR);
}

/**
 * Inside this function we check that the map is surrounded by walls.
 * Also, we keep track of each P, E and C chars found to check that
 * the subject needs are fulfilled
*/

void	validate_row(t_map *map, int row)
{
	int	i;

	i = 0;
	if (row == 0 || row == (map->row_num - 1))
	{
		while (map->map[row][i] == '1')
			i++;
		if (i != map->col_num)
			invalid_map(map, INVALID_WALLS);
	}
	else
	{
		while (map->map[row][i])
		{
			check_char(map, i, row);
			i++;
		}
	}
}

/**
 * We start by checking if the map is an horizontal rectangle.
 * Then we check if there is any row with a different length.
 * And we send each row to validate_row() where more in depth validations will continue.
 * If any mistake is found, we call invalid_map with its particular error.
	More info on the errors definitions inside the .h .
*/
void	validate_map(t_map *map)
{
	int	i;

	i = -1;
	printf("col = %d, row= %d\n", map->col_num, map->row_num);
	if (map->col_num <= map->row_num)
		invalid_map(map, WRONG_SHAPE);
	while ((map->map)[++i])
	{
		if (map->col_num != ft_strlen(map->map[i]))
			invalid_map(map, DIFFERENT_LENGTHS);
		validate_row(map, i);
	}
	if (map->e_count != 1)
		invalid_map(map, NUMBER_EXITS);
	if (map->p_count != 1)
		invalid_map(map, NUMBER_STARTS);
	if (map->c_count < 1)
		invalid_map(map, NO_OBJECT);
}
