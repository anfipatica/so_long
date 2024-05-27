#include "../inc/so_long.h"


void	move_character(t_data *data, int x, int y, int key)
{
	if (key == XK_s && data->map->map[y + 1][x] != '1')
		move_down(data, x, y);
	else if (key == XK_w && data->map->map[y - 1][x] != '1')
		move_up(data, x, y);
	else if (key == XK_a && data->map->map[y][x - 1] != '1')
		move_left(data, x, y);
	else if (key == XK_d && data->map->map[y][x + 1] != '1')
		move_right(data, x, y);
	else
		return;
	if (data->map->map[y][x] == 'E')
		draw_tile(data, data->items->exit, y, x);
	else
		draw_tile(data, data->items->floor, y, x);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->layer->img_ptr, 0, 0);
	check_changes(data, data->map, data->map->p_pos[X], data->map->p_pos[Y]);
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
				merge_tile(data, data->items->character, y, x);
			else if (data->map->map[y][x] == '1')
				merge_tile(data, data->items->wall, y, x);
			else if (data->map->map[y][x] == 'C')
				merge_tile(data, data->items->collectible, y, x);
			else if (data->map->map[y][x] == 'E')
				draw_tile(data, data->items->exit, y, x);
		}
	}
}

int	handle_input(int keysym, t_data *data)
{
	char	**map;
	int		p_x;
	int		p_y;

	map = data->map->map;
	p_x = data->map->p_pos[X];
	p_y = data->map->p_pos[Y];
	if (keysym == XK_Escape)
		free_data(data);
	if (keysym == XK_w || keysym == XK_s || keysym == XK_a || keysym == XK_d)
	{
		move_character(data, p_x, p_y, keysym);
	}

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