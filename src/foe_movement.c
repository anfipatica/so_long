#include "../inc/so_long.h"


void	update_map(t_data *data)
{
	int	x;
	int	y;

	y = -1;
	while (++y < data->map->row_num)
	{
		x = -1;
		while (++x < data->map->col_num)
		{
			if (data->map->ff_map[y][x] == -2)
				data->map->map[y][x] = 'F';
			else if (data->map->ff_map[y][x] == -1)
				data->map->map[y][x] = '0';
		}
	}
}


void	update_foe_path_left(t_data *data, int y, int x)
{
	int	index;

	index = 0;
	while (data->map->map[y][x] == '0' || data->map->map[y][x] == 'F')
	{
		data->map->ff_map[y][x] = --index;
		x--;
	}
}

void	update_foe_path_right(t_data *data, int y, int x)
{
	int	index;

	index = 0;
	while (data->map->map[y][x] == '0' || data->map->map[y][x] == 'F')
	{
		data->map->ff_map[y][x] = --index;
		x++;
	}
}

void	move_foe(t_data *data, int y, int x)
{
	printf("%d\n", data->sprite_state);
	if (data->map->ff_map[y][x] >= 0 || (data->map->map[y][x - 1] != '0' || data->map->map[y][x + 1] != '0'))
	{
		if (data->map->map[y][x - 1] == '0')
			update_foe_path_left(data, y, x);
		else if (data->map->map[y][x + 1] == '0')
			update_foe_path_right(data, y, x);
		else
			return ;
	}
	if (data->map->ff_map[y][x] > data->map->ff_map[y][x + 1])
	{
		merge_tile(data, data->items->foe[data->sprite_state], y, x + 1);
		draw_tile(data, data->items->floor, y, x);
		update_foe_path_right(data, y, x);
	}
	else if (data->map->ff_map[y][x] > data->map->ff_map[y][x - 1])
	{
		merge_tile(data, data->items->foe[data->sprite_state], y, x - 1);
		draw_tile(data, data->items->floor, y, x);
		update_foe_path_left(data, y, x);
	}
}
