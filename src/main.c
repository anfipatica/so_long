#include "../inc/so_long.h"

int	main(int argc, char **argv)
{
	t_map	map;
	if (argc != 2)
		return (1);
	map = read_map(argv[1]);
	create_map(&map);
	draw_map(&map);
}