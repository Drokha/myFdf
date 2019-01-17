/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trabut <trabut@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/08 17:53:38 by trabut            #+#    #+#             */
/*   Updated: 2019/01/17 14:37:30 by trabut           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "mlx.h"
# include "libft/libft.h"
# include <math.h>
# include "get_next_line/get_next_line.h"
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>

#define MAP_LEN 1000

typedef	struct 	t_data
{
	void 	*ptr;
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

typedef	struct	s_coord
{
	int x1;
	int y1;
	int x2;
	int y2;
	int x3;
	int y3;
	int x4;
	int y4;
}				t_coord;

typedef struct	s_info
{
	int 	x1;
	int 	x2;
	int 	y1;
	int 	y2;
	void 	*ptr;
	void 	*win;
}				t_info;

char		**ft_read_input(char *input);
int			deal_mouse(int button, int x, int y, t_mouse_info *info);
void		ft_put_tab(char **tab);
void		ft_realloc(char *str);
void		ft_line(t_mouse_info *info);
void		ft_line_tiles(t_info *info);
void		ft_draw_losange(t_coord *coord, s_data *data);
void		ft_line_xy(s_data *data, int x1, int y1, int x2, int y2);
void		ft_draw_tiles_iso(s_data *data);
void		ft_line_tiles(t_info *info);
