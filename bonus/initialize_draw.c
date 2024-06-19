/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_draw.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anfi <anfi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 19:51:09 by anfi              #+#    #+#             */
/*   Updated: 2024/06/18 23:48:31 by anfi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long_bonus.h"

/**
 * two out of two functions to draw the walls. There are 17 possible wall
 * possitions and therefore, 17 sprites. Why did I do this to myself I don't know
*/
void	draw_wall_continuation(t_data *data, int y, int x, char **map)
{
	if (map[y][x + 1] == '1' && map[y][x - 1] == '1')
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

/**
 * one out of two functions to draw the walls based on if there's other
 * wall tiles adjacent to the one currently drawing.
*/
void	draw_wall(t_data *data, int y, int x)
{
	char	**map;

	map = data->map->map;
	if (y == 0 || y + 1 == data->map->row_num || x == 0
		|| x + 1 == data->map->col_num)
		merge_tile(data, data->items->wall[12], y, x);
	else if (map[y - 1][x] == '1' && map[y][x + 1] == '1'
		&& map[y + 1][x] == '1' && map[y][x - 1] == '1')
		merge_tile(data, data->items->wall[1], y, x);
	else if (map[y - 1][x] == '1' && map[y][x + 1] == '1'
		&& map[y][x - 1] == '1')
		merge_tile(data, data->items->wall[13], y, x);
	else if (map[y - 1][x] == '1' && map[y + 1][x] == '1'
		&& map[y][x + 1] == '1')
		merge_tile(data, data->items->wall[14], y, x);
	else if (map[y][x + 1] == '1' && map[y + 1][x] == '1'
		&& map[y][x - 1] == '1')
		merge_tile(data, data->items->wall[15], y, x);
	else if (map[y - 1][x] == '1' && map[y][x - 1] == '1'
		&& map[y + 1][x] == '1')
		merge_tile(data, data->items->wall[16], y, x);
	else
		draw_wall_continuation(data, y, x, map);
}

/**
 * The first time the game is started we will have to draw every element on
 * it's initial position. We have many items to draw and, mostly, an
 * unnecessarily intricate wall design, so doing this needs it's own file.
*/
void	initialize_draw(t_data *data, int i)
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
				merge_tile(data, data->items->foe[0], y, x);
			if (data->map->map[y][x] == 'F' && i == 1)
				register_foes(data, y, x);
		}
	}
}
