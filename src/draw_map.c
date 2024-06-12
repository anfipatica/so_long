#include "../inc/so_long.h"

void	change_collectible(t_data *data)
{
	int	x;
	int	y;

	y = -1;
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
				move_foe(data, y, x, data->map->ff_map[y][x]);
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
		data->movements++;
		data->message = ft_strjoin("Movements made: ", ft_itoa(data->movements));
		printf("movements made: %d\n", data->movements);
		if (data->map->map[y][x] == 'E')
			draw_tile(data, data->items->exit, y, x);
		else if (data->map->map[y][x] != 'F')
			draw_tile(data, data->items->floor, y, x);
	}
	check_changes(data, data->map, data->map->p_pos[Y], data->map->p_pos[X]);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->layer->img_ptr, 0, 0);
	mlx_string_put(data->mlx_ptr, data->win_ptr, 30, 30, (unsigned int)0xAFBED6, data->message);
}


void	centered_text_on_screen(t_data *data, char *str, int deviation)
{
	int	centerx;
	int	centery;

	centerx = data->map->col_num * (TILE_PIXEL / 2) - (ft_strlen(str) * 3);
	centery = data->map->row_num * (TILE_PIXEL / 2);
	mlx_string_put(data->mlx_ptr, data->win_ptr, centerx - 2, centery + 1 + deviation,
		(unsigned int)0x000000, str);
	mlx_string_put(data->mlx_ptr, data->win_ptr, centerx, centery + deviation,
		(unsigned int)0xAFBED6, str);
}
void	draw_wall(t_data *data, int y, int x)
{
	char	**map;

	map = data->map->map;
	if (y == 0 || y + 1 == data->map->row_num || x == 0 || x + 1 == data->map->col_num)
		merge_tile(data, data->items->wall[12], y, x);
	else if (map[y - 1][x] == '1' && map[y][x + 1] == '1' && map[y + 1][x] == '1' && map[y][x - 1] == '1')
		merge_tile(data, data->items->wall[1], y, x);
	else if (map[y - 1][x] == '1' && map[y][x + 1] == '1' && map[y][x - 1] == '1')
		merge_tile(data, data->items->wall[13], y, x);
	else if (map[y - 1][x] == '1' && map[y + 1][x] == '1' && map[y][x + 1] == '1')
		merge_tile(data, data->items->wall[14], y, x);
	else if (map[y][x + 1] == '1' && map[y + 1][x] == '1' && map[y][x - 1] == '1')
		merge_tile(data, data->items->wall[15], y, x);
	else if (map[y - 1][x] == '1' && map[y][x - 1] == '1' && map[y + 1][x] == '1')
		merge_tile(data, data->items->wall[16], y, x);
	else if (map[y][x + 1] == '1' && map[y][x - 1] == '1')
		merge_tile(data, data->items->wall[2], y, x);
	else if (map[y - 1][x] == '1' && map[y + 1][x] == '1')
		merge_tile(data, data->items->wall[3], y, x);
	else if (map[y - 1][x] == '1' && map[y][x + 1] == '1')
		merge_tile(data, data->items->wall[4], y, x);
	else if (map[y][x + 1] == '1' && map[y + 1][x] == '1')
		merge_tile(data, data->items->wall[5], y, x);
	else if (map[y + 1][x] == '1' && map[y][x - 1] == '1')
		merge_tile(data, data->items->wall[6], y, x);
	else if (map[y - 1][x] == '1' && map[y][x - 1] == '1')
		merge_tile(data, data->items->wall[7], y, x);
	else if (map[y - 1][x] == '1')
		merge_tile(data, data->items->wall[8], y, x);
	else if (map[y][x + 1] == '1')
		merge_tile(data, data->items->wall[9], y, x);
	else if (map[y + 1][x] == '1')
		merge_tile(data, data->items->wall[10], y, x);
	else if (map[y][x - 1] == '1')
		merge_tile(data, data->items->wall[11], y, x);
	else
		merge_tile(data, data->items->wall[0], y, x);
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
				draw_wall(data, y, x);
			else if (data->map->map[y][x] == 'C')
				merge_tile(data, data->items->collectible[0], y, x);
			else if (data->map->map[y][x] == 'E')
				merge_tile(data, data->items->exit, y, x);
			else if (data->map->map[y][x] == 'F')
			{
				register_foes(data, y, x);
				merge_tile(data, data->items->foe[0], y, x);
			}
		}
	}

}

