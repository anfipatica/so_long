#include "../inc/so_long.h"

void	init_window(t_data *data)
{
	int	width;
	int	height;

// ***AÑADIR FALLOS DE MALLOC
	data->layer = ft_calloc(1, sizeof(t_img));
	data->items = ft_calloc(1, sizeof(t_item));

	data->items->floor = ft_calloc(1, sizeof(t_img));
	data->items->character = ft_calloc(1, sizeof(t_img));
	data->items->wall = ft_calloc(1, sizeof(t_img));
	data->items->collectible = ft_calloc(1, sizeof(t_img));
	data->items->exit = ft_calloc(1, sizeof(t_img));

	width = data->map->col_num * TILE_PIXEL;
	height = data->map->row_num * TILE_PIXEL;
	data->mlx_ptr = mlx_init();
	if (!data->mlx_ptr)
		free_data(data);
	data->win_ptr = mlx_new_window(data->mlx_ptr, width, height, "SO LONG");
	if (!data->win_ptr)
		free_data(data);
	data->layer->img_ptr = mlx_new_image(data->mlx_ptr, width, height);
	data->layer->addr = mlx_get_data_addr(data->layer->img_ptr, &data->layer->bpp, &data->layer->line_len, &data->endian);
	add_imgs(data);
}

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
	add_imgs_util(data, data->items->character, "./images/haruspex_front.xpm");
	add_imgs_util(data, data->items->wall, "./images/wall.xpm");
	add_imgs_util(data, data->items->exit, "./images/exit.xpm");
	add_imgs_util(data, data->items->collectible, "./images/collectible.xpm");

}

void	destroy_element(int type, t_data *data, void *element)
{
	if (type == DISPLAY)
	{
		mlx_destroy_display(data->mlx_ptr);
		free(data->mlx_ptr);
	}
	else if (type == WINDOW)
		mlx_destroy_window(data->mlx_ptr, element);
	else if (type == IMAGE)
	{
		mlx_destroy_image(data->mlx_ptr, element);
	}
}

int	free_data(t_data *data)
{
	if (data->items && data->items->floor)
	{
		destroy_element(IMAGE, data, data->items->floor->img_ptr);
		free(data->items->floor);
	}
	if (data->items && data->items->character)
	{
		destroy_element(IMAGE, data, data->items->character->img_ptr);
		free(data->items->character);
	}
	if (data->items && data->items->wall)
	{
		destroy_element(IMAGE, data, data->items->wall->img_ptr);
		free(data->items->wall);
	}
	if (data->items && data->items->exit)
	{
		destroy_element(IMAGE, data, data->items->exit->img_ptr);
		free(data->items->exit);
	}
	if (data->items && data->items->collectible)
	{
		destroy_element(IMAGE, data, data->items->collectible->img_ptr);
		free(data->items->collectible);
	}
	if (data->layer)
	{
		destroy_element(IMAGE, data, data->layer->img_ptr);
		free(data->layer);
	}
	if (data->items)
		free(data->items);
	if (data->win_ptr)
		destroy_element(WINDOW, data, data->win_ptr);
	if (data->mlx_ptr)
		destroy_element(DISPLAY, data, data->mlx_ptr);
	free_map(data->map);
	exit(0);
}
