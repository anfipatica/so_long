/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymunoz-m <ymunoz-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 23:07:11 by anfi              #+#    #+#             */
/*   Updated: 2024/06/19 15:01:30 by ymunoz-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long_bonus.h"

/**
 * Trims the line to make sure there is no new line before or after.
 * This is important to keep the same format before further validations.
*/
void	trim_line(t_map *map)
{
	if (!map->map_line_buf && !map->map_line)
	{
		write(2, "ERROR: Empty map\n", 17);
		exit(1);
	}
	map->map_line_buf = ft_strdup(map->map_line);
	free(map->map_line);
	map->map_line = ft_strtrim(map->map_line_buf, "\n");
	free(map->map_line_buf);
	map->map_line_buf = NULL;
}

/**
 * It will take the map we read as a line and transform it into a matrix.
 * It'll also validate that there are no empty lines inside the map.
*/
void	create_map(t_map *map)
{
	int	i;

	i = 0;
	map->map = ft_split(map->map_line, '\n');
	map->row_num = count_char(map->map_line, '\n') + 1;
	while (map->map[i])
		i++;
	if (map->row_num != i)
		invalid_map(map, EMPTY_LINE);
	map->col_num = ft_strlen(map->map[0]);
}

/**
 * This function reads the map using gnl. It will save it inside one line.
*/
t_map	read_map(char *map_name)
{
	t_map	map;

	map = init_map();
	map.map_fd = open(map_name, O_RDONLY);
	if (map.map_fd < 0)
		invalid_map(NULL, UNABLE_TO_OPEN);
	while (map.map_line_buf)
	{
		map.map_line_buf = get_next_line(map.map_fd);
		if (!(map.map_line_buf))
		{
			trim_line(&map);
			map.row_num = count_char(map.map_line, '\n');
			return (create_map(&map), map);
		}
		else
		{
			map.map_line = gnl_strnjoin(map.map_line, map.map_line_buf,
					ft_strlen(map.map_line) + ft_strlen(map.map_line_buf));
			map.row_num++;
			free(map.map_line_buf);
			map.map_line_buf = "";
		}
	}
	return (free_map(&map), map);
}
