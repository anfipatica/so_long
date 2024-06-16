/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anfi <anfi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 23:02:34 by anfi              #+#    #+#             */
/*   Updated: 2024/06/16 23:18:23 by anfi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../inc/so_long.h"

/**
 * We inicialize every element inside the t_map struct.
*/
t_map	init_map(void)
{
	t_map	map;

	map.c_count = 0;
	map.e_count = 0;
	map.f_count = 0;
	map.accesible_c = 0;
	map.accesible_e = 0;
	map.accesible_f = 0;
	map.p_count = 0;
	map.map_fd = 0;
	map.map_line = NULL;
	map.map_line_buf = "";
	map.row_num = 0;
	map.col_num = 0;
	return (map);
}
