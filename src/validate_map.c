#include "../inc/so_long.h"

void	check_char(t_map *map, int i, int row)
{
	if ((i == 0 || i == (map->col_num - 1)) && map->map[row][i] != '1')
		invalid_map(map, INVALID_WALLS);
	else if (map->map[row][i] == 'C')
		map->c_count++;
	else if (map->map[row][i] == 'E')
	{
		map->e_count++;
		map->e_pos[Y] = row;
		map->e_pos[X] = i;
	}
	else if (map->map[row][i] == 'P')
	{
		map->p_count++;
		map->p_pos[Y] = row;
		map->p_pos[X] = i;
	}
	else if (map->map[row][i] != '0' && map->map[row][i] != '1')
		invalid_map(map, INVALID_CHAR);
}
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

void	validate_map(t_map *map)
{
	int	i;

	i = -1;
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
