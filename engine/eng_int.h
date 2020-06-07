/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eng_int.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-oliv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/03 17:30:50 by rde-oliv          #+#    #+#             */
/*   Updated: 2020/06/07 00:26:12 by rde-oliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENG_INT_H
# define ENG_INT_H
# include <math.h>
# include <stdlib.h>

typedef struct	s_map
{
	int	sz;
	int	mgn_x;
	int	mgn_y;
}				t_map;

typedef struct	s_player
{
	double	x;
	double	y;
	double	radius;
	int		turn;
	int		walk;
	double	rotation_angle;
	double	move_speed;
	double	rotation_speed;
}				t_player;

typedef struct	s_eng
{
	int			wd;
	int			ht;
	int			**mx;
	int			mx_wd;
	int			mx_ht;
	t_map		map;
	t_player	player;
}				t_eng;

int				rgb_map(int p);

#endif
