/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anfi <anfi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 22:55:37 by anfi              #+#    #+#             */
/*   Updated: 2024/06/09 21:43:04 by anfi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../inc/so_long.h"

/**
 * Where the magic happens. We read the map which name was sent as an argv,
 * we create the map as a matrix, making every validation needed, and
 * lastly we draw that map on a window wait for imput from the user and...
 * we let them play, Easy peasy!
*/

/**
 * Validates de correct extension of the map received.
 * CHECK THE FOLLOWING CASES: ".ber" and "whatever.ber.ber"*/
void	validate_name(char *name)
{
	int	i;

	i = 0;
	while (name[i] && name[i] != '.')
		i++;
	if (ft_strncmp(&name[i], ".ber", 5) != 0)
		exit (write(1, "ERROR: Wrong map name. The map needs to have"
		" .ber extension\n", 60));
}

int	main(int argc, char **argv)
{
	t_map	map;
	if (argc == 1)
	{
		return (write(1, "ERROR: No map received!!\n"
		"  To execute the program it needs to also receive a valid map with "
		".ber extension.\n  For example: ./so_long map/map.ber\n"
		"  Already existing maps are inside the *map* folder\n", 197));
	}
	else if (argc > 2)
	{
		return	(write(1, "ERROR: Too many arguments.\n"
		"  Please execute the program followed just by one map name.\n"
		"  For example: ./so_long map/map.ber\n"
		"  Already existing maps are inside the *map* folder\n", 176));
	}
	validate_name(argv[1]);
	map = read_map(argv[1]);
	create_map(&map);
	draw_map(&map);
}
