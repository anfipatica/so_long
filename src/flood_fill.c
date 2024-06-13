/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymunoz-m <ymunoz-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 19:55:04 by anfi              #+#    #+#             */
/*   Updated: 2024/06/13 13:33:31 by ymunoz-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../inc/so_long.h"

int	check_enemy_path(char **map, int y, int x, int dir)
{
	int	valid_tile;
	int	temp_x;
	int	enemies;

	valid_tile = 0;
	enemies = 0;
	temp_x = x;
	printf("%c: x = %d, y = %d\n",map[y][x], x, y);
	while (map[y][--x] == '0' || map[y][x] == 'F')
	{
		printf("--%c, %c, %c\n", map[y][x],  map[y + 1][x],  map[y - 1][x]);
		if (map[y][x] == 'F')
			enemies++;
		if (dir == DOWN && (map[y + 1][x] == '0' && (map[y][x - 1] == '0' || map[y][x - 1] == 'F')))
			valid_tile++;
		else if (dir == UP && (map[y - 1][x] == '0' && (map[y][x - 1] == '0' || map[y][x - 1] == 'F')))
			valid_tile++;
	}
	x = temp_x;
	while (map[y][x] == '0' || map[y][x] == 'F')
	{
		printf("++%c, %c, %c\n", map[y][x],  map[y + 1][x],  map[y - 1][x]);
		if (map[y][x] == 'F')
			enemies++;
		if (dir == DOWN && (map[y + 1][x] == '0' && map[y][x - 1] == '0'))
			valid_tile++;
		else if (dir == UP && (map[y - 1][x] == '0' && map[y][x - 1] == '0'))
			valid_tile++;
		x++;
	}
	printf("valid_tiles = %d, enemies = %d\n", valid_tile, enemies);
	return (valid_tile - enemies);
}
int	check_tile(t_map *map, int y, int x)
{
	if (map->map[y][x] != '1' && map->ff_map[y][x] == 0)
	{
		return (1);
	}
	else
		return (0);
}

int	change_tile(t_map *map, int y, int x, int *tiles)
{
	int	changed;

	changed = 0;
	if (tiles[0] == 1)
	{
		map->ff_map[y-1][x] = map->ff_map[y][x] + 1;
		changed++;
	}
	if (tiles[1] == 1)
	{
		map->ff_map[y+1][x] = map->ff_map[y][x] + 1;
		changed++;
	}
	if (tiles[2] == 1)
	{
		map->ff_map[y][x-1] = map->ff_map[y][x] + 1;
		changed++;
	}
	if (tiles[3] == 1)
	{
		map->ff_map[y][x+1] = map->ff_map[y][x] + 1;
		changed++;
	}
	return (changed);
}

/**
 * The main function for my flood_fill algorithm.
*/
void	flood_fill(t_map *map, int y, int x, int i)
{
	int	tiles[5];

	if (map->map[y][x] == 'C')
		map->accesible_c++;
	if (map->map[y][x] == 'E')
		map->accesible_e++;
	if (map->map[y][x] == 'F')
		map->accesible_f++;
	tiles[0] = check_tile(map, y - 1, x);
	tiles[1] = check_tile(map, y + 1, x);
	tiles[2] = check_tile(map, y, x - 1);
	tiles[3] = check_tile(map, y, x + 1);
	if (change_tile(map, y, x, tiles) != 0)
		i++;
	if (tiles[0] == 1)
		flood_fill(map, y - 1, x, i);
	if (tiles[1] == 1)
		flood_fill(map, y + 1, x, i);
	if (tiles[2] == 1)
		flood_fill(map, y, x - 1, i);
	if (tiles[3] == 1)
		flood_fill(map, y, x + 1, i);
}

/**
 * We create an int matrix to use for the flood_fill algorithm, call flood_fill
 * and once it is done we check the exit and collectibles are reachable.
*/

void	clean_ff_matrix(t_map *map)
{
	int	y;
	int	x;

	y = -1;
	while (++y < map->row_num)
	{
		x = -1;
		while (++x < map->col_num)
			map->ff_map[y][x] = -1;
	}
}

void	pre_flood_fill(t_map *map)
{
	map->ff_map = create_ff_matrix(map->col_num, map->row_num);
	if (map->ff_map == 0)
		malloc_failed(map);
	print_ff_matrix(*map);
	map->ff_map[map->p_pos[Y]][map->p_pos[X]] = 1;
	flood_fill(map, map->p_pos[Y], map->p_pos[X], 2);
	print_ff_matrix(*map);
	validate_path(map);
	clean_ff_matrix(map);
}