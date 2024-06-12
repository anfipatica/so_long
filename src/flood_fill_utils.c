#include "../inc/so_long.h"

void	free_matrix_f_malloc(int **matrix, int i)
{
	while (i >= 0)
	{
		free(matrix[i]);
		i--;
	}
	free(matrix);
}

//Temporal function to see how the ff_map is doing
void	print_ff_matrix(t_map map)
{
	for (int y = 0; y < map.row_num; y++)
	{
		for (int x = 0; x < map.col_num; x++)
		{
			printf("%d|", map.ff_map[y][x]);
		}
		printf("\n");
	}
	printf("\n-----------------------------\n");
}

void	print_matrix(t_map map)
{
	for (int y = 0; y < map.row_num; y++)
	{
		for (int x = 0; x < map.col_num; x++)
			printf("%c", map.map[y][x]);
		printf("\n");
	}
	printf("\n+++++++++++++++++++++++++++\n");

}

int		**create_ff_matrix(int width, int height)
{
	int		i;

	i = -1;
	int		**matrix;
	matrix = ft_calloc(height, sizeof(int *));
	printf("with = %d, height = %d\n", width, height);
	if (!matrix)
		return (NULL);
	while (++i < height)
	{
		matrix[i] = ft_calloc(width, sizeof(int));
		if (!matrix[i])
			return (free_matrix_f_malloc(matrix, i), NULL);
	}
	//printf("todo bien!\n");
	return (matrix);
}