#include "../inc/so_long.h"

/**
 * put_pixel_img colours the x,y position pixel with whatever color
 * receives.
*/

void	put_pixel_img(t_img *img, int x, int y, unsigned int color)
{
	char	*dst;

	dst = img->addr + (y * img->line_len + x * (img->bpp / 8));
	*(unsigned int*)dst = color;
}

/**
 * get_pixel_img gets an image and a certain coordinate, and returns the
 * color that specific pixel has as unsigned int.
*/
unsigned int	get_pixel_img(t_img img, int x, int y)
{
	return (*(unsigned int *)((img.addr
			+ (y * img.line_len) + (x * img.bpp / 8))));
}

/**
 * draw_tile() draws a specific tile inside the matrix that conforms our map, pixel by pixel.
 * We know every tile width and height thanks to TILE_PIXEL, so we will go over
 * each pixel conforming that tile, checking the color corresponding to that pixel inside
 * the img that we want to put on that tile, and drawing it.
*/
void	draw_tile(t_data *data, t_img *img, int row, int col)
{
	int	x;
	int	y;

	y = -1;
	while (++y < TILE_PIXEL)
	{
		x = -1;
		while (++x < TILE_PIXEL)
		{
			put_pixel_img(data->layer, x + (TILE_PIXEL * col), y + (TILE_PIXEL * row), get_pixel_img(*img, x, y));
		}
	}
}

/**
 * It works very similar to draw_tile() but this time we have two images we want
 * in that tile, the floor and the character over it. The character has a transparent background
 * and transparency isn't working properly, so I made this function instead: It checks if the x-y pixel on the top layer 
 * (the character) is empty and if so it draws that x-y pixel from the underlayer (floor).
*/
void	merge_tile(t_data *data, t_img *overlap, int row, int col)
{
	int	x;
	int	y;
	unsigned int	color;
	t_img tile;

	y = -1;
	if (data->map->map[row][col] == 'E')
		tile = *data->items->exit;
	else
		tile = *data->items->floor;
	while (++y < TILE_PIXEL)
	{
		x = -1;
		while (++x < TILE_PIXEL)
		{
			color = get_pixel_img(*overlap, x, y);
			//printf("%d\n", color);
			if (color != (unsigned int)0xFF000000)
				put_pixel_img(data->layer, x + (TILE_PIXEL * col), y + (TILE_PIXEL * row), color);
			else
				put_pixel_img(data->layer, x + (TILE_PIXEL * col), y + (TILE_PIXEL * row), get_pixel_img(tile, x, y));
		}
	}
}