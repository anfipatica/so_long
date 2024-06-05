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
			if (data->map->ff_map[y][x] == -1)
				data->map->map[y][x] = 'F';
			else if (data->map->ff_map[y][x] == -2)
				data->map->map[y][x] = '0';
		}
	}
}

void	move_foe(t_data *data, int y, int x, int )
{
	
}
