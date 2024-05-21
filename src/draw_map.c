#include "../inc/so_long.h"

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
		mlx_destroy_image(data->mlx_ptr, element);
	//free(element);
}

int	free_data(t_data *data)
{
	if (data->imgs->collectible)
		destroy_element(IMAGE, data, data->imgs->collectible);
	if (data->imgs->exit)
		destroy_element(IMAGE, data, data->imgs->exit);
	if (data->imgs->character)
		destroy_element(IMAGE, data, data->imgs->character);
	if (data->imgs->floor)
		destroy_element(IMAGE, data, data->imgs->floor);
	if (data->imgs->wall)
		destroy_element(IMAGE, data, data->imgs->wall);
	if (data->win_ptr)
		destroy_element(WINDOW, data, data->win_ptr);
	if (data->mlx_ptr)
		destroy_element(DISPLAY, data, data->mlx_ptr);
	free_map(data->map);
	free(data->imgs);
	exit(0);
}

//Add more information about the image not found maybe??
void	error_adding_img(t_data *data, int i)
{
	printf("Error adding an image. Image %d not found\n", i);
	free_data(data);
}

void	add_imgs(t_data *data)
{
	int	width;
	int	height;

	data->imgs->floor = mlx_xpm_file_to_image(data->mlx_ptr, "./images/floor.xpm", &width, &height);
	if (!data->imgs->floor)
		error_adding_img(data, 1);
	data->imgs->wall = mlx_xpm_file_to_image(data->mlx_ptr, "./images/wall.xpm", &width, &height);
	if (!data->imgs->wall)
		error_adding_img(data, 2);
	data->imgs->character = mlx_xpm_file_to_image(data->mlx_ptr, "./images/character.xpm", &width, &height);
	if (!data->imgs->character)
		error_adding_img(data, 3);
	data->imgs->exit = mlx_xpm_file_to_image(data->mlx_ptr, "./images/exit.xpm", &width, &height);
	if (!data->imgs->exit)
		error_adding_img(data, 4);
	data->imgs->collectible = mlx_xpm_file_to_image(data->mlx_ptr, "./images/collectible.xpm", &width, &height);
	if (!data->imgs->collectible)
		error_adding_img(data, 5);
}

void	init_window(t_data *data)
{
	int	width;
	int	height;

	width = data->map->col_num * TILE_PIXEL;
	height = data->map->row_num * TILE_PIXEL;
	data->mlx_ptr = mlx_init();
	if (!data->mlx_ptr)
	{
		free_data(data);
		exit(1);
	}
	data->win_ptr = mlx_new_window(data->mlx_ptr, width, height, "SO LONG");
	if (!data->win_ptr)
	{
		free_data(data);
	}
	add_imgs(data);
}


void	put_image(t_data *data, char **map)
{
	int	x;
	int	y;

	printf("All images added\n");
	y = -1;
	while (++y < data->map->row_num)
	{
		x = -1;
		while (++x < data->map->col_num)
		{
			printf("y = %d, x = %d, %c\n", y, x, map[y][x]);
			if (map[y][x] == '0')
				mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->imgs->floor, x * TILE_PIXEL, y * TILE_PIXEL);
			else if (map[y][x] == '1')
				mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->imgs->wall, x * TILE_PIXEL, y * TILE_PIXEL);
			else if (map[y][x] == 'P')
				mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->imgs->character, x * TILE_PIXEL, y * TILE_PIXEL);
			else if (map[y][x] == 'C')
				mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->imgs->collectible, x * TILE_PIXEL, y * TILE_PIXEL);
			else if (map[y][x] == 'E')
				mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->imgs->exit, x * TILE_PIXEL, y * TILE_PIXEL);
		}
	}
}

void	draw_map(t_map *map)
{
	t_data	data;
	data.map = map;
	data.imgs = ft_calloc(1, sizeof(t_img));
	init_window(&data);
	mlx_hook(data.win_ptr, DestroyNotify, StructureNotifyMask, &free_data, &data);
	put_image(&data, map->map);
	mlx_loop(data.mlx_ptr);
	//free_data(&data);
}