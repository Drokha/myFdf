/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trabut <trabut@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/08 18:00:59 by trabut            #+#    #+#             */
/*   Updated: 2019/01/17 14:44:57 by trabut           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_line(t_mouse_info *info)
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

void	ft_resest_info(t_mouse_info *info)
{
	info->x1 = 0;
	info->y1 = 0;
	info->x2 = 0;
	info->y2 = 0;
	info->set = 0;
}

int		deal_mouse(int button, int x, int y, t_mouse_info *info)
{
	if (info->set == 0)
	{
		info->x1 = x;
		info->y1 = y;
		info->set = 1;
	}
	else
	{
		info->x2 = x;
		info->y2 = y;
		ft_line(info);
		ft_resest_info(info);
	}
	return (info->set);
}

int		deal_key(int key, s_data *data)
{
	int i;

	i = 0;
	ft_putnbr(key);
	ft_putendl("");
	if (key == 36)
		mlx_string_put(data->ptr, data->win,
		150, 150, 123, "BONJOUR !\n C LE BOULGOUR");
	if (key == 53)
		exit(1);
	if (key == 69)
	{
		while (i < 100)
		{
			ft_draw_tiles_iso(data);
			data->x++;
			i++;
		}
	}
	return (0);
}

int		main(int ac, char **av)
{
	s_data			data;
	t_mouse_info	info;

	/*
	u = x*cos(α) + y*cos(α+120°) + z*cos(α-120°)
	v = x*sin(α) + y*sin(α+120°) + z*sin(α-120°)
	*/
	data.ptr = mlx_init();
	info.ptr = data.ptr;
	data.win = mlx_new_window(data.ptr, MAP_LEN, MAP_LEN, "window1");
	info.win = data.win;
	info.color = 123;
	mlx_key_hook(data.win, deal_key, &data);
	mlx_mouse_hook(data.win, deal_mouse, &info);
	mlx_loop(data.ptr);
}
