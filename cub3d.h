/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-oliv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/26 19:53:53 by rde-oliv          #+#    #+#             */
/*   Updated: 2020/06/11 22:31:47 by rde-oliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H
# include "engine/eng.h"
# include <mlx.h>
# include <unistd.h>
# include <stdlib.h>
# define SUCCESS 0
# define FAILURE 1

typedef struct	s_glib
{
	void	*mlx;
	void	*win;
	void	*frame;
}				t_glib;

typedef struct	s_vars
{
	void		*eng;
	t_glib		glib;
}				t_vars;

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

int				rgb_alpha(int rgb1, int rgb2);
int				glib_init(void *eng, t_glib *glib);
int				frame(t_vars *vars);
void			frame_draw(int x, int y, int color);
unsigned		*mlx_image_pixel_ptr(void *img, int x, int y);
int				key_press(int code, t_vars *vars);
int				key_release(int code, t_vars *vars);
t_vars			*get_vars(void);
int				quit(t_glib *glib);
#endif
