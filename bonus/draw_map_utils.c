/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anfi <anfi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 22:38:21 by anfi              #+#    #+#             */
/*   Updated: 2024/06/18 23:48:01 by anfi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long_bonus.h"

/**
 * A small function that is used whenever the character wins or looses to freeze
 * the screen for a second so the user can see the message and the little sprite.
*/
int	loop_hook(t_data *data)
{
	static int	counter;

	if (counter++ == REFRESH_RATE)
	{
		if (data->map->map[data->map->p_pos[Y]][data->map->p_pos[X]] != 'E')
			put_centered_image(data, data->items->text[2]);
		else
			put_centered_image(data, data->items->text[1]);
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->layer->img_ptr, 0, 0);
	}
	else if (counter++ > REFRESH_RATE * 5)
		free_data(data);
	return (0);
}

/**
 * A small function to check that the map fits on the device screen.
*/
void	check_screen_size(t_data *data, int width, int height)
{
	int	sizex;
	int	sizey;

	mlx_get_screen_size(data->mlx_ptr, &sizex, &sizey);
	if (sizex < width || sizey < height)
	{
		write(2, "ERROR: Map too big for this device, "
			"	it does not fit the screen\n", 64);
		free_map(data->map);
		destroy_element(DISPLAY, data, data->mlx_ptr);
		exit (1);
	}
}

/**
 * A function that puts on screen the text images, as centered as it can.
*/
void	put_centered_image(t_data *data, t_img *img)
{
	int	x;
	int	y;

	x = ((data->map->col_num * (TILE_PIXEL / 2))
			- img->width / 2) / TILE_PIXEL;
	y = ((data->map->row_num * (TILE_PIXEL / 2))
			- img->height / 2) / TILE_PIXEL;
	if (data->map->col_num * TILE_PIXEL < img->width
		|| data->map->row_num * TILE_PIXEL < img->height)
		return ;
	if (y % 2 != 0)
		y++;
	merge_tile(data, img, y, x + 1);
}
