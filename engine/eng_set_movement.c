/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eng_set_movement.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-oliv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/06 21:43:28 by rde-oliv          #+#    #+#             */
/*   Updated: 2020/06/10 02:13:17 by rde-oliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "eng_int.h"

void	eng_set_walk(t_eng *eng, int value)
{
	eng->player.walk = value;
}

void	eng_set_turn(t_eng *eng, int value)
{
	eng->player.turn = value;
}

void	eng_set_side(t_eng *eng, int value)
{
	eng->player.side = value;
}

void	eng_movement_update(t_eng *eng)
{
	double	move_step;
	double	side_step;
	double	side_angle;

	eng->player.angle += eng->player.turn * eng->player.turn_speed;
	move_step = eng->player.walk * eng->player.move_speed;
	side_step = eng->player.side * eng->player.move_speed;
	side_angle = eng->player.angle - (90 * (M_PI / 180));
	eng->player.x += cos(eng->player.angle) * move_step;
	eng->player.y += sin(eng->player.angle) * move_step;
	eng->player.x += cos(side_angle) * side_step;
	eng->player.y += sin(side_angle) * side_step;
}
