/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   foe_movement.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anfi <anfi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 13:09:31 by ymunoz-m          #+#    #+#             */
/*   Updated: 2024/06/18 22:33:11 by anfi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

/**
 * A function to check if n foe has any movement path or must remain still.*/
void	change_foe_direction(t_data *data, int y, int x, int movement)
{
	data->foe_info[data->map->ff_map[y][x]].dir = movement;
	if (movement == NONE)
		data->map->ff_map[y][x] = data->map->ff_map[y][x];
	else if (movement == LEFT)
	{
		if (data->map->ff_map[y][x - 1] != -1)
			return (change_foe_direction(data, y, x, NONE));
		data->map->ff_map[y][x - 1] = data->map->ff_map[y][x];
		data->map->ff_map[y][x] = -1;
		data->foe_info[data->map->ff_map[y][x - 1]].dir = LEFT;
	}
	else if (movement == RIGHT)
	{
		data->map->ff_map[y][x + 1] = data->map->ff_map[y][x];
		data->map->ff_map[y][x] = -1;
	}
	else if ((movement == PERMANENT_STILL))
		data->foe_info[data->map->ff_map[y][x]].dir = PERMANENT_STILL;
}

void	move_foe_right(t_data *data, int y, int x, int n)
{
	if (data->foe_info[n].dir != RIGHT
		&& ft_strchr("1EC", data->map->map[y][x + 1]))
		return (change_foe_direction(data, y, x, NONE));
	if (ft_strchr("1EC", data->map->map[y][x + 1]))
		return (move_foe_left(data, y, x, n));
	else if (data->map->ff_map[y][x + 1] != -1)
	{
		if (data->foe_info[data->map->ff_map[y][x + 1]].dir == LEFT)
		{
			if (ft_strchr("1CE", data->map->map[y][x - 1]))
				change_foe_direction(data, y, x, NONE);
			else if (data->map->ff_map[y][x + 1] == -1
				&& data->map->map[y][x + 1] == 'F')
				change_foe_direction(data, y, x, NONE);
			else
				change_foe_direction(data, y, x, LEFT);
		}
	}
	else
		change_foe_direction(data, y, x, RIGHT);
}

/**
 * - If the direction the foe has is "RIGHT" means it is trying to turn over, it
 * cannot move to the right. So if the left tile is also non available, no
 * movement must be done.
 * - If it's direction is not right but the left tile is non available, we try to
 * move to the right.
 * - If the tile to the left has a foe, we must check it's information:
 * -if it goes to the right both collide changing it's direction.
 * -if it has temporal no movement, we'll try to move to the right.
 * - Else we'll move to the left.
*/
void	move_foe_left(t_data *data, int y, int x, int n)
{
	if (data->foe_info[n].dir == RIGHT
		&& ft_strchr("1EC", data->map->map[y][x - 1]))
		return (change_foe_direction(data, y, x, NONE));
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
			move_foe_right(data, y, x, n);
	}
	else
		change_foe_direction(data, y, x, LEFT);
}

/**
 * Our enemies only can: move left, right or no movement at all.
 * If the foe is on "PERMANENT_STILL", nothing must be done. This was previously
 * assigned.
 * Else, at the beginning every foe will *try to move to the left*. It will keep
 * doing so until it finds a non walkable tile. Then, *it will change its
 * direction to the right*.
 * More details: The movement is made reading the map from left to right, this
 * means that a foe on the left will move first always. If 2 foes are together:
 * - if they are both moving to the left, both will move to the left.
 * - If both move to the right, the left foe will not be able to move since the
 *   tile is occupied by a foe that moves "slower", so they will collide,
 *   changing the left foe direction.
*/
void	move_foe(t_data *data, int y, int x, int n)
{
	if (data->foe_info[n].dir == PERMANENT_STILL)
		return ;
	if (data->foe_info[n].dir == LEFT || data->foe_info[n].dir == NONE)
		move_foe_left(data, y, x, n);
	else if (data->foe_info[n].dir == RIGHT)
		move_foe_right(data, y, x, n);
}
