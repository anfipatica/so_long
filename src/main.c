#include "../inc/so_long.h"

int	main(int argc, char **argv)
{
	t_data	data;

	if (argc != 2)
		return (1);
	//init_window(&data);
	read_map(&data, argv[1]);
}