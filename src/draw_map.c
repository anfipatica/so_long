#include "../inc/so_long.h"

void	change_collectible(t_data *data)
{
	int	x;
	int	y;
	int	foe;

	y = -1;
	foe = 0;
	data->sprite_state = !data->sprite_state;
	while (++y < data->map->row_num)
	{
		x = -1;
		while (++x < data->map->col_num)
		{
			if (data->map->map[y][x] == 'C')
				merge_tile(data, data->items->collectible[data->sprite_state], y, x);
			else if (data->map->map[y][x] == 'F')
			{
				move_foe(data, y, x, ++foe);
			}
		}
	}
	update_map(data);
}

void	move_character(t_data *data, int x, int y, int key)
{
	t_bool	move;

	if (key == XK_s)
		move = move_down(data, x, y);
	else if (key == XK_w)
		move = move_up(data, x, y);
	else if (key == XK_a)
		move = move_left(data, x, y);
	else if (key == XK_d)
		move = move_right(data, x, y);
	if (move == true)
	{
		if (data->map->map[y][x] == 'E')
			draw_tile(data, data->items->exit, y, x);
		else
			draw_tile(data, data->items->floor, y, x);
		check_changes(data, data->map, data->map->p_pos[X], data->map->p_pos[Y]);
	}
	change_collectible(data);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->layer->img_ptr, 0, 0);
}

void	initialize_draw(t_data *data)
{
	int	x;
	int	y;

	y = -1;

	while (++y < data->map->row_num)
	{
		x = -1;
		while (++x < data->map->col_num)
		{
			if (data->map->map[y][x] == '0')
				draw_tile(data, data->items->floor, y, x);
			else if (data->map->map[y][x] == 'P')
				merge_tile(data, data->items->character[0], y, x);
			else if (data->map->map[y][x] == '1')
				merge_tile(data, data->items->wall, y, x);
			else if (data->map->map[y][x] == 'C')
				merge_tile(data, data->items->collectible[0], y, x);
			else if (data->map->map[y][x] == 'E')
				draw_tile(data, data->items->exit, y, x);
			else if (data->map->map[y][x] == 'F')
				merge_tile(data, data->items->foe[0], y, x);
		}
	}
}

int	handle_input(int keysym, t_data *data)
{
	int		p_x;
	int		p_y;

	p_x = data->map->p_pos[X];
	p_y = data->map->p_pos[Y];
	if (keysym == XK_Escape)
		free_data(data);
	if (keysym == XK_w || keysym == XK_s || keysym == XK_a || keysym == XK_d)
	{
		move_character(data, p_x, p_y, keysym);
	}
	return (0);
}

void	draw_map(t_map *map)
{
	t_data	data;
	data.map = map;
	init_window(&data);
	initialize_draw(&data);
	mlx_put_image_to_window(data.mlx_ptr, data.win_ptr, data.layer->img_ptr, 0, 0);
	mlx_hook(data.win_ptr, DestroyNotify, StructureNotifyMask, &free_data, &data);
	mlx_key_hook(data.win_ptr, handle_input, &data);
	mlx_loop(data.mlx_ptr);
}