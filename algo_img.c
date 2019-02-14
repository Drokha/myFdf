/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_img.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trabut <trabut@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/11 14:43:37 by trabut            #+#    #+#             */
/*   Updated: 2019/02/14 17:54:30 by trabut           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
/*
void	ft_draw_tiles_caval(s_data *data, t_map_info *map)
{
	t_coord coord;

	coord.x1 = ((data->x) * data->XL + data->decX + (map->map[data->y][data->x] * data->mult));
	coord.y1 = ((data->y) * data->YL - (map->map[data->y][data->x] * data->mult) + data->decY);
	coord.x2 = ((data->x + 1) * data->XL + data->decX + (map->map[data->y][data->x] * data->mult));
	coord.y2 = (((data->y) * data->YL) - (map->map[data->y][data->x + 1] * data->mult) + data->decY);
	coord.x3 = ((data->x + 1) * data->XL + data->decX + (map->map[data->y][data->x] * data->mult));
	coord.y3 = ((((data->y + 1)) * data->YL) - (map->map[data->y + 1][data->x + 1] * data->mult) + data->decY);
	coord.x4 = ((data->x) * data->XL + data->decX + (map->map[data->y][data->x] * data->mult));
	coord.y4 = (((data->y + 1) * data->YL) - (map->map[data->y + 1][data->x] * data->mult) + data->decY);
	if (coord.x1 > MAP_LEN || coord.x2 > MAP_LEN || coord.x3 > MAP_LEN ||
		coord.x4 > MAP_LEN || coord.y1 > MAP_LEN || coord.y2 > MAP_LEN ||
		coord.y3 > MAP_LEN || coord.y4 > MAP_LEN || data->x > data->map->longueur - 2 ||
		coord.x1 < 0 || coord.x2 < 0 || coord.x3 < 0 ||
		coord.x4 < 0 || coord.y1 < 0 || coord.y2 < 0 ||
		coord.y3 < 0 || coord.y4 < 0)
	{
		data->x++;
		if (data->x > map->longueur - 2)
		{
			data->y++;
			data->x = 0;
		}
	}
	else
	{
		ft_draw_losange(&coord, data);
		data->x++;
	}
}*/

void	ft_draw_tiles_caval(s_data *data, t_map_info *map)
{
	t_coord coord;

	coord.x1 = ((data->x) * data->XL + data->decX + (map->map[data->y][data->x] * data->mult));
	coord.y1 = ((data->y) * data->YL * 2 - (map->map[data->y][data->x] * data->mult) + data->decY);
	coord.x2 = ((data->x + 1) * data->XL + data->decX + (map->map[data->y][data->x + 1] * data->mult));
	coord.y2 = (((data->y) * data->YL * 2) - (map->map[data->y][data->x + 1] * data->mult) + data->decY);
	coord.x3 = ((data->x + 1) * data->XL + data->decX + (map->map[data->y + 1][data->x + 1] * data->mult));
	coord.y3 = ((((data->y + 1)) * data->YL * 2) - (map->map[data->y + 1][data->x + 1] * data->mult) + data->decY);
	coord.x4 = ((data->x) * data->XL + data->decX + (map->map[data->y + 1][data->x] * data->mult));
	coord.y4 = (((data->y + 1) * data->YL * 2) - (map->map[data->y + 1][data->x] * data->mult) + data->decY);
	if (coord.x1 > MAP_LEN || coord.x2 > MAP_LEN || coord.x3 > MAP_LEN ||
		coord.x4 > MAP_LEN || coord.y1 > MAP_LEN || coord.y2 > MAP_LEN ||
		coord.y3 > MAP_LEN || coord.y4 > MAP_LEN || data->x > data->map->longueur - 2 ||
		coord.x1 < 0 || coord.x2 < 0 || coord.x3 < 0 ||
		coord.x4 < 0 || coord.y1 < 0 || coord.y2 < 0 ||
		coord.y3 < 0 || coord.y4 < 0)
	{
		data->x++;
		if (data->x > map->longueur - 2)
		{
			data->y++;
			data->x = 0;
		}
	}
	else
	{
		ft_draw_losange(&coord, data);
		data->x++;
	}
}