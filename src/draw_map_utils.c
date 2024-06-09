/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anfi <anfi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 22:38:21 by anfi              #+#    #+#             */
/*   Updated: 2024/06/09 22:17:16 by anfi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void *calloc_or_free(t_data *data, int n, int size)
{
	void *item;

	item = ft_calloc(n, size);
	if (!item)
		free_data(data);
	else
		return (item);
	return (NULL);
}


void	init_items(t_data *data)
{
	int i;

	i = -1;
	data->layer = calloc_or_free(data, 1, sizeof(t_img));
	data->items = calloc_or_free(data, 1, sizeof(t_item));
	data->items->floor = calloc_or_free(data, 1, sizeof(t_img));
	while(++i < 13)
		data->items->wall[i] = calloc_or_free(data, 1, sizeof(t_img));
	i = -1;
	while (++i < 10)
		data->items->character[i] = calloc_or_free(data, 1, sizeof(t_img));
	i = -1;
	while (++i < 2)
	{
		data->items->collectible[i] = calloc_or_free(data, 1, sizeof(t_img));
		data->items->foe[i] = calloc_or_free(data, 1, sizeof(t_img));
	}
	data->items->exit = calloc_or_free(data, 1, sizeof(t_img));
}

/**
 * A small function to check that the map fits on the device screen.
*/
void	check_screen_size(t_data *data, int width, int height)
{
	int sizex;
	int sizey;

	mlx_get_screen_size(data->mlx_ptr, &sizex, &sizey);
	if (sizex < width || sizey < height)
	{
		write(1, "ERROR: Map too big for this device, "
		"	it does not fit the screen\n", 63);
		free_data(data);
	}
}

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
	data->layer->addr = mlx_get_data_addr(data->layer->img_ptr, &data->layer->bpp, &data->layer->line_len, &data->endian);
	data->sprite_state = 0;
	data->movements = 0;
	data->message = ft_strdup("Movements made: 0");
	data->char_state = DOWN;
	add_imgs(data);
}

/**
 * A short function that turns an xpm file into an image pointer, handles
 * errors if found, and if not, it saves the image pointer address into
 * the t_img struct.
*/
void	add_imgs_util(t_data *data, t_img *img, char *path)
{
	img->img_ptr = mlx_xpm_file_to_image(data->mlx_ptr, path, &img->width, &img->height);
	if (!img->img_ptr)
	{
		printf("Error adding picture with path: %s\n", path);
		free_data(data);
	}
	img->addr = mlx_get_data_addr(img->img_ptr, &img->bpp, &img->line_len, &img->endian);
}

void	add_imgs(t_data *data)
{
	add_imgs_util(data, data->items->floor, "./images/floor.xpm");
	add_imgs_util(data, data->items->character[0], "./images/haruspex_front.xpm");
	add_imgs_util(data, data->items->character[1], "./images/haruspex_left.xpm");
	add_imgs_util(data, data->items->character[2], "./images/haruspex_back.xpm");
	add_imgs_util(data, data->items->character[3], "./images/haruspex_right.xpm");
	add_imgs_util(data, data->items->character[4], "./images/haruspex_dead.xpm");
	add_imgs_util(data, data->items->character[5], "./images/haruspex_front2.xpm");
	add_imgs_util(data, data->items->character[6], "./images/haruspex_left2.xpm");
	add_imgs_util(data, data->items->character[7], "./images/haruspex_back2.xpm");
	add_imgs_util(data, data->items->character[8], "./images/haruspex_right2.xpm");
	add_imgs_util(data, data->items->character[9], "./images/haruspex_front.xpm");
	add_imgs_util(data, data->items->wall[0], "./images/wall.xpm");
	add_imgs_util(data, data->items->wall[1], "./images/wall_+.xpm");
	add_imgs_util(data, data->items->wall[2], "./images/wall_horizontal.xpm");
	add_imgs_util(data, data->items->wall[3], "./images/wall_vertical.xpm");
	add_imgs_util(data, data->items->wall[4], "./images/wall_up_right.xpm");
	add_imgs_util(data, data->items->wall[5], "./images/wall_bottom_right.xpm");
	add_imgs_util(data, data->items->wall[6], "./images/wall_bottom_left.xpm");
	add_imgs_util(data, data->items->wall[7], "./images/wall_up_left.xpm");
	add_imgs_util(data, data->items->wall[8], "./images/wall_up.xpm");
	add_imgs_util(data, data->items->wall[9], "./images/wall_right.xpm");
	add_imgs_util(data, data->items->wall[10], "./images/wall_bottom.xpm");
	add_imgs_util(data, data->items->wall[11], "./images/wall_left.xpm");
	add_imgs_util(data, data->items->wall[12], "./images/wall_limit.xpm");
	add_imgs_util(data, data->items->exit, "./images/exit.xpm");
	add_imgs_util(data, data->items->collectible[0], "./images/collectible0.xpm");
	add_imgs_util(data, data->items->collectible[1], "./images/collectible1.xpm");
	add_imgs_util(data, data->items->foe[0], "./images/plague0.xpm");
	add_imgs_util(data, data->items->foe[1], "./images/plague1.xpm");
}

