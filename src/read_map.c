#include "../inc/so_long.h"

/* Trim line trims the line to make sure there is no new line before or after.
This is important to keep the same format before doing any validations on the map.*/
void	trim_line(t_map *map)
{
	map->map_line_buf = ft_strdup(map->map_line);
	free(map->map_line);
	map->map_line = ft_strtrim(map->map_line_buf, "\n");
	printf("%s\n", map->map_line);
	free(map->map_line_buf);
	map->map_line_buf = NULL;
}

/*
- We will take the map we read as a line and transform it into a matrix.

- row_num: We calculate row_num based on the \n we find in the line. We deal later with empty lines.
	We add 1 to row_num becase the last line of the map does not have a '\n'. Wheter the .ber has it or not,
	we trimmed map_line to homogenize the format, therefore we count_char will not count this last line.

- We will also validate here if there is any empty line inside the .ber:
	We already trimmed the beggining and the end, but still there could be empty lines inside
	and those will not be saved in the matrix since ft_split "jumps" duplicated chars.
	But this time if there is more than one empty line between lines inside the .ber,
	the map is invalid.

- Once we have our matrix, we first send it to validate_map() where some validations will be done,
	and then we send it to pre_floof_fill where more validations will be made and it will start
	the flood_fill process to check if the map can be solved (Exit is reachable).
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
	validate_map(map);
	pre_flood_fill(map);
}

/**
 * This function reads the map using gnl. It will save it inside one line.
 * Then, it will send it to create_map where it will be splited to create a matrix.
*/
t_map	read_map(char *map_name)
{
	t_map	map;

	map = init_map();
	map.map_fd = open(map_name, O_RDONLY);
	while (map.map_line_buf)
	{
		map.map_line_buf = get_next_line(map.map_fd);
		if (!(map.map_line_buf))
		{
			trim_line(&map);
			map.row_num = count_char(map.map_line, '\n');
			return (map);
		}
		else
		{
			map.map_line = gnl_strnjoin(map.map_line, map.map_line_buf, ft_strlen(map.map_line) + ft_strlen(map.map_line_buf));
			map.row_num++;
			free(map.map_line_buf);
			map.map_line_buf = "";
		}
	}
	free_map(&map);
	return (map);
}
