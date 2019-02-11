/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trabut <trabut@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/14 14:56:22 by trabut            #+#    #+#             */
/*   Updated: 2019/02/11 17:52:20 by trabut           ###   ########.fr       */
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

int		ft_realloc(char **str)
{
	char	*tmp;

	tmp = ft_strdup(*str);
	if (!(*str = malloc((sizeof(char *) * 8 + ft_strlen(*str)))))
		return (0);
	ft_strcpy(*str, tmp);
	free(tmp);
	return (1);
}
