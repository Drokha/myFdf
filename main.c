/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trabut <trabut@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/08 18:00:59 by trabut            #+#    #+#             */
/*   Updated: 2019/02/05 17:47:04 by trabut           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void 	ft_change_height(t_map_info *map, int a)
{
	int i;
	int j;

	i = 0;
	while (i < map->largeur)
	{
		j = 0;
		while(j < map->longueur)
		{
			if (a && map->map[i][j])
				map->map[i][j] += 2;
			else if (map->map[i][j] > 2)
				map->map[i][j] -= 2;
			j++;
		}
		i++;
	}
}

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
	t_map_info *map = data->map;
	s_data img;
	i = 0;
	ft_putnbr(key);
	ft_putendl("");
	data->height = 0;
	if (key == 36)
		mlx_string_put(data->ptr, data->win,
		150, 150, 123, "BONJOUR !\n C LE BOULGOUR");
	if (key == 53)
		exit(1);
	if (key == 83)
	{
		ft_draw_re(data, map);
	}
	if (key == 124)
	{
		data->decX -= 10;
		ft_draw_re(data, map);
	}
	if (key == 123)
	{
		data->decX += 10;
		ft_draw_re(data, map);
	}
	if (key == 125)
	{
		data->decY -= 10;
		ft_draw_re(data, map);
	}
	if (key == 126)
	{
		data->decY += 10;
		ft_draw_re(data, map);
	}
	if (key == 69)
	{
		data->XL = data->XL + 2;
		data->YL = data->XL / 2;
		ft_draw_re(data, map);
	}
	if (key == 78)
	{
		data->XL = data->XL - 2;
		data->YL = data->XL / 2;
		ft_draw_re(data, map);
	}
	if (key == 30)
	{
		ft_change_height(map, 1);
		ft_draw_re(data, map);
	}
	if (key == 33)
	{
		ft_change_height(map, 0);
		ft_draw_re(data, map);
	}
	return (0);
}

void	ft_draw_re(s_data *data, t_map_info *map)
{
	mlx_clear_window(data->ptr,data->win);
	data->x = 0;
	data->y = 0;
	while (data->y < map->largeur - 2)
	{
		ft_draw_tiles_iso(data, map);
	}
}

int		main(int ac, char **av)
{
	s_data			data;
	t_mouse_info	info;
	int				fd;
	t_map_info		map;

	data.ptr = mlx_init();
	info.ptr = data.ptr;
	map.ptr = data.ptr;
	data.win = mlx_new_window(data.ptr, 1000, 1000, "window1");
	info.win = data.win;
	map.win = data.win;
	info.color = 123;
	if (ac == 2)
	{
		fd = open(av[1], O_RDONLY);
		if (!(ft_get_map(&map, fd)))
			return (0);
		ft_put_map(&map);
	ft_putendl("");
	}
	data.XL = 4;
	data.YL = data.XL / 2;
	data.decX = 300;
	data.decY = 300;
	ft_putnbr(map.largeur);
	ft_putendl("");
	ft_putnbr(map.longueur);
	data.map = &map;
	mlx_key_hook(data.win, deal_key, &data);
	mlx_mouse_hook(data.win, deal_mouse, &map);
	mlx_loop(data.ptr);
}
