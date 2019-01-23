/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trabut <trabut@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/17 15:40:59 by trabut            #+#    #+#             */
/*   Updated: 2019/01/23 14:03:44 by trabut           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

char    **ft_get_char_map(int fd)
{
	char	*line;
	char	**map;
	int		len;
	int i;

	len = 1;
	if (!(map = (char **)malloc(sizeof(char *) * len + 1)))
		return (0);
	map[len] = NULL;
	i = 0;
	while (get_next_line(fd, &line))
	{
		if (!(map[i] = ft_strdup(line)))
			return (0);
		if (!(map = ft_realloc_map(map, ++len)))
			return (0);
		i++;
	}
	return (map);
}

int		ft_get_map(t_map_info *map, int fd)
{
	char	**c_map;
	char	**tmp;
	int		i;
	int		j;
	int		cap;

	cap =
	i = 0;
	if (!(c_map = ft_get_char_map(fd)))
		return (0);
	map->largeur = ft_tab_len(c_map);
	if (!(map->map = (int **)malloc(sizeof(int *) * map->largeur)))
		return (0);
	while (i < map->largeur)
	{
		tmp = ft_strsplit(c_map[i], ' ');
		if (cap++ == 0)
			map->longueur = ft_tab_len(tmp);
		if (!((map->map)[i] = (int *)malloc(sizeof(int) * map->longueur)))
			return (0);
		j = 0;
		while (tmp[j])
		{
			map->map[i][j] = ft_atoi(tmp[j]);
			j++;
		}
		i++;
		destroy_tab(&tmp);
	}
	return (1);
}
