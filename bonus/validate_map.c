/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anfi <anfi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 13:26:26 by ymunoz-m          #+#    #+#             */
/*   Updated: 2024/06/18 23:48:50 by anfi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long_bonus.h"

/**
 * After the flood_fill algorithm has been applied, it checks that the cell on
 * the ff_map corresponding to the E position on the map has any number aside
 * from 0 assigned to it. If so, the exit is reachable and the map is valid.
 * Same with the collectibles.
*/
void	validate_path(t_map *map)
{
	if (map->e_count != map->accesible_e)
		invalid_map(map, NON_REACHABLE_EXIT);
	if (map->c_count != map->accesible_c)
		invalid_map(map, NON_REACHABLE_COLLECTIBLE);
}

/**
 * It keeps track of each P, E and C chars found to check that
 * the subject needs are fulfilled.
*/
void	check_char(t_map *map, int i, int row)
{
	if ((i == 0 || i == (map->col_num - 1)) && map->map[row][i] != '1')
		invalid_map(map, INVALID_WALLS);
	else if (map->map[row][i] == 'C')
		map->c_count++;
	else if (map->map[row][i] == 'E')
		map->e_count++;
	else if (map->map[row][i] == 'F')
		map->f_count++;
	else if (map->map[row][i] == 'P')
	{
		map->p_count++;
		map->p_pos[Y] = row;
		map->p_pos[X] = i;
	}
	else if (map->map[row][i] != '0' && map->map[row][i] != '1')
		invalid_map(map, INVALID_CHAR);
}

/**
 * It checks that the map is surrounded by walls.
*/
void	validate_row(t_map *map, int row)
{
	int	i;

	i = 0;
	if (row == 0 || row == (map->row_num - 1))
	{
		while (map->map[row][i] == '1')
			i++;
		if (i != map->col_num)
			invalid_map(map, INVALID_WALLS);
	}
	else
	{
		while (map->map[row][i])
		{
			check_char(map, i, row);
			i++;
		}
	}
}

/**
 * It starts by checking if the map is a rectangle.
 * Then it checks if there is any row with a different length.
 * And it send each row to validate_row() for more in depth validations.
 * If any mistake is found, it calls invalid_map() with its error identifier.
*/
void	validate_map(t_map *map)
{
	int	i;

	i = -1;
	if (map->col_num == map->row_num)
		invalid_map(map, WRONG_SHAPE);
	while ((map->map)[++i])
	{
		if (map->col_num != ft_strlen(map->map[i]))
			invalid_map(map, DIFFERENT_LENGTHS);
		validate_row(map, i);
	}
	if (map->e_count == 0)
		invalid_map(map, NO_EXIT);
	else if (map->e_count > 1)
		invalid_map(map, TOO_MANY_EXITS);
	if (map->p_count == 0)
		invalid_map(map, NO_STARTING_POINT);
	else if (map->p_count > 1)
		invalid_map(map, TOO_MANY_STARTING_POINTS);
	if (map->c_count < 1)
		invalid_map(map, NO_OBJECT);
}
