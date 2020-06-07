/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eng_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-oliv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/06 19:54:13 by rde-oliv          #+#    #+#             */
/*   Updated: 2020/06/06 22:08:54 by rde-oliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "eng_int.h"

t_eng		*eng_init(void)
{
	static t_eng	eng;

	eng.ht = 593;
	eng.wd = 800;
	eng.mx_wd = 14;
	eng.mx_ht = 24;
	eng.player.x = 0.5;
	eng.player.y = 0.5;
	eng.player.radius = 0.2;
	eng.player.turn = 0;
	eng.player.walk = 0;
	eng.player.rotation_angle = M_PI / 2;
	eng.player.move_speed = 0.05;
	eng.player.rotation_speed = 2 * (M_PI / 180);
	eng.map.sz = (eng.ht < eng.wd ? eng.ht : eng.wd) / 5;
	eng.map.sz /= eng.mx_ht > eng.mx_wd ? eng.mx_ht : eng.mx_wd;
	eng.map.sz = eng.map.sz > 0 ? eng.map.sz : 1;
	eng.map.mgn_x = eng.wd / 20;
	eng.map.mgn_y = eng.ht / 16;
	return (&eng);
}
