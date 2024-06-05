#include "../inc/so_long.h"

void	invalid_map(t_map *map, int error)
{
	if (error == EMPTY_LINE)
		printf("Found an empty line inside the .ber\n");
	else if (error == DIFFERENT_LENGTHS)
		printf("row length discrepancy found. Invalid .ber\n");
	else if (error == INVALID_WALLS)
		printf("Walls do not enclose the map. Invalid .ber\n");
	else if (error == INVALID_CHAR)
		printf("Found invalid char inside the .ber.\n");
	else if (error == NUMBER_EXITS)
		printf("The map needs one exit. Only one.\n");
	else if (error == NUMBER_STARTS)
		printf("The map needs one starting point. Only one.\n");
	else if (error == NO_OBJECT)
		printf("There is no collectible. There needs to be at least one.\n");
	else if (error == WRONG_SHAPE)
		printf("Map needs to be an horizontal rectangle. Wrong shape, invalid .ber\n");
	else if (error == NON_REACHABLE_EXIT)
		printf("The exit cannot be reached from the starting point (P). Invalid ber\n");
	else if (error == NON_REACHABLE_COLLECTIBLE)
		printf("At least one collectible cannot be reached from the starting point (P). Invalid ber\n");
	else if (error == NON_REACHABLE_FOE)
		printf("At least one foe is on non reachable location. Enemies are supposed to be able to reach you!! Invalid ber\n");
	free_map(map);
	exit(1);
}

int		count_char(const char *str, const char c)
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