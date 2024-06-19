/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_character.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anfi <anfi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 22:59:34 by anfi              #+#    #+#             */
/*   Updated: 2024/06/19 11:15:38 by anfi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

/** Moves the character one tile down*/
t_bool	move_down(t_data *data, int x, int y)
{
	data->char_state = DOWN;
	if (data->map->map[y + 1][x] == '1')
	{
		merge_tile(data, data->items->character, y, x);
		return (false);
	}
	merge_tile(data, data->items->character, y + 1, x);
	data->map->p_pos[Y] = y + 1;
	return (true);
}

/** Moves the character one tile up*/
t_bool	move_up(t_data *data, int x, int y)
{
	data->char_state = UP;
	if (data->map->map[y - 1][x] == '1')
	{
		merge_tile(data, data->items->character, y, x);
		return (false);
	}
	merge_tile(data, data->items->character, y - 1, x);
	data->map->p_pos[Y] = y - 1;
	return (true);
}

/** Moves the character one tile to the left*/
t_bool	move_left(t_data *data, int x, int y)
{
	data->char_state = LEFT;
	if (data->map->map[y][x - 1] == '1')
	{
		merge_tile(data, data->items->character, y, x);
		return (false);
	}
	merge_tile(data, data->items->character, y, x - 1);
	data->map->p_pos[X] = x - 1;
	return (true);
}

/** Moves the character one tile to the right*/
t_bool	move_right(t_data *data, int x, int y)
{
	data->char_state = RIGHT;
	if (data->map->map[y][x + 1] == '1')
	{
		merge_tile(data, data->items->character, y, x);
		return (false);
	}
	merge_tile(data, data->items->character, y, x + 1);
	data->map->p_pos[X] = x + 1;
	return (true);
}
