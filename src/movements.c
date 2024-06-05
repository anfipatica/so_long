#include "../inc/so_long.h"

void	check_changes(t_data *data, t_map *map, int p_x, int p_y)
{
	data->movements++;
	printf("movements made: %d\n", data->movements);
	
	if (map->map[p_y][p_x] == 'F')
	{
		printf("YOU DIED!!!\n");
		free_data(data);
	}
	if (map->map[p_y][p_x] == 'C')
	{
		map->map[p_y][p_x] = '0';
		map->accesible_c--;
	}
	if (map->map[p_y][p_x] == 'E' && map->accesible_c == 0)
	{
		printf("YOU WON!!!\n");
		free_data(data);
	}
}
t_bool	move_down(t_data *data, int x, int y)
{
	if (data->map->map[y + 1][x] == '1')
	{
		merge_tile(data, data->items->character[0], y, x);
		return (false);
	}
	else
		merge_tile(data, data->items->character[0], y + 1, x);
	data->map->p_pos[Y] = y + 1;
	return (true);
}

t_bool	move_up(t_data *data, int x, int y)
{
	if (data->map->map[y - 1][x] == '1')
	{
		merge_tile(data, data->items->character[2], y, x);
		return (false);
	}
	else
		merge_tile(data, data->items->character[2], y - 1, x);
	data->map->p_pos[Y] = y - 1;
	return (true);
}

t_bool	move_left(t_data *data, int x, int y)
{
	if (data->map->map[y][x - 1] == '1')
	{
		merge_tile(data, data->items->character[1], y, x);
		return (false);
	}
	else
		merge_tile(data, data->items->character[1], y, x - 1);
	data->map->p_pos[X] = x - 1;
	return (true);
}

t_bool	move_right(t_data *data, int x, int y)
{
	if (data->map->map[y][x + 1] == '1')
	{
		merge_tile(data, data->items->character[3], y, x);
		return (false);
	}
	else
		merge_tile(data, data->items->character[3], y, x + 1);
	data->map->p_pos[X] = x + 1;
	return (true);
}
