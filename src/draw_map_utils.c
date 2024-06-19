/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anfi <anfi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 22:38:21 by anfi              #+#    #+#             */
/*   Updated: 2024/06/19 11:10:03 by anfi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

/**
 * A small function that is used whenever the character wins or looses to freeze
 * the screen for a second so the user can see the message and the little sprite.
*/
int	loop_hook(t_data *data)
{
	static int	counter;

	if (counter++ == 20000)
	{
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->layer->img_ptr, 0, 0);
		free_data(data);
	}
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
