#include "../inc/so_long.h"

int loop_hook(t_data *data)
{
	static int counter = 0;
	if (counter++ > REFRESH_RATE)
		free_data(data);
	return 0;
}

void	check_changes(t_data *data, t_map *map, int p_y, int p_x)
{
	if (map->map[p_y][p_x] == 'F')
	{
		printf("YOU DIED!!!\n");
		merge_tile(data, data->items->character[4], p_y, p_x);
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->layer->img_ptr, 0, 0);
		mlx_key_hook(data->win_ptr, NULL, data);
		mlx_loop_hook(data->mlx_ptr, loop_hook, data);
	}
	if (map->map[p_y][p_x] == 'C')
	{
		map->map[p_y][p_x] = '0';
		map->accesible_c--;
	}
	if (map->map[p_y][p_x] == 'E' && map->accesible_c == 0)
	{
		printf("YOU WON!!!\n");
		merge_tile(data, data->items->character[0], p_y, p_x);
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->layer->img_ptr, 0, 0);
		mlx_key_hook(data->win_ptr, NULL, data);
		mlx_loop_hook(data->mlx_ptr, loop_hook, data);
	}
}

t_bool	move_down(t_data *data, int x, int y)
{
	data->char_state = DOWN;
	if (data->map->map[y + 1][x] == '1')
	{
		merge_tile(data, data->items->character[0], y, x);
		return (false);
	}
	merge_tile(data, data->items->character[0], y + 1, x);
	data->map->p_pos[Y] = y + 1;
	return (true);
}

t_bool	move_up(t_data *data, int x, int y)
{
	data->char_state = UP;
	if (data->map->map[y - 1][x] == '1')
	{
		merge_tile(data, data->items->character[2], y, x);
		return (false);
	}
	merge_tile(data, data->items->character[2], y - 1, x);
	data->map->p_pos[Y] = y - 1;
	return (true);
}

t_bool	move_left(t_data *data, int x, int y)
{
	data->char_state = LEFT;
	if (data->map->map[y][x - 1] == '1')
	{
		merge_tile(data, data->items->character[1], y, x);
		return (false);
	}
	merge_tile(data, data->items->character[1], y, x - 1);
	data->map->p_pos[X] = x - 1;
	return (true);
}

t_bool	move_right(t_data *data, int x, int y)
{
	data->char_state = RIGHT;
	if (data->map->map[y][x + 1] == '1')
	{
		merge_tile(data, data->items->character[3], y, x);
		return (false);
	}
	merge_tile(data, data->items->character[3], y, x + 1);
	data->map->p_pos[X] = x + 1;
	return (true);
}
