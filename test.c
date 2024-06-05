##include "../inc/so_long.h"

void *calloc_or_free(t_data *data, int n, int size)
{
	void *item;

	item = ft_calloc(n, size);
	if (!item)
		free_data(data);
	else
	{
		printf("todo ok en el calloc\n");
		return (item);
	}
	return (NULL);
}

void	init_items(t_data *data)
{
	int i;

	i = -1;
	data->layer = calloc_or_free(data, 1, sizeof(t_img));
	data->items = calloc_or_free(data, 1, sizeof(t_item));
	data->items->floor = calloc_or_free(data, 1, sizeof(t_img));
	while (++i < 4)
		data->items->character[i] = calloc_or_free(data, 1, sizeof(t_img));
	i = -1;
	while (++i < 2)
	{
		data->items->collectible[i] = calloc_or_free(data, 1, sizeof(t_img));
		data->items->foe[i] = calloc_or_free(data, 1, sizeof(t_img));
	}
	data->items->wall = calloc_or_free(data, 1, sizeof(t_img));
	data->items->exit = calloc_or_free(data, 1, sizeof(t_img));
	add_imgs(data);
}
void	init_window(t_data *data)
{
	int	width;
	int	height;
	init_items(data);
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
	data->c_state = 0;
}

void	add_imgs_util(t_data *data, t_img *img, char *path)
{
	printf("ñe\n");
	img->img_ptr = mlx_xpm_file_to_image(data->mlx_ptr, path, &img->width, &img->height);
	printf("ñe\n");
	if (!img->img_ptr)
	{
		printf("Error adding picture with path: %s\n", path);
		free_data(data);
	}
	img->addr = mlx_get_data_addr(img->img_ptr, &img->bpp, &img->line_len, &img->endian);
}

void	add_imgs(t_data *data)
{
	printf("Llegamos a add_imgs()\n");
	add_imgs_util(data, data->items->character[0], "./images/haruspex_front.xpm");

	add_imgs_util(data, data->items->floor, "./images/floor.xpm");
	printf("ñejejeje\n");
	add_imgs_util(data, data->items->character[1], "./images/haruspex_left.xpm");
	add_imgs_util(data, data->items->character[2], "./images/haruspex_back.xpm");
	add_imgs_util(data, data->items->character[3], "./images/haruspex_right.xpm");
	add_imgs_util(data, data->items->wall, "./images/wall.xpm");
	add_imgs_util(data, data->items->exit, "./images/exit.xpm");
	add_imgs_util(data, data->items->collectible[0], "./images/collectible.xpm");
	add_imgs_util(data, data->items->collectible[1], "./images/haruspex_right.xpm");
	printf("foe0!!\n");
	add_imgs_util(data, data->items->foe[0], "./images/plague0.xpm");
	printf("foe01!\n");

	add_imgs_util(data, data->items->foe[1], "./images/plague1.xpm");
	printf("salimos de add_imgs()\n");
}

void	destroy_element(int type, t_data *data, void *element)
{
	t_img *img_element;

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
		mlx_destroy_image(data->mlx_ptr, img_element->img_ptr);
		free(element);
	}
}

void	free_items(t_data *data)
{
	int i;

	i = -1;
	if (data->items->floor)
		destroy_element(IMAGE, data, data->items->floor);
	while (++i < 4)
	{
		if (data->items->character[i])
			destroy_element(IMAGE, data, data->items->character[i]);
	}
	i = -1;
	while (++i < 2)
	{
		if (data->items->collectible[i])
			destroy_element(IMAGE, data, data->items->collectible[i]);
		if (data->items->foe[i])
			destroy_element(IMAGE, data, data->items->foe[i]);
	}
	if (data->items->wall)
		destroy_element(IMAGE, data, data->items->wall);
	if (data->items->exit)
		destroy_element(IMAGE, data, data->items->exit);
	free(data->items);
}
int	free_data(t_data *data)
{
	if (data->items)
		free_items(data);
	if (data->layer)
		destroy_element(IMAGE, data, data->layer);
	if (data->win_ptr)
		destroy_element(WINDOW, data, data->win_ptr);
	if (data->mlx_ptr)
		destroy_element(DISPLAY, data, data->mlx_ptr);
	free_map(data->map);
	exit(0);
}
