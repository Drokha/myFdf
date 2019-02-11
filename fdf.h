/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trabut <trabut@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/08 17:53:38 by trabut            #+#    #+#             */
/*   Updated: 2019/02/11 17:54:03 by trabut           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "mlx.h"
# include "libft/libft.h"
# include <math.h>
# include "get_next_line/get_next_line.h"
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>

# define RGB(r, g, b)(256 * 256 * (int)(r) + 256 * (int)(g) + (int)(b))
# define MAP_LEN 500
# define mov 300
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
	int z1;
	int x2;
	int y2;
	int z2;
	int x3;
	int y3;
	int z3;
	int x4;
	int y4;
	int z4;
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

typedef		struct	s_map_info
{
	void	*ptr;
	void	*win;
	int		**map;
	int		longueur;
	int 	largeur;
}					t_map_info;

typedef	struct 	t_data
{
	void 		*ptr;
	void 		*win;
	int 		x;
	int			y;
	int			XL;
	int			YL;
	int			decX;
	int			decY;
	int 		color;
	int			height;
	char		*addr;
	t_map_info 	*map;
	void		*img;
}				s_data;

char		**ft_read_input(char *input);
int			deal_mouse(int button, int x, int y, t_mouse_info *info);
void		ft_put_tab(char **tab);
int			ft_realloc(char **str);
void		ft_line(t_mouse_info *info);
void		ft_line_tiles(t_info *info);
void		ft_draw_losange(t_coord *coord, s_data *data);
void		ft_line_xy(s_data *data, int x1, int y1, int x2, int y2);
void		ft_draw_tiles_iso(s_data *data, t_map_info *map);
void		ft_line_tiles(t_info *info);
int			ft_realloc_pt(char ***str);
int			ft_tab_len(char **tab);
void		destroy_tab(char ***tab);
char		**ft_realloc_map(char **map, int len);
int			test_input(char **map);
char		**ft_get_char_map(int fd);
int			ft_get_map(t_map_info *map, int fd);
void		ft_put_map(t_map_info *map);
void		ft_draw_re(s_data *data, t_map_info *map);
void 		ft_change_height(t_map_info *map, int a);
void 		ft_drawimg(s_data *data);
void		ft_img_mod(int x, int y, s_data *data);
