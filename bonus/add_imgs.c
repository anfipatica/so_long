/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_imgs.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anfi <anfi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 21:12:22 by anfi              #+#    #+#             */
/*   Updated: 2024/06/18 23:47:56 by anfi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long_bonus.h"

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
 * A complementary function to add_imgs() to add the wall images to its
 * corresponding item.
*/
void	add_wall_imgs(t_data *data, t_item *items)
{
	add_imgs_util(data, items->wall[0], "./images/wall.xpm");
	add_imgs_util(data, items->wall[1], "./images/wall_+.xpm");
	add_imgs_util(data, items->wall[2], "./images/wall_horizontal.xpm");
	add_imgs_util(data, items->wall[3], "./images/wall_vertical.xpm");
	add_imgs_util(data, items->wall[4], "./images/wall_up_right.xpm");
	add_imgs_util(data, items->wall[5], "./images/wall_bottom_right.xpm");
	add_imgs_util(data, items->wall[6], "./images/wall_bottom_left.xpm");
	add_imgs_util(data, items->wall[7], "./images/wall_up_left.xpm");
	add_imgs_util(data, items->wall[8], "./images/wall_up.xpm");
	add_imgs_util(data, items->wall[9], "./images/wall_right.xpm");
	add_imgs_util(data, items->wall[10], "./images/wall_bottom.xpm");
	add_imgs_util(data, items->wall[11], "./images/wall_left.xpm");
	add_imgs_util(data, items->wall[12], "./images/wall_limit.xpm");
	add_imgs_util(data, items->wall[13], "./images/wall_t_up.xpm");
	add_imgs_util(data, items->wall[14], "./images/wall_t_right.xpm");
	add_imgs_util(data, items->wall[15], "./images/wall_t_down.xpm");
	add_imgs_util(data, items->wall[16], "./images/wall_t_left.xpm");
}

/**
 * It adds every sprite into its corresponding t_img element.
*/
void	add_imgs(t_data *data, t_item *items)
{
	add_imgs_util(data, items->floor, "./images/floor.xpm");
	add_imgs_util(data, items->character[0], "./images/haruspex_front.xpm");
	add_imgs_util(data, items->character[1], "./images/haruspex_left.xpm");
	add_imgs_util(data, items->character[2], "./images/haruspex_back.xpm");
	add_imgs_util(data, items->character[3], "./images/haruspex_right.xpm");
	add_imgs_util(data, items->character[4], "./images/haruspex_dead.xpm");
	add_imgs_util(data, items->character[5], "./images/haruspex_front2.xpm");
	add_imgs_util(data, items->character[6], "./images/haruspex_left2.xpm");
	add_imgs_util(data, items->character[7], "./images/haruspex_back2.xpm");
	add_imgs_util(data, items->character[8], "./images/haruspex_right2.xpm");
	add_imgs_util(data, items->character[9], "./images/haruspex_front.xpm");
	add_imgs_util(data, items->exit, "./images/exit.xpm");
	add_imgs_util(data, items->collectible[0], "./images/collectible0.xpm");
	add_imgs_util(data, items->collectible[1], "./images/collectible1.xpm");
	add_imgs_util(data, items->foe[0], "./images/plague0.xpm");
	add_imgs_util(data, items->foe[1], "./images/plague1.xpm");
	add_imgs_util(data, items->text[0], "./images/instructions.xpm");
	add_imgs_util(data, items->text[1], "./images/you_won.xpm");
	add_imgs_util(data, items->text[2], "./images/you_died.xpm");
	add_wall_imgs(data, items);
}
