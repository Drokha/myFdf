/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trabut <trabut@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/14 14:56:22 by trabut            #+#    #+#             */
/*   Updated: 2019/01/14 15:55:22 by trabut           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

char	**ft_read_input(char *input)
{
	char 	*line;
	int		fd;
	char 	**ret;
	int 	i;

	i = 0;
	fd = open(input, O_RDONLY);
	while (get_next_line(fd, &line))
	{
		ft_realloc_pt(&ret);
		while (ft_strlen(line) > ft_strlen(ret[i]))
		{
			ft_realloc(&ret[i]);
			ret[i] = line;
		}
		i++;
	}
	close(fd);
	return (ret);
}

void	ft_put_tab(char **tab)
{
	int i;

	i = 0;
	while (tab[i])
	{
		ft_putendl(tab[i]);
		i++;
	}
}

void	ft_realloc(char **str)
{
	char 	*tmp;

	tmp = ft_strdup(*str);
	if (!(*str = malloc(char*) * 8 + ft_strlen(*str)))
		return (0);
	ft_strcpy(*str, tmp);
}

void	ft_realloc_pt(char ***str)
{

}