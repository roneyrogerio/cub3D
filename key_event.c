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
		eng_set_walk(vars->eng, 1);
	if (code == 65361)
		eng_set_turn(vars->eng, -1);
	if (code == 119)
		eng_set_walk(vars->eng, -1);
	if (code == 65363)
		eng_set_turn(vars->eng, 1);
	if (code == 97)
		eng_set_side(vars->eng, -1);
	if (code == 100)
		eng_set_side(vars->eng, 1);
	return (0);
}

int		key_release(int code, t_vars *vars)
{
	if (code == 119)
		eng_set_walk(vars->eng, 0);
	if (code == 65361)
		eng_set_turn(vars->eng, 0);
	if (code == 115)
		eng_set_walk(vars->eng, 0);
	if (code == 65363)
		eng_set_turn(vars->eng, 0);
	if (code == 97)
		eng_set_side(vars->eng, 0);
	if (code == 100)
		eng_set_side(vars->eng, 0);
	return (0);
}
