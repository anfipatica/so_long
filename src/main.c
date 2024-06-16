/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anfi <anfi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 22:55:37 by anfi              #+#    #+#             */
/*   Updated: 2024/06/16 22:50:52 by anfi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

/**
 * Validates de correct extension of the map received.
*/
void	validate_name(char *name)
{
	int	i;

	i = 0;
	while (name[i])
		i++;
	if (ft_strncmp(&name[i - 4], ".ber", 5) != 0)
		invalid_map(NULL, WRONG_MAP_EXTENSION);
}

/** Where everything begins.
 * This program can be separated into three parts:
 * 1. Validate the received map.
 * 2. Create a window with minilibx that displays said map.
 * 3. The game itself. Every second that passes changes the game sprites, the
 * 	foes move and every input the user makes needs to be evaluated and
 * 	represented in our window.
*/
int	main(int argc, char **argv)
{
	t_map	map;

	if (argc == 1)
	{
		return (write(1, "ERROR: No map received!!\n"
				"  To execute the program it needs to also receive a valid map "
				"with .ber extension.\n  For example: ./so_long map/map.ber\n"
				"  Already existing maps are inside the *map* folder\n", 197));
	}
	else if (argc > 2)
	{
		return (write(1, "ERROR: Too many arguments.\n"
				"  Please execute the program followed just by one map name.\n"
				"  For example: ./so_long map/map.ber\n"
				"  Already existing maps are inside the *map* folder\n", 176));
	}
	validate_name(argv[1]);
	map = read_map(argv[1]);
	validate_map(&map);
	pre_flood_fill(&map);
	draw_map(&map);
}
