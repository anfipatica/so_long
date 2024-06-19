/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_input.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anfi <anfi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 21:41:01 by anfi              #+#    #+#             */
/*   Updated: 2024/06/19 11:08:18 by anfi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

/**
 * After every character or foe movement this function is called to check
 * if the character won, died or collected a collectible.
*/
void	check_changes(t_data *data, t_map *map, int p_y, int p_x)
{
	if (map->map[p_y][p_x] == 'F')
	{
		write(1, "YOU DIED!\n", 10);
		merge_tile(data, data->items->character, p_y, p_x);
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->layer->img_ptr, 0, 0);
		mlx_key_hook(data->win_ptr, NULL, data);
		mlx_loop_hook(data->mlx_ptr, loop_hook, data);
	}
	else if (map->map[p_y][p_x] == 'C')
	{
		map->map[p_y][p_x] = '0';
		map->accesible_c--;
	}
	else if (map->map[p_y][p_x] == 'E' && map->accesible_c == 0)
	{
		write(1, "YOU WON!\n", 9);
		merge_tile(data, data->items->character, p_y, p_x);
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->layer->img_ptr, 0, 0);
		mlx_key_hook(data->win_ptr, NULL, data);
		mlx_loop_hook(data->mlx_ptr, loop_hook, data);
	}
}

/**
 * The character can move so this function handles the small changes aside from
 * the movement itself like changing the movement message and change the last
 * tile the character was on.
*/
void	update_character_movement(t_data *data, int y, int x, char *movements)
{
	data->movements++;
	free(data->message);
	data->message = ft_strjoin("Movements made: ", movements);
	free(movements);
	write(1, data->message, ft_strlen(data->message));
	write(1, "\n", 1);
	if (data->map->map[y][x] == 'E')
		merge_tile(data, data->items->exit, y, x);
	else if (data->map->map[y][x] != 'F')
		draw_tile(data, data->items->floor, y, x);
	check_changes(data, data->map, data->map->p_pos[Y], data->map->p_pos[X]);
}

/**
 * When any of the WASD keys is pressed the character must be updated.
 * If it can move, it's possition and movements will be updated.
 * If not, it will not change possition but must be facing that direction.
*/
void	update_character(t_data *data, int x, int y, int key)
{
	t_bool	move;

	if (key == XK_s)
		move = move_down(data, x, y);
	else if (key == XK_w)
		move = move_up(data, x, y);
	else if (key == XK_a)
		move = move_left(data, x, y);
	else if (key == XK_d)
		move = move_right(data, x, y);
	if (move == true)
		update_character_movement(data, y, x, ft_itoa(data->movements));
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
		data->layer->img_ptr, 0, 0);
}

/**
 * handle_input is the event handler that is activated whenever a key if pressed.
 * - If 'esc' is pressed the program must close.
 * - If WASD is pressed, the character must be moved to that direction.
 * Also, when launching the game it first stays frozen waiting for any key input
 * to allow the user to read the instructions, then the game starts and the
 * refresh loop starts.
*/
int	handle_input(int keysym, t_data *data)
{
	int			p_x;
	int			p_y;

	p_x = data->map->p_pos[X];
	p_y = data->map->p_pos[Y];
	if (keysym == XK_Escape)
		free_data(data);
	else if (keysym == XK_w || keysym == XK_s || keysym == XK_a
		|| keysym == XK_d)
		update_character(data, p_x, p_y, keysym);
	return (0);
}
