/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymunoz-m <ymunoz-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 22:47:48 by anfi              #+#    #+#             */
/*   Updated: 2024/06/19 14:37:14 by ymunoz-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

/**
 * free_map() frees the elements allocated inside the t_map struct.
*/
void	free_map(t_map *map)
{
	int	i;

	if (!map)
		exit(2);
	i = -1;
	while (map->map && map->map[++i])
		free(map->map[i]);
	if (map->map)
		free(map->map);
	if (map->map_line)
		free(map->map_line);
	i = -1;
	if (map->ff_map)
	{
		while (++i < map->row_num)
		{
			free(map->ff_map[i]);
		}
		free(map->ff_map);
	}
}

/**
 * A function that calls a mlx destroy function, depending on the element
 * we want to destroy. Then, it frees the memory previosly allocated.
*/
void	destroy_element(int type, t_data *data, void *element)
{
	t_img	*img_element;

	img_element = NULL;
	if (type == DISPLAY)
	{
		mlx_destroy_display(data->mlx_ptr);
		free(data->mlx_ptr);
	}
	else if (type == WINDOW)
		mlx_destroy_window(data->mlx_ptr, element);
	else if (type == IMAGE)
	{
		img_element = element;
		if (img_element->addr)
			mlx_destroy_image(data->mlx_ptr, img_element->img_ptr);
		free(element);
	}
}

/**
 * A continuation to free_data(). It frees everything inside de t_item
 * struct that belongs to t_data.
*/
void	free_items(t_data *data)
{
	destroy_element(IMAGE, data, data->items->floor);
	destroy_element(IMAGE, data, data->items->wall);
	destroy_element(IMAGE, data, data->items->character);
	destroy_element(IMAGE, data, data->items->collectible);
	destroy_element(IMAGE, data, data->items->exit);
}

/**
 * free_data() frees all previously allocated memory from the t_data struct.
 * Since there are so many items inside t_data, it calls free_items() to
 * limit this function to 25 lines.
 * It also calls free_map().
*/
int	free_data(t_data *data)
{
	free_items(data);
	if (data->layer)
		destroy_element(IMAGE, data, data->layer);
	if (data->items)
		free(data->items);
	if (data->win_ptr)
		destroy_element(WINDOW, data, data->win_ptr);
	if (data->mlx_ptr)
		destroy_element(DISPLAY, data, data->mlx_ptr);
	free_map(data->map);
	free(data->message);
	exit (0);
}
