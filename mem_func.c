/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mem_func.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trabut <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/17 15:43:27 by trabut            #+#    #+#             */
/*   Updated: 2019/01/17 15:43:46 by trabut           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		ft_tab_len(char **tab)
{
	int i;

	i = 0;
	while (tab[i])
		i++;
	return (i);
}

void	destroy_tab(char ***tab)
{
	int i;

	i = 0;
	while ((*tab)[i])
	{
		free((*tab)[i]);
		(*tab)[i] = 0;
		i++;
	}
	free(*tab);
	*tab = 0;
}

char	**ft_realloc_map(char **map, int len)
{
	int i;
	char **ret;

	if (!(ret = (char **)malloc(sizeof(char *) * len + 1)))
		return (0);
	ret[len] = NULL;
	i = 0;
	while (i < len)
	{
		if (!(ret[i] = ft_strdup(map[i])))
			return (0);
		i++;
	}
	destroy_tab(&map);
	return (ret);
}
