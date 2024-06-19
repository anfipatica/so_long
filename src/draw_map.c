/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anfi <anfi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 21:41:32 by anfi              #+#    #+#             */
/*   Updated: 2024/06/19 11:14:48 by anfi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

/**
 * Where we start working with X11 and minilibx.
 * The functions it calls will: iniciate the window, draw the image,
 * put the image on the window, create a loop listening to any key event.
*/
void	draw_map(t_map *map)
{
	t_data	data;

	data.map = map;
	init_window(&data);
	initialize_draw(&data);
	mlx_put_image_to_window(data.mlx_ptr, data.win_ptr,
		data.layer->img_ptr, 0, 0);
	mlx_hook(data.win_ptr, DestroyNotify, StructureNotifyMask,
		&free_data, &data);
	mlx_key_hook(data.win_ptr, handle_input, &data);
	mlx_loop(data.mlx_ptr);
}
