/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   refresh_sprites.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anfi <anfi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 20:18:26 by anfi              #+#    #+#             */
/*   Updated: 2024/06/18 23:48:45 by anfi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long_bonus.h"

/**
 * This function updates the map sprites after the foe movements.
*/
void	update_map(t_data *data)
{
	int	y;
	int	x;

	y = -1;
	while (++y < data->map->row_num)
	{
		x = -1;
		while (++x < data->map->col_num)
		{
			if (data->map->map[y][x] == 'F' && data->map->ff_map[y][x] == -1)
			{
				data->map->map[y][x] = '0';
				draw_tile(data, data->items->floor, y, x);
			}
			if (data->map->map[y][x] != 'F' && data->map->ff_map[y][x] >= 0)
			{
				data->map->map[y][x] = 'F';
				merge_tile(data, data->items->foe[data->sprite_state], y, x);
			}
		}
	}
}

/**
 * A function that goes over the map and the moment it finds any 'C' or 'F'
 * proceeds to refresh their sprites. Since foes algo move, that is done inside
 * other functions called in move_foe().
*/
void	refresh_collectibles_and_foes(t_data *data)
{
	int	x;
	int	y;
	int	s;

	y = -1;
	data->sprite_state = !data->sprite_state;
	s = data->sprite_state;
	while (++y < data->map->row_num)
	{
		x = -1;
		while (++x < data->map->col_num)
		{
			if (data->map->map[y][x] == 'C')
				merge_tile(data, data->items->collectible[s], y, x);
			else if (data->map->map[y][x] == 'F')
			{
				move_foe(data, y, x, data->map->ff_map[y][x]);
			}
		}
	}
}

/**
 * This is a function that refreshes the character sprite to make it look
 * like it is breathing if not moving.
*/
void	refresh_character(t_data *data)
{
	int	y;
	int	x;

	y = data->map->p_pos[Y];
	x = data->map->p_pos[X];
	if (data->char_state == DOWN && data->sprite_state == 0)
		merge_tile(data, data->items->character[5], y, x);
	else if (data->char_state == DOWN)
		merge_tile(data, data->items->character[0], y, x);
	else if (data->char_state == LEFT && data->sprite_state == 0)
		merge_tile(data, data->items->character[6], y, x);
	else if (data->char_state == LEFT)
		merge_tile(data, data->items->character[1], y, x);
	else if (data->char_state == UP && data->sprite_state == 0)
		merge_tile(data, data->items->character[7], y, x);
	else if (data->char_state == UP)
		merge_tile(data, data->items->character[2], y, x);
	else if (data->char_state == RIGHT && data->sprite_state == 0)
		merge_tile(data, data->items->character[8], y, x);
	else if (data->char_state == RIGHT)
		merge_tile(data, data->items->character[3], y, x);
}

/**
 * A function that calls other functions to refresh the sprites when the
 * refresh_time has been reached.
*/
int	refresh_sprites(t_data *data)
{
	static int	i;

	if (++i > REFRESH_RATE)
	{
		i = 0;
		refresh_collectibles_and_foes(data);
		refresh_character(data);
		update_map(data);
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->layer->img_ptr, 0, 0);
		mlx_string_put(data->mlx_ptr, data->win_ptr, 30, 30,
			(unsigned int)0xAFBED6, data->message);
		check_changes(data, data->map, data->map->p_pos[Y],
			data->map->p_pos[X]);
	}
	return (0);
}
