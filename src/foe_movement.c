/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   foe_movement.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anfi <anfi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 13:09:31 by ymunoz-m          #+#    #+#             */
/*   Updated: 2024/06/14 21:18:45 by anfi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../inc/so_long.h"

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
				draw_tile(data, data->items->floor , y, x);
			}
			else if (data->map->map[y][x] != 'F' && data->map->ff_map[y][x] >= 0)
			{
				data->map->map[y][x] = 'F';
				merge_tile(data, data->items->foe[data->sprite_state], y, x);
			}
		}
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

/**
 * A function to check if n foe has any movement path or must remain still.
*/

void	change_foe_direction(t_data *data, int y, int x, int movement)
{
	data->foe_info[data->map->ff_map[y][x]].dir = movement;
	if (movement == NONE)
		data->map->ff_map[y][x] = data->map->ff_map[y][x];
	else if (movement == LEFT)
	{
		data->map->ff_map[y][x - 1] = data->map->ff_map[y][x];
		data->map->ff_map[y][x] = -1;
		data->foe_info[data->map->ff_map[y][x - 1]].dir  = LEFT;
	}
	else if (movement == RIGHT)
	{
		data->map->ff_map[y][x + 1] = data->map->ff_map[y][x];
		data->map->ff_map[y][x] = -1;
		data->foe_info[data->map->ff_map[y][x - 1]].dir  = RIGHT;
	}
	

}

/** A function that checks if a foe can move or not. If not, it will return 0
 * as in 0 movements can be made. Otherwise, it will return 1.*/
int		check_if_foe_can_move(t_data *data, int y, int x, int n)
{
	if (ft_strchr("1EC", data->map->map[y][x - 1]))
	{
		if (ft_strchr("1EC", data->map->map[y][x + 1]))
			return (change_foe_direction(data, y, x, NONE), 0);
		else if (ft_strchr("F", data->map->map[y][x + 1]))
		{
			if (check_if_foe_can_move(data, y, x + 1, data->map->ff_map[y][x + 1]) == 0)
				return (change_foe_direction(data, y, x, NONE), 0);
		}
	}
	else if (ft_strchr("F", data->map->map[y][x - 1]))
	{
		if (data->foe_info[data->map->ff_map[y][x - 1]].dir == NONE)
			return (change_foe_direction(data, y, x, NONE), 0);
		if (ft_strchr("1EC", data->map->map[y][x + 1]))
			return (0);
		else if (ft_strchr("F", data->map->map[y][x + 1]))
			check_if_foe_can_move(data, y, x + 1, data->map->ff_map[y][x + 1]);
	}
	else if (data->foe_info[n].dir == NONE)
		data->foe_info[n].dir = LEFT;
	return (1);
}

int		move_foe_right(t_data *data, int y, int x, int n)
{
	if (data->foe_info[n].dir == LEFT && ft_strchr("1EC", data->map->map[y][x + 1]))
		return (change_foe_direction(data, y, x, NONE), 0);
	if (ft_strchr("1EC", data->map->map[y][x + 1]))
		return (move_foe_left(data, y, x, n));
	change_foe_direction(data, y, x, RIGHT);
	return (0);
}

int		move_foe_left(t_data *data, int y, int x, int n)
{
	(void)n;
	if (data->foe_info[n].dir == RIGHT && ft_strchr("1EC", data->map->map[y][x - 1]))
		return (change_foe_direction(data, y, x, NONE), 0);
	if (ft_strchr("1EC", data->map->map[y][x - 1]))
		return (move_foe_right(data, y, x, n));
	change_foe_direction(data, y, x, LEFT);
	return (0);

}

int		move_foe(t_data *data, int y, int x, int n)
{
	
	int	moves;

	moves = 0;
	printf("antes de ningún movimiento:\n");
	print_ff_matrix(*data->map);
	if (check_if_foe_can_move(data, y, x, n) == 0)
		return (0);
	if (data->foe_info[n].dir == LEFT)
	{
		move_foe_left(data, y, x, n);
	}
	else if (data->foe_info[n].dir == RIGHT)
	{
		move_foe_right(data, y, x, n);
	}
	printf("Al terminar el movimiento:\n");
	print_ff_matrix(*data->map);
	
	return (moves);
}
