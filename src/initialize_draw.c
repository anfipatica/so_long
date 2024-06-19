/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_draw.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anfi <anfi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 19:51:09 by anfi              #+#    #+#             */
/*   Updated: 2024/06/19 11:13:37 by anfi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"


/**
 * The first time the game is started we will have to draw every element on
 * it's initial position. We have many items to draw and, mostly, an
 * unnecessarily intricate wall design, so doing this needs it's own file.
*/
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
				merge_tile(data, data->items->exit, y, x);
		}
	}
}
