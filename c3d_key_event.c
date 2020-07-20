/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c3d_key_event.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-oliv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/29 22:10:15 by rde-oliv          #+#    #+#             */
/*   Updated: 2020/07/20 11:52:31 by rde-oliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "c3d.h"

int		c3d_key_press(int code, t_c3d *c3d)
{
	if (code == 65307)
		c3d_quit(EXIT_SUCCESS);
	else if (code == 115)
		ngn_set_walk(c3d->ngn, 1);
	else if (code == 65361)
		ngn_set_turn(c3d->ngn, -1);
	else if (code == 119)
		ngn_set_walk(c3d->ngn, -1);
	else if (code == 65363)
		ngn_set_turn(c3d->ngn, 1);
	else if (code == 97)
		ngn_set_turn(c3d->ngn, -1);
	else if (code == 100)
		ngn_set_turn(c3d->ngn, 1);
	return (0);
}

int		c3d_key_release(int code, t_c3d *c3d)
{
	if (code == 119)
		ngn_set_walk(c3d->ngn, 0);
	else if (code == 65361)
		ngn_set_turn(c3d->ngn, 0);
	else if (code == 115)
		ngn_set_walk(c3d->ngn, 0);
	else if (code == 65363)
		ngn_set_turn(c3d->ngn, 0);
	else if (code == 97)
		ngn_set_turn(c3d->ngn, 0);
	else if (code == 100)
		ngn_set_turn(c3d->ngn, 0);
	return (0);
}
