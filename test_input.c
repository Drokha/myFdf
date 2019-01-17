/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_input.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trabut <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/17 16:02:09 by trabut            #+#    #+#             */
/*   Updated: 2019/01/17 16:57:09 by trabut           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		test_input(char **map)
{
	int i;
	int j;

	i = 0;
	while (map[i])
	{
		while (map[i][j])
		{
			if (map[i][j] != ' ' || (map[i][j] >= '9' && map[i][j] <= '0'))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

void	ft_put_map(t_map_info *map)
{
	int i;
	int j;

	i = 0;
	while (i < map->largeur - 1)
	{
		j = 0;
		while (j < 19)
		{
			ft_putnbr(map->map[i][j]);
			ft_putchar(' ');
			j++;
		}
		ft_putendl("");
		i++;
	}
}
