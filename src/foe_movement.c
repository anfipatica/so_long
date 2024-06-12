/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   foe_movement.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymunoz-m <ymunoz-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 13:09:31 by ymunoz-m          #+#    #+#             */
/*   Updated: 2024/06/12 17:19:13 by ymunoz-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../inc/so_long.h"


void	update_map(t_data *data)
{
	int	n;
	int x;
	int y;

	n = -1;
	while ( ++n < data->map->f_count)
	{
		x = data->foe_info[n].x;
		y = data->foe_info[n].y;
		data->map->map[y][x] = 'F';
		if (data->foe_info[n].dir == LEFT)
			data->map->map[y][x + 1] = '0';
		else if (data->foe_info[n].dir == RIGHT)
			data->map->map[y][x - 1] = '0';
	}
}
void	register_foes(t_data *data, int y, int x)
{
	static int n;

	data->foe_info[n].x = x;
	data->foe_info[n].y = y;
	data->foe_info[n].dir = LEFT;
	data->map->ff_map[y][x] = n++;
}

void	move_foe_left(t_data *data, int y, int x, int n)
{
	if (data->foe_info[n].dir == RIGHT)
		data->foe_info[n].dir = LEFT;
	if (ft_strchr("1CE", data->map->map[y][x - 1]) != NULL)
		move_foe_right(data, y, x, n);
	else if (ft_strchr("F", data->map->map[y][x - 1]) != NULL
		&& data->foe_info[data->map->ff_map[y][x - 1]].dir == RIGHT)
		move_foe_right(data, y, x, n);
	else
	{
		data->map->ff_map[y][x - 1] = n;
		data->map->ff_map[y][x] = -1;
		merge_tile(data, data->items->foe[data->sprite_state], y, x - 1);
		draw_tile(data, data->items->floor, y, x);
		data->foe_info[n].x = x - 1;
	}
}

void	move_foe_right(t_data *data, int y, int x, int n)
{
	if (data->foe_info[n].dir == LEFT)
		data->foe_info[n].dir = RIGHT;
	if (ft_strchr("1CE", data->map->map[y][x + 1]) != NULL)
		move_foe_left(data, y, x, n);
	else if (ft_strchr("F", data->map->map[y][x + 1]) != NULL
		&& data->foe_info[data->map->ff_map[y][x + 1]].dir == LEFT)
		move_foe_left(data, y, x, n);
	else
	{
		data->map->ff_map[y][x + 1] = n;
		data->map->ff_map[y][x] = -1;
		merge_tile(data, data->items->foe[data->sprite_state], y, x + 1);
		draw_tile(data, data->items->floor, y, x);
		data->foe_info[n].x = x + 1;
	}
}

void	move_foe(t_data *data, int y, int x, int n)
{
	print_matrix(*data->map);
	print_ff_matrix(*data->map);
	if (data->foe_info[n].dir == LEFT)
		move_foe_left(data, y, x, n);
	else if (data->foe_info[n].dir == RIGHT)
		move_foe_right(data, y, x, n);
	print_matrix(*data->map);
	print_ff_matrix(*data->map);
}
