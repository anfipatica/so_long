#include "../inc/so_long.h"

void	check_changes(t_data *data, t_map *map, int p_x, int p_y)
{
	static int	movements;

	if (!movements)
		movements = 0;
	movements++;
	printf("movements made: %d\n", movements);
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
void	move_down(t_data *data, int x, int y)
{
	merge_tile(data, data->items->character, y + 1, x);
	data->map->p_pos[Y] = y + 1;
}

void	move_up(t_data *data, int x, int y)
{
	merge_tile(data, data->items->character, y - 1, x);
	data->map->p_pos[Y] = y - 1;
}

void	move_left(t_data *data, int x, int y)
{
	merge_tile(data, data->items->character, y, x - 1);
	data->map->p_pos[X] = x - 1;
}

void	move_right(t_data *data, int x, int y)
{
	merge_tile(data, data->items->character, y, x + 1);
	data->map->p_pos[X] = x + 1;

}