/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anfi <anfi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 23:12:04 by anfi              #+#    #+#             */
/*   Updated: 2024/06/16 23:16:19 by anfi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../inc/so_long.h"

/**
 * In case any calloc failed during the creation of the int matrix, this function
 * frees it.
*/
void	free_matrix_f_malloc(int **matrix, int i)
{
	while (i >= 0)
	{
		free(matrix[i]);
		i--;
	}
	free(matrix);
}

/**
 * A simple function that creates an int matrix with the same dimensions as the
 * map char array. It will act as an "underlayer" to the char array. It's purpose
 * is to hold the paths the character can go through from the starting point.
*/
int		**create_ff_matrix(int width, int height)
{
	int		i;

	i = -1;
	int		**matrix;
	matrix = ft_calloc(height, sizeof(int *));
	if (!matrix)
		return (NULL);
	while (++i < height)
	{
		matrix[i] = ft_calloc(width, sizeof(int));
		if (!matrix[i])
			return (free_matrix_f_malloc(matrix, i), NULL);
	}
	return (matrix);
}

/*
Here commented we have two functions that were vital while coding, but
rather useless now that the program is done. I'll leave them here
as a vestige of a bygone time.

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
*/