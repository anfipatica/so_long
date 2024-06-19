/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_imgs.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anfi <anfi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 21:12:22 by anfi              #+#    #+#             */
/*   Updated: 2024/06/18 23:58:48 by anfi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

/**
 * A short function that turns an xpm file into an image pointer, handles
 * errors if found, and if not, it saves the image pointer address into
 * the t_img struct.
*/
void	add_imgs_util(t_data *data, t_img *img, char *path)
{
	img->img_ptr = mlx_xpm_file_to_image(data->mlx_ptr, path, &img->width,
			&img->height);
	printf("%p\n", img->img_ptr);
	if (!img->img_ptr)
	{
		write(2, "Error adding picture with path: ", 32);
		write(2, path, ft_strlen(path));
		write(2, "\n", 1);
		free_data(data);
	}
	img->addr = mlx_get_data_addr(img->img_ptr, &img->bpp, &img->line_len,
			&img->endian);
}

/**
 * It adds every sprite into its corresponding t_img element.
*/
void	add_imgs(t_data *data, t_item *items)
{
	add_imgs_util(data, items->wall, "./images/wall.xpm");
	add_imgs_util(data, items->floor, "./images/floor.xpm");
	add_imgs_util(data, items->character, "./images/haruspex_front.xpm");
	add_imgs_util(data, items->exit, "./images/exit.xpm");
	add_imgs_util(data, items->collectible, "./images/collectible0.xpm");
}
