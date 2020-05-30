/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-oliv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/26 19:53:53 by rde-oliv          #+#    #+#             */
/*   Updated: 2020/05/29 22:52:01 by rde-oliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_H
# define CUB_H
# include <mlx.h>
# include <stdlib.h>

typedef struct	s_map
{
	int	size;
	int	slice;
	int mgnx;
	int mgny;
}				t_map;

typedef struct	s_core
{
	void	*mlx;
	void	*win;
	void	*img;
	int		wd;
	int		ht;
	int		px;
	int		py;
	int		**mx;
	int		mxwd;
	int		mxht;
	t_map	map;
}				t_core;

t_core			*mcore();
void			core_init();
void			map_setup();
void			mlx_pixel_put_image();
void			raycast();
void			map();
int				frame();
int				mapc();
int				rgb_sum();
int				key_event();
int				quit();
#endif
