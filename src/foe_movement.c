/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   foe_movement.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anfi <anfi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 13:09:31 by ymunoz-m          #+#    #+#             */
/*   Updated: 2024/06/16 19:40:27 by anfi             ###   ########.fr       */
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
	printf("vamos a hacer un movimiento!!!! dirección: %d\n", movement);
	data->foe_info[data->map->ff_map[y][x]].dir = movement;
	if (movement == NONE)
		data->map->ff_map[y][x] = data->map->ff_map[y][x];
	else if (movement == LEFT)
	{
		if (data->map->ff_map[y][x - 1] != -1)
			return (change_foe_direction(data, y, x, NONE));
		data->map->ff_map[y][x - 1] = data->map->ff_map[y][x];
		data->map->ff_map[y][x] = -1;
		data->foe_info[data->map->ff_map[y][x - 1]].dir  = LEFT;
	}
	else if (movement == RIGHT)
	{
		data->map->ff_map[y][x + 1] = data->map->ff_map[y][x];
		data->map->ff_map[y][x] = -1;
	}
	else if ((movement == PERMANENT_STILL))
		data->foe_info[data->map->ff_map[y][x]].dir  = PERMANENT_STILL;
}

// int		move_many_foes_right(t_data *data, int y, int x, int n)
// {
// 	int	i;
// 	int	j;
// 	int	last_foe;

// 	i = 0;
// 	j = 0;
// 	last_foe = 0;
// 	printf("move_many_foes_right\n");
// 	while (data->map->map[y][x + i] == 'F' && data->foe_info[n + i].dir != LEFT)
// 	{
// 		printf("n = %d, dir = %d\n", n + i, data->foe_info[n + i].dir);
// 		i++;
// 	}
// 	printf("n = %d, dir = %d\n", n + i, data->foe_info[n + i].dir);
// 	last_foe = i;
// 	printf("tenemos que mover %d foes\n", last_foe);
// 	while (--i >= 0)
// 	{
// 		printf("ANDA COMPADRE. i = %d. n = %d\n", i, n + i);
// 		if (ft_strchr("1CE", data->map->map[y][last_foe + 1]))
// 			change_foe_direction(data, y, x + i, NONE);
// 		else
// 			change_foe_direction(data, y, x + i, RIGHT);
// 		j++;
// 	}
// 	return (j);
// }

/** A function that checks if a foe can move or not. If not, it will return 0
 * as in 0 movements can be made. Otherwise, it will return 1.*/
int		check_if_foe_can_move(t_data *data, int y, int x)
{
	int	temp_x;

	temp_x = x;
	printf("check_if_foe_can_move\n");
	if (ft_strchr("1EF", data->map->map[y][x - 1]))
	{
		while (x >= 0 && data->map->map[y][x - 1] == 'F')
		{
			if (ft_strchr("1E", data->map->map[y][x - 1]))
				return (1);
			x--;
		}
		x = temp_x;
		if (ft_strchr("1E", data->map->map[y][x + 1]) != NULL)
			return (change_foe_direction(data, y, x, PERMANENT_STILL), 0);
		else if (data->map->map[y][x + 1] == 'F')
		{
			while ( x < data->map->col_num && data->map->map[y][x + 1] == 'F')
			{
				if (!ft_strchr("1E", data->map->map[y][x + 1]))
					return (1);
				x++;
			}
			return (change_foe_direction(data, y, x, PERMANENT_STILL), 0);
		}
	}
	return (1);
}

int		move_foe_right(t_data *data, int y, int x, int n)
{
	if (data->foe_info[n].dir != RIGHT && ft_strchr("1EC", data->map->map[y][x + 1]))
		return (change_foe_direction(data, y, x, NONE), 0);
	if (ft_strchr("1EC", data->map->map[y][x + 1]))
		return (move_foe_left(data, y, x, n));
	else if (data->map->ff_map[y][x + 1] != -1)
	{
		if (data->foe_info[data->map->ff_map[y][x + 1]].dir == LEFT)
		{
			data->foe_info[data->map->ff_map[y][x + 1]].dir = RIGHT;
			if (ft_strchr("1CE", data->map->map[y][x - 1]))
				change_foe_direction(data, y, x, NONE);
			else if (data->map->ff_map[y][x + 1] == -1 && data->map->map[y][x + 1] == 'F')
				change_foe_direction(data, y, x, NONE);
			else
				change_foe_direction(data, y, x, LEFT);
		}
	}
	else
		change_foe_direction(data, y, x, RIGHT);
	return (0);
}

int		move_foe_left(t_data *data, int y, int x, int n)
{
	if (data->foe_info[n].dir == RIGHT && ft_strchr("1EC", data->map->map[y][x - 1]))
		return (change_foe_direction(data, y, x, NONE), 0);
	if (ft_strchr("1EC", data->map->map[y][x - 1]))
		return (move_foe_right(data, y, x, n));
	else if (data->map->ff_map[y][x - 1] != -1)
	{
		if (data->foe_info[data->map->ff_map[y][x - 1]].dir == RIGHT)
		{
			data->foe_info[data->map->ff_map[y][x - 1]].dir = LEFT;
			data->foe_info[data->map->ff_map[y][x]].dir = RIGHT;
		}
		else if (data->foe_info[data->map->ff_map[y][x - 1]].dir == NONE)
		{
			move_foe_right(data, y, x, n);
		}
	}
	else
		change_foe_direction(data, y, x, LEFT);
	return (0);

}

int		move_foe(t_data *data, int y, int x, int n)
{
	
	int	moves;

	moves = 0;
	if (data->foe_info[n].dir == PERMANENT_STILL)
		return (0);
	if (data->foe_info[n].dir == LEFT || data->foe_info[n].dir == NONE)
	{
		move_foe_left(data, y, x, n);
	}
	else if (data->foe_info[n].dir == RIGHT)
	{
		moves = move_foe_right(data, y, x, n);
	}
	return (moves);
}
