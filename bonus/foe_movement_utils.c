/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   foe_movement_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anfi <anfi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 21:10:20 by anfi              #+#    #+#             */
/*   Updated: 2024/06/18 23:48:12 by anfi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long_bonus.h"

void	register_foes(t_data *data, int y, int x)
{
	static int	n;

	data->foe_info[n].dir = LEFT;
	data->map->ff_map[y][x] = n++;
	if (check_if_foe_can_move(data, y, x) == 2)
		change_foe_direction(data, y, x, PERMANENT_STILL);
}

/** A function that checks if a foe can move or not. If not, it will return 0
 * as in 0 movements can be made. Otherwise, it will return 1.*/
/** This no movement can be temporal or permanent. The only time it is permanent
 * is if the tiles that don't allow the movement are walls or the exit.
 * Collectibles and other foes coult allow movement in the future.*/
int	check_if_foe_can_move(t_data *data, int y, int x)
{
	int	temp_x;
	int	n;

	temp_x = x;
	n = 0;
	while (--x >= 0 && ft_strchr("1EF", data->map->map[y][x]) != NULL)
	{
		if (ft_strchr("1E", data->map->map[y][x]) != NULL)
		{
			n++;
			break ;
		}
	}
	x = temp_x;
	while ((n == 1 && ++x < data->map->col_num)
		&& ft_strchr("1EF", data->map->map[y][x]) != NULL)
	{
		if (ft_strchr("1E", data->map->map[y][x]) != NULL)
		{
			n++;
			break ;
		}
	}
	return (n);
}
