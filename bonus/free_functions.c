/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anfi <anfi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 22:47:48 by anfi              #+#    #+#             */
/*   Updated: 2024/06/18 23:24:35 by anfi             ###   ########.fr       */
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
	while (map->map[++i])
		free(map->map[i]);
	free(map->map);
	free(map->map_line);
	i = -1;
	if (map->ff_map)
	{
		while (++i < map->row_num)
			free(map->ff_map[i]);
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
void	free_items(t_data *data, int i)
{
	if (data->items && data->items->floor->img_ptr)
		destroy_element(IMAGE, data, data->items->floor);
	while (++i < 17 && data->items)
		destroy_element(IMAGE, data, data->items->wall[i]);
	i = -1;
	while (++i < 10 && data->items)
		destroy_element(IMAGE, data, data->items->character[i]);
	i = -1;
	while (++i < 2 && data->items)
	{
		destroy_element(IMAGE, data, data->items->collectible[i]);
		destroy_element(IMAGE, data, data->items->foe[i]);
	}
	i = -1;
	while (++i < 3)
		destroy_element(IMAGE, data, data->items->text[i]);
	if (data->items)
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
	free_items(data, -1);
	if (data->layer)
		destroy_element(IMAGE, data, data->layer);
	if (data->items)
		free(data->items);
	if (data->win_ptr)
		destroy_element(WINDOW, data, data->win_ptr);
	if (data->mlx_ptr)
		destroy_element(DISPLAY, data, data->mlx_ptr);
	free(data->foe_info);
	free_map(data->map);
	free(data->message);
	exit (0);
}
