/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trabut <trabut@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/08 17:53:38 by trabut            #+#    #+#             */
/*   Updated: 2019/01/14 15:44:24 by trabut           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "mlx.h"
# include "libft/libft.h"
# include <math.h>
# include "get_next_line/get_next_line.h"
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>

typedef	struct 	t_data
{
	void 	*init;
	void 	*win;
	int 	x;
	int		y;
	int 	color;
}				s_data;

typedef struct  s_mouse_info
{
	void			*ptr;
	void			*win;
	int			x1;
	int			y1;
	int			x2;
	int			y2;
	int			color;
	int			set;
}				t_mouse_info;

char		**ft_read_input(char *input);
int			deal_mouse(int button, int x, int y, t_mouse_info *info);
void		ft_put_tab(char **tab);
void		ft_realloc(char *str);
