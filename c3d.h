/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c3d.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-oliv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/26 19:53:53 by rde-oliv          #+#    #+#             */
/*   Updated: 2020/07/27 15:11:20 by rde-oliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef C3D_H
# define C3D_H
# include "libft.h"
# include "ngn.h"
# include "lbmp.h"
# include "mlx.h"
# include <unistd.h>

typedef struct	s_c3d
{
	void	*mlx;
	void	*win;
	void	*ngn;
	void	*frame;
	int		save;
}				t_c3d;

typedef struct	s_rgb
{
	double	a;
	int		r;
	int		g;
	int		b;
}				t_rgb;

typedef struct	s_alpha
{
	t_rgb	rgb1;
	t_rgb	rgb2;
}				t_alpha;

t_c3d			g_c3d;
int				rgb_alpha(int rgb1, int rgb2);
int				c3d_window_init(void);
int				c3d_frame(t_c3d *c3d);
void			c3d_mlx_draw(int x, int y, int color);
void			c3d_lbmp_draw(int x, int y, int color);
unsigned		*mlx_image_pixel_ptr(void *img, int x, int y);
int				c3d_key_press(int code, t_c3d *c3d);
int				c3d_key_release(int code, t_c3d *c3d);
int				c3d_quit(int ret_code);
#endif
