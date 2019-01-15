/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trabut <trabut@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/15 15:33:59 by trabut            #+#    #+#             */
/*   Updated: 2019/01/15 16:22:18 by trabut           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_line_tiles(t_info *info)
{
	int dx;
	int sx;
	int dy;
	int sy;
	int err;
	int e2;

	dx = abs(info->x2 - info->x1);
	sx = info->x1 < info->x2 ? 1 : -1;
	dy = abs(info->y2 - info->y1);
	sy = info->y1 < info->y2 ? 1 : -1;
	err = (dx > dy ? dx : -dy) / 2;
	while (1)
	{
		if (info->x1 == info->x2 && info->y1 == info->y2)
			break ;
		mlx_pixel_put(info->ptr, info->win, info->x1, info->y1, 000377000377);
		e2 = err;
		if (e2 > -dx)
		{
			err -= dy;
			info->x1 += sx;
		}
		if (e2 < dy)
		{
			err += dx;
			info->y1 += sy;
		}
	}
}

void	ft_draw_tiles_iso(s_data *data)
{
	t_coord coord;

	coord.x1 = (data->x - data->y) * 64;
	coord.y1 = (data->x + data->y) * 32;
	coord.x2 = (data->x + 1 - data->y) * 64;
	coord.y2 = (data->x + 1 + data->y) * 32;
	coord.x4 = (data->x + 1 - data->y + 1) * 64;
	coord.y4 = (data->x + 1 + data->y + 1) * 32;
	coord.x3 = (data->x - data->y + 1) * 64;
	coord.y3 = (data->x + data->y + 1) * 32;
	ft_draw_losange(&coord, data);
}

void	ft_draw_losange(t_coord *coord, s_data *data)
{
	t_info info;
	
	ft_line_tiles()
}

void	ft_line_xy(s_data *data, int x1, int y1, int x2, int y2)
{
	int dx;
	int sx;
	int dy;
	int sy;
	int err;
	int e2;

	dx = abs(x2 - x1);
	sx = x1 < x2 ? 1 : -1;
	dy = abs(y2 - y1);
	sy = y1 < y2 ? 1 : -1;
	err = (dx > dy ? dx : -dy) / 2;
	while (1)
	{
		if (x1 == x2 && y1 == y2)
			break ;
		mlx_pixel_put(data->ptr, data->win, x1, y1, 000377000377);
		e2 = err;
		if (e2 > -dx)
		{
			err -= dy;
			info->x1 += sx;
		}
		if (e2 < dy)
		{
			err += dx;
			info->y1 += sy;
		}
	}
}