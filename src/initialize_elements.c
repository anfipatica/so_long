/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_elements.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anfi <anfi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 21:25:41 by anfi              #+#    #+#             */
/*   Updated: 2024/06/19 11:17:41 by anfi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

/**
 * It allocates memory for every t_item inside t_data.
 * Yes, the wall alone needs 17 callocs, every sprite is a t_item element.
*/
void	init_items(t_data *data)
{
	data->layer = calloc_or_free(data, 1, sizeof(t_img));
	data->items = calloc_or_free(data, 1, sizeof(t_item));
	data->items->floor = calloc_or_free(data, 1, sizeof(t_img));
	data->items->wall = calloc_or_free(data, 1, sizeof(t_img));
	data->items->character = calloc_or_free(data, 1, sizeof(t_img));
	data->items->collectible = calloc_or_free(data, 1, sizeof(t_img));
	data->items->exit = calloc_or_free(data, 1, sizeof(t_img));
}

/**
 * It initializes every item inside t_data, starts the connection with the X11
 * server, creates the window, and calls other functions that initialize items.
*/
void	init_window(t_data *data)
{
	int	width;
	int	height;

	width = data->map->col_num * TILE_PIXEL;
	height = data->map->row_num * TILE_PIXEL;
	data->mlx_ptr = mlx_init();
	if (!data->mlx_ptr)
		free_data(data);
	check_screen_size(data, width, height);
	data->win_ptr = mlx_new_window(data->mlx_ptr, width, height, "SO LONG");
	if (!data->win_ptr)
		free_data(data);
	init_items(data);
	data->layer->img_ptr = mlx_new_image(data->mlx_ptr, width, height);
	data->layer->addr = mlx_get_data_addr(data->layer->img_ptr,
			&data->layer->bpp, &data->layer->line_len, &data->layer->endian);
	data->movements = 0;
	data->message = ft_strdup("Movements made: 0");
	data->char_state = DOWN;
	add_imgs(data, data->items);
}
