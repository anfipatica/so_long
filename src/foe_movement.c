#include "../inc/so_long.h"


void	update_map(t_data *data)
{
	int	i;

	i = -1;
	while ( ++i < data->map->f_count)
	{
		data->map->map[data->foe_info[i].y][data->foe_info[i].x] = 'F';

		if (data->foe_info[i].dir == LEFT)
			data->map->map[data->foe_info[i].y][data->foe_info[i].x - 1] = '0';
		else
			data->map->map[data->foe_info[i].y][data->foe_info[i].x + 1] = '0';
	}
}
void	register_foes(t_data *data, int y, int x)
{
	static int n;

	data->foe_info[n].x = x;
	data->foe_info[n].y = y;
	data->foe_info[n].dir = LEFT;
	data->map->ff_map[y][x] = n++;
}

void	move_foe_left(t_data *data, int y, int x, int n)
{
	merge_tile(data, data->items->foe[data->sprite_state], y, x - 1);
	draw_tile(data, data->items->floor, y, x);
	data->map->ff_map[y][x] = -1;
	data->map->ff_map[y][x - 1] = n;
	data->foe_info[n].x = x - 1;
}

void	move_foe_right(t_data *data, int y, int x, int n)
{
	merge_tile(data, data->items->foe[data->sprite_state], y, x + 1);
	draw_tile(data, data->items->floor, y, x);
	data->map->ff_map[y][x] = -1;
	data->map->ff_map[y][x + 1] = n;
	data->foe_info[n].x = x + 1;
}

void	move_foe(t_data *data, int y, int x, int n)
{
	print_ff_matrix(*data->map);
	printf("n = %d, dir = %d\n", n, data->foe_info[n].dir);
	if (data->foe_info[n].dir == LEFT)
	{
		printf("HE ENTRADO EN LEFT\n");
		if (ft_strchr("0P",data->map->map[y][x - 1]) != NULL)
			move_foe_left(data, y, x, n);
		else if (ft_strchr("F",data->map->map[y][x - 1]) != NULL)
		{
			if (data->foe_info[data->map->ff_map[y][x - 1]].dir == RIGHT
				|| ft_strchr("1CE", data->map->map[y][x - 2]) != NULL)
			{
				move_foe_right(data, y, x, n);
				data->foe_info[n].dir = RIGHT;
			}
			else
				move_foe_left(data, y, x, n);
		}
		else
		{
			move_foe_right(data, y, x, n);
			data->foe_info[n].dir = RIGHT;
		}
	}
	else if (data->foe_info[n].dir == RIGHT)
	{
		printf("HE ENTRADO EN RIGHT\n");
		if (ft_strchr("0P",data->map->map[y][x + 1]) != NULL)
			move_foe_right(data, y, x, n);
		else if (ft_strchr("F",data->map->map[y][x + 1])  != NULL)
		{
			if (data->foe_info[data->map->ff_map[y][x + 1]].dir == RIGHT
				|| ft_strchr("1CE", data->map->map[y][x + 2]) != NULL)
			{
				move_foe_left(data, y, x, n);
				data->foe_info[n].dir = LEFT;
			}
			else
				move_foe_left(data, y, x, n);
		}
		else
		{
			move_foe_left(data, y, x, n);
			data->foe_info[n].dir = LEFT;
		}
	}
	printf("SALIMOS DE FOE_MOVEMENT\n");
}
