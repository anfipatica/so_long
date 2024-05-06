#include "minilibx-linux/mlx.h"
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <X11/X.h>
#include <X11/keysym.h>

#define WIDTH 700
#define HEIGHT 300
#define MALLOC_ERROR 1
#define TILE_PIXEL 64



void	end_program(void *mlx)
{
	mlx_destroy_display(mlx);
	free(mlx);
}

void	*put_character(void *mlx, void *window, int move_x, int move_y)
{
	void	*img;
	char	*relative_path = "./images/character1.xpm";
	int		img_width;
	int		img_height;
	static int	x;
	static int	y;

	if (!img)
	{
		x = 0;
		y = 0;
	}
	else
	{
		x += move_x;
		y += move_y;
	}

	img = mlx_xpm_file_to_image(mlx, relative_path, &img_width, &img_height);
	mlx_put_image_to_window(mlx, window, img, x, y);
}

void	put_floor(void *mlx, void *window)
{
	void	*img;
	char	*relative_path = "./images/tileset1.xpm";
	int		img_width;
	int		img_height;

	img = mlx_xpm_file_to_image(mlx, relative_path, &img_width, &img_height);
	if (!img)
		return (end_program(mlx));
	for (int y = 0; y * img_height < HEIGHT; y++)
	{
		for (int x = 0; x * img_width < WIDTH; x++)
		{
			mlx_put_image_to_window(mlx, window, img, x * img_width, y * img_height);
		}
	}
}

int	on_destroy(t_data *data)
{
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	mlx_destroy_display(data->mlx_ptr);
	free(data->mlx_ptr);
	exit (0);
	//return (0);
}

int	handle_key_input(int keysym, t_data *data)
{
	static void	*character;

	printf("Pressed key: %d\n", keysym);
	if (keysym == XK_Escape)
		on_destroy(data);
	if (!character)
	{
		printf("acá\n");
	}
	if (keysym == XK_s)
	{
		character = put_character(data->mlx_ptr, data->win_ptr, 0, TILE_PIXEL);
	}
	else if (keysym == XK_w)
		character = put_character(data->mlx_ptr, data->win_ptr, 0, -TILE_PIXEL);
	return (0);
}

int	main(void)
{
	t_data	data;

	data.mlx_ptr = mlx_init();
	if (!data.mlx_ptr)
		return (1);
	data.win_ptr = mlx_new_window(data.mlx_ptr, WIDTH, HEIGHT, "HOla!!");
	if (!data.win_ptr)
		return (free(data.mlx_ptr), 1);

	put_floor(data.mlx_ptr, data.win_ptr);
	put_character(data.mlx_ptr, data.win_ptr, 0, 0);
	mlx_key_hook(data.win_ptr, &handle_key_input, &data);

	//To exit when pressing the "x" button.
	mlx_hook(data.win_ptr, DestroyNotify, StructureNotifyMask, &on_destroy, &data);
	mlx_loop(data.mlx_ptr);
	return (0);
}
