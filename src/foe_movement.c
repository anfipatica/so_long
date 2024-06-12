/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   foe_movement.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymunoz-m <ymunoz-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 13:09:31 by ymunoz-m          #+#    #+#             */
/*   Updated: 2024/06/12 21:14:32 by ymunoz-m         ###   ########.fr       */
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
				data->map->map[y][x] = '0';
			else if (data->map->map[y][x] != 'F' && data->map->ff_map[y][x] >= 0)
				data->map->map[y][x] = 'F';
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

void	move_foe_left(t_data *data, int y, int x, int n)
{
	if (data->foe_info[n].dir == RIGHT)
		data->foe_info[n].dir = LEFT;
	if (ft_strchr("1CE", data->map->map[y][x - 1]) != NULL)
	{
		printf("1. Aquí!!\n");
		move_foe_right(data, y, x, n);
	}
	else if (ft_strchr("F", data->map->map[y][x - 1]) != NULL
		&& data->foe_info[data->map->ff_map[y][x - 1]].dir == RIGHT)
	{
		printf("2. QUe no!!! por aquí!!!\n");
		move_foe_right(data, y, x, n);
	}
	else
	{
		data->map->ff_map[y][x - 1] = n;
		data->map->ff_map[y][x] = -1;
		merge_tile(data, data->items->foe[data->sprite_state], y, x - 1);
		draw_tile(data, data->items->floor, y, x);
		data->foe_info[n].x = x - 1;
	}
}

int	check_foes_sides(t_data *data, int y, int x, int n)
{
	int	left_n;
	int	right_n;

	left_n = data->map->ff_map[y][x - 1];
	right_n = data->map->ff_map[y][x + 1];
	if (data->foe_info[n].dir == LEFT)
	{
		if (data->map->ff_map[y][x - 1] != -1 && data->foe_info[left_n].dir == RIGHT)
		{
			if (data->map->map[y][x - 1] != 'F')
				return -1;
			move_foe_right(data, y, x, n);
		}
		return (0);
	}
	
	else if (data->map->map[y][x + 1] == 'F' && data->foe_info[right_n].dir == LEFT)
	{
		move_foe_left(data, y, x, n);
		move_foe_right(data, y, x + 1, right_n);
		return (1);
	}
	return (0);
}
void	move_foe_right(t_data *data, int y, int x, int n)
{
	if (data->foe_info[n].dir == LEFT)
		data->foe_info[n].dir = RIGHT;
	if (ft_strchr("1CE", data->map->map[y][x + 1]) != NULL)
	{
		printf("3. He entrado en este if uw\n");
		move_foe_left(data, y, x, n);
	}
	else if (ft_strchr("F", data->map->map[y][x + 1]) != NULL
		&& data->foe_info[data->map->ff_map[y][x + 1]].dir == LEFT)
	{
		printf("4. He entrado en este if uwu\n");
		move_foe_left(data, y, x, n);
	}
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
	printf("antes de ningún movimiento:\n");
	print_ff_matrix(*data->map);
	if (data->foe_info[n].dir == LEFT)
	{
		printf("en un inicio, vamos a la izquierda\n");
		if (check_foes_sides(data, y, x, n) == 0)
			move_foe_left(data, y, x, n);
	}
	else if (data->foe_info[n].dir == RIGHT)
	{
		printf("en un inicio, vamos a la derecha\n");
		if (check_foes_sides(data, y, x, n) == 0)
			move_foe_right(data, y, x, n);
	}
	printf("Al terminar el movimiento:\n");
	print_ff_matrix(*data->map);
}