int	change_sprite(t_data *data)
{
	static int	i;

	if (!i)
		i = 0;
	if (i * 1000 == 0)
		printf("i = %d\n", i);
	if (++i > REFRESH_RATE)
	{
		printf("HORA DE REFRESZARªªªªªªªªªªªªªªªªª!!!!!!!!!\n");
		i = 0;
		change_collectible(data);
		if (data->char_state == DOWN && data->sprite_state == 0)
			merge_tile(data, data->items->character[5], data->map->p_pos[Y], data->map->p_pos[X]);
		else if (data->char_state == DOWN)
			merge_tile(data, data->items->character[0], data->map->p_pos[Y], data->map->p_pos[X]);
		else if (data->char_state == LEFT && data->sprite_state == 0)
			merge_tile(data, data->items->character[6], data->map->p_pos[Y], data->map->p_pos[X]);
		else if (data->char_state == LEFT)
			merge_tile(data, data->items->character[1], data->map->p_pos[Y], data->map->p_pos[X]);
		else if (data->char_state == UP && data->sprite_state == 0)
			merge_tile(data, data->items->character[7], data->map->p_pos[Y], data->map->p_pos[X]);
		else if (data->char_state == UP)
			merge_tile(data, data->items->character[2], data->map->p_pos[Y], data->map->p_pos[X]);
		else if (data->char_state == RIGHT && data->sprite_state == 0)
			merge_tile(data, data->items->character[8], data->map->p_pos[Y], data->map->p_pos[X]);
		else if (data->char_state == RIGHT)
			merge_tile(data, data->items->character[3], data->map->p_pos[Y], data->map->p_pos[X]);

		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->layer->img_ptr, 0, 0);
		mlx_string_put(data->mlx_ptr, data->win_ptr, 30, 30, (unsigned int)0xAFBED6, data->message);
		check_changes(data, data->map, data->map->p_pos[Y], data->map->p_pos[X]);
	}
	return (0);
}

int	handle_input(int keysym, t_data *data)
{
	int		p_x;
	int		p_y;
	static int		i;

	p_x = data->map->p_pos[X];
	p_y = data->map->p_pos[Y];
	if (keysym == XK_Escape)
		free_data(data);
	if (i == 0 && keysym != XK_Return)
		++i;
	else if (i++ == 1)
	{
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->layer->img_ptr, 0, 0);
		mlx_string_put(data->mlx_ptr, data->win_ptr, 30, 30,
			(unsigned int)0xAFBED6, data->message);
		mlx_loop_hook(data->mlx_ptr, change_sprite, data);
	}
	else if (keysym == XK_w || keysym == XK_s || keysym == XK_a || keysym == XK_d)
		move_character(data, p_x, p_y, keysym);
	return (0);
}


/**
 * Where we start working with X11 and minilibx.
*/
void	draw_map(t_map *map)
{
	t_data	data;
	data.map = map;

	init_window(&data);
	initialize_draw(&data);
	mlx_put_image_to_window(data.mlx_ptr, data.win_ptr, data.layer->img_ptr, 0, 0);
	centered_text_on_screen(&data, "PRESS ANY KEY TO START", 0);
	centered_text_on_screen(&data, "Rules: Move with WASD, get all the collectibles and reach the exit!", 20);
	mlx_hook(data.win_ptr, DestroyNotify, StructureNotifyMask, &free_data, &data);
	mlx_key_hook(data.win_ptr, handle_input, &data);
	mlx_loop(data.mlx_ptr);
}