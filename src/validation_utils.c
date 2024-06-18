/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anfi <anfi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 23:04:41 by anfi              #+#    #+#             */
/*   Updated: 2024/06/18 22:57:41 by anfi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

/**
 * The continuation of invalid_map(). You know, to keep everything under 25 lines
*/
void	invalid_map_continuation(int error)
{
	if (error == INVALID_WALLS)
		write(2, "Walls do not enclose the map. Invalid .ber\n", 43);
	else if (error == INVALID_CHAR)
		write(2, "Found an invalid char inside the .ber.\n", 39);
	else if (error == NO_EXIT)
		write(2, "No exit found, invalid .ber\n", 28);
	else if (error == TOO_MANY_EXITS)
		write(2, "Found more than one exit, invalid .ber\n", 39);
	else if (error == NO_STARTING_POINT)
		write(2, "No starting point found, invalid .ber\n", 38);
	else if (error == TOO_MANY_EXITS)
		write(2, "Found more than one starting point, invalid .ber\n", 49);
	else if (error == NO_OBJECT)
		write(2, "There needs to be at least one collectible.\n", 44);
	else if (error == WRONG_SHAPE)
		write(2, "Map needs to be a rectangle, invalid .ber\n", 42);
	else if (error == NON_REACHABLE_EXIT)
		write(2, "Exit cannot be reached from the starting point.\n", 49);
	else if (error == NON_REACHABLE_COLLECTIBLE)
	{
		write(2, "At least one collectible cannot be reached "
			"from the starting point. Invalid ber\n", 80);
	}
}

/**
 * A function to print the corresponding error and correctly exit the program.
*/
void	invalid_map(t_map *map, int error)
{
	write(2, "ERROR: ", 7);
	if (error == WRONG_MAP_EXTENSION)
	{
		write(2, "Wrong map name."
			" The map needs to have .ber extension\n", 53);
	}
	else if (error == WRONG_MAP_NAME)
		write(2, "\".ber\" is not a valid map name\n", 31);
	else if (error == UNABLE_TO_OPEN)
	{
		write(2, "map could not be opened. Please make sure the map "
			"exists and that you entered the right address\n", 96);
	}
	if (error == EMPTY_LINE)
		write(2, "Found an empty line inside the .ber\n", 36);
	else if (error == DIFFERENT_LENGTHS)
	{
		write(2, "row length discrepancy found."
			" All rows must have the same length. Invalid .ber\n", 79);
	}
	invalid_map_continuation(error);
	free_map(map);
	exit (1);
}

/**
 * count_char returns how many times it has encountered character c
 * inside str.
*/
int	count_char(const char *str, const char c)
{
	int	i;
	int	count;

	i = -1;
	count = 0;
	while (str[++i])
	{
		if (str[i] == c)
			count++;
	}
	return (count);
}
