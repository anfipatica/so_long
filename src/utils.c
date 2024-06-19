/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymunoz-m <ymunoz-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 23:02:34 by anfi              #+#    #+#             */
/*   Updated: 2024/06/19 14:36:06 by ymunoz-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

/**
 * We inicialize every element inside the t_map struct.
*/
t_map	init_map(void)
{
	t_map	map;

	map.c_count = 0;
	map.e_count = 0;
	map.accesible_c = 0;
	map.accesible_e = 0;
	map.p_count = 0;
	map.map_fd = 0;
	map.map_line = NULL;
	map.map_line_buf = "";
	map.row_num = 0;
	map.col_num = 0;
	map.map = NULL;
	map.ff_map = NULL;
	return (map);
}

/**
 * A small function that is used when initializing t_data since there are
 * are many mallocs, as a way to save lines.
*/
void	*calloc_or_free(t_data *data, int n, int size)
{
	void	*item;

	item = ft_calloc(n, size);
	if (!item)
		free_data(data);
	else
		return (item);
	return (NULL);
}
