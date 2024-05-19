//maybe rename the file to: create_map.c

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
- We will take the map we read as a line and transform it into a matrix for an easier
validation of the map, thanks to the last \0 char of each line that ft_split will add.
- We will also validate here if there is any empty line inside the .ber:
	We already trimmed the beggining and the end, but still there could be empty lines inside
	and those will not be saved in the matrix since ft_split "jumps" duplicated chars.
	But this time if there is more than one empty line between lines inside the .ber,
	the map is invalid.

- row_num: We calculate row_num based on the \n we find in the line. We deal later with empty lines.
	We add 1 to row_num becase the last line of the map does not have a '\n'. Wheter the .ber has it or not,
	we trimmed map_line to homogenize the format, therefore we count_char will not count this last line.
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