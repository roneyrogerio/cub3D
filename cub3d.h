/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-oliv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/26 19:53:53 by rde-oliv          #+#    #+#             */
/*   Updated: 2020/05/31 23:25:52 by rde-oliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H
# include <mlx.h>
# include <stdlib.h>

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

typedef struct	s_map
{
	int	size;
	int	slice;
	int mgn_x;
	int mgn_y;
}				t_map;

typedef struct	s_vars
{
	void	*mlx;
	void	*win;
	void	*frame;
	int		wd;
	int		ht;
	int		px;
	int		py;
	int		**mx;
	int		mx_wd;
	int		mx_ht;
	t_map	map;
}				t_vars;

t_vars			*my_vars();
void			vars_setup();
void			mini_map_setup();
void			frame_pixel_draw();
void			raycast();
void			mini_map_draw();
int				frame_draw();
int				rgb_map();
int				rgb_alpha();
int				key_event();
int				quit();
#endif
