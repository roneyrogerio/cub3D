/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_event.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-oliv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/29 22:10:15 by rde-oliv          #+#    #+#             */
/*   Updated: 2020/06/14 04:54:52 by rde-oliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		key_press(int code, t_vars *vars)
{
	if (code == 65307)
		quit(&vars->glib);
	if (code == 115)
		ngn_set_walk(vars->ngn, 1);
	if (code == 65361)
		ngn_set_turn(vars->ngn, -1);
	if (code == 119)
		ngn_set_walk(vars->ngn, -1);
	if (code == 65363)
		ngn_set_turn(vars->ngn, 1);
	if (code == 97)
		ngn_set_side(vars->ngn, -1);
	if (code == 100)
		ngn_set_side(vars->ngn, 1);
	return (0);
}

int		key_release(int code, t_vars *vars)
{
	if (code == 119)
		ngn_set_walk(vars->ngn, 0);
	if (code == 65361)
		ngn_set_turn(vars->ngn, 0);
	if (code == 115)
		ngn_set_walk(vars->ngn, 0);
	if (code == 65363)
		ngn_set_turn(vars->ngn, 0);
	if (code == 97)
		ngn_set_side(vars->ngn, 0);
	if (code == 100)
		ngn_set_side(vars->ngn, 0);
	return (0);
}
